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

vector<string>board;
int n;

bool c[8] , dia1[16] , dia2[16];
void sol(int row = 0) {
    if(row == n){
        loop(board.size())
            cout << board[i] << endl;
        cout << endl;
    }
        
    loop(n){
        if(!c[i] && !dia1[i + row] && !dia2[i - row + n]){
            c[i] = dia1[i + row] = dia2[i - row + n] = 1;
            board[row][i] = 'Q';
            sol(row + 1);
            board[row][i] = '.';
            c[i] = dia1[i + row] = dia2[i - row + n] = 0;
        }
    }
    
}
/*
3 * 3 =>
Q..
..Q
.Q.

==========
8 x 8 =>
...Q.... 4
......Q. 7
..Q..... 3
.......Q 8
.Q...... 2
....Q... 5
Q....... 1
.....Q.. 6
=========
4 * 4 =>
Q... 1
.Q.. 2
..Q. 3
...Q 4
====
4
====
..Q. 3
Q... 1
...Q 4
.Q.. 2
====
.Q.. 2
...Q 4
Q... 1
..Q. 3
*/

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n;
    string s = "";
    loop(n)
        s.push_back('.');
    loop(n)
        board.push_back(s);
    while(t--)
        sol();

    return 0;
}
