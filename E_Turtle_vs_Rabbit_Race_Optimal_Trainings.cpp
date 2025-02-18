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
    #define int long long
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
    signed main()
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
        for(int&x:nums)
        cin>>x;
        int m;
        cin>>m;
        vector<vector<int>> query(m,vector<int>(2));
        for(auto&arr:query)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        }

        vector<int> pre_sum=nums;
        for(int i=1;i<pre_sum.size();++i)
            pre_sum[i]+=pre_sum[i-1];

        for(auto q:query)
        {
            int l=q[0];
            int u=q[1];
            int left=l,right=n;
            while(left<right)
            {
                int mid=(left+right)/2;
                
                int sum=pre_sum[mid];
                if(l!=0)
                sum-=pre_sum[l-1];
                if(sum<u+1)
                left=mid+1;
                else
                right=mid;
            }
            //cout<<left<<endl;
            int rst1=0x3f3f3f3f3f3f3f3f;
            int rst2=0x3f3f3f3f3f3f3f3f;
            if(left!=n)
            rst1=pre_sum[left];
            if(left-1>=l)
            rst2=pre_sum[left-1];
            if(l!=0)
            {
                rst1-=pre_sum[l-1];
                rst2-=pre_sum[l-1];
            }
            //cout<<rst1<<endl;
            //cout<<rst2<<endl;
            if(abs(u-rst1)==abs(rst2-(u+1)))
            {
                cout<<left<<" ";
                continue;
            }
            if(abs(u-rst1)<abs(rst2-(u+1)))
            cout<<left+1<<" ";
            else
            cout<<left-1+1<<" ";


        }
        cout<<endl;

        
    }