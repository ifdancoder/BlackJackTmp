#include <limits>
#include "GenericPlayer.h"

#ifndef __HOUSE_H__
#define __HOUSE_H__

class House : public GenericPlayer {
public:
    House(const std::string& name="House", long long total=std::numeric_limits<long long int>::max());
    virtual ~House();
    bool IsHitting() const;
    void setTotal(long long newtotal);
    void FlipFirstCard();
};

#endif