    #include <iostream>
    #include <vector>
    #include <string>
    #include <map>
    #include <cmath>
    #include <algorithm>
    #include <set>
    #include <tuple>
    #include <queue>
    #include <iomanip>
    #include <numeric>
    #include <assert.h>
    #define int long long

    using namespace std;

    void compete_solution();
    signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
        cin >> t;
        for (int i = 0; i < t; ++i)
        {
            compete_solution();
        }
        return 0;
    }
    void debug(int n){
        cout<<n<<endl;
    }
    template <typename T>
    void print(const std::vector<T> &vec)
    {
        for (auto element : vec)
        {
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

    vector<int> cin_nums(int n)
    {
        vector<int> ans(n);
        for (auto &x : ans)
            cin >> x;
        return ans;
    }
    vector<vector<int>> cin_matrix(int n, int m)
    {
        vector<vector<int>> ans(n, vector<int>(m));
        for (auto &arr : ans)
        {
            for (int i = 0; i < m; ++i)
                cin >> arr[i];
        }
        return ans;
    }


    //严格小于n的最大2次幂的
    int cal(int n){
        for(int i=0;i<40;++i){
            int mask=1ll<<i;
            if(mask>=n){
                return i-1;
            }
        }
        return -1;
    }
    int mul4(int x){
        return 1ll<<(2ll*x);
    }
    int sp_cal(int rx,int ry){
        if(rx==ry){
            //3 ->
            return mul4(rx);
        }
        if(rx>ry){
            return 2ll*mul4(rx);
        }
        return 3ll*mul4(ry);
    }
    void compete_solution()
    {
        int n,q;
        cin >> n>>q;
        while(q--){
            string op;
            cin>>op;
            if(op=="->"){
                int x,y;
                cin>>x>>y;
                int ans=1;
                while(x!=1||y!=1){
                    int rx=cal(x);
                    int ry=cal(y);
                    if(rx>=ry&&rx!=-1)
                    x-=1ll<<rx;
                    if(ry>=rx&&ry!=-1)
                    y-=1ll<<ry;
                    ans+=sp_cal(rx,ry);
                }
                cout<<ans<<endl;
            }
            else{
                int val;
                cin>>val;
                val-=1ll;
                int x=1,y=1;
                for(int i=0;i<31&&val;++i){
                    int step=1ll<<(i);
                    
                    int rst=val%4ll;
                    val/=4ll;
                    if(rst==0){
                        continue;
                    }
                    if(rst==1){
                        x+=step;
                        y+=step;
                        continue;
                    }
                    if(rst==2){
                        x+=step;
                        continue;
                    }
                    if(rst==3){
                        y+=step;
                        continue;
                    }
                    

                }
                cout<<x<<" "<<y<<endl;
            }
        }

        
    }