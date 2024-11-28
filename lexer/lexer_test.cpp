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
        {LET, "let"},
        {IDENT, "five"},
        {ASSIGN, "="},
        {INT, "5"},
        {SEMICOLON, ";"},
        {LET, "let"},
        {IDENT, "ten"},
        {ASSIGN, "="},
        {INT, "10"},
        {SEMICOLON, ";"},
        {LET, "let"},
        {IDENT, "add"},
        {ASSIGN, "="},
        {FUNCTION, "fn"},
        {LPAREN, "("},
        {IDENT, "x"},
        {COMMA, ","},
        {IDENT, "y"},
        {RPAREN, ")"},
        {LBRACE, "{"},
        {IDENT, "x"},
        {PLUS, "+"},
        {IDENT, "y"},
        {SEMICOLON, ";"},
        {RBRACE, "}"},
        {SEMICOLON, ";"},
        {LET, "let"},
        {IDENT, "result"},
        {ASSIGN, "="},
        {IDENT, "add"},
        {LPAREN, "("},
        {IDENT, "five"},
        {COMMA, ","},
        {IDENT, "ten"},
        {RPAREN, ")"},
        {SEMICOLON, ";"},
        {BANG, "!"},
        {MINUS, "-"},
        {SLASH, "/"},
        {ASTERISK, "*"},
        {INT, "5"},
        {SEMICOLON, ";"},
        {INT, "5"},
        {LT, "<"},
        {INT, "10"},
        {GT, ">"},
        {INT, "5"},
        {SEMICOLON, ";"},
        {IF, "if"},
        {LPAREN, "("},
        {INT, "5"},
        {LT, "<"},
        {INT, "10"},
        {RPAREN, ")"},
        {LBRACE, "{"},
        {RETURN, "return"},
        {TRUE, "true"},
        {SEMICOLON, ";"},
        {RBRACE, "}"},
        {ELSE, "else"},
        {LBRACE, "{"},
        {RETURN, "return"},
        {FALSE, "false"},
        {SEMICOLON, ";"},
        {RBRACE, "}"},
        {INT, "10"},
        {EQ, "=="},
        {INT, "10"},
        {SEMICOLON, ";"},
        {INT, "10"},
        {NOT_EQ, "!="},
        {INT, "9"},
        {SEMICOLON, ";"},
        {END_OF_FILE, ""},
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