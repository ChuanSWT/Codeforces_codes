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
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        //山
        vector<long long> nxt={nums.back()};
        deque<long long> cache;
        long long maxv=nums.back();
        for(int i=nums.size()-2;i>=0;--i)
        {
            long long cur=nums[i];
            while(!cache.empty())
            {
                if(cur>=maxv)
                {
                    cur-=maxv-cache.front();
                    nxt.push_back(maxv);
                    cache.pop_front();
                }
                else
                break;
            }
            if(cur>=maxv)
            {
                nxt.push_back(cur);
                maxv=max(maxv,cur);
            }
            else
            cache.push_back(cur);
        }
        print(nxt);
       
        long long min1=1e16;
        long long max1=-1;
        for(auto x:cache)
        {
            min1=min(min1,x);
            max1=max(max1,x);
        }
        vector<long long> ans2(2,-1);
        long long sum=0;
        for(auto x:nxt)
        sum+=x;
        ans2[0]=sum/nxt.size();
        if(sum%nxt.size())
        ans2[1]=ans2[0]+1;
        else
        ans2[1]=ans2[0];
        long long left=min(ans2[0],min1);
        long long right=max(ans2[1],max1);
        cout<<right<<" "<<left<<endl;
        cout<<right-left<<endl;

        


        
    }