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

    enum class SideIndicator : unsigned char {
        Buy = 'B',
        Sell = 'S'
    };

    enum class Display : unsigned char {
        Yes = 'Y',
        No = 'N'
    };

    enum class HaltStatus : unsigned char {
        AcceptingOrders = 'A',
        Halted = 'H',
        QuoteOnly = 'Q',
        ExchangeSpecificSuspension = 'S',
        Trading = 'T'
    };

    enum class RegSHOAction : unsigned char {
        None = '0',
        PriceTestRestriction = '1'
    };

    enum class AuctionType : unsigned char {
        OpeningAuction = 'O',
        ClosingAuction = 'C',
        HaltAuction = 'H',
        IPOAuction = 'I',
        CBOEMarketClose = 'M'
    };

    enum class RPI : unsigned char {
        BuySide = 'B',
        SellSide = 'S',
        BuyAndSellSide = 'A',
        None = 'N'
    };
}
