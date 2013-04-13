#include <unittest++/UnitTest++.h>
#include "../parser/type.h"
#include "../parser/scope_inferrer.h"
#include <exception>
#include <iostream>
#include "tests.h"

using namespace std;

shared_ptr<shimmr::Scope> first(map<Visitable*,shared_ptr<shimmr::Scope>> e) {
	return (*e.begin()).second;
}

TEST(TestScope) {
	auto progTxt = "val x = 3; val Int y; def foo(1:3 z) { z + 1 }";
	auto prog = getAST(progTxt);
	auto scope = shimmr::ScopeInferrer::infer(prog);
	CHECK(scope->isScopeValid());
	CHECK_EQUAL(1,scope->children.size());
	CHECK_EQUAL(1,first(scope->children)->children.size());
	CHECK(scope->resolve("x") != nullptr);
	CHECK(scope->resolve("y") != nullptr);
	CHECK(first(scope->children)->resolve("y") != nullptr);
}

TEST(TestBadScope) {
	auto prog1 = getAST("val x = 3 ; val x = 4");
	auto scope1 = shimmr::ScopeInferrer::infer(prog1);
	CHECK(!scope1->isScopeValid());
	auto prog2 = getAST("val x = 3 ; def foo(Int x) { x + 1 }");
	auto scope2 = shimmr::ScopeInferrer::infer(prog2);
	CHECK(!scope2->isScopeValid());
}