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

        int n,k;
        cin>>n>>k;
        vector<vector<int>> nums(n,vector<int>(2));
        for(auto &arr:nums)
        cin>>arr[0]>>arr[1];
        unordered_map<int,int> dp;
        dp[0]=0;

        for(auto p:nums)
        {
           
            int x=p[0];
            int y=p[1];
            map<int,int> add;
            add[0]=0;
            for(int i=0;i<=200;++i)
            add[i]=0x3f3f3f3f;
            int step=0;
            int cnt=0;
            while(x!=0&&y!=0)
            {
                if(x>y)
                {
                    step+=y;
                    --x;
                    ++cnt;
                    add[cnt]=step;
                }
                else
                {
                    step+=x;
                    --y;
                    ++cnt;
                    add[cnt]=step;
                }
            }
            add[p[0]+p[1]]=p[0]*p[1];
            add[0]=0;
            //for(auto p:add)
            //cout<<p.first<<" "<<p.second<<endl;

            
            unordered_map<int,int> temp;
            for(int i=0;i<=200;++i)
            temp[i]=0x3f3f3f3f;
            for(auto &p:add)
            {
                int plus=p.first;
                int step=p.second;
                for(auto &p2:dp)
                {
                   if(p2.first+plus>=k) 
                   temp[k]=min(temp[k],p2.second+step);
                   else
                   temp[p2.first+plus]=min(temp[p2.first+plus],p2.second+step);
                }
            }
            dp=temp;
        }
        if(dp[k]>1e9)
        cout<<-1<<endl;
        else
        cout<<dp[k]<<endl;
        

        
    }