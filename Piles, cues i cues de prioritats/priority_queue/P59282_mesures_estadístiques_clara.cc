#include <iostream>
#include <queue>
using namespace std;


int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    string s;
    int n = 0;
    double sum = 0.0000;
    int max;
    priority_queue <int> heap; 
    while (cin >> s){

        if (s == "number"){
            int t;
            cin >> t;
            sum += t;
            if (n == 0) max = t;
            else if (max < t) max = t;
            heap.push(-t);
            ++n;
            double x = sum/n;
            cout << "minimum: " << -heap.top() << ", maximum: " << max << ", average: " << x << endl; 
        }

        else if (s == "delete"){

            if (!heap.empty()){
                --n;
                int t = -heap.top();
                heap.pop();
                sum -= t;
            }

            if (!heap.empty()) {
                double x = sum/n;
                cout << "minimum: " << -heap.top() << ", maximum: " << max << ", average: " << x << endl;
            }
            else {
                cout << "no elements" << endl;
            } 
        }
    }
}
