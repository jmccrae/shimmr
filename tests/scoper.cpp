#include "../parser/type.h"
#include "../parser/scope_inferrer.h"
#include <exception>
#include <iostream>
#include "tests.h"
#include "scoper.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(ScoperTests);

shared_ptr<shimmr::Scope> first(map<Visitable*,shared_ptr<shimmr::Scope>> e) {
	return (*e.begin()).second;
}

void ScoperTests::testScope() {
	auto progTxt = "val x = 3; val Int y; def foo(1:3 z) { z + 1 }";
	auto prog = getAST(progTxt);
	auto scope = shimmr::ScopeInferrer::infer(prog);
	CPPUNIT_ASSERT(scope->isScopeValid());
	CPPUNIT_ASSERT_EQUAL(1,(int)scope->children.size());
	CPPUNIT_ASSERT_EQUAL(1,(int)first(scope->children)->children.size());
	CPPUNIT_ASSERT(scope->resolve("x") != nullptr);
	CPPUNIT_ASSERT(scope->resolve("y") != nullptr);
	CPPUNIT_ASSERT(first(scope->children)->resolve("y") != nullptr);
}

void ScoperTests::testBadScope() {
	auto prog1 = getAST("val x = 3 ; val x = 4");
	auto scope1 = shimmr::ScopeInferrer::infer(prog1);
	CPPUNIT_ASSERT(!scope1->isScopeValid());
	auto prog2 = getAST("val x = 3 ; def foo(Int x) { x + 1 }");
	auto scope2 = shimmr::ScopeInferrer::infer(prog2);
	CPPUNIT_ASSERT(!scope2->isScopeValid());
}