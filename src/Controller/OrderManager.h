#pragma once

#include <memory>
#include "Model/OrderBook.h"

namespace PITCH {
    class OrderManager {
        std::shared_ptr<OrderBook> _book;

        auto addOrder(const std::string& rawOrder) -> void;
        auto cancelOrder(const std::string& rawOrder) -> void;
        auto executeOrder(const std::string& rawOrder) -> void;
        auto trade(const std::string& rawOrder) -> void;
    public:
        OrderManager() = delete;
        explicit OrderManager(std::shared_ptr<OrderBook> book);

        auto processOrder(const std::string& unknownOrder) -> void;
    };
}
