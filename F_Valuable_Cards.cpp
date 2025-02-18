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
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }
    vector<int> gcd_v(int x)
    {
        vector<int> ans;
        for(int i=1;i*i<=x;++i)
        {
            if(x%i==0)
            {
                if(i*i==x)
                ans.push_back(i);
                else
                {
                    ans.push_back(i);
                    ans.push_back(x/i);
                }
            }
        }
        return ans;
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
        int n,x;
        cin>>n>>x;
        vector<long long> cards(n,0);
        for(int i=0;i<n;++i)
        cin>>cards[i];
        vector<int> nums=gcd_v(x);
        map<long long ,long long> mp;
        for(int num:nums)
        mp[num]=0;//存储所有因数
        mp[1]=1;
        reverse(cards.begin(),cards.end());
        cards.push_back(x);
         reverse(cards.begin(),cards.end());
         /*for(int num:cards)
         cout<<num<<" ";
         cout<<endl;*/
         int ans=0;
 
         map<long long ,long long> ori_mp=mp;
         int count=0;
         while(!cards.empty())
         {
            long long num=cards.back();

            for(auto p=mp.rbegin();p!=mp.rend();++p)
            {
                if(p->second==0)
                continue;
                long long newN=p->first;
                newN*=num;
                if(mp.find(newN)!=mp.end())
                mp[newN]=1;
            }
            if(mp.find(num)!=mp.end())
                mp[num]=1;
            if(mp.rbegin()->second==1)
            {
                mp=ori_mp;
                ++ans;
                //++count;//
                if(num==x)
                break;
            }
            else
            cards.pop_back();
         }
         cout<<ans<<endl;
        
    }