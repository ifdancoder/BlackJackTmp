#include <iostream>
#include "Card.h"
#include "Player.h"
#include "House.h"

using namespace std;

int main()
{
    Player p("Daniel");
    cout << p;

    Card a(Card::TEN, Card::DIAMONDS, 1);
    Card b(Card::TEN, Card::HEARTS, 0);
    Card c(Card::ACE, Card::SPADES, 1);

    p.Add(&a);
    p.Add(&b);
    p.Add(&c);

    cout << p;
    return 0;
}