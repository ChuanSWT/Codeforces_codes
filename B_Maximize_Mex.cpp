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
    cout.tie(NULL) ;
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
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int&x:nums)
        cin>>x;
        sort(nums.begin(),nums.end());
        map<int,long long> mp;
        for(int &x:nums)
        {
            if(x<=mp[x%k]+x%k)
            mp[x%k]+=k;
        }
        long long minv=0x3f3f3f3f;
        for(long long i=0;i<k;++i)
        {
            if(mp.find(i)!=mp.end())
            minv=min(minv,mp[i]+i);
            else
            {
            minv=min(minv,i);
            break;
            }
        }
        cout<<minv<<'\n';
    }