#include "Hand.h"

Hand::Hand() {
    cardsArr.reserve(7);
};
Hand::~Hand() {
    Clear();
};
void Hand::Add(Card* pCard) {
    cardsArr.push_back(pCard);
}
void Hand::Clear() {
    for (int i = 0; i < cardsArr.size(); i++) {
        delete cardsArr[i];
        cardsArr[i] = nullptr;
    }
    cardsArr.clear();
}
int Hand::GetTotal() const {
    int amount = 0;
    bool ace = false;
    for (int i = 0; i < cardsArr.size(); i++) {
        amount += cardsArr[i]->GetValue();
        if (cardsArr[i]->GetValue() == Card::ACE) {
            ace++;
        }
    }
    return amount + 10 * (amount <= 11 && ace);
}