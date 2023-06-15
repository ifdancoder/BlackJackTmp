#include <iostream>
#include "Game.h"
#include <locale>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    std::locale::global(std::locale("ru_RU.utf8"));
    system("cls");

    cout << "Welcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<wstring> names;
    wstring name;
    for (int i = 0; i < numPlayers; ++i) {
        wcout << "Enter player name: ";
        wcin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game gm(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        system("cls");
        for (int i = 0; i < gm.getPlayers().size(); i++) {
            if (!(gm.getPlayers()[i].setBet())) {
                std::wcout << gm.getPlayers()[i].getName() << L" can't play anymore" << std::endl;
                gm.getPlayers().erase(gm.getPlayers().begin() + i);
                i--;
            }
        }
        if (gm.getPlayers().size()) {
            gm.Play();
            cout << "\nDo you want to play again? (Y/N): ";
            cin >> again;
        }
        else {
            std::wcout << "The game cannot continue" << std::endl;
            break;
        }
    }
    return 0;
}