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
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto&x:nums)
        cin>>x;

        vector<int> arr(1001,0);
        for(auto x:nums)
        ++arr[x];
        sort(arr.begin(),arr.end());
        int ans=0;
        bool flag=true;
        for(int i=0;i<arr.size();++i)
        {
            if(arr[i]==0)
            continue;
            if(arr[i]==1)
            {
                if(flag)
                {
                ans+=2;
                flag=false;
                continue;
                }
                else
                {
                flag=true;
                continue;
                }
            }
            ++ans;
        }
        cout<<ans<<endl;
        

        
    }