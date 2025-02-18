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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        //最多看m部
        //使用map表统计
        long long n,m,d;
        cin>>n>>m>>d;
        vector<long long> nums(n);
        for(auto& x:nums)
        cin>>x;
        vector<long long> left=nums;
        map<long long,long long> mp;
        long long sz=0;
        long long sum=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
            {
            ++mp[nums[i]];
            sum+=nums[i];
            ++sz;
            }
            if(sz>m)
            {
                //选取最小
                long long val=mp.begin()->first;
                sum-=val;
                --sz;
                mp.begin()->second--;
                if(mp.begin()->second==0)
                mp.erase(val);
            }
            left[i]=sum;
        }
    //print(left);

        long long maxv=0;
        for(int i=0;i<nums.size();++i)
        maxv=max(maxv,left[i]-(i+1)*d);
        cout<<maxv<<endl;

        

        
    }