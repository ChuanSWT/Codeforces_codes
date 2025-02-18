    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    #include<cmath>
    #include<queue>
    #define MOD 1000000007ll
    using namespace std;
    void compete_solution();
    template <typename T>
    void print(const std::vector<T>& vec) {
    for (auto element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    }
        int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }  
    int main() 
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
void compete_solution() {
    string s;
    cin >> s;
    int sz = s.size();
    vector<int> left(sz+1, 0);
    
    for (int i = 0; i < sz; ++i) {
        if(s[i] == '1')
            left[i+1] = left[i] + 1;
        else
            left[i+1] = left[i] - 1;
    }
    
    long long ans = 0;
    map<int, pair<int, long long>> mp;
    mp[0] = {1, 0};
    
    for (int i = 1; i <= sz; ++i) {
        int cur = left[i];
        if (mp.find(cur) != mp.end()) {
            long long LCho = mp[cur].first;
            long long RCho = sz - i + 1;
            ans += LCho * RCho + mp[cur].second * RCho;
            ans %= MOD;
        }
        
        mp[cur].first++;
        mp[cur].second += i;
        mp[cur].second %= MOD;
    }
    
    cout << ans << endl;
}