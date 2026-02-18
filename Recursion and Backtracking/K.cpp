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

int ans = LONG_LONG_MAX;

void sol(string s , int idx = 0 , int t1 = 5, int t2 = 5 , bool t1_turn = true , int t1_score = 0 , int t2_score = 0) {
    int kicked = 10 - t1 - t2;
    if (t1_score > t2_score + t2 || t2_score > t1_score + t1) {
        ans = min(ans, kicked);
        return;
    }
    if (idx == 10) {
        ans = min(ans, 10LL);
        return;
    }
    if(t1_turn) {
        t1_turn = !t1_turn;
        t1--;
        if(s[idx] == '1'){
            t1_score++;
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        }
        else if(s[idx] == '0')
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        else{
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score + 1 , t2_score);
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        }
    }
    else {
        t1_turn = !t1_turn;
        t2--;
        if(s[idx] == '1'){
            t2_score++;
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        }
        else if(s[idx] == '0')
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        else{
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score + 1);
            sol(s , idx + 1 , t1 , t2 , t1_turn , t1_score , t2_score);
        }
    }
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        ans = LONG_LONG_MAX;
        string s;cin>>s;
        sol(s);
        cout << ans << endl;
    }
    return 0;
}

