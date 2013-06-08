#include "logicproc_tests.h"
#include "tests.h"
#include "../parser/type_checker.h"
#include "../parser/scope_inferrer.h"
#include "../logic/logic_processor.h"
#include <sstream>

CPPUNIT_TEST_SUITE_REGISTRATION(LogicprocTests);

using namespace std;

LogicprocTests::LogicprocTests(void)
{
}


LogicprocTests::~LogicprocTests(void)
{
}

const std::string LogicprocTests::evaluate(const string& exp) {
	auto decl = getAST(exp.c_str());
	auto topScope = shimmr::ScopeInferrer::infer(decl);
	auto checker = new shimmr::TypeChecker(topScope);
	decl->accept(checker);
	auto processor = new shimmr::logic::LogicProcessor(checker->sys,topScope,checker->expressionTypes);
	decl->accept(processor);
	auto stats = processor->statements();
	delete processor;
	delete checker;
	stringstream ss;
	int i = 1;
	for(auto s : stats) {
		ss << s->toString();
		if(i != stats.size()) {
			ss << " ^ ";
		}
		i++;
	}
	return ss.str();
}

void LogicprocTests::testEq() {
	auto logic = evaluate("val Int x = 3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,3)",logic);
}

void LogicprocTests::testSTE() {
	auto logic = evaluate("val x = { \"a\", 3, 0.3 }");
	CPPUNIT_ASSERT_EQUAL((string)"@in(?1,\"a\") ^ @in(?1,3) ^ @in(?1,0.300000) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testString() {
	auto logic = evaluate("val x = \"x\"");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,\"x\")",logic);
}

void LogicprocTests::testInt() {
	auto logic = evaluate("val x = 3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,3)",logic);
}

void LogicprocTests::testFloat() {
	auto logic = evaluate("val x = 0.3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,0.300000)",logic);
}

