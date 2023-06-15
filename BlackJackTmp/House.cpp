#include "House.h"

House::House(const std::wstring& name, long long total) : GenericPlayer(name, total) {

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
        std::wcout << "No card to flip" << std::endl;
    }
}

void House::setTotal(long long newtotal) {
    total = newtotal;
}