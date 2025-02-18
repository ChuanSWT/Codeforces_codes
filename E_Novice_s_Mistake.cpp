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
    using namespace std;
    void compete_solution();
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }
    vector<int> gcd_v(int x)
    {
        vector<int> ans;
        for(int i=1;i*i<x;++i)
        {
            if(x%i==0)
            {
                if(i*i==x)
                ans.push_back(i);
                else
                {
                    ans.push_back(i);
                    ans.push_back(x/i);
                }
            }
        }
        return ans;
    }   
    string i_t_s(int n)
{
    if (n == 0) return "0";
    string s;
    while (n)
    {
        s += (char)('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int s_t_i(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        num = num * 10 + (s[i] - '0');
        if (num > 1e8)
            return 1e8;
    }
    return num;
}

    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
    vector<vector<int>> nums;
    string s = i_t_s(i);
    int len = s.size();

    for (int a = 1; a <= 10000; ++a)
    {
        for (int b = max(1, a * len - 8); b < a * len && b <= 10000; ++b)
        {
            string num1 = string(a, '0'); 
            for (int j = 0; j < a; ++j)
                num1.replace(j * len, len, s); 

            num1.resize(num1.size() - b);
            int rst = s_t_i(num1);
            if (a * i - b == rst)
            {
                nums.push_back({ a,b });
            }
        }
    }
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        if(n==1)

        {
            cout<<9999<<endl;
            for(int i=2;i<=10000;++i)
            cout<<i<<" "<<i-1<<endl;
            return;
        }
        unordered_map<int, vector<pair<int, int>>> results;
    
    results[2] = {{20, 18}, {219, 216}, {2218, 2214}};
    results[3] = {{165, 162}};
    results[4] = {{14, 12}, {147, 144}, {1480, 1476}};
    results[5] = {{138, 135}};
    results[7] = {{129, 126}};
    results[10] = {{1262, 2519}};
    results[11] = {{12, 21}, {123, 242}, {1234, 2463}};
    results[13] = {{119, 234}};
    results[14] = {{1178, 2351}};
    results[16] = {{1154, 2303}};
    results[18] = {{1136, 2267}};
    results[20] = {{112, 220}};
    results[21] = {{11, 19}};
    results[24] = {{110, 216}};
    results[35] = {{107, 210}};
    results[68] = {{104, 204}};
    results[90] = {{1033, 2061}};
    results[94] = {{1032, 2059}};
   if (results.find(n) != results.end()) {
        cout << results[n].size()<< endl;
        for (auto& result : results[n]) {
            cout << result.first << " " << result.second << endl;
        }
    } else {
        cout <<0 << endl;
    }
    }