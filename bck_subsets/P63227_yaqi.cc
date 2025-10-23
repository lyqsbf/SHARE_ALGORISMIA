#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
VI V;
int n;
int x;

void write(){
	cout << "{";
	int k = 0;
	for(int i = 0; i < n; i++){
		int a = V[i];
		while(a){
			cout << (k ? "," : "") << i + 1;
			a--;
			k++;
		}
	}
	cout << "}" << endl;
}

void f(int i){
	if(i > n) return;
	if(i == n) return write();
	for(int j = 0; j <= x ; ++j){
		V[i] = j;
		f(i + 1);
	}
}

int main(){
	cin >> n >> x;
	V = VI(n);
	f(0);
}
