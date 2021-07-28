#include "Game.h"

Game::Game(const std::vector<std::string>& names) {
    for (int i = 0; i < names.size(); i++) {
        players.push_back(Player(names[i]));
    }
    deck.Populate();
}

Game::~Game() {

}

void Game::Play() {
    for (int i = 0; i < 2; ++i) {
        for (int i = 0; i < players.size(); i++) {
            deck.Deal(players[i]);
        }
        deck.Deal(house);
    }
    house.FlipFirstCard();
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i] << std::endl;
    }
    std::cout << house << std::endl;
    for (int i = 0; i < players.size(); i++) {
        deck.AdditionalCards(players[i]);
    }
    house.FlipFirstCard();
    std::cout << std::endl << house;
    deck.AdditionalCards(house);
    if (house.IsBusted()) {
        for (int i = 0; i < players.size(); i++) {
            if (!(players[i].IsBusted())) {
                players[i].Win();
            }
        }
    }
    else {
        for (int i = 0; i < players.size(); i++) {
            if (!(players[i].IsBusted())) {
                if (players[i].GetTotal() > house.GetTotal()) {
                    house.setTotal(house.getTotal() - players[i].getBet());
                    players[i].Win();
                }
                else if (players[i].GetTotal() < house.GetTotal()) {
                    house.setTotal(house.getTotal() + players[i].getBet());
                    players[i].Lose();
                }
                else {
                    players[i].Push();
                }
            }
        }
    }
    for (int i = 0; i < players.size(); i++) {
        players[i].Clear();
    }
    house.Clear();
}

std::vector<Player>& Game::getPlayers() {
    return players;
}