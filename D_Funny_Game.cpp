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
        vector<int> left(2001);
        vector<int> right(2001);
        vector<int> nums(2001,0);
        for(int i=1;i<=n;++i)
        cin>>nums[i];
        vector<int> life(2001,0);//表示仍然可以选取
        for(int i=1;i<=n;++i)
        life[i]=1;    
        vector<int> mark(1999);//存储模数



        for(int x=n-1;x>0;--x)//反向 //不包含最后一个点！
        {
            //所有mark置为0
            for(int i=0;i<n;++i)mark[i]=0;

            //正向 //可以选取最后一个点
            for(int i=1;i<=n;++i)
            {
                if(life[i]==0)
                continue;
                //temp:当前节点的模
                int temp=nums[i]%x;

                if(mark[temp])//模位存在 //对应到节点
                {
                    //连接
                    left[x]=mark[temp];
                    right[x]=i;
                    //清除其中一个节点
                    life[i]=0;
                    break;
                }
                else
                mark[temp]=i;
            }
            

        }
            cout<<"YES"<<endl;
            for(int i=1;i<n;++i)
            cout<<left[i]<<" "<<right[i]<<endl;
        //鸽笼原理
        //总体来说，利用了鸽笼原理进行无顾虑的排除

        //--可以证明一定成功
        

        
    }