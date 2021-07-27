#include "House.h"

House::House(const std::string& name = "House") : GenericPlayer(name) {

}

House::~House() {

}

bool House::IsHitting() const {
    return GetTotal() <= 16;
}

void House::FlipFirstCard() {
    if (cardsArr.size()) {
        cardsArr[0]->Flip();
    }
    else {
        std::cout << "No card to flip" << std::endl;
    }
}