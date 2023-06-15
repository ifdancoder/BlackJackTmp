#include <ctime>
#include <algorithm>
#include "Deck.h"

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
            Add(new Card(static_cast<Card::rnk>(r), static_cast<Card::suit>(s), 1));
        }
    }
    Shuffle();
}

void Deck::Shuffle() {
    srand(time(NULL));
    std::random_shuffle(std::begin(cardsArr), std::end(cardsArr));
}

void Deck::Deal(Hand& aHand) {
    if (!cardsArr.empty()) {
        aHand.Add(cardsArr.back());
        cardsArr.pop_back();
    }
    else {
        std::wcout << "Out of cards. Unable to deal.";
    }
}

void Deck::AdditionalCards(GenericPlayer& gp) {
    std::wcout << std::endl;
    while (!(gp.IsBusted()) && gp.IsHitting()) {
        Deal(gp);
        std::wcout << gp << std::endl;
        if (gp.IsBusted()) {
            gp.Bust();
        }
    }
}