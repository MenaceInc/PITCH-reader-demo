#include "OrderManager.h"

using namespace PITCH;

OrderManager::OrderManager(std::shared_ptr<OrderBook> book) : _book(std::move(book)) {
}

auto OrderManager::addOrder(const std::string& rawOrder) -> void {
    const auto* order = reinterpret_cast<const PITCH::AddOrder*>(&rawOrder[0]);
    const auto orderID = std::string(order->orderID.begin(), order->orderID.end());
    const auto stockID = std::string(order->stock.begin(), order->stock.end());
    const auto shares = std::stoull(std::string(order->shares.begin(), order->shares.end()));

    _book->addOrder(orderID, stockID, shares);
}

auto OrderManager::cancelOrder(const std::string& rawOrder) -> void {
    const auto* order = reinterpret_cast<const PITCH::OrderCancel*>(&rawOrder[0]);
    const auto orderID = std::string(order->orderID.begin(), order->orderID.end());
    const auto shares = std::stoull(std::string(order->cancelledShares.begin(), order->cancelledShares.end()));

    _book->cancelOrder(orderID, shares);
}

auto OrderManager::executeOrder(const std::string& rawOrder) -> void {
    const auto* order = reinterpret_cast<const PITCH::OrderExecuted*>(&rawOrder[0]);
    const auto orderID = std::string(order->orderID.begin(), order->orderID.end());
    const auto sharesExecuted = std::stoull(std::string(order->executedShares.begin(), order->executedShares.end()));

    _book->executeOrder(orderID, sharesExecuted);
}

auto OrderManager::processOrder(const std::string& unknownOrder) -> void {
    auto orderType = MessageType(unknownOrder[8]);

    switch (orderType) {
        case MessageType::SymbolClear:
            break;
        case MessageType::AddOrder:
            addOrder(unknownOrder);
            break;
        case MessageType::AddOrderLong:
            break;
        case MessageType::OrderExecuted:
            executeOrder(unknownOrder);
            break;
        case MessageType::OrderCancel:
            cancelOrder(unknownOrder);
            break;
        case MessageType::Trade:
            trade(unknownOrder);
            break;
        case MessageType::TradeLong:
            break;
        case MessageType::TradeBreak:
            break;
        case MessageType::TradeStatus:
            break;
        case MessageType::AuctionUpdate:
            break;
        case MessageType::AuctionSummary:
            break;
        case MessageType::RetailPriceImprovement:
            break;
    }
}

void OrderManager::trade(const std::string& rawOrder) {
    const auto* order = reinterpret_cast<const PITCH::*>(&rawOrder[0]);
    const auto orderID = std::string(order->orderID.begin(), order->orderID.end());
    const auto sharesExecuted = std::stoull(std::string(order->executedShares.begin(), order->executedShares.end()));

    _book->executeOrder(orderID, sharesExecuted);
}
