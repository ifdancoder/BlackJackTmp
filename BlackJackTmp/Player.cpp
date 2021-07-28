#include "Player.h"

Player::Player(const std::string& name, long long total) : GenericPlayer(name, total) {

}

Player::~Player() {

}

bool Player::IsHitting() const {
    if (GetTotal() != 21) {
        std::cout << name << ", do you want a hit (Y/N)? ";
        char tmp;
        std::cin >> tmp;
        return tmp == 'Y' || tmp == 'y';
    }
    return false;
}

bool Player::setBet() {
    if (total >= 50) {
        std::cout << name << ", how much do you bet (bet >= 50 and bet <= " << total << "): ";
        std::cin >> bet;
        while (bet < 50 || bet > total) {
            std::cout << name << ", how much do you bet (bet >= 50 and bet <= " << total << "): ";
            std::cin >> bet;
        }
        std::cout << std::endl;
        total -= bet;
        return true;
    }
    return false;
}

void Player::Win() {
    total += bet * 2;
    std::cout << name << " wins. His total is " << total << '$' << std::endl;
}

void Player::Lose() const {
    std::cout << name << " loses. His total is " << total << '$' << std::endl;
}

void Player::Push() {
    total += bet;
    std::cout << name << " pushes. His total is " << total << '$' << std::endl;
}

long long Player::getBet() const {
    return bet;
}