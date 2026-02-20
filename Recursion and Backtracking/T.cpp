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

string brazil; 
string dream;
int dest = 0;
int tt = 0;
int prop = 1;

void sol(int idx = 0 , int postion = 0){
    if(idx == dream.size()){
        if(postion == dest)
            tt++;
        return;
    }
    if(dream[idx] == '+')
        sol(idx + 1 , postion + 1);
    else if (dream[idx] == '-')
        sol(idx + 1 , postion - 1);
    else{
        prop++;
        sol(idx + 1 , postion + 1);
        sol(idx + 1 , postion - 1);
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> brazil >> dream;
    for(auto c : brazil){
        if (c == '+')
            dest++;
        else
            dest--;
    }
    while(t--)
        sol();
    if (prop == 0)
        cout << fixed << setprecision(12) << (double)tt;
    else
        cout << fixed << setprecision(12) << (double)tt / prop;

    return 0;
}

