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
        vector<int> ans(n,0);
        int val=1;
        for(int i=0;i<k;i+=2)
        {
            for(int j=i;j<n;j+=k)
            {
                ans[j]=val;
                ++val;
            }
        }
        for(int i=1;i<k;i+=2)
        {
            int right=i;
            while(right+k<n)
            right+=k;
            for(int j=right;j>=i;j-=k)
            {
                ans[j]=val;
                ++val;
            }

        }
        print(ans);

        
        

        
    }