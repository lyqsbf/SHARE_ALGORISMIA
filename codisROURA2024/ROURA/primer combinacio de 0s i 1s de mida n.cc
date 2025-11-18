// Troba la primera (lexicograficament) combinacio de 0s i 1s de mida n
// que no tingui dos o mes 0s seguits.


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


bool f(int i) {
  if (i == n) {
    escriu();
    return true;
  }

  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;  
    if (f(i + 1)) return true;
  }
  V[i] = 1;
  return f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  if (not f(0)) cout << "sense solucio" << endl; // aqui no passara mai
}
