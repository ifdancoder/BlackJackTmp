#include "House.h"
#include "Player.h"
#include "Deck.h"

#ifndef __GAME_H__
#define __GAME_H__

class Game
{
public:
    Game(const std::vector<std::string>& names);
    ~Game();
    void Play();
private:
    Deck deck;
    House house;
    std::vector<Player> players;
};

#endif
