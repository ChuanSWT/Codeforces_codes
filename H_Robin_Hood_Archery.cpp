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
        int n,q;
        cin>>n>>q;
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;
        vector<vector<int>> query(q,vector<int>(2));
        for(auto&arr:query)
        cin>>arr[0]>>arr[1];
        //状态压缩，ll
        set<int> st;
        for(int &x:nums)
        st.insert(x);
        int index=1;
        map<int,int> mp;
        int maxv=0;
        for(int x:st)
        {
            mp[x]=index;
            ++index;
            maxv=index;
        }
        for(int &x:nums)
        x=mp[x];
        vector<__int128> line;
        while(maxv>=0)
        {
            maxv-=110;
            line.push_back(0);
        }
        vector<vector<__int128>> pre_sum(n,line);
        pre_sum[0][nums[0]/120]^=((__int128)1ll<<(nums[0]%120));
        for(int i=1;i<pre_sum.size();++i)
        {
            for(int j=0;j<line.size();++j)
            pre_sum[i][j]^=pre_sum[i-1][j];
            pre_sum[i][nums[i]/120]^=((__int128)1ll<<(nums[i]%120));
        }
        /*for(auto arr:pre_sum)
        {
            for(auto x:arr)
            cout<<(long long )x<<" ";
            cout<<endl;
        }*/
       for(auto q:query)
       {
            int left=q[0]-1;
            int right=q[1]-1;
            bool ok=true;
            for(int i=0;i<line.size();++i)
            {
                if(left==0)
                {
                    if(pre_sum[right][i]!=0)
                    ok=false;
                }
                else
                {
                    if(pre_sum[left-1][i]!=pre_sum[right][i])
                    ok=false;
                }
            }
            if(ok)
            {
                cout<<"YES"<<endl;
            }
            else
            cout<<"NO"<<endl;
       }

        
        

        
    }