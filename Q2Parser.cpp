// Q2Parser.cpp
// Abigail Tamburello
// Ch 4 Assignment Q2

#include <iostream>
#include <string>
#include "globals.cpp"
#include "symbolTable.cpp"
using namespace std;

void S();
void A_term();
void B_term();
void C_term();

void S() {
    if (nextToken == A) {
        A_term();
        if (nextToken == C) {
            C_term();
            B_term();
        }
    }
    else {
        errMsg("s -> expected A, found " + lexeme);
    }
}

void A_term() {
    if (nextToken == A) {
        lex();
        if (nextToken == A) {
            A_term();
        }
    }
    else {
        errMsg ("A -> expected 'a', found" + lexeme);
    }
}

void B_term() {
    if (nextToken == B) {
        lex();
        if (nextToken == B) {
            B_term();
        }
    }
    else {
        errMsg("B -> expected 'b', found" + lexeme);
    }
}

void C_term() {
    if (nextToken == C) {
        lex();
    }
    else {
        errMsg("C -> expected 'c', found" + lexeme);
    }
}