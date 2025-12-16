#include <iostream>
#include <vector>
using namespace std;

int n;
int m;

int main(){
    while (cin >> n >> m){
        cout << (n % (m+1) == 0? "Felix" : "Edgar") << endl;
    }
}