#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum) {
    int luku, arvaus;
    int arvausKerrat = 0;

    luku = rand() % maxnum + 1;

    do {
        cout << "Arvaa luku (1-" << maxnum << "): ";
        cin >> arvaus;
        arvausKerrat++;

        if (arvaus < luku) {
            cout << "Liian pieni" << endl;
        } else if (arvaus > luku) {
            cout << "Liian suuri" << endl;
        } else {
            cout << "Oikein!" << endl;
        }

    } while (arvaus != luku);

    return arvausKerrat;
}

int main() {
    srand(time(0));

    int tulos = game(40);
    cout << "Arvauksia yhteensa: " << tulos << endl;

    return 0;
}
