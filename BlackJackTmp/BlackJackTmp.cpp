#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
    Card c(Card::ACE, Card::DIAMONDS, true);
    Card c(Card::JACK, Card::DIAMONDS, false);
    
    cout << c;
}