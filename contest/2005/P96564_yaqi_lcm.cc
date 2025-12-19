//mcm
#include <iostream>
using namespace std;

int gcd(int a, int b) {
        while ( b > 0 ) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
}

int main (){
    int n;
    while ( cin >> n and n != 0){
        int m = 1;
        for ( int i = 0; i < n; ++i){
            int x;
            cin >> x;
            x = x / gcd (m, x);
            m = m * x;
        }
    cout << m << endl;
    }
}
