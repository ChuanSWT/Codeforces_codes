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
        long long n,q;
        cin>>n>>q;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;

        vector<vector<long long>> query(q,vector<long long>(2));
        for(auto&arr:query)
        cin>>arr[0]>>arr[1];
        long long sum=0;
        for(auto x:nums)
        sum+=x;
        vector<long long>pre_sum=nums;
        for(int i=1;i<pre_sum.size();++i)
        pre_sum[i]+=pre_sum[i-1];
//1 2 3
//2 3 1
//3 1 2

//0 2
        for(auto q:query)
        {
            long long left=q[0]-1;
            long long right=q[1]-1;
            long long ans=0;
            // left bad
            if(left>=n)
            {
                long long t=left/(n-1);
                left-=t*(n-1);
                right-=t*(n-1);
            }

            if(right<nums.size())//left ok,right ok
            {
                ans=pre_sum[right];
                if(left!=0)
                ans-=pre_sum[left-1];
                cout<<ans<<endl;
                continue;
            }
            //right bad
            ans=pre_sum.back();
            if(left!=0)
            ans-=pre_sum[left-1];
            left=n;
            //计算loop
            long long lp=(right-left+1)/n;
            ans+=sum*lp;
            left+=lp*n;
            cout<<left<<" "<<right<<endl;
            if(left>=n)
            {
                long long t=left/(n-1);
                left-=t*(n-1);
                right-=t*(n-1);
            }
            if(left<=right)
            {
                ans+=pre_sum[right];
                if(left!=0)
                ans-=pre_sum[left-1];
            }
            else
            {
                ans+=pre_sum[right];
                ans+=pre_sum.back();
                if(left!=0)
                ans-=pre_sum[left-1];


            }
            cout<<ans<<endl;
            //
            
        }
        

        
    }