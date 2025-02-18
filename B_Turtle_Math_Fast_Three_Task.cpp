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
    #include<iomanip>
    #include<numeric>
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
        int roundc=1;
        cin >> roundc;
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
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;
        map<int,int> mp;
        for(int x:nums)
        ++mp[x%3];
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%3==0)
        {
            cout<<0<<endl;
            return;
        }
        if(sum%3==2)
        {
            cout<<1<<endl;
            return;
        }        
        if(sum%3==1)
        {
            if(mp.find(1)!=mp.end())
            cout<<1<<endl;
            else
            cout<<2<<endl;
        }
    }