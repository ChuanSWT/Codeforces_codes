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
    long long cal(vector<int> nums)
    {
        long long sum=0;
        long long cur=0;
        for(int x:nums)
        {
            if(x==0)
            sum+=cur;
            else
            ++cur;
        }
        return sum;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,-1);
        for(int &x:nums)
        cin>>x;
        int a=0,b=0;
        for(int x:nums)
        if(x)
        ++b;
        else
        ++a;
        if(a==0||b==0)
        {
            cout<<n-1<<endl;
            return ;
        }
        //最右边的1转为0
        vector<int> arr1=nums;
        for(int i=n-1;i>=0;--i)
        if(arr1[i]==1)
        {
        arr1[i]=0;
        break;
        }
        //最左边的0转为1
        vector<int> arr2=nums;
        for(int i=0;i<n;++i)
        if(arr2[i]==0)
        {
        arr2[i]=1;
        break;
        }
        cout<<max(cal(arr1),max(cal(arr2),cal(nums)))<<endl;
        

        
    }