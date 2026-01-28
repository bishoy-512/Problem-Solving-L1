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
    string s;cin >> s;
    int l = 0,r = 0;
    bool q = false;
    unordered_set<char>nums;
    queue<int>idx;
    unordered_set<int>asc;
    for(int i = 0;i<26;i++)
        asc.insert(i);
    int max_s = -1;
    int temp = 0;
    while(r < s.size()){
        if(s[r] == '?'){
            temp++;
            idx.push(r);
            r++;
        }
        else if (!nums.count(s[r])){
            nums.insert(s[r]);
            asc.erase(s[r] - 'A');
            r++;
        }else{
            if(s[l] == '?'){
                temp--;
                idx.pop();
            }
            else{
                nums.erase(s[l]);
                asc.insert(s[l] - 'A');
            }
            l++;
        }
        max_s = max(max_s , (int)nums.size());
        if ((r - l) == 26 && nums.size() + temp == 26){
            int f = 0;
            q = true;
            for(auto k : asc){
                s[idx.front()] = char(k + 'A');
                idx.pop();
                f++;
            }
            break;
        }
    }
    if (q) {
        for (char &c : s) {
            if (c == '?')
                c = 'A';
        }
        cout << s;
    }
    else 
        cout << -1;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    // int t;cin >> t;
    // while(t--)
        sol();
    return 0;
}