void LogicprocTests::testRange() {
	auto logic = evaluate("val x = 1:3");
	CPPUNIT_ASSERT_EQUAL((string)"@range(?1,1,3) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testFuncCall() {
	auto logic = evaluate("def foo(Int x) { x } ; val y = foo(3)");
	CPPUNIT_ASSERT_EQUAL((string)"(foo@0(x@1) -> @eq(!foo@0[x@1],x@1)) ^ foo@0(3) ^ @eq(y@0,!foo@0[3])",logic);
}

void LogicprocTests::testIdent() {
	auto logic = evaluate("val y = 3 ; val x = y");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(y@0,3) ^ @eq(x@0,y@0)",logic);
}

void LogicprocTests::testNot() {
	auto logic = evaluate("val x = !true");
	CPPUNIT_ASSERT_EQUAL((string)"@not(?1,true@0) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testDiv() {
	auto logic = evaluate("val x = 2 / 3");
	CPPUNIT_ASSERT_EQUAL((string)"@divide(?1,2,3) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testMul() {
	auto logic = evaluate("val x = 3 * 5");
	CPPUNIT_ASSERT_EQUAL((string)"@times(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testSub() {
	auto logic = evaluate("val x = 1 - 1");
	CPPUNIT_ASSERT_EQUAL((string)"@minus(?1,1,1) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testAdd() {
	auto logic = evaluate("val x = 3 + 10");
	CPPUNIT_ASSERT_EQUAL((string)"@plus(?1,3,10) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testGT() {
	auto logic = evaluate("val x = 3 > 5");
	CPPUNIT_ASSERT_EQUAL((string)"@gt(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testLT() {
	auto logic = evaluate("val x = 3 < 5");
	CPPUNIT_ASSERT_EQUAL((string)"@lt(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testLEQ() {
	auto logic = evaluate("val x = 3 <= 5");
	CPPUNIT_ASSERT_EQUAL((string)"@leq(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testGEQ() {
	auto logic = evaluate("val x = 3 >= 5");
	CPPUNIT_ASSERT_EQUAL((string)"@geq(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testNEQ() {
	auto logic = evaluate("val x = 3 != 5");
	CPPUNIT_ASSERT_EQUAL((string)"@neq(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testAND() {
	auto logic = evaluate("val x = 3 && 5");
	CPPUNIT_ASSERT_EQUAL((string)"@and(?1,3,5) ^ @eq(x@0,?1)",logic);
}

void LogicprocTests::testOR() {
	auto logic = evaluate("val x = 3 || 5");
	CPPUNIT_ASSERT_EQUAL((string)"() v () ^ @or(?1,3,5) ^ @eq(x@0,?1)",logic);
	logic = evaluate("val Int x ; val Int y ; x = 3 || y = 5");
	CPPUNIT_ASSERT_EQUAL((string)"(@eq(?1,x@0,3)) v (@eq(?2,y@0,5)) ^ @or(?3,?1,?2)",logic);
}

void LogicprocTests::testEQ() {
	auto logic = evaluate("3 = 5");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(?1,3,5)",logic);
}

void LogicprocTests::testConditional() {
	auto logic = evaluate("val x = 3 ; x = 5 with 2 * 3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,3) ^ @times(?1,2,3) ^ (@eq(?2,x@0,5)) with ?1",logic);
}

void LogicprocTests::testSomeElse() {
	auto logic = evaluate("some(x in 1:3) { x = 3 } else { false }");
	CPPUNIT_ASSERT_EQUAL((string)"@range(?1,1,3) ^ O[x@1](@eq(?2,x@1,3) ^ @in(?1,x@1) ^ @eq(?3,?2)) o (@eq(?3,false@0))",logic);
}

void LogicprocTests::testSome() {
	auto logic = evaluate("some(x in 1:3) { x = 3 }");
	CPPUNIT_ASSERT_EQUAL((string)"@range(?1,1,3) ^ O[x@1](@eq(?2,x@1,3) ^ @in(?1,x@1) ^ @eq(?3,?2)) o (@false())",logic);
}

void LogicprocTests::testElseFail() {
	auto logic = evaluate("if(2 = 3) { 4 } else fail");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(?1,2,3) ^ (@true(?1) -> @eq(?2,4)) ^ (@true(?1)) v (@false() ^ @eq(?2,unit))",logic);
}

void LogicprocTests::testIfElseIfElse() {
	auto logic = evaluate("if(2 = 3) { 4 } else if(false) { 5 } else { 6 }");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(?1,2,3) ^ (@true(?1) -> @eq(?3,4)) ^ (@true(?1)) v ((@true(false@0) -> @eq(?2,5)) ^ (@true(false@0)) v (@eq(?2,6)) ^ @eq(?3,?2))",logic);
}

void LogicprocTests::testIf() {
	auto logic = evaluate("if(2 = 3) { val x = 2 * 3 ; x }");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(?1,2,3) ^ (@true(?1) -> @times(?2,2,3) ^ @eq(x@2,?2) ^ @eq(?3,x@2)) ^ (@true(?1)) v (@none(?3))",logic);
}

void LogicprocTests::testIfElse() {
	auto logic = evaluate("if(2 < 3) { 2 * 3 } else if(3 > 2) { 2 / 3 }");
	CPPUNIT_ASSERT_EQUAL((string)"@lt(?1,2,3) ^ (@true(?1) -> @times(?2,2,3) ^ @eq(?6,?2)) ^ (@true(?1)) v (@gt(?3,3,2) ^ (@true(?3) -> @divide(?4,2,3) ^ @eq(?5,?4)) ^ (@true(?3)) v (@none(?5)) ^ @eq(?6,?5))",logic);
}

void LogicprocTests::testFor() {
	auto logic = evaluate("for(i in 1:3) { i + 1 }");
	CPPUNIT_ASSERT_EQUAL((string)"@range(?1,1,3) ^ (@in(?1,i@1) -> @plus(?2[i@1],i@1,1) ^ @in(?3,i@1,?2[i@1]))",logic);
}
		 
void LogicprocTests::testFunc() {
	auto logic = evaluate("def foo(Int x) { x + 1 }");
	CPPUNIT_ASSERT_EQUAL((string)"(foo@0(x@1) -> @plus(?1[x@1],x@1,1) ^ @eq(!foo@0[x@1],?1[x@1]))",logic);
}
		 
void LogicprocTests::testFuncWithType() {
	auto logic = evaluate("def Int foo(Int x) { x + 1 }");
	CPPUNIT_ASSERT_EQUAL((string)"(foo@0(x@1) -> @plus(?1[x@1],x@1,1) ^ @eq(!foo@0[x@1],?1[x@1]))",logic);
}

void LogicprocTests::testSimpleDecl() {
	auto logic = evaluate("val x = 3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,3)",logic);
}

void LogicprocTests::testTypedDecl() {
	auto logic = evaluate("val Int x = 3");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(x@0,3)",logic);
}

void LogicprocTests::testSimpleDeclWith() {
	auto logic = evaluate("val w = 2 ; val x = 3 with w");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(w@0,2) ^ (@eq(x@0,3)) with w@0",logic);
}

void LogicprocTests::testTypedDeclWith() {
	auto logic = evaluate("val w = 2 ; val Int x = 3 with w");
	CPPUNIT_ASSERT_EQUAL((string)"@eq(w@0,2) ^ (@eq(x@0,3)) with w@0",logic);
}

void LogicprocTests::testBareDecl() {
	auto logic = evaluate("val Int x");
	CPPUNIT_ASSERT_EQUAL((string)"",logic);
}