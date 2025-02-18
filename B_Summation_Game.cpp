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
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> nums(n,0);
        for(int &num:nums)
        cin>>num;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int> right_sum=nums;
        for(int i=nums.size()-2;i>=0;--i)
        right_sum[i]+=right_sum[i+1];
        vector<int> left_sum=nums;
        for(int i=1;i<nums.size();++i)
        left_sum[i]+=left_sum[i-1];
        long long sum=0;
        for(int num:nums)
        sum+=num;
        long long maxv=LLONG_MIN;
        //print(left_sum);
        for(int i=0;i<=k;++i)//a可以删除的
        {
            //cout<<i<<endl;
            if(i==nums.size())
            {
                maxv=max(maxv,0ll);
                break;
            }
            long long minus=right_sum[i];//总反转数目
            if(i+x<nums.size())
            minus-=right_sum[i+x];
            long long del=0;
            if(i!=0)
            del=left_sum[i-1];
            maxv=max(maxv,sum-2*minus-del);

        }
cout<<maxv<<endl;
        
    }