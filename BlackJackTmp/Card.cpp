#include "Card.h"

Card::Card(rnk rk, suit st, bool ps) : cardRank(rk), cardSuit(st), cardPos(ps) {

}

bool Card::getCardPos() const {
    return cardPos;
}

Card::suit Card::getCardSuit() const {
    return cardSuit;
}

Card::rnk Card::getCardRank() const {
    return cardRank;
}

void Card::Flip() {
    cardPos = !cardPos;
}

int Card::GetValue() const {
    return cardPos * (cardRank > 10 ? 10 : cardRank);
}

std::ostream& operator<<(std::ostream& otp, const Card& card) {
    if (card.cardPos) {
        otp << "********\n* " << card.ranks[card.cardRank] << (card.ranks[card.cardRank].size() > 1 ? " " : "  ") << card.suits[card.cardSuit] << " *\n********\n";
    }
    else {
        otp << "********\n********\n********\n";
    }
    return otp;
}