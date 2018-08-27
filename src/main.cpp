#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include "Model/OrderBook.h"
#include "Controller/OrderManager.h"

int main(int argc, char* argv[]) {
    // redirect std::cin to file passed in as first argument
    std::fstream file;
    if (argc > 1) {
        file.open(argv[1]);
        std::cin.rdbuf(file.rdbuf());
    }

    auto orderBook = std::make_shared<PITCH::OrderBook>();
    auto orderManager = PITCH::OrderManager(orderBook);

    std::string temp;

    while (std::getline(std::cin, temp)) {
        if (temp[0] == 'S') { // specific to example data received
            temp.erase(0, 1);
        }

        orderManager.processOrder(temp);
    }

    std::cout << orderBook->getTopTenStocks() << std::endl;

    return 0;
}
