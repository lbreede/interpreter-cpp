#include <pwd.h>
#include <repl.h>
#include <unistd.h>

#include <iostream>

std::string getCurrentUsername() {
    struct passwd* pw;
    uid_t uid = geteuid();
    pw = getpwuid(uid);
    if (pw) {
        return std::string(pw->pw_name);
    }
    return "unknown";
}

int main() {
    std::string username = getCurrentUsername();
    if (username == "unknown") {
        std::cerr << "Could not get current username\n";
        return 1;
    }
    std::cout << "Hello " << username << "! This is the Monkey programming language!\n";
    std::cout << "Feel free to type in commands\n";
    start();
    return 0;
}