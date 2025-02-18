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
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    long long cal(long long n,long long k)//sz 原始步长
    //k=2 ->s=2 ,r=4
    {
        long long ans=0;
        n-=k;
        ++ans;
        k*=2;
        ans+=n/k;
        return ans;

    }
    void compete_solution()
    {
        long long n,k;
        cin>>n>>k;
        //1 特判 步长=2
        long long cur=1;
        //cout<<cal(7,1)<<endl;
        while(k>0)
        {
            long long newK=k-cal(n,cur);
            if(newK<=0)
            {
                cout<<2*cur*(k-1)+cur<<endl;
                return;
            }
            k=newK;
            cur*=2;
        }
        
        

        
    }