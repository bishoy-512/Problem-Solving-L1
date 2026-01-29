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

/*
    1 2 3 4 5 6 7 8
====================
1   1 0 0 0 0 0 0 0
2   0 0 0 0 0 0 0 0
3   0 0 1 0 0 0 0 0
4   0 0 0 1 0 0 0 0
5   0 0 0 0 1 0 0 0
6   0 0 0 0 0 0 1 0
7   0 0 0 0 0 0 0 1
8   0 0 0 0 0 0 0 0
===================
1   1 1 1 1 1 1 1 1
2   1 1 1 1 1 1 1 1
3   1 1 2 2 2 2 2 2
4   1 1 2 3 3 3 3 3
5   1 1 2 3 4 4 4 4
6   1 1 2 3 4 4 5 5
7   1 1 2 3 4 4 5 6 
8   1 1 2 3 4 4 5 6
*/
void sol(){
    int n,k;cin >> n >> k;
    int size = 1000;
    int maxx = 1, maxy = 1;
    vector<vector<int>>nums(size+1 , vector<int>(size+1));
    while(n--){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        x1++;y1++;x2++;y2++;
        nums[x1][y1] += 1;
        nums[x2][y2] += 1;
        maxx = max(maxx , max(x1,x2));
        maxy = max(maxy , max(y1,y2));
    }
    // prefix sum for each row =>
    for (int i = 1;i<=size;i++){
        for (int j = 1;j<=size;j++){
            nums[i][j] += nums[i][j-1];
        }
    }
    // prefix sum for each column =>
    int maxi = -1;
    for (int i = 1;i<=size;i++){
        for (int j = 1;j<=size;j++){
            nums[i][j] += nums[i-1][j];
            maxi = max(nums[i][j] , maxi);
        }
    }
    for (int i = 1;i<=maxx;i++){
        for (int j = 1;j<=maxy;j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    // cout << maxi + k;
}

signed main() {
    fast;
    // freopen("paintbarn.in" , "r" , stdin);
    // freopen("paintbarn.out" , "w" , stdout);
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
