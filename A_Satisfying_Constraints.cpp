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
        vector<vector<int>> op;
        for(int i=0;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            op.push_back({a,b});
        }
        int left=0;
        int right=0x3f3f3f3f;
        for(auto arr:op)
        {
            if(arr[0]==1)
            left=max(left,arr[1]);
            if(arr[0]==2)
            right=min(right,arr[1]);
        }
        long long sum=right-left+1;
        if(sum<=0)
        {
            cout<<0<<endl;
            return;
        }
        for(auto arr:op)
        {
            if(arr[0]==3&&arr[1]>=left&&arr[1]<=right)
            --sum;

        }
        cout<<sum<<endl;
        

        
    }