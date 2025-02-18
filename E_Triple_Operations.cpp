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
    void quest(vector<long long> &arr,vector<long long> &left_sum)
    {
        int left,right;
        cin>>left>>right;
        long long ans=left_sum[right];
        if(left!=0)
        ans-=left_sum[left-1];
        ans+=arr[left];
        cout<<ans<<endl;
    }
    void compete_solution()
    {

        vector<long long> nums;
        for(long long i=0;i<20;++i)
        {
            long long cur=1;
            for(int j=0;j<i;++j)
            cur*=3;
            nums.push_back(cur-1);
        }

        //print(nums);
        long long ans=0;
        vector<long long> arr;
        for(int i=0;i<=2e5+10;++i)
        {
            for(int j=0;j<nums.size();++j)
            if(i<=nums[j])
            {
                arr.push_back(j);
                break;
            }
        }
        //print(arr);
        vector<long long> left=arr;
        for(int i=1;i<left.size();++i)
        left[i]+=left[i-1];  
        int n;      
        cin>>n;
        while(n--)
        quest(arr,left);
        
    }
    