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
    __int128 cal(long long n1)
    {
        __int128 n=n1;
        return (n*(n-1))>>1;
    }
    void compete_solution()
    {
        long long n;
        cin>>n;
        long long left=0,right=2648956421ll+10ll;
        while(left<right)
        {
            long long mid=(left+right)/2;
            if(cal(mid)<=n)
            left=mid+1;
            else
            right=mid;
        }
        long long ans=left-1;
        long long l=n-cal(ans);
        cout<<ans+l<<endl;
        

        
    }