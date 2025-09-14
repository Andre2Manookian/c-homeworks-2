#include <iostream>
#include <vector>
using namespace std;

class Player {
private:
    int id;
    string name;
    string choice;

public:
    Player(int i, string n) {
        id = i;
        name = n;
        choice = "";
    }

    void makeChoice(string c) {
        choice = c;
    }

    string getChoice() {
        return choice;
    }

    string getName() {
        return name;
    }

    void displayInfo() {
        cout << name << " chose " << choice << endl;
    }
};

class Game {
private:
    vector<Player> players;

public:
    void addPlayer(Player p) {
        players.push_back(p);
    }

    void play() {
        if (players.size() != 2) return;

        string c1 = players[0].getChoice();
        string c2 = players[1].getChoice();

        players[0].displayInfo();
        players[1].displayInfo();

        if (c1 == c2) {
            cout << "Draw!" << endl;
        }
        else if ((c1 == "rock" && c2 == "scissors") ||
                 (c1 == "paper" && c2 == "rock") ||
                 (c1 == "scissors" && c2 == "paper")) {
            cout << players[0].getName() << " wins!" << endl;
        }
        else {
            cout << players[1].getName() << " wins!" << endl;
        }
    }
};

int main() {
    string name1, name2;
    cout << "Enter Player 1 name: ";
    cin >> name1;
    cout << "Enter Player 2 name: ";
    cin >> name2;

    Player p1(1, name1);
    Player p2(2, name2);

    string choice;
    cout << name1 << ", enter your choice (rock/paper/scissors): ";
    cin >> choice;
    p1.makeChoice(choice);

    cout << name2 << ", enter your choice (rock/paper/scissors): ";
    cin >> choice;
    p2.makeChoice(choice);

    Game game;
    game.addPlayer(p1);
    game.addPlayer(p2);
    game.play();

    return 0;
}
