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
        int n,k;
        cin>>n>>k;
        string a;
        cin>>a;
        string b;
        cin>>b;
        //mark模拟并查集
        vector<int> mark(n,0);
        //不标号，直接填充
        vector<vector<int>> nums;
        //使用bfs
        for(int i=0;i<a.size();++i)
        {
            if(mark[i])
            continue;
            mark[i]=1;
            vector<int> cache={i};
            vector<int> sum;
            while(!cache.empty())
            {
                int index=cache.back();
                sum.push_back(index);
                cache.pop_back();
                if(index+k<a.size()&&mark[index+k]==0)
                {
                    cache.push_back(index+k);
                    mark[index+k]=1;
                }
                if(index+k+1<a.size()&&mark[index+k+1]==0)
                {
                    cache.push_back(index+k+1);
                    mark[index+k+1]=1;
                }
                if(index-k>=0&&mark[index-k]==0)
                {
                    cache.push_back(index-k);
                    mark[index-k]=1;
                }
                if(index-k-1>=0&&mark[index-k-1]==0)
                {
                    cache.push_back(index-k-1);
                    mark[index-k-1]=1;
                }
            }
            nums.push_back(sum);
        }
        for(auto arr:nums)
        {
            map<char,int> mp;
            for(int x:arr)
            {
                mp[a[x]]++;
                mp[b[x]]--;
            }
            for(auto p:mp)
            if(p.second!=0)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }