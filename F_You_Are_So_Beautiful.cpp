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
    long long cal(int n)
    {
        long long a=n;
        return (1+a)*a/2;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int& x:nums)
        cin>>x;
        long long sum=0;
        set<int> st;
        vector<int> mark(n,0);
        for(int i=0;i<n;++i)
        {
            if(i!=0)
            mark[i]+=mark[i-1];            
            if(st.find(nums[i])==st.end())
            ++mark[i];
            st.insert(nums[i]);
        }
        st.clear();
        for(int i=nums.size()-1;i>=0;--i)
        {   
            if(st.find(nums[i])==st.end())
            {
                sum+=mark[i];
            }
            st.insert(nums[i]);
        }
        cout<<sum<<endl;
        

        
    }