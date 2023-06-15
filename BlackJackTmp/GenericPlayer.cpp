#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::wstring& const name, long long total) : name(name), total(total) {

}

GenericPlayer::~GenericPlayer() {

}

bool GenericPlayer::IsBusted() const {
    return GetTotal() > 21;
}

void GenericPlayer::Bust() const {
    std::wcout << name << L" busts" << std::endl;
}

std::wstring GenericPlayer::getName() {
    return name;
}

std::wostream& operator<<(std::wostream& otp, const GenericPlayer& gp) {
    otp << gp.name << L": " << gp.getTotal() << L'$' << std::endl << L"Total is " << gp.GetTotal() << L":\n";
    if (gp.cardsArr.size()) {
        for (int i = 0; i < gp.cardsArr.size(); i++) {
            otp << std::endl;
            std::wcout << *gp.cardsArr[i];
        }
        otp << std::endl;
    }
    else {
        otp << L"<empty>" << std::endl;
    }
    return otp;
}

long long GenericPlayer::getTotal() const {
    return total;
}