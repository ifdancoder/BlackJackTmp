#include "Card.h"

Card::Card(rnk rk = ACE, suit st = SPADES, bool ps = true) : cardRank(rk), cardSuit(st), cardPos(ps) {
}

void Card::Flip() {
    cardPos = !cardPos;
}

int Card::GetValue() const {
    return cardPos * (cardRank > 10 ? 10 : cardRank);
}