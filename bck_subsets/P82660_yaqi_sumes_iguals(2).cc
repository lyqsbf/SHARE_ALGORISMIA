#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
VB usat;
VI V;
int s;
int n;

void write(){
	cout << "{";
	int k = 0;
	for(int i = n - 1; i >= 0 ; i--){
		if(usat[i]){
			cout << (k ? "," : "" ) << V[i];
			k++;
		}
	}
	cout << "}" << endl;
}

int f(int i, int sum){
	if(i == -1){
		if(sum == s) return 1;
		return 0;
	}
	usat[i] = true;
	if (f(i - 1, sum + V[i])) return 1;
	usat[i] = false;
	if (f(i - 1, sum)) return 1;
	return 0;
}

int main(){
	cin >> s >> n;
	V = VI(n);
	usat = VB(n, false);
	for(int& x : V) cin >> x;
	sort(V.begin(), V.end());
	if(f(n - 1, 0)) write();
	else cout << "no solution" << endl;
}
