// tests.cpp : All tests for Shimmr
//
#include "../parser/type.h"
#include <exception>
#include <iostream>
#include "type_axioms.h"

using namespace shimmr::type;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(TypeTests);

void TypeTests::TestAnything() {
	auto sys = make_shared<TypeSystem>();
	CPPUNIT_ASSERT(sys->Anything->isSuperclassOf(sys->Int));
	//CPPUNIT_ASSERT(sys->Anything->isEqual(sys->Anything,sys));
}

void TypeTests::TestPrimitive() {
	auto sys = make_shared<TypeSystem>();
	CPPUNIT_ASSERT(sys->Int->isEqual(sys->Int));
	CPPUNIT_ASSERT(!sys->Int->isSuperclassOf(sys->Int));
	CPPUNIT_ASSERT(!sys->Int->isEqual(sys->Bool));
}

void TypeTests::TestUnion() {
	auto sys = make_shared<TypeSystem>();
	CPPUNIT_ASSERT_EQUAL((string)"Bool|Int",sys->Int->unify(sys->Bool)->symbol());
	// (A|B)|C = A|(B|C)
	CPPUNIT_ASSERT(sys->Int->unify(sys->Bool->unify(sys->Float))->isEqual(
		 sys->Int->unify(sys->Bool)->unify(sys->Float)));
	// A|B = B|A
	CPPUNIT_ASSERT(sys->Int->unify(sys->Bool)->isEqual(
		sys->Bool->unify(sys->Int)));
	// A|Anything = Anything
	CPPUNIT_ASSERT(sys->Int->unify(sys->Anything)->isEqual(
		sys->Anything));
	CPPUNIT_ASSERT(sys->Anything->unify(sys->Int)->isEqual(
		sys->Anything));
	// A|A == A
	CPPUNIT_ASSERT(sys->Int->isEqual(sys->Int->unify(sys->Int)));
	// A|B == A B <= A
	CPPUNIT_ASSERT(sys->Numeric->isEqual(sys->Int->unify(sys->Numeric)));
	CPPUNIT_ASSERT(sys->Numeric->isEqual(sys->Numeric->unify(sys->Int)));
}

void TypeTests::TestError() {
	auto sys = make_shared<TypeSystem>();
	auto err = sys->makeError(0,"Something went wrong!");
	CPPUNIT_ASSERT(err->isError());
	CPPUNIT_ASSERT(!err->isEqual(sys->Numeric));
	CPPUNIT_ASSERT(err->unify(sys->String)->isError());
	CPPUNIT_ASSERT(sys->String->unify(err)->isError());
}

void TypeTests::TestSet() {
	auto sys = make_shared<TypeSystem>();
	set<shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals(compareTypeValue);
	vals.insert(make_shared<StringTypeValue>("a"));
	vals.insert(make_shared<IntTypeValue>(2));
	vals.insert(make_shared<FloatTypeValue>(2.0));
	auto setType = sys->makeSet(vals);
	CPPUNIT_ASSERT_EQUAL((string)"{\"a\",2,2.000000}",setType->symbol());
	set<shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals2(compareTypeValue);
	vals2.insert(make_shared<IntTypeValue>(2));
	auto setType2 = sys->makeSet(vals2);
	CPPUNIT_ASSERT(setType->isSuperclassOf(setType2));
	CPPUNIT_ASSERT(setType->isEqual(setType2->unify(setType)));
	CPPUNIT_ASSERT(setType->isEqual(setType->unify(setType2)));
	set<shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals3(compareTypeValue);
	vals2.insert(make_shared<IntTypeValue>(4));
	auto setType4 = sys->makeSet(vals3);
	CPPUNIT_ASSERT(setType->unify(setType4)->isSet());
	CPPUNIT_ASSERT(sys->Int->isSuperclassOf(setType4));
	CPPUNIT_ASSERT_EQUAL((string)"Int",setType2->unify(sys->Int)->symbol());
	CPPUNIT_ASSERT_EQUAL((string)"Int|{\"a\",2,2.000000}",setType->unify(sys->Int)->symbol());
}

void TypeTests::TestRange() {
	auto sys = make_shared<TypeSystem>();
	auto t1 = sys->makeRange(1,3);
	CPPUNIT_ASSERT_EQUAL((string)"1:3",t1->symbol());
	auto t2 = sys->makeRange(2,4);
	auto t3 = sys->makeRange(1,4);
	CPPUNIT_ASSERT(t3->isEqual(t1->unify(t2)));
	set<shared_ptr<TypeValue>, decltype(compareTypeValue)*> vals(compareTypeValue);
	vals.insert(make_shared<IntTypeValue>(4));
	auto t4 = sys->makeSet(vals);
	CPPUNIT_ASSERT_EQUAL((string)"{1,2,3,4}",t1->unify(t4)->symbol());
	CPPUNIT_ASSERT_EQUAL((string)"1:4",t3->unify(t4)->symbol());
	auto t5 = sys->makeRange(5,7);
	CPPUNIT_ASSERT_EQUAL((string)"1:7",t3->unify(t5)->symbol());
	CPPUNIT_ASSERT(t3->isSuperclassOf(t2));
	CPPUNIT_ASSERT(sys->Int->isSuperclassOf(t2));
}

void TypeTests::TestVector() {
	auto sys = make_shared<TypeSystem>();
	auto t1 = sys->makeVector(sys->Int,sys->makeRange(1,3));
	CPPUNIT_ASSERT_EQUAL((string)"Int[1:3]", t1->symbol());
}