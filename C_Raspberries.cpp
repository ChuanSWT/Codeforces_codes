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
        vector<int> nums(n,0);
        for(int &x:nums)
        cin>>x;
        if(k==4)
        {
            int count2=0;
            int count37=0;
            int count159=0;
            for(int x:nums)
            {
            if(x%2==0)
            ++count2;
            if(x%4==3)
            ++count37;
            if(x%4==1)
            ++count159;
            if(x%4==0)
            {
                cout<<0<<endl;
                return;
            }

            }
            if(count2>=2)
            {
                cout<<0<<endl;
                return;
            }
            if(count2&&count159)
            {
                cout<<1<<endl;
                return;
            }
            if(count37)
            {
            cout<<1<<endl;
            return;
            }
            cout<<2<<endl;
            return;

        }
        int minv=1e9;
        for(int x:nums)
        minv=min(minv,(k-x%k)%k);
        cout<<minv<<endl;
        

        
    }