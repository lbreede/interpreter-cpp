#include "lexer.h"

#include <token.h>

#include <string>

int main() {
    std::string input =
        "let five = 5;\n"
        "let ten = 10;\n\n"
        "let add = fn(x, y) {\n"
        "  x + y;\n"
        "};\n\n"
        "let result = add(five, ten);\n"
        "!-/*5;\n"
        "5 < 10 > 5;\n\n"
        "if (5 < 10) {\n"
        "  return true;\n"
        "} else {\n"
        "  return false;\n"
        "}\n\n"
        "10 == 10;\n"
        "10 != 9;\n";

    struct expectedToken {
        TokenType type;
        std::string literal;
    };

    struct expectedToken expectedTokens[] = {
        {TokenType::Let, "let"},
        {TokenType::Ident, "five"},
        {TokenType::Assign, "="},
        {TokenType::Int, "5"},
        {TokenType::Semicolon, ";"},
        {TokenType::Let, "let"},
        {TokenType::Ident, "ten"},
        {TokenType::Assign, "="},
        {TokenType::Int, "10"},
        {TokenType::Semicolon, ";"},
        {TokenType::Let, "let"},
        {TokenType::Ident, "add"},
        {TokenType::Assign, "="},
        {TokenType::Function, "fn"},
        {TokenType::LParen, "("},
        {TokenType::Ident, "x"},
        {TokenType::Comma, ","},
        {TokenType::Ident, "y"},
        {TokenType::RParen, ")"},
        {TokenType::LBrace, "{"},
        {TokenType::Ident, "x"},
        {TokenType::Plus, "+"},
        {TokenType::Ident, "y"},
        {TokenType::Semicolon, ";"},
        {TokenType::RBrace, "}"},
        {TokenType::Semicolon, ";"},
        {TokenType::Let, "let"},
        {TokenType::Ident, "result"},
        {TokenType::Assign, "="},
        {TokenType::Ident, "add"},
        {TokenType::LParen, "("},
        {TokenType::Ident, "five"},
        {TokenType::Comma, ","},
        {TokenType::Ident, "ten"},
        {TokenType::RParen, ")"},
        {TokenType::Semicolon, ";"},
        {TokenType::Bang, "!"},
        {TokenType::Minus, "-"},
        {TokenType::Slash, "/"},
        {TokenType::Asterisk, "*"},
        {TokenType::Int, "5"},
        {TokenType::Semicolon, ";"},
        {TokenType::Int, "5"},
        {TokenType::Lt, "<"},
        {TokenType::Int, "10"},
        {TokenType::Gt, ">"},
        {TokenType::Int, "5"},
        {TokenType::Semicolon, ";"},
        {TokenType::If, "if"},
        {TokenType::LParen, "("},
        {TokenType::Int, "5"},
        {TokenType::Lt, "<"},
        {TokenType::Int, "10"},
        {TokenType::RParen, ")"},
        {TokenType::LBrace, "{"},
        {TokenType::Return, "return"},
        {TokenType::True, "true"},
        {TokenType::Semicolon, ";"},
        {TokenType::RBrace, "}"},
        {TokenType::Else, "else"},
        {TokenType::LBrace, "{"},
        {TokenType::Return, "return"},
        {TokenType::False, "false"},
        {TokenType::Semicolon, ";"},
        {TokenType::RBrace, "}"},
        {TokenType::Int, "10"},
        {TokenType::Eq, "=="},
        {TokenType::Int, "10"},
        {TokenType::Semicolon, ";"},
        {TokenType::Int, "10"},
        {TokenType::NotEq, "!="},
        {TokenType::Int, "9"},
        {TokenType::Semicolon, ";"},
        {TokenType::Eof, ""},
    };

    Lexer lexer(input);

    for (expectedToken expectedToken : expectedTokens) {
        Token token = lexer.nextToken();
        if (token.type != expectedToken.type) {
            std::cerr << "Expected token type " << expectedToken.type << ", got " << token.type << std::endl;
            exit(1);
        }
        if (token.literal != expectedToken.literal) {
            std::cerr << "Expected token literal " << expectedToken.literal << ", got " << token.literal << std::endl;
            exit(1);
        }
    }
    return 0;
}