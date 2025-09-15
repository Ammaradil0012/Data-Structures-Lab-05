#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Guessgame(int s, int cP, int n) {
    int guess;
    cout << "Player " << cP << ", enter your guess between 1-100 ";
    cin >> guess;

    if (guess == s) {
        cout << "player " << cP << " wins"<< endl;
        return;
    }
    else if (guess < s) {
        cout << "guess is too low\n";
    }
    else {
        cout << "guess is too high\n";
    }

    int nextPlayer = (cP % n) + 1;
    Guessgame(s, nextPlayer, n);
}

int main() {
    srand(time(0));
    int secret = 1 + rand() % 100;
    int n;

    cout << "Guess the number between the range (1-100)\n";
    cout << "Enter number of players: ";
    cin >> n;

    Guessgame(secret, 1, n);
    return 0;
}

