// Exemples senzills d'us de pairs.
// Son structs predefinits amb dos camps (first i second).
// Els pairs es poden comparar directament: primer per first i,
// en cas d'empat, per second.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using P = pair<string, int>;


int main() {
  vector<P> V = { P("Maria", 5), P("Anna", 12), P("Ivet", 11), P("Maria", 40) };
  sort(V.begin(), V.end());
  for (P p : V) cout << p.first << ' ' << p.second << endl;
// Escriu:
// Anna 12
// Ivet 11
// Maria 5
// Maria 40
}
