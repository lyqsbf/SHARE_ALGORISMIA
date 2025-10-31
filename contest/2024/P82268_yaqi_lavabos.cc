//lavabo
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string sb;
    string sl;
    while(cin >> sb >> sl){
        int n = sb.size();

        int b = 0;
        int l = 0;
        int s = 0;
        for(int i = 0; i < n; ++i){
            if(sb[i] == '1' and sl[i] == '0') b+=1;
            else if(sb[i] == '0' and sl[i] == '1') l+=1;
            else if(sb[i] == '1' and sl[i] == '1') s+=1;
        }
		if(s > 0){
			int x = abs(b-l);
			if(s > x) cout << max(b,l) + (s-x)/2 << endl;
			else if(s < x) cout << min(b,l)+s << endl;
			else if(s == x) cout << max(b,l) << endl;
		}
		else cout << min(b,l) << endl;
    }
}
