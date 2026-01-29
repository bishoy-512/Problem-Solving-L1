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
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;


void sol(){
    int n,m;cin >> n >> m;
    vector<vector<int>>aa(n+1 , vector<int>(n+1));
    vector<vector<int>>cc(n+1 , vector<int>(n+1));
    vector<vector<int>>ee(n+1 , vector<int>(n+1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            char c;cin >> c;
            if(c == 'a'){
                aa[i][j] = 1;
                cc[i][j] = 0;
                ee[i][j] = 0;
            }
            else if (c == 'c'){
                aa[i][j] = 0;
                cc[i][j] = 1;
                ee[i][j] = 0;
            }
            else if (c == 'e'){
                aa[i][j] = 0;
                cc[i][j] = 0;
                ee[i][j] = 1;
            }
            else{
                aa[i][j] = 0;
                cc[i][j] = 0;
                ee[i][j] = 0;
            }
        }
    }
    // prefix sum for each row =>
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            aa[i][j] += aa[i][j-1];
            cc[i][j] += cc[i][j-1];
            ee[i][j] += ee[i][j-1];
        }
    }
    // prefix sum for each column =>
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            aa[i][j] += aa[i-1][j];
            cc[i][j] += cc[i-1][j];
            ee[i][j] += ee[i-1][j];
        }
    }
    int q;cin >> q;
    while(q--){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        int a_count = aa[x2][y2] - aa[x1-1][y2] - aa[x2][y1-1] + aa[x1-1][y1-1];
        int c_count = cc[x2][y2] - cc[x1-1][y2] - cc[x2][y1-1] + cc[x1-1][y1-1];
        int e_count = ee[x2][y2] - ee[x1-1][y2] - ee[x2][y1-1] + ee[x1-1][y1-1];
        int ans = min(a_count, min(c_count, e_count));
        cout << ans << endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    // int t;cin >> t;
    // while(t--)
        sol();
    return 0;
}
