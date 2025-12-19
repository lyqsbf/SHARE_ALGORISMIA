//collats(2)
#include <iostream>
#include <map>
using namespace std;

using ll = long long;

// Funció per calcular la longitud del cicle o el primer número que supera 10^8
ll f(int x, int y, int n) {
    map<ll, int> visitats; // Emmagatzema el número i la seva posició a la seqüència
    int pos = 0;

    while (n <= 1e8 and not visitats.count(n)) {
		visitats[n] = pos++;
		n = (n%2 == 0) ? n/2 + x : 3*n + y;
	}
	if (n > 1e8) return n;
	return pos - visitats[n];
}

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        cout << f(x, y, n) << endl;
    }
}
