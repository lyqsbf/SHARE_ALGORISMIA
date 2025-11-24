#include <iostream>
#include <vector>
using namespace std;

int n;
int t;

using VI = vector<int>;
VI V;

void write(){
	cout << "{";
	int k = 0;
	for(int i = 0; i < n; i++){
		int a = V[i];
		while(a--){
			cout << (k? "," : "") << i + 1;
			k++;
		}
	}
	cout << "}" << endl;
}

void f(int i, int lenght){
	if(lenght > t) return;
	if(i == n){
		if(lenght == t) return write();
		return;
	}
	for(int k = 0; k <= t; k++){
		V[i] = k;
		f(i + 1, lenght + k);
	}
}

int main(){
	cin >> n >> t;
	V = VI(n);
	f(0, 0);
}
