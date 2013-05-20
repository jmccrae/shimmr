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