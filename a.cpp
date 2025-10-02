#include <iostream>
#include <string>
#include <fstream>
#include "bnf.cpp"
using namespace std;

std::ifstream infile;
char nextChar = '';

char getChar() {
    char c = infile.get();
    if (c =='\n')
    line++;
    return c;
}

char getNonSpaceChar() {
    char c ='';
    while (isspace(c))
    c = getChar();
    return c;
}

void addChar(char c) {
    lexeme = lexeme + c;
    if (lexeme.length() > MAX_SIZE -1) {
        cout << "Error: lexeme too long ... n";
        errors++;
    }
}

Tokens lookupKeyword(string lexeme) {
    Tokens t;
    if (lexeme == "int")
    t = INT_KEYWORD;
    else
    t = VAR;
    return t;
}

Tokens lookupOp(string lexeme) {
    if (lexeme =="(")
    return LEFT_PAREN;
    if (lexeme ==")")
    return RIGHT_PAREN;
    if (lexeme =="+")
    return ADD_OP;
    if (lexeme =="-")
    return SUB_OP;
    if (lexeme =="*")
    return MUL_OP;
    if (lexeme =="/")
    return DIV_OP;
    if (lexeme =="=")
    return ASSIGN_OP;
    if (lexeme ==",")
    return COMMA;
    else
    return UNKNOWN;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == ',' || c == '(' || c == ')'|| c == '=')
    return true;
    else
    return false;
}

void prt(Tokens nt) {
    
}