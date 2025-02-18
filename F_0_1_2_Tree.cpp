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
    bool check_ok(int a,int b,int c)
    {
        int sum=1;
        sum+=a;
        sum-=c;
        return sum==0;
    }
    void compete_solution()
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(!check_ok(a,b,c))
        {
            cout<<-1<<endl;
            return ;
        }        
        if(a==0)
        {
            cout<<b+c-1<<endl;
            return;
        }
        priority_queue<int,vector<int>,greater<>> pq;//当前空缺的子节点
        int maxv=0;
        pq.push(1);
        pq.push(1);
        --a;
        while(a)
        {
            int val=pq.top();
            pq.pop();
            maxv=max(maxv,val+1);
            pq.push(val+1);
            pq.push(val+1);
            --a;
        }
        while(b)
        {
            int val=pq.top();
            pq.pop();
            maxv=max(maxv,val+1);
            pq.push(val+1);
            --b;
        }
        while(!pq.empty())
        {
            maxv=max(maxv,pq.top());
            pq.pop();
        }
        cout<<maxv<<endl;


        
        

        
    }