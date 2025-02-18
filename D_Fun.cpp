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


    long long cal(int n, int x) 
    {
    long long ans=0;
    for (int a=1; a<=x;++a) {
        for (int b=1; b<=x-a;++b) {
            if (a*b>n) 
            break;
            int maxv = min(x-a-b,(n-a*b)/(a+b));
            ans += max(0, maxv);
        }
    }
    return ans;
    }
    void compete_solution()
    {
        int n,x;
        cin>>n>>x;
        long long sum=cal(n,x);
        cout<<sum<<endl;
        
        

        
    }