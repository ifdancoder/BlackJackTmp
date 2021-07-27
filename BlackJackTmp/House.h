#include "GenericPlayer.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

class House : public GenericPlayer
{
public:
    House(const std::string& name);
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

#endif