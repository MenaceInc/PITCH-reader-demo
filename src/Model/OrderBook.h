#pragma once

#include <cstdint>
#include <unordered_map>
#include "OrderTypes.h"

namespace PITCH {
    class OrderManager; // forward declaration for friend class

    using OrderID = std::string;
    using StockSymbol = std::string;
    using Shares = uint64_t;

    class OrderBook {
        friend class OrderManager;

        std::unordered_map<OrderID, std::tuple<Shares, StockSymbol>> _orderQueue;
        std::unordered_map<StockSymbol, Shares> _executedOrders;

        auto addOrder(const std::string& orderID, const std::string& stockID, uint64_t shares) -> void;
        auto cancelOrder(const std::string& orderID, uint64_t sharesCancelled) -> void;
        auto executeOrder(const std::string& orderID, uint64_t sharesExecuted) -> void;
        auto trade(const std::string& stockName, uint64_t sharesTraded) -> void;
    public:
        OrderBook() = default;

        auto getTopTenStocks() const -> std::string;
    };
}
