#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

VI V;
int n;
int t;
int x;
int y;

void write(){
	cout << "{";
	int k = 0;
	for(int i = 0; i < n; i++){
		int a = V[i];
		while(a--){
			cout << (k ? "," : "") << i + 1;
			k++;
		}
	}
	cout << "}" << endl;
}

void f(int i, int lenght){
	if(lenght + (n - i) * y < t) return;
	if(lenght + (n - i) * x > t) return;
	if(lenght > t) return;
	if(i == n){
		if(lenght == t) return write();
		return;
	}
	for(int k = x; k <= y; k++){
		V[i] = k;
		f(i + 1, lenght + k);
	}
}


int main(){
	cin >> n >> x >> y >> t;
	V = VI(n);
	f(0,0);
}
