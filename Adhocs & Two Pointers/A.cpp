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
#define loop(x,n) for(int i = x;i<n;i++)
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;


void sol(){
    int n;cin>>n;
    vector<int>nums(n);

    for(int i = 0;i<n;i++)
        cin >> nums[i];

    int l = 0,r = n-1;
    int f = true;
    int s = 0,d = 0;
    while(l <= r){
        int max = -1;
        if(nums[l] > nums[r]){
            max = nums[l];
            l++;
        }
        else{
            max = nums[r];
            r--;
        }
        if(f)
            s += max;
        else
            d += max;
        f = !f;
    }
    cout << s << " " << d;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    
    //while()
        sol();
    return 0;
}
