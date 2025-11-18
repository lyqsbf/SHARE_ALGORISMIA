// Exemples senzills d'us de structs.


#include <iostream>
#include <vector>
using namespace std;


struct Persona {
  int dni;
  string nom, cognom1, cognom2;
  int telefon;
  double pes;
};


int main() {
  vector<Persona> V(10);
// aixo no compilaria, perque Persona no te definit un comparador:
// sort(V.begin(), V.end());

  V[0].dni = 12345678;
  Persona p;
  p.nom = "Josep";
  p.pes = 100.5;
  Persona p2 = { 987654321, "Joan", "Garcia", "Puig", 601123456, 80.5 };
}
