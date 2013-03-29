// tests.cpp : All tests for Shimmr
//
#include <UnitTest++.h>
#include "../parser/type.h"
#include <exception>
#include <iostream>

using namespace shimmrType;
using namespace std;

TEST(TestAnything) {
	auto sys = make_shared<TypeSystem>();
	CHECK(sys->Anything->isSuperclassOf(sys->Int));
	//CHECK(sys->Anything->isEqual(sys->Anything,sys));
}

TEST(TestPrimitive) {
	auto sys = make_shared<TypeSystem>();
	CHECK(sys->Int->isEqual(sys->Int));
	CHECK(!sys->Int->isSuperclassOf(sys->Int));
	CHECK(!sys->Int->isEqual(sys->Bool));
}

TEST(TestUnion) {
	auto sys = make_shared<TypeSystem>();
	CHECK_EQUAL("Bool|Int",sys->Int->or(sys->Bool)->symbol());
	// (A|B)|C = A|(B|C)
	CHECK(sys->Int->or(sys->Bool->or(sys->Float))->isEqual(
		 sys->Int->or(sys->Bool)->or(sys->Float)));
	// A|B = B|A
	CHECK(sys->Int->or(sys->Bool)->isEqual(
		sys->Bool->or(sys->Int)));
	// A|Anything = Anything
	CHECK(sys->Int->or(sys->Anything)->isEqual(
		sys->Anything));
	CHECK(sys->Anything->or(sys->Int)->isEqual(
		sys->Anything));
	// A|A == A
	CHECK(sys->Int->isEqual(sys->Int->or(sys->Int)));
	// A|B == A B <= A
	CHECK(sys->Numeric->isEqual(sys->Int->or(sys->Numeric)));
	CHECK(sys->Numeric->isEqual(sys->Numeric->or(sys->Int)));
}

TEST(TestError) {
	auto sys = make_shared<TypeSystem>();
	auto err = sys->makeError("Something went wrong!");
	CHECK(err->isError());
	CHECK(!err->isEqual(sys->Numeric));
	CHECK(err->or(sys->String)->isError());
	CHECK(sys->String->or(err)->isError());
}

TEST(TestSet) {
	auto sys = make_shared<TypeSystem>();
	set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals(compareTypeValue);
	vals.insert(make_shared<StringTypeValue>("a"));
	vals.insert(make_shared<IntTypeValue>(2));
	vals.insert(make_shared<FloatTypeValue>(2.0));
	auto setType = sys->makeSet(vals);
	CHECK_EQUAL("{\"a\",2,2.000000}",setType->symbol());
	set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals2(compareTypeValue);
	vals2.insert(make_shared<IntTypeValue>(2));
	auto setType2 = sys->makeSet(vals2);
	CHECK(setType->isSuperclassOf(setType2));
	CHECK(setType->isEqual(setType2->or(setType)));
	CHECK(setType->isEqual(setType->or(setType2)));
	set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals3(compareTypeValue);
	vals2.insert(make_shared<IntTypeValue>(4));
	auto setType4 = sys->makeSet(vals3);
	CHECK(setType->or(setType4)->isSet());
	CHECK(sys->Int->isSuperclassOf(setType4));
	CHECK_EQUAL("Int",setType2->or(sys->Int)->symbol());
	CHECK_EQUAL("Int|{\"a\",2,2.000000}",setType->or(sys->Int)->symbol());
}

TEST(TestRange) {
	auto sys = make_shared<TypeSystem>();
	auto t1 = sys->makeRange(1,3);
	CHECK_EQUAL("1:3",t1->symbol());
	auto t2 = sys->makeRange(2,4);
	auto t3 = sys->makeRange(1,4);
	CHECK(t3->isEqual(t1->or(t2)));
	set<const shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals(compareTypeValue);
	vals.insert(make_shared<IntTypeValue>(4));
	auto t4 = sys->makeSet(vals);
	CHECK_EQUAL("{1,2,3,4}",t1->or(t4)->symbol());
	CHECK_EQUAL("1:4",t3->or(t4)->symbol());
	auto t5 = sys->makeRange(5,7);
	CHECK_EQUAL("1:7",t3->or(t5)->symbol());
	CHECK(t3->isSuperclassOf(t2));
	CHECK(sys->Int->isSuperclassOf(t2));
}

TEST(TestVector) {
	auto sys = make_shared<TypeSystem>();
	auto t1 = sys->makeVector(sys->Int,sys->makeRange(1,3));
	CHECK_EQUAL("Int[1:3]", t1->symbol());
}