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
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;

        int m;
        cin>>m;
        vector<string> query(m);
        for(auto&s:query)
        cin>>s;
        for(auto s:query)
        {
            if(s.size()!=n)
            {
                cout<<"NO"<<endl;
                continue;
            }
            map<char,int> mp;
            map<int,char> mp2;
            bool ok=true;
            for(int i=0;i<n;++i)
            {
                if(mp.find(s[i])!=mp.end()&&mp[s[i]]!=nums[i])
                {
                    ok=false;
                    break;
                }
                if(mp2.find(nums[i])!=mp2.end()&&mp2[nums[i]]!=s[i])
                {
                    ok=false;
                    break;
                }
                mp[s[i]]=nums[i];
                mp2[nums[i]]=s[i];
            }
            if(ok)
                cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        

        
    }