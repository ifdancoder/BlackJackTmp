#include "Deck.h"
#include <algorithm>

Deck::Deck() {
    cardsArr.reserve(52);
    Populate();
}

Deck::~Deck() {

}

void Deck::Populate() {
    Clear();
    for (int s = Card::SPADES; s <= Card::DIAMONDS; s++) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            Add(new Card(static_cast<Card::rnk>(r), static_cast<Card::suit>(s)));
        }
    }
}

void Deck::Shuffle() {
    std::random_shuffle(cardsArr.begin(), cardsArr.end());
}

void Deck::Deal(Hand& aHand) {
    if (!cardsArr.empty()) {
        aHand.Add(cardsArr.back());
        cardsArr.pop_back();
    }
    else {
        std::cout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer& gp) {
    std::cout << std::endl;
    while (!(gp.IsBusted()) && gp.IsHitting()) {
        Deal(gp);
        std::cout << gp << std::endl;
        if (gp.IsBusted()) {
            gp.Bust();
        }
    }
}