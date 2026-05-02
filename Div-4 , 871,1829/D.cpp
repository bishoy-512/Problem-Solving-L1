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
unordered_set<int>nums;
void sol(int n) {
    int a = n / 3;
    int b = (2 * n) / 3;
    nums.insert(a);
    nums.insert(b);
    if(a % 3 == 0)
        sol(a);
    if(b % 3 == 0)
        sol(b);
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        int n,m;
        nums.clear();
        cin >> n >> m;
        if (n == m)
            cout << "YES\n";
        else if(n % 3 != 0 || m > n)
            cout << "NO\n";
        else{
            sol(n);
            if(nums.count(m))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
