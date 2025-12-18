#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    set<string> S;
    // L'iterador 'it' sempre apuntarà a la mediana actual
    set<string>::iterator it;
    
    while (cin >> s && s != "END") {
        auto res = S.insert(s);
        // res.first és l'iterador de la paraula acabada d'inserir
        
        if (S.size() == 1) {
            it = S.begin();
        } else {
            // Lògica per moure l'iterador segons la mida i la posició de la inserció
            if (S.size() % 2 == 0) {
                // Si la mida passa de senar a parell
                // Només movem l'iterador enrere si la nova paraula és més petita
                if (s < *it) --it;
            } else {
                // Si la mida passa de parell a senar
                // Només movem l'iterador endavant si la nova paraula és més gran
                if (s > *it) ++it;
            }
        }
        
        cout << *it << endl;
    }
}
