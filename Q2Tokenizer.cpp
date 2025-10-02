// Q2Tokenizer.cpp
// Abigail Tamburello
// Ch. 4 Assignment

#include <iostream>
#include <string>
#include <fstream>
#include "Q2Parser.cpp"
using namespace std;

ifstream infile;
char nextChar = '';

char getChar() {
char c = infile.get();
if (c == '\n')
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
    if (lexeme.length() > MAX_SIZE - 1) {
        cout << "Error: lexeme too long ... \n",
        errors++;
    }
}

Tokens lookupKeyword(string lexeme) {
    if (lexeme == "a") return A;
    if (lexeme == "b") return B;
    if (lexeme == "c") return C;
    return UNKNOWN;
}

void prt(Tokens nt) {
    switch (nt) {
        case A:
        cout << "<A>";
        break;
        case B:
        cout << "<B>";
        break;
        case C:
        cout << "<C>";
        break;
        case ENDFILE:
        cout <<"ENDFILE>";
        break;
        case UNKNOWN:
        cout <<"UNKNOWN>";
        break;
    }
}

void lex() {
    lexeme = "";
    while (isspace(nextChar)) {
        nextChar = getChar();
    }
    if (nextChar == EOF) {
        nextToken = ENDFILE;
    }
    else {
        addChar(nextChar);
        nextToken = lookupKeyword(lexeme);
        nextChar = getChar();
    }

    cout << "Next token is:";
    prt(nextToken);
    cout <<"Next lexeme is:" << lexeme << endl;
}

int main() {
    string filename;
    filename = "prg3.in";
    infile.open(filename);

    if(infile) {
        cout <<"Error: cant open" << filename << "\n";
        errors++;
        return 0;
    }

    nextChar = getChar();
    S();
    do {
        lex();
    }
    while (nextToken !=ENDFILE);

    cout <<"Total num of errors: " << errors << endl;
    return 0;
}