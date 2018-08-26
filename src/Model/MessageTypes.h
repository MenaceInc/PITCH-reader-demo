#pragma once

namespace PITCH {
    enum class MessageType : unsigned char {
        SymbolClear = 's',
        AddOrder = 'A',
        AddOrderLong = 'd',
        OrderExecuted = 'E',
        OrderCancel = 'X',
        Trade = 'P',
        TradeLong = 'r',
        TradeBreak = 'B',
        TradeStatus = 'H',
        AuctionUpdate = 'I',
        AuctionSummary = 'J',
        RetailPriceImprovement = 'R'
    };
}
