//parcial 2011 balance beam
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using ll = long long;
VI V;
int m;
int n;

void f(ll pos, int jumps){
	if(pos > m/2 or pos < - m/2) return ;
	if(jumps == n){
		cout << pos << endl;
		return ;
	}
	f(pos + V[jumps], jumps + 1);
	f(pos - V[jumps], jumps + 1);
}

int main(){
	cin >> m >> n;
	V = VI(n);
	for(int&x : V) cin >> x;
	f(0, 0);
}
