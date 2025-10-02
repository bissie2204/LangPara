#include <iostream>
#include <string>
using namespace std;

enum Tokens {A, B, C, UNKNOWN, ENDFILE};
const int MAX_SIZE = 100;

string lexeme = "";

Tokens nextToken;
int errors = 0;
int line = 1;

void lex();

void errMsg(string msg) {
    cout << "Error on line" << line << ":" << msg << endl;
    errors++;
    lex();
}