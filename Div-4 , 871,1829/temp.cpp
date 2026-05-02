#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <numeric> 
#include<cmath>
#include<array>
#include<iomanip>
#include<queue>
#include<set>
#include<bitset>
#include<stack>
#include<map>
#include<unordered_set>
#include <climits>
#include <cstring>
#include <bitset>
using namespace std;
#define ll long long
const int MOD = 1000000007, MAXN = 200000;
string dtb(int n) {
    if (n == 0) {
        return "0";
    }
    string binaryStr = "";
    while (n > 0) {
        binaryStr += to_string(n % 2);
        n /= 2;
    }
    reverse(binaryStr.begin(), binaryStr.end());
    return binaryStr;
}
int main (){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1)
            cout << "YES\n";
        else{
            bool flag = false;
            for(int i = 2 ; i < 64 ; i++){
                ll ans = stoi(dtb(i));
                cout << "ANS = " << ans << endl;
                if(n % ans == 0){
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
    }

    }
return 0;
}
