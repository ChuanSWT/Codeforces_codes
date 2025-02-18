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
        int n;
        cin>>n;
        vector<vector<int>> edges(n-1,vector<int>(2));
        for(auto&arr:edges)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        --arr[1];
        }
        string s;
        cin>>s;
        vector<int> nums(n,0);
        for(auto arr:edges)
        {
            ++nums[arr[0]];
            ++nums[arr[1]];
        }
        vector<int> leaves;
        int zero=0;
        int one=0;
        int other=0;
        int life=0;
        for(int i=1;i<nums.size();++i)
        {
        if(nums[i]==1)
        {
        leaves.push_back(i);
        if(s[i]=='0')
        ++zero;
        if(s[i]=='1')
        ++one;
        if(s[i]=='?')
        ++other;
        }
        else
        if(s[i]=='?')
        ++life;
        }
        //print(nums);
        //先手想要最大化差异
        life%=2;
        bool flag=true;
        int maxv=0;

        string ori=s;
        if(s[0]=='?')
        {
            flag=false;
        if(one<zero)
        s[0]='1';
        else
        s[0]='0';

        }
        //根是0
        if(s[0]=='0')
        {
            //cout<<other<<endl;
            //cout<<one<<' '<<zero<<endl;
            while(other)
        {
            if(flag)
            ++one;
            else
            ++zero;
            flag=!flag;
            --other;
        }
        maxv=max(maxv,one);
        }
        else//根是1
        {
            while(other)
        {
            if(flag)
            ++zero;
            else
            ++one;
            flag=!flag;
            --other;
        }
        maxv=max(maxv,zero);
        }


        if(life==1)
        {
            flag=false;
            s=ori;
        if(s[0]=='?')
        {
            flag=true;
        if(one<zero)
        s[0]='1';
        else
        s[0]='0';

        }
            if(s[0]=='0')
        {
            //cout<<other<<endl;
            //cout<<one<<' '<<zero<<endl;
            while(other)
        {
            if(flag)
            ++one;
            else
            ++zero;
            flag=!flag;
            --other;
        }
        maxv=max(maxv,one);
        }
        else//根是1
        {
            while(other)
        {
            if(flag)
            ++zero;
            else
            ++one;
            flag=!flag;
            --other;
        }
        maxv=max(maxv,zero);
        }
        }
        cout<<maxv<<endl;




        
    }