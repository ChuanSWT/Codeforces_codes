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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> nums(n,1);
        --x;
        --y;
        bool flag=false;
        for(int i=x+1;i<nums.size();++i)
        {
            if(flag==false)
            {
                nums[i]=-1;
                flag=true;
            }
            else
            {
                nums[i]=1;
                flag=false;
            }
        }
        flag =false;
        for(int i=y-1;i>=0;--i)
        {
            if(flag==false)
            {
                nums[i]=-1;
                flag=true;
            }
            else
            {
                nums[i]=1;
                flag=false;
            }
        }
        print(nums);
        
        

        
    }