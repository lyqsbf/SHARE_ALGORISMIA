#include <iostream>
using namespace std;

double p(int suma){
    int count = 0;

    for(int i= 1; i <= 9; i++){
        for(int j = i + 1; j <= 9; j++){
            for(int k = j + 1; k <= 9; k++){
                if(i+j+k >= suma) count++;
            }
        }
    }

    return ((double)count/84);
}


int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    int s;
    while (cin >> s){
        cout << p(s) << endl;
    }
}