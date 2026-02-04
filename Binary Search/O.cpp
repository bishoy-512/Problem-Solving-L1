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
    vector<int>nums(n);
    loop(n)
        cin >> nums[i];
    vector<pair<int,int>>ans;
    loop(n){
        if(nums[i] < i+1)
            ans.push_back({nums[i] , i+1});
    }
    sort(ans.begin() , ans.end());
    int fina = 0;
    loop(ans.size()){
        int x = ans[i].second;
        int l = i + 1 , r = ans.size() - 1,dis = -1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(ans[mid].first > x){
                dis = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        if(dis != -1)
            fina += (ans.size() - dis);
    }
    cout << fina << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
