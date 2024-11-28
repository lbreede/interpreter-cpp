#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <unordered_map>

enum TokenType {
    ILLEGAL,
    END_OF_FILE,

    IDENT,
    INT,

    ASSIGN,
    PLUS,
    MINUS,
    BANG,
    ASTERISK,
    SLASH,

    LT,
    GT,
    EQ,
    NOT_EQ,

    COMMA,
    SEMICOLON,

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
};

std::ostream &operator<<(std::ostream &os, const TokenType &type);

extern std::unordered_map<std::string, TokenType> keywords;

TokenType lookupIdent(const std::string &ident);

struct Token {
    TokenType type;
    std::string literal;
};

std::ostream &operator<<(std::ostream &os, const Token &token);

#endif