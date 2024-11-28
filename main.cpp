#include <iostream>

#include "lexer.h"

int main() {
    Lexer lexer("let _foo = 5;");
    Token token = lexer.nextToken();
    while (token.type != END_OF_FILE) {
        std::cout << token << std::endl;
        token = lexer.nextToken();
    }
    return 0;
}