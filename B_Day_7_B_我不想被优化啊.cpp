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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    vector<long long> cal(long long n)
    {
        vector<long long> ans;
        for(long long i=1;i*i<=n;++i)
        if(n%i==0)
        {
            ans.push_back(i);
            if(i*i!=n)
            ans.push_back(n/i);
        }
        return ans;
    }
    bool check(long long n)
    {
        for(long long i=2;i*i<=n;++i)
        if(n%(i*i)==0)
        return false;
        return true;
    }
    void compete_solution()
    {
        long long n;
        cin>>n;
        vector<long long> nums=cal(n);
        sort(nums.rbegin(),nums.rend());
        print(nums);
        for(long long x:nums)
        {
            if(check(x))
            {
                cout<<x<<endl;
                return;
            }
        }
        cout<<1<<endl;

        
    }