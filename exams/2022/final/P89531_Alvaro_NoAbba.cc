#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;

string s;
int n;
VVI R;

int f(int i, int j){
	if(i == 4) return 0;
	if(j == n) return 1;
	if(R[i][j] > -1) return R[i][j];
	
	if(s[j] != '.'){
		if(s[j] == 'A' and i < 3) return R[i][j] = f(1, j + 1)%(100000007);
		else if(s[j] == 'A') return  0;
		else if(s[j] == 'B' and (i == 0 or i == 3)) return R[i][j] = f(0, j + 1)%(100000007);
		else if(i == 1 or i == 2) return R[i][j] = f(i + 1, j + 1)%(100000007);
	}


	
	if(i == 0) return R[i][j] = (f(1, j + 1) + f(0, j + 1))%(100000007);
	if(i == 1) return R[i][j] = (f(2, j + 1) + f(1, j + 1))%(100000007);
	if(i == 2) return R[i][j] = (f(1, j + 1) + f(3, j + 1))%(100000007);
	return R[i][j] = (f(0, j + 1) + f(4, j + 1))%(100000007);
}

int main(){
	while(cin >> s){
		n = s.size();
		R = VVI(4, VI(n, -1));
		cout << f(0, 0) << endl;
	}
}
