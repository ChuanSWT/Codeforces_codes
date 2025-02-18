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
        int n;
        cin>>n;
        //left最大值，right最小值
        vector<int> left(n,0),right(n,0);
        vector<char> ops(n);
        for(int i=0;i<n;++i)
        {
            cin>>ops[i];
            cin>>left[i];
            cin>>right[i];
        }
        map<int,int> left_c,right_c;
        for(int i=0;i<left.size();++i)
        {
            //cout<<i<<endl;
            int a;
            int b;
            a=left[i];
            b=right[i];
            if(ops[i]=='+')
            {
                
                left_c[a]++;
                right_c[b]++;
            }
            else
            {
                left_c[a]--;
                if(left_c[a]==0)
                left_c.erase(a);
                right_c[b]--;
                if(right_c[b]==0)
                right_c.erase(b);
            }
            if(left_c.empty())
            {
                cout<<"NO"<<endl;
                continue;
            }
            int left_max=left_c.rbegin()->first;
            int left_min=left_c.begin()->first;
            int right_max=right_c.rbegin()->first;
            int right_min=right_c.begin()->first;
            if(right_min<left_max)
            {
                cout<<"YES"<<endl;

            }
            else
            {
                cout<<"NO"<<endl;
            }
        }


        

        
    }