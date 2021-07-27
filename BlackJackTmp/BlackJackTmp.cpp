#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
    Card c(Card::ACE, Card::DIAMONDS, true);
    cout << c;
}