#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using filestream = std::ifstream;

int main(int argc, char* argv[]) {
    if (argc > 1) {
        filestream file(argv[1]);
        std::cin.rdbuf(file.rdbuf());
    }

    std::string temp;
    int line = 1;
    while(std::getline(std::cin, temp)) {
        std::cout << "Line " << std::to_string(line++) << ": " << temp << std::endl;
    }

    return 0;
}
