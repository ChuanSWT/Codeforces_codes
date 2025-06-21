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



    class graphMeth
    {
    public:
        int n;
        vector<vector<int>> edges;
        vector<int> nums;
        // default
        graphMeth(int sz, vector<vector<int>> raw_edges) : edges(sz), n(sz)
        {
            for (auto edge : raw_edges)
            {
                edges[edge[0]].push_back(edge[1]);
                edges[edge[1]].push_back(edge[0]);
            }
        }
        // 点权
        graphMeth(int sz, vector<vector<int>> raw_edges, vector<int> vals) : edges(sz), n(sz), nums(vals)
        {
            for (auto edge : raw_edges)
            {
                edges[edge[0]].push_back(edge[1]);
                edges[edge[1]].push_back(edge[0]);
            }
        }
    };
    void compete_solution()
    {
        string s;
        cin>>s;
        int n=s.size();
        int a,b,ab,ba;
        cin>>a>>b>>ab>>ba;
        vector<int> mark(n,0);
        int A=0,B=0;
        int AB=0,BA=0,fitable=0;
        priority_queue<int> ABQ,BAQ;
        for(int i=0;i<s.size();++i){
            if(mark[i])
                continue;
            if(i!=n-1&&s[i]!=s[i+1]){
                string temp;
                temp+=s[i];
                mark[i]=1;
                for(int j=i+1;j<s.size();++j){
                    if(s[j]==s[j-1]){
                        break;
                    }
                    temp+=s[j];
                    mark[j]=1;
                }
                if(temp.size()%2==0){
                    if(temp[0]=='A'){
                        AB+=temp.size()/2;
                        ABQ.push(temp.size()/2);
                    }
                    else{
                        BA+=temp.size()/2;
                        BAQ.push(temp.size()/2);
                    }
                }
                else{
                    fitable+=temp.size()/2;
                    if(temp[0]=='A')
                        ++A;
                    else
                        ++B;
                }
            }
            else{
                if(s[i]=='A')
                    ++A;
                else
                    ++B;
            }
        }
        if(A>a||B>b){
            cout<<"NO"<<endl;
            return;
        }
        //cout<<A<<" "<<B<<endl;
        //cout<<AB<<" "<<BA<<" "<<fitable<<endl;
        //尝试分配固定的AB BA
        while(A<a&&B<b){
            //cout<<A<<" "<<B<<endl;
            //cout<<AB<<" "<<BA<<" "<<fitable<<endl;
            /*if(ABQ.top()>=BAQ.top()&&AB>ab){
                int val=ABQ.top();
                ABQ.pop();
                AB-=val;
                BAQ.push(val-1);
                BA+=val-1;
                ++A;
                ++B;
                --AB;
                continue;
            }
            if(BAQ.top()>=ABQ.top()&&BA>ba){
                int val=BAQ.top();
                BAQ.pop();
                BA-=val;
                ABQ.push(val-1);
                AB+=val-1;
                ++A;
                ++B;
                --BA;
                continue;
            }*/
            if(AB>ab){
                int val=ABQ.top();
                ABQ.pop();
                AB-=val;
                fitable+=val-1;
                ++A;
                ++B;
                continue;
            }
            if(BA>ba){
                int val=BAQ.top();
                BAQ.pop();
                BA-=val;
                fitable+=val-1;
                ++A;
                ++B;
                continue;
            }
            if(AB+BA+fitable>ab+ba){
                ++A;
                ++B;
                --fitable;
                continue;
            }
            break;
            
        }
        //cout<<A<<" "<<B<<endl;
        //cout<<AB<<" "<<BA<<" "<<fitable<<endl;
        if(AB<=ab&&BA<=ba&&AB+BA+fitable<=ab+ba){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
    }