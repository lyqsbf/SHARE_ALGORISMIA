#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;


int n, r;
VVI V;


void escriu(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) {
			if (V[i][j] == 2) cout << 'K';
			else cout << '.';
		}
		cout << endl;
	}
	cout << "----------" << endl;
}


void f(int reis, int i, int j){
	
	if (n == 1) {
		if (r == 1){
			V[i][j] = 2;
			escriu();
			return;
		}
		else escriu();
		return;
	}
	
	if (reis == r) {
		escriu();
		return;
	}
	
	if (i == n) return;
	
	if (i == 0 and j == 0){
		V[i][j] = 2;
			
		f(reis + 1, i, j + 1);
			
		V[i][j] = 0;
			
		f(reis, i, j + 1);
	}
	
	else if (i == 0) {
		if (V[i][j - 1] != 2) {
			V[i][j] = 2;
			
			if (j == n - 1) f(reis + 1, i + 1, 0);
			else f(reis + 1, i, j + 1);
		}
		V[i][j] = 0;
			
		if (j == n - 1) f(reis, i + 1, 0);
		else f(reis, i, j + 1);
	}
	
	else if (j == 0){
		if (V[i - 1][j] != 2 and V[i - 1][j + 1] != 2){
			V[i][j] = 2;
			
			if (j == n - 1) f(reis + 1, i + 1, 0);
			else f(reis + 1, i, j + 1);
		}
		V[i][j] = 0;
			
		if (j == n - 1) f(reis, i + 1, 0);
		else f(reis, i, j + 1);
	}
	
	else if (j == n - 1){
		if (V[i - 1][j] != 2 and V[i - 1][j - 1] != 2 and V[i][j - 1] != 2){
			V[i][j] = 2;
			
			if (j == n - 1) f(reis + 1, i + 1, 0);
			else f(reis + 1, i, j + 1);
		}
		V[i][j] = 0;
			
		if (j == n - 1) f(reis, i + 1, 0);
		else f(reis, i, j + 1);
	}
	
	else if (i == n - 1){
		if (V[i - 1][j - 1] != 2 and V[i - 1][j] != 2 and V[i - 1][j + 1] != 2 and V[i][j - 1] != 2){
			V[i][j] = 2;
			
			if (j == n - 1) f(reis + 1, i + 1, 0);
			else f(reis + 1, i, j + 1);
		}
		V[i][j] = 0;
			
		if (j == n - 1) f(reis, i + 1, 0);
		else f(reis, i, j + 1);
	}
	
	else {
		if (V[i - 1][j - 1] != 2 and V[i - 1][j] != 2 and V[i - 1][j + 1] != 2 and V[i][j - 1] != 2){
			V[i][j] = 2;
			
			if (j == n - 1) f(reis + 1, i + 1, 0);
			else f(reis + 1, i, j + 1);
		}
		V[i][j] = 0;
			
		if (j == n - 1) f(reis, i + 1, 0);
		else f(reis, i, j + 1);
	}	
	
}


int main(){
	cin >> n >> r;
	V = VVI(n, VI(n, 0));
	f(0, 0, 0);
}
