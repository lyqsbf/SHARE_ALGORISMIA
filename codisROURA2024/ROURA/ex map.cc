#include <iostream>
#include <map>
using namespace std;


int main() {
// llegeix una sequencia de paraules i compta quantes vagades apareix cadascuna
  map<string, int> M;
  string s;
  while (cin >> s) ++M[s];

/*
  for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it)
    cout << (*it).first << ' ' << (*it).second << endl;

  for (auto it = M.begin(); it != M.end(); ++it)
    cout << it->first << ' ' << it->second << endl;
*/

// Escriu un llistat ordenat per paraula amb quantes vegades ha aparescut cadascuna.
// Els dos bucles anteriors (comentats) farien el mateix.

  for (auto p : M) cout << p.first << ' ' << p.second << endl;

// Diu que la paraula pastanaga ha aparescut 3 vegades.
// Aixo serveix tant per inserir com per actualitzar.
  M["pastanaga"] = 3;

// Si la paraula pissarra no ha aparescut, escriu un missatge indicant-ho.
  if (M.find("pissarra") == M.end()) cout << "pissarra no esta" << endl;

// Diu quantes vegades ha aparescut la paraula pop.
// Vigila de no inserir la paraula pop si no hi era.
  auto it = M.find("pop");
  cout << (it != M.end() ? it->second : 0) << endl;

// Esborra la informacio relativa a la paraula pastanaga.
  M.erase("pastanaga");

// Sabent que la paraula hola esta, volem saber quantes vegades apareix
// la paraula immediatament anterior a hola dintre del map.
  it = M.find("hola");
  if (it == M.begin()) cout << "hola es la primera paraula (no te anterior)" << endl;
  else {
    --it;
    cout << "la paraula " << it->first << " apareix " << it->second << " vegada(es)" << endl;
  }
}
