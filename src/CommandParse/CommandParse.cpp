#include <iostream>
#include "CommandParse.hpp"

bool DebugFlag;
bool VerboseFlag;

CommandParse::CommandParse() :
    InputFiles(llvm::cl::Positional, llvm::cl::desc("<input files>"), llvm::cl::OneOrMore),
    OutputFilename("o", llvm::cl::desc("Specify output filename"), llvm::cl::value_desc("filename"), llvm::cl::Required),
    Debug("d", llvm::cl::desc("Activate debug mode"), llvm::cl::location(DebugFlag)),
    DebugLong("debug", llvm::cl::desc("Activate debug mode"), llvm::cl::aliasopt(Debug)),
    Verbose("v", llvm::cl::desc("Activate verbose mode"), llvm::cl::location(VerboseFlag))
{
}

CommandParse::~CommandParse() = default;

void CommandParse::parse(int argc, char **argv)
{
    llvm::cl::ParseCommandLineOptions(argc, argv);
}


llvm::cl::list<std::string> &CommandParse::getInputFiles()
{
    return InputFiles;
}

std::string CommandParse::getOutputFile() const
{
    return OutputFilename;
}
