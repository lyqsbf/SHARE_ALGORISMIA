#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	int n;
	while (cin >> n) {
		priority_queue<ll> Q;
		while (n--) {
			ll x;
			cin >> x;
			Q.push(-x);
		}

		ll res = 0;
		while (Q.size() > 1) {
			ll x = -Q.top(); Q.pop();
			ll y = -Q.top(); Q.pop();
			ll z = x + y;
			res += z;
			Q.push(-z);
		}

		cout << res << endl;
	}
}
