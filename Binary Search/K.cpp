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

void sol(){
    int n,m,q;cin>>n>>m>>q;
    vector<int>t_cells(m);
    loop(m)
        cin >> t_cells[i];
    sort(t_cells.begin() , t_cells.end());
    while(q--){
        int x;cin>>x;
        int l = 0, r = m - 1, mini = -1, maxi = -1, mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(t_cells[mid] > x){
                maxi = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        l = 0; r = t_cells.size()-1;
        while(l <= r){
            mid = l + (r-l)/2;
            if(t_cells[mid] < x){
                mini = mid;
                l = mid + 1;
            }else r = mid - 1;
        }
        int ans;
        if(mini == -1)
            ans = t_cells[maxi] - 1;
        else if (maxi == -1)
            ans = n - t_cells[mini];
        else
            ans = (t_cells[maxi] - t_cells[mini] - 2)/2 + 1;
        cout << ans << endl;
    }
}
/*
# first case => david can go to lowest cell
1 2 3 4 5 6 7 8 9 10
. D . . T . . . T .
# second case => david can go to highest cell
1 2 3 4 5 6 7 8 9 10
. T . T . D . . . .
# third case => david between two teachers
1 2 3 4 5 6 7 8 9 10
. . T . D . . . T .
. . . T D . . T . .
. . . T . D . T . .
. . . . T D T . . .

*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
