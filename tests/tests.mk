##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=tests
ConfigurationName      :=Debug
WorkspacePath          := "/home/jmccrae/projects/shimmr"
ProjectPath            := "/home/jmccrae/projects/shimmr/tests"
IntermediateDirectory  :=Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=John McCrae
Date                   :=04/14/2013
CodeLitePath           :="/home/jmccrae/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="tests.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(UNIT_TEST_PP_SRC_DIR)/src $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UnitTest++ $(LibrarySwitch)parser 
ArLibs                 :=  "libUnitTest++.a" "libparser.a" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(UNIT_TEST_PP_SRC_DIR)/Debug $(LibraryPathSwitch)../parser/Debug/ 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -std=c++11 $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/scoper$(ObjectSuffix) $(IntermediateDirectory)/tests$(ObjectSuffix) $(IntermediateDirectory)/test_checker$(ObjectSuffix) $(IntermediateDirectory)/type_axioms$(ObjectSuffix) 

Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d Debug || $(MakeDirCommand) Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/scoper$(ObjectSuffix): scoper.cpp $(IntermediateDirectory)/scoper$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/tests/scoper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scoper$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scoper$(DependSuffix): scoper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scoper$(ObjectSuffix) -MF$(IntermediateDirectory)/scoper$(DependSuffix) -MM "scoper.cpp"

$(IntermediateDirectory)/scoper$(PreprocessSuffix): scoper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scoper$(PreprocessSuffix) "scoper.cpp"

$(IntermediateDirectory)/tests$(ObjectSuffix): tests.cpp $(IntermediateDirectory)/tests$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/tests/tests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tests$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tests$(DependSuffix): tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tests$(ObjectSuffix) -MF$(IntermediateDirectory)/tests$(DependSuffix) -MM "tests.cpp"

$(IntermediateDirectory)/tests$(PreprocessSuffix): tests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tests$(PreprocessSuffix) "tests.cpp"

$(IntermediateDirectory)/test_checker$(ObjectSuffix): test_checker.cpp $(IntermediateDirectory)/test_checker$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/tests/test_checker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_checker$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_checker$(DependSuffix): test_checker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_checker$(ObjectSuffix) -MF$(IntermediateDirectory)/test_checker$(DependSuffix) -MM "test_checker.cpp"

$(IntermediateDirectory)/test_checker$(PreprocessSuffix): test_checker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_checker$(PreprocessSuffix) "test_checker.cpp"

$(IntermediateDirectory)/type_axioms$(ObjectSuffix): type_axioms.cpp $(IntermediateDirectory)/type_axioms$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/tests/type_axioms.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/type_axioms$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/type_axioms$(DependSuffix): type_axioms.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/type_axioms$(ObjectSuffix) -MF$(IntermediateDirectory)/type_axioms$(DependSuffix) -MM "type_axioms.cpp"

$(IntermediateDirectory)/type_axioms$(PreprocessSuffix): type_axioms.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/type_axioms$(PreprocessSuffix) "type_axioms.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/scoper$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scoper$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scoper$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tests$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tests$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tests$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/test_checker$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/test_checker$(DependSuffix)
	$(RM) $(IntermediateDirectory)/test_checker$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/type_axioms$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/type_axioms$(DependSuffix)
	$(RM) $(IntermediateDirectory)/type_axioms$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/tests"


