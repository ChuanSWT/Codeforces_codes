#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <iomanip>
#include <numeric>
//#define int long long

using namespace std;
typedef long long ll;

const int W = 30;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;
    //前缀异或
    vector<int> pre(n + 1);
    pre[0] = a[0];
    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1] ^a[i];
    }
    //[n][30]的数组
    vector<vector<int>> last(n,vector<int>(30,0));
    for (int i = 0; i < n; i++){
        if (i > 0) last[i] = last[i - 1];
        // 刷新最近的该位的下标
        last[i][__lg(a[i])] = i;
        //由高位向低位覆盖
        for (int j = W - 2; j >= 0; j--){
            last[i][j] = max(last[i][j], last[i][j + 1]);
        }
    }

    while (q--) {
        int x;
        cin >> x;
        //idx:当前面对的数字
        int idx = n - 1;
        while (idx >= 0 && x > 0){
            int msb = __lg(x);
            //前缀和快进到考验点
            //nxt:下一个面对的数字
            int nxt = last[idx][msb];
            x ^= pre[idx] ^ pre[nxt];
            idx = nxt;
            //布豪,吃不了,直接退出了
            if (a[nxt] > x) 
                break;
            //计算当前
            x ^= a[nxt];
            //当前被吃, 移向下一位
            idx--;
        }

        cout << n - idx - 1 << " ";
    }
    cout<<" "<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}