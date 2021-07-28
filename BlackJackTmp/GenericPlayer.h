#include "Hand.h"

#ifndef __GENERIC_PLAYER_H__
#define __GENERIC_PLAYER_H__

class GenericPlayer : public Hand {
public:
    GenericPlayer(const std::string& const name);
    virtual ~GenericPlayer();
    virtual bool IsHitting() const = 0;
    bool isBoosted() const;
    void Bust() const;
    friend std::ostream& operator<<(std::ostream& otp, const GenericPlayer& gp);
protected:
    std::string name;
};

#endif
