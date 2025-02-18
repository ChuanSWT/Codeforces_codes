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
        long long n;
        cin>>n;
        vector<long long> nums(1e7,1);
        vector<long long > arr;
        for(int i=2;i<nums.size();++i)
        {
            if(nums[i])
            {
            arr.push_back(i);
            for(int j=i;j<nums.size();j+=i)
            nums[j]=0;
            }  
        }
        //print(arr);
        //return ;
        int count=0;
        while(n)
        {
            long long z=3;
            bool found=false;
            for(auto x:arr)
            {
                long long d=x*x*x;
                if(d>1e18+10)
                {
                    cout<<x<<endl;
                break;
                }
                if(n%d==0)
                {
                    ++count;
                    n/=d;
                    found=true;
                    break;
                }
            }
            if(!found)
            break;
        }
        
        cout<<count<<endl;
    
    }