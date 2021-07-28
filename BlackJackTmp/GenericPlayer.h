#include "Hand.h"

#ifndef __GENERIC_PLAYER_H__
#define __GENERIC_PLAYER_H__

class GenericPlayer : public Hand {
public:
    GenericPlayer(const std::string& const name="", long long total=0);
    virtual ~GenericPlayer();
    virtual bool IsHitting() const = 0;
    bool IsBusted() const;
    void Bust() const;
    long long getTotal() const;
    std::string getName();
    friend std::ostream& operator<<(std::ostream& otp, const GenericPlayer& gp);
protected:
    std::string name;
    long long total;
};

#endif
