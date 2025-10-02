#include <iostream>
#include <string>
#include "globals.cpp"
#include "symbolTable.cpp"
using namespace std;

void S();
void A();
void B();
void C();

void expr() {
    term();
    while (nextToken -- ADD_OP || nextToken == SUB_OP) {
        lex();
        term();
    }
}

void term() {
    while (nextToken == MUL_OP || nextToken == DIV_OP) {
        lex();
        factor();
    }
}

void factor() {
    if (nextToken == VAR || nextToken == INT_LIT)
    lex();
    else {
        if (nextToken == LEFT_PAREN) {
            lex();
            expr();
            if (nextToken == RIGHT_PAREN)
            lex();
            elseerrMsg("Riht parenthesis expected, found" + lexeme); 
        }
        else 
        errMsg("expected var, integer literaly, or left parenthesis, found" + lexeme);
    }
}

void assign() {
    if (nextToken == VAR) {
        if (!search_symbol(lexeme))
        errMsg("undefined variable" + lexeme);
        lex();
        if (nextToken == ASSIGN_OP) {
            lex();
            expr();
        }
        else
        errMsg("equal sign expected, found " + lexeme);
    }
    else
    errMsg("Variable expected, found " + lexeme);
}

void initializeVar() {
    string varName = lexeme;
    lex();
    if (nextToken == ASSIGN_OP) {
        lex();
        if (nextToken == INT_LIT) {
            int value = atoi(lexeme.c_str());
            add_symbol(varName, value);
            lex();
        }
        else
        errMsg("Integer initilization expected, found" + lexeme);
    }
    else
    add_symbol(varName, 0);
}

void intVar() {
    if (nextToken == VAR) {
        while (nextToken == VAR) {
            initializeVar();
            if (nextToken == COMMA)
            lex();
            else
            break;
        }
    }
    else 
    errMsg("variable expected, found" + lexeme);
}

void declaration() {
    lex();
    intVar();
}

void stmt() {
    if (nextToken == INT_KEYWORD)
    declaration();
    else
    assign();
}