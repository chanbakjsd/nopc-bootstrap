#include <iostream>
#include <llvm/Support/CommandLine.h>

using namespace llvm;

int main(int argc, char **argv) {
	cl::ParseCommandLineOptions(argc, argv);

	// TODO: temporary, add argument parsing stuff using llvm's CommandLine.h here
	//       docs: https://llvm.org/docs/CommandLine.html
	std::cout << "hello, world!" << std::endl;
	return 0;
}
