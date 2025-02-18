    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    #include<queue>
    using namespace std;
    #define MOD 1000000007
    void compete_solution();
    int main()
    {
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    vector<long long> cin_vector(int length)
    {
        vector<long long> a(length,0);
        for(int i=0;i<length;++i)
        cin>>a[i];
        return a;
    }
    void compete_solution()
    {
        int n;
        long long c;
        cin>>n>>c;
        vector<long long> nums=cin_vector(n);//constant
        vector<long long> right_sum=nums;
        for(int i=nums.size()-2;i>=0;++i)
        right_sum[i]+=right_sum[i+1];
        vector<int> ans(n,n-1);
        for(int i=0;i<ans.size();++i)
        {
            if()
        }
    }