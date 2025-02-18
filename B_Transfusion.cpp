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
        vector<long long> nums(n);
        for(long long&x:nums)
            cin>>x;
        long long odd=0,even=0;
        long long cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i+=2)
        {
            even+=nums[i];
            ++cnt1;
        }
        for(int i=1;i<nums.size();i+=2)
        {
            odd+=nums[i];
            ++cnt2;
        }
        if(even%cnt1==0&&odd%cnt2==0)
        {
        if(even/cnt1==odd/cnt2)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
        }
        else
        cout<<"NO"<<endl;
        

        
    }