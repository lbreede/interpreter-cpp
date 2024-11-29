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
                token.type = TokenType::Eq;
                token.literal = "==";
            } else {
                token = newToken(TokenType::Assign, ch);
            }
            break;
        case '+':
            token = newToken(TokenType::Plus, ch);
            break;
        case '-':
            token = newToken(TokenType::Minus, ch);
            break;
        case '!':
            if (peekChar() == '=') {
                readChar();
                token.type = TokenType::NotEq;
                token.literal = "!=";
            } else {
                token = newToken(TokenType::Bang, ch);
            }
            break;
        case '*':
            token = newToken(TokenType::Asterisk, ch);
            break;
        case '/':
            token = newToken(TokenType::Slash, ch);
            break;
        case '<':
            token = newToken(TokenType::Lt, ch);
            break;
        case '>':
            token = newToken(TokenType::Gt, ch);
            break;
        case ';':
            token = newToken(TokenType::Semicolon, ch);
            break;
        case ',':
            token = newToken(TokenType::Comma, ch);
            break;
        case '(':
            token = newToken(TokenType::LParen, ch);
            break;
        case ')':
            token = newToken(TokenType::RParen, ch);
            break;
        case '{':
            token = newToken(TokenType::LBrace, ch);
            break;
        case '}':
            token = newToken(TokenType::RBrace, ch);
            break;
        case 0:
            token.literal = "";
            token.type = TokenType::Eof;
            break;
        default:
            if (isalpha(ch) || ch == '_') {
                token.literal = readIdentifier();
                token.type = lookupIdent(token.literal);
                return token;
            } else if (isdigit(ch)) {
                token.literal = readNumber();
                token.type = TokenType::Int;
                return token;
            } else {
                token = newToken(TokenType::Illegal, ch);
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
