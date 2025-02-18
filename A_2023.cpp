    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
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
    vector<int> cin_vector(int length)
    {
        vector<int> a(length,0);
        for(int i=0;i<length;++i)
        cin>>a[i];
        return a;
    }
    void compete_solution()
    {
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        long long sum=1;
        for(int n:nums)
        sum*=n;
        if(2023%sum)
        {
            cout<<"NO"<<endl;
            return;
        }
        --k;
        cout<<"YES"<<endl;
        cout<<2023/sum<<" ";
        for(int i=0;i<k;++i)
        cout<<1<<" ";
        cout<<endl;
    
    }