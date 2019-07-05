#include <iostream>
#include "CommandParse.hpp"
#include "nopLexer.h"
#include "nopParser.h"
#include "ParsingTools.hpp"

int parse_files(CommandParse &commandParse)
{
    ParserErrorListener errorListener;

    for (auto &InputFile : commandParse.getInputFiles()) {
        LOG_VERBOSE("Parsing " << InputFile)
        try {
            std::ifstream stream(InputFile);
            antlr4::ANTLRInputStream input(stream);

            nopLexer lexer(&input);
            lexer.removeErrorListeners();
            lexer.addErrorListener(&errorListener);

            antlr4::CommonTokenStream tokens(&lexer);
            tokens.fill();

            nopParser parser(&tokens);
            parser.removeErrorListeners();
            parser.addErrorListener(&errorListener);
            antlr4::tree::ParseTree *tree = parser.nop_file();

            LOG_DEBUG(tree->toStringTree(&parser));
        } catch (std::invalid_argument &e) {
            LOG_ERROR(e.what());
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    CommandParse commandParse;

    commandParse.parse(argc, argv);
    IFDEBUG(
        LOG_DEBUG("Output : " << commandParse.getOutputFile());
        LOG_DEBUG("Inputs :");
        for (auto &InputFile : commandParse.getInputFiles()) {
            LOG_DEBUG("\t" << InputFile);
        }
    )
    return parse_files(commandParse);
}
