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
        int n;
        cin>>n;
        deque<int> nums(n);
        for(int&x:nums)
        cin>>x;
        int bk=nums.back();
        bk=0;
        sort(nums.begin(),nums.end());
        int cur=0;
        while(nums.size()!=1)
        {
            if(cur%2==0)
            nums.pop_front();
            else
            nums.pop_back();
            ++cur;
        }
        cout<<max(bk,nums[0])<<endl;
        

        
    }