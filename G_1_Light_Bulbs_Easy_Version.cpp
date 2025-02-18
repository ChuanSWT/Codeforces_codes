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
    int fd(map<int,vector<int>> &mp,int n,int i)
    {
        vector<int> nums=mp[n];
        for(int x:nums)
        if(x!=i)
        return x;
        return -1;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n*2,0);
        for(int &x:nums)
        cin>>x;
        int a=0,b=0;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();++i)
        mp[nums[i]].push_back(i);
        int count=0;
        int left=0,right=fd(mp,nums[0],0);
        int parts=1;
        vector<int> ppp={0};

        while(right<nums.size())
        {
            //cout<<left<<" "<<right<<endl;
            int c=0;
            int d=right;
            for(int i=left;i<=right;++i)
            {
                int o=fd(mp,nums[i],i);
                if(o>right)
                ++c;
                d=max(d,o);
            }
            count+=c;
            if(d>right)
            {
                left=right+1;
                right=d;
            }
            else
            {
                if(right+1>=nums.size())
                break;
                left=right+1;
                ppp.push_back(left);
                right=fd(mp,nums[left],left);
                ++parts;
            }
            
        }

        ppp.push_back(nums.size());
        for(int i=0;i<ppp.size()-1;++i)
        ppp[i]=ppp[i+1]-ppp[i];
                print(ppp);
        long long ans2=1;   
        for(int i=0;i<ppp.size()-1;++i)
        ans2*=ppp[i];
        cout<<parts<<" " <<ans2<<endl;

        
    }