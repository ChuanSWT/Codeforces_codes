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
        int roundc=1;
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    bool is_prime(int n)
    {
        for(int i=2;i*i<=n;++i)
        if(n%i==0)
        return false;
        return true;
    }
    int cal(int n)
    {
        int maxv=0;
        for(int i=2;i*i<=n;++i)
        {
            if(n%i==0&&is_prime(n%i)&&is_prime(n/i))
            maxv=n/i;
        }
        return maxv;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        cout<<cal(n)<<endl;
        

        
    }