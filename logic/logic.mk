##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=logic
ConfigurationName      :=Debug
WorkspacePath          := "/home/jmccrae/projects/shimmr"
ProjectPath            := "/home/jmccrae/projects/shimmr/logic"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=John McCrae
Date                   :=06/04/2013
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
ObjectsFileList        :="logic.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)../parser/Debug/libparser 
ArLibs                 :=  "../parser/Debug/libparser.a" 
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
Objects0=$(IntermediateDirectory)/logic$(ObjectSuffix) $(IntermediateDirectory)/logic_processor$(ObjectSuffix) 

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
	@echo rebuilt > "/home/jmccrae/projects/shimmr/.build-debug/logic"

./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/logic$(ObjectSuffix): logic.cpp $(IntermediateDirectory)/logic$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/logic/logic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logic$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logic$(DependSuffix): logic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logic$(ObjectSuffix) -MF$(IntermediateDirectory)/logic$(DependSuffix) -MM "logic.cpp"

$(IntermediateDirectory)/logic$(PreprocessSuffix): logic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logic$(PreprocessSuffix) "logic.cpp"

$(IntermediateDirectory)/logic_processor$(ObjectSuffix): logic_processor.cpp $(IntermediateDirectory)/logic_processor$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jmccrae/projects/shimmr/logic/logic_processor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logic_processor$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logic_processor$(DependSuffix): logic_processor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logic_processor$(ObjectSuffix) -MF$(IntermediateDirectory)/logic_processor$(DependSuffix) -MM "logic_processor.cpp"

$(IntermediateDirectory)/logic_processor$(PreprocessSuffix): logic_processor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logic_processor$(PreprocessSuffix) "logic_processor.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/logic$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/logic$(DependSuffix)
	$(RM) $(IntermediateDirectory)/logic$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/logic_processor$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/logic_processor$(DependSuffix)
	$(RM) $(IntermediateDirectory)/logic_processor$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/logic"


