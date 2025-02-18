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
    int fd(vector<int>& nums,int limit)
    {
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>=limit)
            right=mid;
            else
            left=mid+1;
        }
        if(left==0)
        return -1;
        
        return nums[left-1];
    }
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> nums(m);
        for(int &x:nums)
        cin>>x;
        vector<int> mark(n,0x3f3f3f3f);
        vector<int> ans(n,0);
        for(int i=0;i<ans.size();++i)
        {
            int rst=fd(nums,mark[i]);
            if(rst==-1)
            {
                cout<<-1<<endl;
                return;
            }
            ans[i]=rst;
            for(int j=i;j<ans.size();j+=i+1)
                mark[j]=min(mark[j],rst);
        }
        print(ans);
        

        
    }