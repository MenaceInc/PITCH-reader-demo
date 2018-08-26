#pragma once

#include <array>
#include "AuctionTypes.h"
#include "MessageTypes.h"

namespace PITCH {
    struct SymbolClear {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 8> stock;
    };

    struct AddOrder {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        unsigned char sideIndicator;
        std::array<unsigned char, 6> shares;
        std::array<unsigned char, 6> stock;
        std::array<unsigned char, 10> price;
        unsigned char display;
    };

    struct AddOrderLong {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        unsigned char sideIndicator;
        std::array<unsigned char, 6> shares;
        std::array<unsigned char, 8> stock;
        std::array<unsigned char, 10> price;
        unsigned char display;
        unsigned char participantID;
    };

    struct OrderExecuted {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        std::array<unsigned char, 6> executedShares;
        std::array<unsigned char, 12> executionID;
    };

    struct OrderCancel {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        std::array<unsigned char, 6> cancelledShares;
    };

    struct Trade {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        unsigned char sideIndicator;
        std::array<unsigned char, 6> shares;
        std::array<unsigned char, 6> stock;
        std::array<unsigned char, 10> price;
        std::array<unsigned char, 12> executionID;
    };

    struct TradeLong {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> orderID;
        unsigned char sideIndicator;
        std::array<unsigned char, 6> shares;
        std::array<unsigned char, 8> stock;
        std::array<unsigned char, 10> price;
        std::array<unsigned char, 12> executionID;
    };

    struct TradeBreak {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 12> executionID;
    };

    struct TradeStatus {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 8> stock;
        unsigned char haltStatus;
        unsigned char regSHOAction;
        unsigned char reserved1;
        unsigned char reserved2;
    };

    struct AuctionUpdate {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 8> stock;
        AuctionType auctionType;
        std::array<unsigned char, 10> referencePrice;
        std::array<unsigned char, 10> buyShares;
        std::array<unsigned char, 10> sellShares;
        std::array<unsigned char, 10> indicativePrice;
        std::array<unsigned char, 10> auctionOnlyPrice;
    };

    struct AuctionSummary {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 8> stock;
        AuctionType auctionType;
        std::array<unsigned char, 10> price;
        std::array<unsigned char, 10> shares;
    };

    struct RetailPriceImprovement {
        std::array<unsigned char, 8> timestamp;
        MessageType messageType;
        std::array<unsigned char, 8> stock;
        unsigned char retailPriceImprovement;
    };
}
