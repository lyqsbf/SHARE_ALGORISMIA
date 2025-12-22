#include <iostream>
#include <map>
using namespace std;


int main(){
    map<string, int> paraules;
    string s;
    while (cin >> s){
        if (s == "minimum?") {
            if (paraules.size() == 0){
                cout << "indefinite minimum" << endl;
            }

            else {
                auto it = paraules.begin();
                //++it;
                cout << "minimum: " << it -> first << ", " << it -> second << " time(s)" << endl;
            }
        }

        else if (s == "maximum?"){
            if (paraules.size() == 0){
                cout << "indefinite maximum" << endl;
            }

            else {
                auto it = paraules.end();
                --it;
                cout << "maximum: " << it -> first << ", " << it -> second << " time(s)" << endl;
            }
        }

        else if (s == "store"){
            cin >> s;
            auto it = paraules.find(s);

            if (it == paraules.end()){
                paraules[s] = 1;
            }

            else {
                int x = it -> second;
                paraules[s] = x + 1;
            }
        }

        else {
            cin >> s;
            auto it = paraules.find(s);

            if (it != paraules.end()){
                int x = it -> second;

                if (x == 1) paraules.erase(s);
                else {
                    paraules[s] = x - 1;
                }
            }
        }
    }
}
