#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
VVB maleta;
VVI V;
int a, b, n;
int sol;


bool can(int x, int y, int w, int h) {
	if (x + w > a or y + h > b) return false;
	
	for (int i = x; i < x + w; ++i) {
		for (int j = y; j < y + h; ++j) {
			if (maleta[i][j]) return false;
		}
	}
	return true;
}


void put(int x, int y, int w, int h) {
	for (int i = x; i < x + w; ++i) {
		for (int j = y; j < y + h; ++j) {
			maleta[i][j] = true;
		}
	}
}


void remove(int x, int y, int w, int h) {
	for (int i = x; i < x + w; ++i) {
		for (int j = y; j < y + h; ++j) {
			maleta[i][j] = false;
		}
	}
}


void f(int k) {	
	if (k == n) {
		++sol;
		return;
	}
	
	
	for (int i = 0; i < a; ++i) {
		if (i + V[k][0] > a) break;
		for (int j = 0; j < b; ++j) {
			if (j + V[k][1] > b) break;
			if (!maleta[i][j]) {
				if (can(i, j, V[k][0], V[k][1])) {
					put (i, j, V[k][0], V[k][1]);
					f(k + 1);
					remove(i, j, V[k][0], V[k][1]);
				}
			}
		}
	}
	return;
}


bool comparar(VI& obj1, VI& obj2) {
    // Priorizar objetos más grandes primero (puede ayudar a podar antes)
    return obj1[0] * obj1[1] > obj2[0] * obj2[1];
}


int main() {
	int num = 1;
	while(cin >> a >> b >> n) {
		maleta = VVB(a, VB(b, false));
		V = VVI(n, VI(2));
		for (int i = 0; i < n; ++i) cin >> V[i][0] >> V[i][1];
		sol = 0;
		
		sort(V.begin(), V.end(), comparar);
		
		f(0);
		
		cout << "#" << num << ": " << sol << endl;
		++num;
	}
}
