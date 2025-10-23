#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
VB usat;
VI V;
VI sumas;
int s;
int n;

void write(){
	cout << "{";
	int k = 0;
	for(int i = 0; i < n ; i++){
		if(usat[i]){
			cout << (k ? "," : "" ) << V[i];
			k++;
		}
	}
	cout << "}" << endl;
}

void f(int i, int sum){
    if(sum + sumas[i] < s or sum > s) return;
	if(i == n){
		if(sum == s) write();
		return ;
	}
    usat[i] = false;
	f(i + 1, sum);
	usat[i] = true;
	f(i + 1, sum + V[i]);
}

void omple_sumas(){
	sumas[n - 1] = V[n - 1];
	for(int i = n - 2; i >= 0; --i){
		sumas[i] = V[i] + sumas[i + 1];
	}
	return;
}

int main(){
	cin >> s >> n;
	V = VI(n);
	sumas = VI(n);
	usat = VB(n);
	for(int& x : V) cin >> x;
	omple_sumas();
	f(0 , 0);
}
