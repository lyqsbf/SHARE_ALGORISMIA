// L'entrada consisteix en diverses linies amb enters.
// Per a cadascuna, en calcula la suma.


#include <iostream>
#include <sstream>
using namespace std;


int main() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    int suma = 0;
    int x;
    while (ss >> x) suma += x;
    cout << suma << endl;
  }
}
