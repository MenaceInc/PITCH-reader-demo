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
using fileoutput = std::ofstream;

using OrderID = string;
using StockSymbol = string;


//void processOrder(const string& order);

int main(int argc, char* argv[]) {
    fileinput file;
    if (argc > 1) {
        file.open(argv[1]);
        std::cin.rdbuf(file.rdbuf());
    }

    string temp;

    unordered_map<OrderID, unordered_map<StockSymbol, uint64_t>> orderQueue;
    unordered_map<StockSymbol, uint64_t> executedOrders;

    fileoutput out("output.txt");

    while (std::getline(std::cin, temp)) {
        switch (temp[9]) {
            case 'A' : {
                const auto orderID = temp.substr(10, 12);
                const auto stockID = temp.substr(29, 6);
                orderQueue[orderID][stockID] += std::stoll(temp.substr(23,6));
            } break;
            case 'X' : {
                const auto orderID = temp.substr(10, 12);
                const auto sharesReduced = std::stoll(temp.substr(22,6));

                auto& order = orderQueue[orderID];
                auto size = order.size();

                int i = 23;
            } break;
            case 'E' : {
                const auto orderID = temp.substr(10, 12);
                auto order = orderQueue[orderID];

                for(const auto& stock : order) {
                    executedOrders[stock.first] += stock.second;
                }

                orderQueue.erase(orderID);
            } break;
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
