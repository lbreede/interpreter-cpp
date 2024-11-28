#include "token.h"

std::unordered_map<std::string, TokenType> keywords = {
    {"fn", FUNCTION},
    {"let", LET},
    {"true", TRUE},
    {"false", FALSE},
    {"if", IF},
    {"else", ELSE},
    {"return", RETURN},
};

TokenType lookupIdent(const std::string &ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return IDENT;
}

std::ostream &operator<<(std::ostream &os, const TokenType &type) {
    switch (type) {
        case ILLEGAL:
            os << "ILLEGAL";
            break;
        case END_OF_FILE:
            os << "EOF";
            break;
        case IDENT:
            os << "IDENT";
            break;
        case INT:
            os << "INT";
            break;
        case ASSIGN:
            os << "ASSIGN";
            break;
        case PLUS:
            os << "PLUS";
            break;
        case MINUS:
            os << "MINUS";
            break;
        case BANG:
            os << "BANG";
            break;
        case ASTERISK:
            os << "ASTERISK";
            break;
        case SLASH:
            os << "SLASH";
            break;
        case LT:
            os << "LT";
            break;
        case GT:
            os << "GT";
            break;
        case EQ:
            os << "EQ";
            break;
        case NOT_EQ:
            os << "NOT_EQ";
            break;
        case COMMA:
            os << "COMMA";
            break;
        case SEMICOLON:
            os << "SEMICOLON";
            break;
        case LPAREN:
            os << "LPAREN";
            break;
        case RPAREN:
            os << "RPAREN";
            break;
        case LBRACE:
            os << "LBRACE";
            break;
        case RBRACE:
            os << "RBRACE";
            break;
        case FUNCTION:
            os << "FUNCTION";
            break;
        case LET:
            os << "LET";
            break;
        case TRUE:
            os << "TRUE";
            break;
        case FALSE:
            os << "FALSE";
            break;
        case IF:
            os << "IF";
            break;
        case ELSE:
            os << "ELSE";
            break;
        case RETURN:
            os << "RETURN";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << token.type << "(\"" << token.literal << "\")";
    return os;
}