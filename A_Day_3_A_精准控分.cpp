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
    class trie
{
public:
	struct node
	{
		bool isEnd;
		vector<node*> child;
		node():child(26,nullptr),isEnd(false)
		{
		}
	};
	node* root;
	trie()
	{
		root = new node();
	}
	bool insert(string s)
	{
		node* cur = root;
		for (char c : s)
		{
			if (cur->child[c - 'a'] == nullptr)
				cur->child[c - 'a'] = new node();
			cur = cur->child[c - 'a'];
		}
		if (cur->isEnd)
			return false;
		cur->isEnd = true;
		return true;
	}
	bool find(string s)
	{
		node* cur = root;
		for (char c : s)
		{
			if (cur->child[c - 'a'] == nullptr)
				return false;
			cur = cur->child[c - 'a'];
		}
		if (cur->isEnd)
			return true;
		else
			return false;
	}
};
    class unionfind
    {
        public:
        vector<int> f,rank;
        int n;
        unionfind(int num):n(num),rank(num,1),f(num)
        {
            for(int i=0;i<n;++i)
            f[i]=i;
        }
        int find(int x)
        {
            //尝试寻找父节点
            if(f[x]==x)
                return x;
            else
                return find(f[x]);
        }
        void link(int x,int y)
        {
            int fx=find(x);
            int fy=find(y);
            //已经链接
            if(fx==fy)
            return;
            //确保fx的rank比fy的大
            //rank值可能为其子节点个数，做优化考虑
            if(rank[fx]<rank[fy])
            swap(fx,fy);
            rank[fx]+=rank[fy];
            f[fy]=fx;
            
        }
    };
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
        int n,k;
        cin>>n>>k;
        if(n*2>k)
        {
            cout<<0<<endl;
            return;
        }
        if(n*3<k)
        {
            cout<<0<<endl;
            return;
        }
        cout<<n*3-k<<endl;
        
        

        
    }