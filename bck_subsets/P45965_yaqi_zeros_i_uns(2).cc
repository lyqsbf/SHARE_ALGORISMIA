#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
int n;
int o;
VI V;

void write()
{
	for (int i = 0; i < n; ++i)
		cout << (i ? " ": "") << V[i];
	cout << endl;   
}

void f(int i, int z, int one)
{
	if(z < 0 or one < 0) return;
	if(i == n) return write();
	V[i] = 0;
	f(i + 1, z - 1, one);
	V[i] = 1;
	f(i + 1, z, one - 1);
}

int main()
{
	cin >> n >> o;
	V = VI(n);
	f(0, n - o, o);
}
