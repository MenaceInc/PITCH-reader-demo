#pragma once

namespace PITCH {
    enum class AuctionType : unsigned char {
        OpeningAuction = 'O',
        ClosingAuction = 'C',
        HaltAuction = 'H',
        IPOAuction = 'I',
        CBOEMarketClose = 'M'
    };
}
