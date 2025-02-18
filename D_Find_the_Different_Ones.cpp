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
        vector<int> nums(n,0);
        for(int&x:nums)
        cin>>x;
        int m;
        cin>>m;
        vector<vector<int>> quest;
        for(int i=0;i<m;++i)
        {
            int a,b;
            cin>>a>>b;
            quest.push_back({a-1,b-1});
        }

        //存储最近不同元素的下标
        vector<vector<int>> cache;
        cache.push_back({nums[0],0});
        vector<int> rst(n,-1);
        for(int i=1;i<nums.size();++i)
        {
            while(cache.size()&&nums[i]!=cache.back()[0])
            {
                rst[cache.back()[1]]=i;
                cache.pop_back();
            }
            cache.push_back({nums[i],i});
        }
        //print(rst);
        for(auto arr:quest)
        {
            int left=arr[0],right=arr[1];
            int index=rst[arr[0]];
            if(index==-1||index>right)
            {
                cout<<"-1 -1"<<endl;
            }
            else
            {
                cout<<left+1<<" "<<index+1<<endl;
            }
        }
        cout<<endl;

        
    }