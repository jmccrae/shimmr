#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/logic/logic.o \
	${OBJECTDIR}/logic/logic_processor.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/parser/Absyn.o \
	${OBJECTDIR}/parser/Printer.o \
	${OBJECTDIR}/parser/Skeleton.o \
	${OBJECTDIR}/parser/lexer.o \
	${OBJECTDIR}/parser/parser.o \
	${OBJECTDIR}/parser/scope.o \
	${OBJECTDIR}/parser/scope_inferrer.o \
	${OBJECTDIR}/parser/type.o \
	${OBJECTDIR}/parser/type_checker.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shimmr.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shimmr.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shimmr ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/logic/logic.o: logic/logic.cpp 
	${MKDIR} -p ${OBJECTDIR}/logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/logic/logic.o logic/logic.cpp

${OBJECTDIR}/logic/logic_processor.o: logic/logic_processor.cpp 
	${MKDIR} -p ${OBJECTDIR}/logic
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/logic/logic_processor.o logic/logic_processor.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/parser/Absyn.o: parser/Absyn.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Absyn.o parser/Absyn.cpp

${OBJECTDIR}/parser/Printer.o: parser/Printer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Printer.o parser/Printer.cpp

${OBJECTDIR}/parser/Skeleton.o: parser/Skeleton.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Skeleton.o parser/Skeleton.cpp

${OBJECTDIR}/parser/lexer.o: parser/lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/lexer.o parser/lexer.cpp

${OBJECTDIR}/parser/parser.o: parser/parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/parser.o parser/parser.cpp

${OBJECTDIR}/parser/scope.o: parser/scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/scope.o parser/scope.cpp

${OBJECTDIR}/parser/scope_inferrer.o: parser/scope_inferrer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/scope_inferrer.o parser/scope_inferrer.cpp

${OBJECTDIR}/parser/type.o: parser/type.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/type.o parser/type.cpp

${OBJECTDIR}/parser/type_checker.o: parser/type_checker.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/type_checker.o parser/type_checker.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ShimmrTestRunner.o ${TESTDIR}/tests/scoper.o ${TESTDIR}/tests/test_checker.o ${TESTDIR}/tests/tests.o ${TESTDIR}/tests/type_axioms.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/ShimmrTestRunner.o: tests/ShimmrTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ShimmrTestRunner.o tests/ShimmrTestRunner.cpp


${TESTDIR}/tests/scoper.o: tests/scoper.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/scoper.o tests/scoper.cpp


${TESTDIR}/tests/test_checker.o: tests/test_checker.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/test_checker.o tests/test_checker.cpp


${TESTDIR}/tests/tests.o: tests/tests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/tests.o tests/tests.cpp


${TESTDIR}/tests/type_axioms.o: tests/type_axioms.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/type_axioms.o tests/type_axioms.cpp


${OBJECTDIR}/logic/logic_nomain.o: ${OBJECTDIR}/logic/logic.o logic/logic.cpp 
	${MKDIR} -p ${OBJECTDIR}/logic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/logic/logic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/logic/logic_nomain.o logic/logic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/logic/logic.o ${OBJECTDIR}/logic/logic_nomain.o;\
	fi

${OBJECTDIR}/logic/logic_processor_nomain.o: ${OBJECTDIR}/logic/logic_processor.o logic/logic_processor.cpp 
	${MKDIR} -p ${OBJECTDIR}/logic
	@NMOUTPUT=`${NM} ${OBJECTDIR}/logic/logic_processor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/logic/logic_processor_nomain.o logic/logic_processor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/logic/logic_processor.o ${OBJECTDIR}/logic/logic_processor_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/parser/Absyn_nomain.o: ${OBJECTDIR}/parser/Absyn.o parser/Absyn.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/Absyn.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Absyn_nomain.o parser/Absyn.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/Absyn.o ${OBJECTDIR}/parser/Absyn_nomain.o;\
	fi

${OBJECTDIR}/parser/Printer_nomain.o: ${OBJECTDIR}/parser/Printer.o parser/Printer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/Printer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Printer_nomain.o parser/Printer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/Printer.o ${OBJECTDIR}/parser/Printer_nomain.o;\
	fi

${OBJECTDIR}/parser/Skeleton_nomain.o: ${OBJECTDIR}/parser/Skeleton.o parser/Skeleton.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/Skeleton.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/Skeleton_nomain.o parser/Skeleton.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/Skeleton.o ${OBJECTDIR}/parser/Skeleton_nomain.o;\
	fi

${OBJECTDIR}/parser/lexer_nomain.o: ${OBJECTDIR}/parser/lexer.o parser/lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/lexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/lexer_nomain.o parser/lexer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/lexer.o ${OBJECTDIR}/parser/lexer_nomain.o;\
	fi

${OBJECTDIR}/parser/parser_nomain.o: ${OBJECTDIR}/parser/parser.o parser/parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/parser_nomain.o parser/parser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/parser.o ${OBJECTDIR}/parser/parser_nomain.o;\
	fi

${OBJECTDIR}/parser/scope_nomain.o: ${OBJECTDIR}/parser/scope.o parser/scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/scope.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/scope_nomain.o parser/scope.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/scope.o ${OBJECTDIR}/parser/scope_nomain.o;\
	fi

${OBJECTDIR}/parser/scope_inferrer_nomain.o: ${OBJECTDIR}/parser/scope_inferrer.o parser/scope_inferrer.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/scope_inferrer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/scope_inferrer_nomain.o parser/scope_inferrer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/scope_inferrer.o ${OBJECTDIR}/parser/scope_inferrer_nomain.o;\
	fi

${OBJECTDIR}/parser/type_nomain.o: ${OBJECTDIR}/parser/type.o parser/type.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/type.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/type_nomain.o parser/type.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/type.o ${OBJECTDIR}/parser/type_nomain.o;\
	fi

${OBJECTDIR}/parser/type_checker_nomain.o: ${OBJECTDIR}/parser/type_checker.o parser/type_checker.cpp 
	${MKDIR} -p ${OBJECTDIR}/parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parser/type_checker.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/parser/type_checker_nomain.o parser/type_checker.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parser/type_checker.o ${OBJECTDIR}/parser/type_checker_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/shimmr.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
