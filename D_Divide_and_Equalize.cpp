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
    int check(int n)
    {
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0)
            return i;
        }
        return 0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)
        cin>>x;

        map<int,int> mp;
        for(int &num:nums)
        {
            while(check(num))
            {
                int val=check(num);
                mp[val]++;
                num/=val;
            }
            mp[num]++;
            num=1;
        }
        for(auto p:mp)
        if(p.first!=1&&p.second%n!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        

        
    }