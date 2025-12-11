#include <iostream>
#include <vector>
#include <string>
using namespace std;


using VB = vector<bool>;
int N;
long long n;
string m;
VB v;
bool trobat;


void f(int i, long long res, long long act) {
	if (i == N) {
		if (res + act == n) {
			trobat = true;
			cout << n << " = " << m[0];
			for (int j = 0; j < N; ++j) {
                if(v[j] == 1) cout << " + ";
                cout << m[j+1];
            }
            cout << endl;
			}
        return;
	}
	
	if (res + act > n) return;
	
	v[i] = true;
	f(i + 1, res + act, m[i + 1] - '0');
	v[i] = false;
	f(i + 1, res, 10*act + m[i + 1] -'0');
}


int main() {
	while (cin >> n >> m) {
		N = m.size() - 1;
		trobat = false;
		v = VB(N, false);
		f(0, 0, m[0] - '0');
		if (!trobat) cout << "No solution for " << n << ' ' << m << '.' << endl;
	}
}
