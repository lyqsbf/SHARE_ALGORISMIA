// Escriu en ordre lexicografic totes les combinacions de 0s i 1s de mida n.
// Versio millor a Algorismia.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


void escriu() {
  for (int x : V) cout << x;
  cout << endl;
}


void f(int i) {
  if (i == n) return escriu();

  V[i] = 0;
  f(i + 1);
  V[i] = 1;
  f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  f(0);
}
