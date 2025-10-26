#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
VL res;
VVI G;
const int LL_MIN = -1e9;
int n;

ll f(int k){
	if(res[k] != LL_MIN) return res[k];
	ll max_cost = 0;
	for(int i = k + 1; i < n; i++){
		ll path_cost = G[k][i] + f(i);
		max_cost = max(path_cost, max_cost);
	}
	return res[k] = max_cost;
}

int main(){
	cin >> n;
	G = VVI(n, VI (n));
	res = VL(n, LL_MIN);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> G[i][j];
		}
	}
	ll final_cost = 0;
	for(int i = 0; i < n; i ++)
		final_cost = max(final_cost, f(i));
	cout << final_cost << endl;
}
