// L'entrada consisteix en un nombre n seguit d'almenys n linies amb enters.
// Per a les n primeres, en calcula la suma.


#include <iostream>
#include <sstream>
using namespace std;


int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s); // per gastar el salt de linia
  while (n--) {
    getline(cin, s);
    stringstream ss(s);
    int suma = 0;
    int x;
    while (ss >> x) suma += x;
    cout << suma << endl;
  }
}
