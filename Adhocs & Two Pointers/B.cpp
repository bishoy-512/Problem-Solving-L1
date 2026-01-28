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
    int n,x;cin >> n >> x;
    vector<pair<int,int>>nums(n);

    for(int i = 0;i<n;i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }
    int l = 0,r = n-1;
    bool flag = false;
    sort(nums.begin(),nums.end());

    while(true){
        if(l == r)
            break;
        if(nums[l].first + nums[r].first == x){
            flag = true;
            break;
        }
        else if (nums[l].first + nums[r].first > x)
            r--;
        else
            l++;
    }
    if(flag)
        cout << nums[l].second + 1 << " " << nums[r].second + 1;
    else
        cout << "IMPOSSIBLE";

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    
    //while()
        sol();
    return 0;
}
