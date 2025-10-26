#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI fibo;
int n, m;

long long int f(int i){
	if(fibo[i] != -1) return fibo[i];
	
	return fibo[i] = f(i - 1)%m + f(i - 2)%m;
}

int main(){	
	while(cin >> n >> m){
		fibo = VI(1001, -1);
		fibo[0] = 0;
		fibo[1] = 1;
		f(n);
		cout << fibo[n]%m << endl;
	}
}
