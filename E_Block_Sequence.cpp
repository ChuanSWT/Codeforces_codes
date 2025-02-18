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
        int n;
        cin>>n;
        //数组不存在0
        vector<int> nums(n);
        for(int&x:nums)
        cin>>x;
        //可以在这里开始
        //vector<int> dp(n,0);
        //dp[0]=1;
        //直到这里累积的要删除的数量
        vector<int> del(n,0x3f3f3f3f);
        del[0]=1;
        if(0+nums[0]<nums.size())
        {
        del[nums[0]]=0;
        }
        for(int i=1;i<nums.size();++i)
        {
            del[i]=min(del[i],del[i-1]+1);
            //
            int index=i+nums[i];
            if(index<nums.size())
            {
                del[index]=min(del[index],del[i-1]);
            }
        }
        //print(del);
        cout<<del.back()<<endl;
    

        
    }