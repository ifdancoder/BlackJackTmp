#include <iostream>
#include <vector>
#include "Card.h"

#ifndef __HAND_H__
#define __HAND_H__

class Hand {
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void Clear();
    int GetTotal() const;
protected:
    vector<Card*> cardsArr;
};

#endif
