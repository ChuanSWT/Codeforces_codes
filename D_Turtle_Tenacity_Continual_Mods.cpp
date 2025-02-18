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
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(int x:nums)
        ++mp[x];
        if(mp.begin()->second==1)
        {
            cout<<"YES"<<endl;
            return;
        }
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]%nums[0]!=0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
cout<<"NO"<<endl;
        
    }