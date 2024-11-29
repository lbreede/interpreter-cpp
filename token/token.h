#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>
#include <unordered_map>

enum class TokenType {
    Illegal,
    Eof,

    Ident,
    Int,

    Assign,
    Plus,
    Minus,
    Bang,
    Asterisk,
    Slash,

    Lt,
    Gt,
    Eq,
    NotEq,

    Comma,
    Semicolon,

    LParen,
    RParen,
    LBrace,
    RBrace,

    Function,
    Let,
    True,
    False,
    If,
    Else,
    Return,
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