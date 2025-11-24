#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

VI V;
int n;

void write()
{
	bool primer = true;
	for(int x : V) {
		if(primer)
			primer = false;
		else
			cout << " ";
		cout << x;
	}
	cout << endl;
}

void f(int i)
{
	if(i == n) return write();
	V[i] = 0;
	f(i+1);
	V[i] = 1;
	f(i+1);
}

int main()
{
	cin >> n;
	V = VI(n);
	f(0);
}
