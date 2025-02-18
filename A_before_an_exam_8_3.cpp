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
        int n,time;
        cin>>n>>time;
        long long minv=0;
        long long maxv=0;
        vector<vector<int>> days(n,vector<int>(2));
        for(auto &arr:days)
        {
            cin>>arr[0]>>arr[1];
            minv+=arr[0];
            maxv+=arr[1];
        }
        if(minv>time||maxv<time)
        {
            cout<<"NO"<<endl;
            return;
        }
        vector<int> ans(n);
        for(int i=0;i<ans.size();++i)
        ans[i]=days[i][0];
        int left=time-minv;
        for(int i=0;i<ans.size();++i)
        {
            if(days[i][1]-days[i][0]>=left)
            {
                ans[i]+=left;
                cout<<"YES"<<endl;
                print(ans);
                return;
            }
            else
            {
                ans[i]=days[i][1];
                left-=days[i][1]-days[i][0];
            }
        }
        cout<<"NO"<<endl;
    }