#include <iostream>

#ifndef __CARD_H__
#define __CARD_H__

class Card {
public:
    enum suit { SPADES, HEARTS, CLUBS, DIAMONDS };
    enum rnk { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    std::wstring ranks[14] = { L"Error", L"A", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"10", L"J", L"Q", L"K" };
    std::wstring suits[4] = { L"\u2660", L"\u2665", L"\u2663", L"\u2666" };

    Card(rnk rk = ACE, suit st = SPADES, bool ps = true);
    bool getCardPos() const;
    suit getCardSuit() const;
    rnk getCardRank() const;
    void Flip();
    int GetValue() const;
    friend std::wostream& operator<<(std::wostream& otp, const Card& card);
protected:
    bool cardPos;
    suit cardSuit;
    rnk cardRank;
};

#endif
