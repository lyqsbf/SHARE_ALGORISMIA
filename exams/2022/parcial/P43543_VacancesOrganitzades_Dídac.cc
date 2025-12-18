#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;

const ll INF = 1e18;
int n, k;
VI V;
VVI M;

ll f(int i, int j){
	if(j < 0) return -INF;
	ll& res = M[i][j];
	if(res != -1) return res;
	if(i == 0) return res = 0;
	
	return res = max(f(i-1, j-1) + V[i-1], f(i-1, k));
}

int main(){
	while(cin >> n >> k){
		V = VI(n);
		for(ll& i : V) cin >> i;
		M = VVI(n+1, VI(k+1, -1));
		cout << f(n, k) << endl;
	}
}
