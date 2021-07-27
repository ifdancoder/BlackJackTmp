#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
    Card a(Card::ACE, Card::DIAMONDS, true);
    Card b(Card::JACK, Card::DIAMONDS, false);
    
    cout << a << b;
}