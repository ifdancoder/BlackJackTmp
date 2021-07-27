#include <iostream>
#ifndef __CARD_H__
#define __CARD_H__

class Card {
public:
    enum suit { SPADES, HEARTS, CLUBS, DIAMONDS };
    enum rnk { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    std::string ranks[14] = { "Error", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    char suits[4] = { 6, 3, 5, 4 };

    Card(rnk rk, suit st, bool ps);
    bool getCardPos() const;
    suit getCardSuit() const;
    rnk getCardRank() const;
    void Flip();
    int GetValue() const;
    friend std::ostream& operator<<(std::ostream& otp, const Card& card);
protected:
    bool cardPos;
    suit cardSuit;
    rnk cardRank;
};

#endif
