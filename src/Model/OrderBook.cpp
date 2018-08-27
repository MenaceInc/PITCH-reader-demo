#include "OrderBook.h"
#include <algorithm>
#include <vector>

using namespace PITCH;


auto OrderBook::addOrder(const std::string& orderID, const std::string& stockID, uint64_t shares) -> void {
    _orderQueue[orderID] = {shares, stockID};
}

auto OrderBook::cancelOrder(const std::string& orderID, uint64_t sharesCancelled) -> void {
    auto& order = _orderQueue[orderID];
    auto& orderShares = std::get<0>(order);

    if (sharesCancelled >= orderShares) {
        _orderQueue.erase(orderID);
    } else {
        orderShares -= sharesCancelled;
    }
}

auto OrderBook::executeOrder(const std::string& orderID, uint64_t sharesExecuted) -> void {
    auto& order = _orderQueue[orderID];
    auto& orderShares = std::get<0>(order);
    auto& stockID = std::get<1>(order);

    if (sharesExecuted >= orderShares) {
        _orderQueue.erase(orderID);
    } else {
        orderShares -= sharesExecuted;
    }
    _executedOrders[stockID] += sharesExecuted;
}

auto OrderBook::getTopTenStocks() const -> std::string {
    // copy from map for sorting and keep const
    std::vector<std::tuple<Shares, StockSymbol>> temp;
    temp.reserve(_executedOrders.size());

    // swap stock and shares to sort by shares
    for (const auto& stock : _executedOrders) {
        temp.emplace_back(stock.second, stock.first);
    }

    std::sort(temp.rbegin(), temp.rend()); // reverse because want descending order

    auto sharesSize = std::to_string(std::get<0>(temp[0])).size(); // needed for formatting

    std::string result;

    for (size_t i = 0; i < temp.size() and i < 10; ++i) {
        std::string line = std::get<1>(temp[i]);
        line.append(6 - line.size(), ' ');

        auto shares = std::to_string(std::get<0>(temp[i]));

        line.append(sharesSize - shares.size(), ' ');
        line += shares;

        result += line + '\n';
    }

    return result;
}

auto OrderBook::trade(const std::string& stockName, uint64_t sharesTraded) -> void {
    _executedOrders[stockName] += sharesTraded;
}
