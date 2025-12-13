#include <iostream>
#include <vector>
#include <string>
using namespace std;


using VI = vector<long long>;
using ll = long long;
VI cas;
int n;
string s;


ll f(int k) {
	if (cas[k]!= -1) return cas[k];
	if (k == 0) {
		cas[k] = 0;
		return 0;
	}
	
	cas[k] = 0;
	for (int i = 0; i < k; ++i) {
		if (s[i] < s[k]) cas[k] += f(i) + 1;
	}
	return cas[k];
}


int main() {
	while (cin >> s) {
		n = s.size();
		cas = VI(n, -1);
		ll res = 0;
		for (int i = 1; i < n; ++i) res += f(i);
		cout << res << endl;
	}
}
