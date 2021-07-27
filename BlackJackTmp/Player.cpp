#include "Player.h"

Player::Player(const std::string& name = "") : GenericPlayer(name) {
}

Player::~Player() {
}

bool Player::IsHitting() const {
    std::cout << name << ", do you want a hit (Y/N)? ";
    char tmp;
    std::cin >> tmp;
    return tmp == 'Y' || tmp == 'y';
}

void Player::Win() const {
    std::cout << name << " wins" << std::endl;
}

void Player::Lose() const {
    std::cout << name << " loses" << std::endl;
}

void Player::Push() const {
    std::cout << name << " pushes" << std::endl;
}