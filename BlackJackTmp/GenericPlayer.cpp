#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& const name, long long total) : name(name), total(total) {

}

GenericPlayer::~GenericPlayer() {

}

bool GenericPlayer::IsBusted() const {
    return GetTotal() > 21;
}

void GenericPlayer::Bust() const {
    std::cout << name << " busts" << std::endl;
}

std::string GenericPlayer::getName() {
    return name;
}

std::ostream& operator<<(std::ostream& otp, const GenericPlayer& gp) {
    otp << gp.name << ": " << gp.getTotal() << '$' << std::endl << "Total is " << gp.GetTotal() << ":\n";
    if (gp.cardsArr.size()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < gp.cardsArr.size(); j++) {
                if (gp.cardsArr[j]->getCardPos()) {
                    switch (i) {
                    case 0:
                        std::cout << "******** ";
                        break;
                    case 1:
                        std::cout << "* " << gp.cardsArr[i]->ranks[gp.cardsArr[j]->getCardRank()] << (gp.cardsArr[j]->ranks[gp.cardsArr[j]->getCardRank()].size() > 1 ? " " : "  ") << gp.cardsArr[i]->suits[gp.cardsArr[j]->getCardSuit()] << " * ";
                        break;
                    case 2:
                        std::cout << "******** ";
                        break;
                    }
                }
                else {
                    std::cout << "******** ";
                }
            }
            std::cout << std::endl;
        }
    }
    else {
        otp << "<empty>" << std::endl;
    }
    return otp;
}

long long GenericPlayer::getTotal() const {
    return total;
}