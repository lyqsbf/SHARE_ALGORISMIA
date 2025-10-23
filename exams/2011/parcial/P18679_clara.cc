#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
VI V;
int m, n;


void f(int pos, int i){
	if (i == n) {
		cout << pos - m/2 << endl;
		return;
	}
	
	
	if (pos - V[i] >= 0) f(pos - V[i], i + 1);
	if (pos + V[i] <= m) f(pos + V[i], i + 1);
	return;
}


int main(){
	cin >> m >> n;
	V = VI(n);
	for (int i = 0; i < n; ++i){
		int k;
		cin >> k;
		V[i] = k;
	}
	f(m/2, 0);
}
