//ChuanSWT is looking at you
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
    #include<numeric>
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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> a_arr(n);
        vector<int> b_arr(n);
        for(auto&x:a_arr)
        cin>>x;
        for(auto&x:b_arr)
        cin>>x;
        //每次操作下，你可以将a数组中每个元素-1
        //若元素已经为0，则操作对这个元素不起作用
        set<int> st;
        int maxv=0;
        for(int i=0;i<n;++i)
        {
            if(a_arr[i]<b_arr[i])
            {
                cout<<"NO"<<endl;
                return;
            }
            if(b_arr[i]==0)
            {
                maxv=max(maxv,a_arr[i]);
            }
            else
            st.insert(a_arr[i]-b_arr[i]);

        }
        if(st.size()>=2)
        {
            cout<<"NO"<<endl;
            return;
        }
        if(st.size()==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        int op=*st.begin();
        if(op>=maxv)
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }


        
    }