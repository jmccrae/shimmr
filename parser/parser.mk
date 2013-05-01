##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=parser
ConfigurationName      :=Debug
WorkspacePath          := "/home/jmccrae/projects/shimmr"
ProjectPath            := "/home/jmccrae/projects/shimmr/parser"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=John McCrae
Date                   :=04/30/2013
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="parser.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

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
Objects0=$(IntermediateDirectory)/Test$(ObjectSuffix) $(IntermediateDirectory)/Printer$(ObjectSuffix) $(IntermediateDirectory)/scope$(ObjectSuffix) $(IntermediateDirectory)/type$(ObjectSuffix) $(IntermediateDirectory)/Skeleton$(ObjectSuffix) $(IntermediateDirectory)/Test$(ObjectSuffix) $(IntermediateDirectory)/lexer$(ObjectSuffix) $(IntermediateDirectory)/Absyn$(ObjectSuffix) $(IntermediateDirectory)/parser$(ObjectSuffix) $(IntermediateDirectory)/scope_inferrer$(ObjectSuffix) \
	$(IntermediateDirectory)/type_checker$(ObjectSuffix) 

Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/jmccrae/projects/shimmr/.build-debug"
	@echo rebuilt > "/home/jmccrae/projects/shimmr/.build-debug/parser"

./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Test$(ObjectSuffix): Test.cpp $(IntermediateDirectory)/Test$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/Test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test$(DependSuffix): Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test$(ObjectSuffix) -MF$(IntermediateDirectory)/Test$(DependSuffix) -MM "Test.cpp"

$(IntermediateDirectory)/Test$(PreprocessSuffix): Test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test$(PreprocessSuffix) "Test.cpp"

$(IntermediateDirectory)/Printer$(ObjectSuffix): Printer.cpp $(IntermediateDirectory)/Printer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/Printer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Printer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Printer$(DependSuffix): Printer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Printer$(ObjectSuffix) -MF$(IntermediateDirectory)/Printer$(DependSuffix) -MM "Printer.cpp"

$(IntermediateDirectory)/Printer$(PreprocessSuffix): Printer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Printer$(PreprocessSuffix) "Printer.cpp"

$(IntermediateDirectory)/scope$(ObjectSuffix): scope.cpp $(IntermediateDirectory)/scope$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/scope.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scope$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scope$(DependSuffix): scope.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scope$(ObjectSuffix) -MF$(IntermediateDirectory)/scope$(DependSuffix) -MM "scope.cpp"

$(IntermediateDirectory)/scope$(PreprocessSuffix): scope.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scope$(PreprocessSuffix) "scope.cpp"

$(IntermediateDirectory)/type$(ObjectSuffix): type.cpp $(IntermediateDirectory)/type$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/type.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/type$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/type$(DependSuffix): type.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/type$(ObjectSuffix) -MF$(IntermediateDirectory)/type$(DependSuffix) -MM "type.cpp"

$(IntermediateDirectory)/type$(PreprocessSuffix): type.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/type$(PreprocessSuffix) "type.cpp"

$(IntermediateDirectory)/Skeleton$(ObjectSuffix): Skeleton.cpp $(IntermediateDirectory)/Skeleton$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/Skeleton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Skeleton$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Skeleton$(DependSuffix): Skeleton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Skeleton$(ObjectSuffix) -MF$(IntermediateDirectory)/Skeleton$(DependSuffix) -MM "Skeleton.cpp"

$(IntermediateDirectory)/Skeleton$(PreprocessSuffix): Skeleton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Skeleton$(PreprocessSuffix) "Skeleton.cpp"

$(IntermediateDirectory)/Test$(ObjectSuffix): Test.C $(IntermediateDirectory)/Test$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/Test.C" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test$(DependSuffix): Test.C
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test$(ObjectSuffix) -MF$(IntermediateDirectory)/Test$(DependSuffix) -MM "Test.C"

$(IntermediateDirectory)/Test$(PreprocessSuffix): Test.C
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test$(PreprocessSuffix) "Test.C"

$(IntermediateDirectory)/lexer$(ObjectSuffix): lexer.cpp $(IntermediateDirectory)/lexer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/lexer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lexer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lexer$(DependSuffix): lexer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lexer$(ObjectSuffix) -MF$(IntermediateDirectory)/lexer$(DependSuffix) -MM "lexer.cpp"

$(IntermediateDirectory)/lexer$(PreprocessSuffix): lexer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lexer$(PreprocessSuffix) "lexer.cpp"

$(IntermediateDirectory)/Absyn$(ObjectSuffix): Absyn.cpp $(IntermediateDirectory)/Absyn$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/Absyn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Absyn$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Absyn$(DependSuffix): Absyn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Absyn$(ObjectSuffix) -MF$(IntermediateDirectory)/Absyn$(DependSuffix) -MM "Absyn.cpp"

$(IntermediateDirectory)/Absyn$(PreprocessSuffix): Absyn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Absyn$(PreprocessSuffix) "Absyn.cpp"

$(IntermediateDirectory)/parser$(ObjectSuffix): parser.cpp $(IntermediateDirectory)/parser$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/parser$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/parser$(DependSuffix): parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/parser$(ObjectSuffix) -MF$(IntermediateDirectory)/parser$(DependSuffix) -MM "parser.cpp"

$(IntermediateDirectory)/parser$(PreprocessSuffix): parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/parser$(PreprocessSuffix) "parser.cpp"

$(IntermediateDirectory)/scope_inferrer$(ObjectSuffix): scope_inferrer.cpp $(IntermediateDirectory)/scope_inferrer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/scope_inferrer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/scope_inferrer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/scope_inferrer$(DependSuffix): scope_inferrer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/scope_inferrer$(ObjectSuffix) -MF$(IntermediateDirectory)/scope_inferrer$(DependSuffix) -MM "scope_inferrer.cpp"

$(IntermediateDirectory)/scope_inferrer$(PreprocessSuffix): scope_inferrer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/scope_inferrer$(PreprocessSuffix) "scope_inferrer.cpp"

$(IntermediateDirectory)/type_checker$(ObjectSuffix): type_checker.cpp $(IntermediateDirectory)/type_checker$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/parser/type_checker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/type_checker$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/type_checker$(DependSuffix): type_checker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/type_checker$(ObjectSuffix) -MF$(IntermediateDirectory)/type_checker$(DependSuffix) -MM "type_checker.cpp"

$(IntermediateDirectory)/type_checker$(PreprocessSuffix): type_checker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/type_checker$(PreprocessSuffix) "type_checker.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/Test$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Test$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Test$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Printer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Printer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Printer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scope$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scope$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scope$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/type$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/type$(DependSuffix)
	$(RM) $(IntermediateDirectory)/type$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Skeleton$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Skeleton$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Skeleton$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Test$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Test$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Test$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/lexer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/lexer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/lexer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Absyn$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Absyn$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Absyn$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/parser$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/parser$(DependSuffix)
	$(RM) $(IntermediateDirectory)/parser$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/scope_inferrer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/scope_inferrer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/scope_inferrer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/type_checker$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/type_checker$(DependSuffix)
	$(RM) $(IntermediateDirectory)/type_checker$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/parser"


