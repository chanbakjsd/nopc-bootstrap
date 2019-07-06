#ifndef NOPC_BOOTSTRAP_AST_HPP
#define NOPC_BOOTSTRAP_AST_HPP

#include <string>

class OperationAST {
public:
    ~OperationAST() = default;
};
class StatementAST : public OperationAST {};
class LiteralAST : public StatementAST {};

/*******/


/*
 * Functions for AST
 */
// TODO: Change type to look more like in .g4 file

class FunctionParameterAST {
public:
private:
    std::vector<std::string> Identifiers;
    std::string type;
};

class FunctionHeaderAST {
public:
    FunctionHeaderAST(std::string identifier, std::string returnType)
    : Identifier(std::move(identifier)), ReturnType(std::move(returnType)) {}
private:
    std::string Identifier;
    std::string ReturnType;
};

class FunctionAST {
public:
private:
    FunctionHeaderAST FunctionHeader;
    std::vector<OperationAST> Operations;
};

/*
 * Operations for AST
 */

class LetVariableDefinitionAST {
public:
    LetVariableDefinitionAST(bool Pub, bool Mut, bool Static, std::string Identifier)
    : Pub(Pub), Mut(Mut), Static(Static), Identifier(std::move(Identifier)) {}
private:
    bool Pub;
    bool Mut;
    bool Static;
    std::string Identifier;
};

class LetAST : public OperationAST {
public:
    LetAST(std::vector<LetVariableDefinitionAST> Vars, StatementAST Value)
    : Vars(std::move(Vars)), Value(Value) {}
private:
    std::vector<LetVariableDefinitionAST> Vars;
    StatementAST Value;
};

class ReturnStatementAST : public OperationAST {
public:
    explicit ReturnStatementAST(StatementAST Statement) : Statement(Statement) {}
private:
    StatementAST Statement;
};

/*
 * Statements for AST
 */

class FunctionCallAST : public StatementAST {
public:
    FunctionCallAST(std::string Called, std::vector<std::unique_ptr<StatementAST>> Args)
    : Called(std::move(Called)), Args(std::move(Args)) {}
private:
    std::string Called;
    std::vector<std::unique_ptr<StatementAST>> Args;
};

/*
 * Literals for AST
 */

class StringAST: public LiteralAST {
public:
    explicit StringAST(std::string Str) : Str(std::move(Str)) {}
private:
    std::string Str;
};

class NumberAST: public LiteralAST {
public:
    explicit NumberAST(std::string Nbr) : Nbr(std::move(Nbr)) {}
private:
    std::string Nbr;
};

class FloatAST: public LiteralAST {
public:
    explicit FloatAST(std::string Float) : Float(std::move(Float)) {}
private:
    std::string Float;
};

class BooleanAST: public LiteralAST {
public:
    explicit BooleanAST(bool Bool) : Bool(Bool) {}
private:
    bool Bool;
};

#endif //NOPC_BOOTSTRAP_AST_HPP
