#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define MOD 1000000007
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    int roundc;
    cin >> roundc;
    vector<int> ans;
    for (int ic = 0; ic < roundc; ++ic)
    {
        int n;
        cin>>n;
        vector<int> nums;
        for(int i=0;i<n;++i)//熊孩子搞破坏前的数组
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        vector<int> left;
        for(int i=1;i<nums.size();++i)
        {
        left.push_back(gcd(nums[i-1],nums[i]));
        //cout<<gcd(nums[i-1],nums[i])<<" ";//
        }
        //cout<<endl;//
        vector<int> diff;
        for(int i=1;i<left.size();++i)
        if(left[i-1]>left[i])
        {
        diff.push_back(i-1);
        //cout<<"diff "<<i-1<<endl;//
        }
        if(diff.size()>=5)
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool safe=false;
        if(diff.size()==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0;i<diff.size();++i)
        {
            int j=diff[i]-1;
            if(j<=0)
            j=0;
            for(;j<diff[i]+4&&j<nums.size()&&j>=0;++j)
            //for(int j=0;j<nums.size();++j)
            {
            vector<int> temp;
            for(int k=0;k<nums.size();++k)
            if(k!=j)
            temp.push_back(nums[k]);
            vector<int> newleft;
            for(int i=1;i<temp.size();++i)
                newleft.push_back(gcd(temp[i-1],temp[i]));
            /*for(int n:diff)
            cout<<n<<" ";
            cout<<endl;*/
            bool sure=true;
            for(int j=1;j<newleft.size();++j)
            {
                if(newleft[j-1]>newleft[j])
                {
                    sure=false;
                    break;
                }
            }
            if(sure)
            safe=true;
            }
            if(safe)
            break;
        }
        if(safe)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}