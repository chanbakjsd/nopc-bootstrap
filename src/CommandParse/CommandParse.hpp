#ifndef NOPC_COMMANDPARSE_HPP
#define NOPC_COMMANDPARSE_HPP

#include <llvm/Support/CommandLine.h>
#include "DebugFlag.hpp"

// TODO: temporary, add more argument parsing stuff using llvm's CommandLine.h here
//       docs: https://llvm.org/docs/CommandLine.html

class CommandParse {
    public:
	CommandParse();
	~CommandParse();
	void parse(int argc, char **argv);

	llvm::cl::list<std::string> &getInputFiles();
	std::string getOutputFile() const;

    private:
	llvm::cl::list<std::string> InputFiles;
	llvm::cl::opt<std::string> OutputFilename;
	llvm::cl::opt<bool, true> Debug;
	llvm::cl::alias DebugLong;
	llvm::cl::opt<bool, true> Verbose;
};

#endif //NOPC_COMMANDPARSE_HPP
