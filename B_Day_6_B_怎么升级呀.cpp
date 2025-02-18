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
        int n,m;
        cin>>n>>m;
        deque<int> nums(m);
        for(int i=0;i<nums.size();++i)
        nums[i]=i+1;
        vector<int> q;
        if(m%2==0)
        {

            deque<int> temp=nums;
            while(!temp.empty())
            {
                q.push_back(temp.back());
                q.push_back(temp.front());
                temp.pop_back();
                temp.pop_front();
            }
        }
        else
        {
            deque<int> temp=nums;
            while(temp.size()>1)
            {
                q.push_back(temp.back());
                q.push_back(temp.front());
                temp.pop_back();
                temp.pop_front();
            }
            q.push_back(temp[0]);
        }
        reverse(q.begin(),q.end());
        for(int i=0;i<n;++i)
        {
            cout<<q[i%q.size()]<<endl;
        }
        
        

        
    }