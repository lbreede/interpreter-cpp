#include <lexer.h>

#include <string>
const std::string PROMPT = ">> ";

void start() {
    std::string input;
    while (true) {
        std::cout << PROMPT;
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        Lexer lexer(input);
        Token token = lexer.nextToken();
        while (token.type != TokenType::Eof) {
            std::cout << token << std::endl;
            token = lexer.nextToken();
        }
    }
}