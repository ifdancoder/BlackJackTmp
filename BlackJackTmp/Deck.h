#include "GenericPlayer.h"
#include "Hand.h"

#ifndef __DECK_H__
#define __DECK_H__

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif
