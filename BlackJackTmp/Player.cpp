#include "Player.h"

Player::Player(const std::wstring& name, long long total) : GenericPlayer(name, total) {

}

Player::~Player() {

}

bool Player::IsHitting() const {
    if (GetTotal() != 21) {
        std::wcout << name << ", do you want a hit (Y/N)? ";
        char tmp;
        std::cin >> tmp;
        return tmp == 'Y' || tmp == 'y';
    }
    return false;
}

bool Player::setBet() {
    if (total >= 50) {
        std::wcout << name << L", how much do you bet (bet >= 50 and bet <= " << total << L"): ";
        std::cin >> bet;
        while (bet < 50 || bet > total) {
            std::wcout << name << L", how much do you bet (bet >= 50 and bet <= " << total << L"): ";
            std::cin >> bet;
        }
        std::wcout << std::endl;
        total -= bet;
        return true;
    }
    return false;
}

void Player::Win() {
    total += bet * 2;
    std::wcout << name << " wins. His total is " << total << '$' << std::endl;
}

void Player::Lose() const {
    std::wcout << name << " loses. His total is " << total << '$' << std::endl;
}

void Player::Push() {
    total += bet;
    std::wcout << name << " pushes. His total is " << total << '$' << std::endl;
}

long long Player::getBet() const {
    return bet;
}