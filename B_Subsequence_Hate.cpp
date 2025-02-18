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
        string s;
        cin>>s;
        int n=s.size();
        vector<int> pre_sum(n,0);
        if(s[0]=='1')
        pre_sum[0]=1;
        for(int i=1;i<pre_sum.size();++i)
        {
        pre_sum[i]+=pre_sum[i-1];
        if(s[i]=='1')
        ++pre_sum[i];
        }
        int minv=0x3f3f3f3f;
        for(int i=0;i<s.size();++i)
        {
            int pre_one=pre_sum[i];
            int pre_zero=i+1-pre_one;
            int nxt_one=pre_sum.back()-pre_sum[i];
            int nxt_zero=n-pre_one-pre_zero-nxt_one;
            int val1=pre_zero+nxt_one;
            int val2=pre_one+nxt_zero;
            minv=min(minv,min(val1,val2));
        }
        cout<<minv<<endl;
        

        
    }