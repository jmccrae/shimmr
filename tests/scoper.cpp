// tests.cpp : All tests for Shimmr
//
#include <UnitTest++.h>
#include "../parser/type.h"
#include "../parser/scope_inferer.h"
#include <exception>
#include <iostream>
#include "tests.h"

using namespace std;

TEST(TestScope) {
	auto progTxt = "val x = 3; val Int y; def foo(1:3 x) { x + 1 }";
	auto prog = getAST(progTxt);
	auto scope = shimmr::ScopeInferer::infer(prog);
	CHECK(scope->isScopeValid());
}
