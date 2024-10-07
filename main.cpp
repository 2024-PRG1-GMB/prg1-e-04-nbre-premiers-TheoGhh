/**
* \file main.cpp
 * \version 1.0.0
 * \author Théo Ghaemmaghami
 * \date : 04.10.2024
 * \brief : Afficheur dynamiques (selon saisie utilisateur) des nombres premiers
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Limites permettant de contrôler la saisie de l'utilisateur
    const int upper_limit = 1000;
    const int lower_limit = 2;
    int user_value;

    constexpr int display_limit = 5;   // limite l'affichage de 5 nombres premiers par ligne

    char retry;

    // Permet à l'utilisateur de recommencer le programme
    do {

        // Vérifie la saisie de l'utilisateur et redemande un nouveau saisie si hors limite
        do {
            cout << "Entrer une valeur [2-1000] :";
            cin  >> user_value; cout << endl;

        } while (user_value < lower_limit || user_value > upper_limit);

        int display_counter = 0; // compteur permettant de gérer l'affichage

        // Logique permettant de retrouver les nombres premiers
        for (int current_value = lower_limit; current_value < user_value; ++current_value) {

            int counter_divisions = 0;

            // Divise le nombre actuel par tous les nombres inférieurs y compris lui-même (sauf 1)
            for (int current_divider = 2; current_divider <= current_value; ++current_divider) {
                if (current_value % current_divider == 0) {
                    ++counter_divisions;
                }
            }

            // Vérifie si le nombre actuel possède uniquement 2 diviseurs (propriété nombres premiers)
            if (counter_divisions == 1) {
                cout << "\t" << current_value << "\t";
                ++display_counter;
            }

            // S'occupe du retour à la ligne lors de l'affichage des nombres premiers
            if (display_counter == display_limit) {
                display_counter = 0;
                cout << endl;
            }
        }

        cout << "\nVoulez-vous recommencer [O/N] :";
        cin  >> retry;

    } while (toupper(retry) == 'O');

    return EXIT_SUCCESS;
}
