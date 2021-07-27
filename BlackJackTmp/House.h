#include "GenericPlayer.h"

#ifndef __HOUSE_H__
#define __HOUSE_H__

class House : public GenericPlayer
{
public:
    House(const std::string& name);
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

#endif