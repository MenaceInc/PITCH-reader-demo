#include <iostream>

int main() {
    std::string temp;
    int line = 1;
    while(std::getline(std::cin, temp)) {
        std::cout << "Line " << std::to_string(line++) << temp << std::endl;
    }

    return 0;
}
