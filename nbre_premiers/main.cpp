#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Limites permettant de contrôler la saisie de l'utilisateur
    const int upper_limit = 1000;
    const int lower_limit = 2;
    int value = 0;

    char retry = 'X';

    // Permet à l'utilisateur de recommencer le programme
    do {

        // Vérifie la saisie de l'utilisateur et redemande un nouveau saisie si hors limite
        do {
            cout << "Entrer une valeur [2-1000] :" << " ";
            cin >> value;
        } while (value < lower_limit || value > upper_limit);

        cout << "Voulez-vous recommencer [O/N] :";
        cin >> retry;
    } while (retry == 'o' || retry == 'O');





    return EXIT_SUCCESS;
}
