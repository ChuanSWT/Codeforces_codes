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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int &x:nums)
        cin>>x;
        vector<int> left=nums;
        int sum=0;
        for(int x:nums)
        sum+=x;
        for(int i=1;i<left.size();++i)
        left[i]+=left[i-1];
        //print(left);
        if(n==1)
        {
            cout<<"1 0"<<endl;
            return;
        }
        for(int i=0;i<left.size();++i)
        {
            int t1=0;
            if(i!=0)
            t1=left[i-1];
            int t2=sum-left[i];
            if(t1>t2)//开始品尝的时间点
            {
                cout<<i<<" "<<n-i<<endl;
                return;
            }
        }
        

        
    }