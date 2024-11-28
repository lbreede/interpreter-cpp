#include "lexer.h"

Lexer::Lexer(const std::string &input)
    : input(input), position(0), readPosition(0), ch(0) {
    readChar();
}

Token Lexer::nextToken() {
    Token token;

    skipWhitespace();

    switch (ch) {
        case '=':
            if (peekChar() == '=') {
                readChar();
                token.type = EQ;
                token.literal = "==";
            } else {
                token = newToken(ASSIGN, ch);
            }
            break;
        case '+':
            token = newToken(PLUS, ch);
            break;
        case '-':
            token = newToken(MINUS, ch);
            break;
        case '!':
            if (peekChar() == '=') {
                readChar();
                token.type = NOT_EQ;
                token.literal = "!=";
            } else {
                token = newToken(BANG, ch);
            }
            break;
        case '*':
            token = newToken(ASTERISK, ch);
            break;
        case '/':
            token = newToken(SLASH, ch);
            break;
        case '<':
            token = newToken(LT, ch);
            break;
        case '>':
            token = newToken(GT, ch);
            break;
        case ';':
            token = newToken(SEMICOLON, ch);
            break;
        case ',':
            token = newToken(COMMA, ch);
            break;
        case '(':
            token = newToken(LPAREN, ch);
            break;
        case ')':
            token = newToken(RPAREN, ch);
            break;
        case '{':
            token = newToken(LBRACE, ch);
            break;
        case '}':
            token = newToken(RBRACE, ch);
            break;
        case 0:
            token.literal = "";
            token.type = END_OF_FILE;
            break;
        default:
            if (isalpha(ch) || ch == '_') {
                token.literal = readIdentifier();
                token.type = lookupIdent(token.literal);
                return token;
            } else if (isdigit(ch)) {
                token.literal = readNumber();
                token.type = INT;
                return token;
            } else {
                token = newToken(ILLEGAL, ch);
            }
    }
    readChar();
    return token;
}

void Lexer::readChar() {
    if (readPosition >= input.length()) {
        ch = 0;
    } else {
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition++;
}

char Lexer::peekChar() {
    if (readPosition >= input.length()) {
        return 0;
    } else {
        return input[readPosition];
    }
}

void Lexer::skipWhitespace() {
    while (isspace(ch)) {
        readChar();
    }
}

std::string Lexer::readIdentifier() {
    size_t position = this->position;
    while (isalpha(ch) || ch == '_') {
        readChar();
    }
    return input.substr(position, this->position - position);
}
std::string Lexer::readNumber() {
    size_t position = this->position;
    while (isdigit(ch)) {
        readChar();
    }
    return input.substr(position, this->position - position);
}

Token Lexer::newToken(TokenType type, char ch) {
    Token token;
    token.type = type;
    token.literal = std::string(1, ch);
    return token;
}
