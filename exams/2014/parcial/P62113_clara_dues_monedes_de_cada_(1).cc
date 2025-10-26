#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
int x, n;
VB usat;
VI V;


void escriu() {
	cout << x << " =";
	bool primer = true;
	for (int i = 0; i < 2*n; ++i) {
		if (usat[i] == true) {
			if (i%2 == 0 and not primer) cout << " + " << V[i];
			else if (i%2 == 0 and primer) {
				cout << ' ' << V[i];
				primer = false;
			}
			else if (i%2 == 1 and not primer) cout << " + " << V[i] << 'p';
			else {
				cout << ' ' << V[i] << 'p';
				primer = false;
			}
		}
	}
	cout << endl;
}


void f(int cont, int k) {
	if (cont == x) {
		escriu();
		return;
	}
	
	if (cont > x) return;
	
	
	for (int i = k; i < 2*n; ++i) {
		if (usat[i] == false) {
			usat[i] = true;
			f(cont + V[i], i + 1);
			usat[i] = false;
		}
	}
	return;
}


int main() {
	while (cin >> x >> n) {
		V = VI(2*n, 0);
		usat = VB(2*n, false);
		int k = 0;
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			V[k] = V[k + 1] = m;
			k += 2;
		}
		sort(V.begin(), V.end());
		f(0, 0);
		cout << "----------" << endl;
	}
}
