#include <token.h>

#include <string>
#ifndef LEXER_H
#define LEXER_H

class Lexer {
   public:
    Lexer(const std::string &input);
    Token nextToken();

   private:
    void readChar();
    char peekChar();
    void skipWhitespace();
    std::string readIdentifier();
    std::string readNumber();
    Token newToken(TokenType type, char ch);

    std::string input;
    std::size_t position;
    std::size_t readPosition;
    char ch;
};

#endif