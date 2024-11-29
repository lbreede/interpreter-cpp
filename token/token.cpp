#include "token.h"

std::unordered_map<std::string, TokenType> keywords = {
    {"fn", TokenType::Function},
    {"let", TokenType::Let},
    {"true", TokenType::True},
    {"false", TokenType::False},
    {"if", TokenType::If},
    {"else", TokenType::Else},
    {"return", TokenType::Return},
};

TokenType lookupIdent(const std::string &ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return TokenType::Ident;
}

std::ostream &operator<<(std::ostream &os, const TokenType &type) {
    switch (type) {
        case TokenType::Illegal:
            os << "Illegal";
            break;
        case TokenType::Eof:
            os << "Eof";
            break;
        case TokenType::Ident:
            os << "Ident";
            break;
        case TokenType::Int:
            os << "Int";
            break;
        case TokenType::Assign:
            os << "Assign";
            break;
        case TokenType::Plus:
            os << "Plus";
            break;
        case TokenType::Minus:
            os << "Minus";
            break;
        case TokenType::Bang:
            os << "Bang";
            break;
        case TokenType::Asterisk:
            os << "Asterisk";
            break;
        case TokenType::Slash:
            os << "Slash";
            break;
        case TokenType::Lt:
            os << "Lt";
            break;
        case TokenType::Gt:
            os << "Gt";
            break;
        case TokenType::Eq:
            os << "Eq";
            break;
        case TokenType::NotEq:
            os << "NotEq";
            break;
        case TokenType::Comma:
            os << "Comma";
            break;
        case TokenType::Semicolon:
            os << "Semicolon";
            break;
        case TokenType::LParen:
            os << "LParen";
            break;
        case TokenType::RParen:
            os << "RParen";
            break;
        case TokenType::LBrace:
            os << "LBrace";
            break;
        case TokenType::RBrace:
            os << "RBrace";
            break;
        case TokenType::Function:
            os << "Function";
            break;
        case TokenType::Let:
            os << "Let";
            break;
        case TokenType::True:
            os << "True";
            break;
        case TokenType::False:
            os << "False";
            break;
        case TokenType::If:
            os << "If";
            break;
        case TokenType::Else:
            os << "Else";
            break;
        case TokenType::Return:
            os << "Return";
            break;
        default:
            os << "Unhandled";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << token.type << "(\"" << token.literal << "\")";
    return os;
}