#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "Controller/OrderManager.h"
#include "Model/OrderBook.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::unordered_map;
using std::vector;
using fileinput = std::ifstream;



int main(int argc, char* argv[]) {
    fileinput file;
    if (argc > 1) {
        file.open(argv[1]);
        std::cin.rdbuf(file.rdbuf());
    }

    auto orderBook = std::make_shared<PITCH::OrderBook>();
    auto orderManager = PITCH::OrderManager(orderBook);

    string temp;

    while (std::getline(std::cin, temp)) {
        if (temp[0] == 'S') {
            temp.erase(0, 1);
        }

        orderManager.processOrder(temp);

        // Something similar to this should work well
        // auto* p = reinterpret_cast<PakFileHeader*>(&data[0]);


//        switch (temp[8]) {
//            case 'X' : {
//                const auto orderID = temp.substr(9, 12);
//                const auto sharesCancelled = std::stoll(temp.substr(21, 6));
//
//                auto& order = orderQueue[orderID];
//                auto& orderShares = std::get<0>(order);
//
//                if (sharesCancelled >= orderShares) {
//                    orderQueue.erase(orderID);
//                } else {
//                    orderShares -= sharesCancelled;
//                }
//            }
//                break;
//            case 'E' : {
//                const auto orderID = temp.substr(9, 12);
//                const auto sharesExecuted = std::stoll(temp.substr(21, 6));
//                auto order = orderQueue[orderID];
//
//                auto& orderShares = std::get<0>(order);
//                auto& stockname = std::get<1>(order);
//
//                if (sharesExecuted >= orderShares) {
//                    orderQueue.erase(orderID);
//                } else {
//                    orderShares -= sharesExecuted;
//                }
//                executedOrders[stockname] += sharesExecuted;
//            }
//                break;
//            case 'P' : {
//                const auto sharesExecuted = std::stoll(temp.substr(22, 6));
//                const auto stockname = temp.substr(28, 6);
//
//                executedOrders[stockname] += sharesExecuted;
//            }
//                break;
//            default:
//                break;
//        }
    }

    std::cout << orderBook->getTopTenStocks() << std::endl;

    return 0;
}
