#pragma once

#include <memory>
#include "Model/OrderBook.h"

namespace PITCH {
    class OrderManager {
        std::shared_ptr<OrderBook> _book;
    public:
        OrderManager() = delete;
        explicit OrderManager(std::shared_ptr<OrderBook> book);

        auto addOrder(const std::string& rawOrder) -> void;
        auto cancelOrder(const std::string& rawOrder) -> void;
        auto processOrder(const std::string& unknownOrder) -> void;
        auto executeOrder(const std::string& rawOrder) -> void;
        void trade(const std::string& rawOrder);
    };
}
