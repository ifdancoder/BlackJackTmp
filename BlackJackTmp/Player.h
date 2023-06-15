#include "GenericPlayer.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player : public GenericPlayer {
public:
    Player(const std::wstring& name=L"", long long total = 500);
    bool setBet();
    virtual ~Player();
    virtual bool IsHitting() const;
    long long getBet() const;
    void Win();
    void Lose() const;
    void Push();
protected:
    long long bet;
};

#endif
