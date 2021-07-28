#include <algorithm>
#include <random>
#include <chrono>   
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
}

void Deck::Shuffle() {
    std::default_random_engine e(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(cardsArr), std::end(cardsArr), e);
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