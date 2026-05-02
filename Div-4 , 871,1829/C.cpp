#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;

void sol() {
    int n;cin>>n;
    int zero_one , one_zero , one_one;
    zero_one = one_zero = one_one = LONG_LONG_MAX;
    bool f_one_one , f_one_zero , f_zero_one;
    f_one_one = f_one_zero = f_zero_one = false;
    loop(n){
        int temp;
        string s;
        cin >> temp >> s;
        if(s == "10"){
            one_zero = min(one_zero , temp);
            f_one_zero = true;
        }
        else if(s == "01"){
            zero_one = min(zero_one , temp);
            f_zero_one = true;
        }
        else if(s == "11"){
            one_one = min(one_one , temp);
            f_one_one = true;
        }
    }
    if(f_one_one && f_one_zero && f_zero_one){
        if(zero_one + one_zero < one_one)
            cout << zero_one + one_zero << endl;
        else
            cout << one_one << endl;
    }
    else if (f_one_one == false && f_one_zero && f_zero_one)
        cout << zero_one + one_zero << endl;
    else if(f_one_zero == false || f_zero_one == false){
        if(f_one_one)
            cout << one_one << endl;
        else cout << -1 << endl;
    }else cout << -1 << endl;

}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
