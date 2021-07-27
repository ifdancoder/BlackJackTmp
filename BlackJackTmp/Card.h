#ifndef __CARD_H__
#define __CARD_H__

class Card {
public:
    enum suit { SPADES, HEARTS, CLUBS, DIAMONDS };
    enum rnk { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    Card(rnk rk, suit st, bool ps);
    void Flip();
    int GetValue() const;
protected:
    bool cardPos;
    suit cardSuit;
    rnk cardRank;
};

#endif
