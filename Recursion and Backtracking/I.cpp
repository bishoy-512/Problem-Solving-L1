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

vector<string>board(8);
bool c[10] , dia1[20] , dia2[20];
int sol(int row = 0) {
    if(row == 8)
        return 1;
    
    int ans = 0;
    loop(8) {
        if(!c[i] && !dia1[i + row] && !dia2[i - row + 8] && board[row][i] != '*'){
            c[i] = dia1[i + row] = dia2[i - row + 8] = 1;
            board[row][i] = 'Q';
            ans += sol(row + 1);
            board[row][i] = '.';
            c[i] = dia1[i + row] = dia2[i - row + 8] = 0;
        }
    }
    return ans;
}


signed main() {
    fast;
    int t = 1;
    // cin >> t;
    loop(8)
        cin >> board[i];

    while(t--)
        cout << sol();
    return 0;
}
