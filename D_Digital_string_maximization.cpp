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
    int cal(string s)
    {
        int cur=0;
        for(int i=0;i<s.size();++i)
        {
            cur*=10;
            cur+=s[i]-'0';
            cur%=9;
        }
        return cur;
    }
    void compete_solution()
    {
        string s;
        cin>>s;
        vector<int> nums;
        for(char c:s)
        nums.push_back(c-'0');
        for(int i=0;i<s.size();++i)
        {
            for(int j=i+1;j<s.size()&&j<i+10;++j)
            {
                int rst=nums[j]-(j-i);
                if(rst>nums[i])
                {
                    for(int k=j;k>i;--k)
                        nums[k]=nums[k-1];
                    nums[i]=rst;
                }
            }
        }
        for(int x:nums)
        cout<<x;
        cout<<endl;
    }