#ifndef NOPC_BOOTSTRAP_PARSINGTOOLS_HPP
#define NOPC_BOOTSTRAP_PARSINGTOOLS_HPP

class ParserErrorListener: public antlr4::BaseErrorListener {
    virtual void syntaxError(
        antlr4::Recognizer *recognizer,
        antlr4::Token *offendingSymbol,
        size_t line,
        size_t charPositionInLine,
        const std::string &msg,
        std::exception_ptr e) override {
        std::ostringstream s;
        s << "Line(" << line << ":" << charPositionInLine << ") Error(" << msg << ")";
        throw std::invalid_argument(s.str());
    }
};

#endif //NOPC_BOOTSTRAP_PARSINGTOOLS_HPP
