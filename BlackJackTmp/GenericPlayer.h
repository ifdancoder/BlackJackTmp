#include "Hand.h"

#ifndef __GENERIC_PLAYER_H__
#define __GENERIC_PLAYER_H__

class GenericPlayer : public Hand {
public:
    GenericPlayer(const std::wstring& const name=L"", long long total=0);
    virtual ~GenericPlayer();
    virtual bool IsHitting() const = 0;
    bool IsBusted() const;
    void Bust() const;
    long long getTotal() const;
    std::wstring getName();
    friend std::wostream& operator<<(std::wostream& otp, const GenericPlayer& gp);
protected:
    std::wstring name;
    long long total;
};

#endif
