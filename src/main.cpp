#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::unordered_map;
using std::vector;
using fileinput = std::ifstream;

using OrderID = string;
using StockSymbol = string;


int main(int argc, char* argv[]) {
    fileinput file;
    if (argc > 1) {
        file.open(argv[1]);
        std::cin.rdbuf(file.rdbuf());
    }

    string temp;

    unordered_map<OrderID, tuple<uint64_t, StockSymbol>> orderQueue;
    unordered_map<StockSymbol, uint64_t> executedOrders;

    while (std::getline(std::cin, temp)) {
        if (temp[0] == 'S') {
            temp.erase(0, 1);
        }

        // Something similar to this should work well
        // auto* p = reinterpret_cast<PakFileHeader*>(&data[0]);


        switch (temp[8]) {
            case 'A' : {
                const auto orderID = temp.substr(9, 12);
                const auto stockID = temp.substr(28, 6);
                orderQueue[orderID] = {std::stoll(temp.substr(22, 6)), stockID};
            }
                break;
            case 'X' : {
                const auto orderID = temp.substr(9, 12);
                const auto sharesCancelled = std::stoll(temp.substr(21, 6));

                auto& order = orderQueue[orderID];
                auto& orderShares = std::get<0>(order);

                if (sharesCancelled >= orderShares) {
                    orderQueue.erase(orderID);
                } else {
                    orderShares -= sharesCancelled;
                }
            }
                break;
            case 'E' : {
                const auto orderID = temp.substr(9, 12);
                const auto sharesExecuted = std::stoll(temp.substr(21, 6));
                auto order = orderQueue[orderID];

                auto& orderShares = std::get<0>(order);
                auto& stockname = std::get<1>(order);

                if (sharesExecuted >= orderShares) {
                    orderQueue.erase(orderID);
                } else {
                    orderShares -= sharesExecuted;
                }
                executedOrders[stockname] += sharesExecuted;
            }
                break;
            case 'P' : {
                const auto sharesExecuted = std::stoll(temp.substr(22, 6));
                const auto stockname = temp.substr(28, 6);

                executedOrders[stockname] += sharesExecuted;
            }
                break;
            default:
                break;
        }
    }

    vector<tuple<uint64_t, string>> results;
    results.reserve(executedOrders.size());

    for (const auto& stock : executedOrders) {
        results.emplace_back(stock.second, stock.first);
    }

    std::sort(results.rbegin(), results.rend());

    auto sharesSize = std::to_string(std::get<0>(results[0])).size();

    for (size_t i = 0; i < results.size() and i < 10; ++i) {
        string line = std::get<1>(results[i]);
        line.append(6 - line.size(), ' ');

        auto shares = std::to_string(std::get<0>(results[i]));

        line.append(sharesSize - shares.size(), ' ');
        line += shares;

        cout << line << endl;
    }

    return 0;
}
