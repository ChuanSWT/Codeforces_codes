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

int cal(vector<int> nums,int k){
    sort(nums.rbegin(),nums.rend());
    int sum=0;
    for(int i=0;i<k;++i){
        sum+=nums[i];
    }
    return sum;
}


void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<int> nums=cin_nums(n);
    if(k==1){
        if(nums.size()==2){
            cout<<nums[0]+nums[1]<<endl;
            return;
        }
        cout<<max({*max_element(nums.begin()+1,nums.end()-1)+nums[0],*max_element(nums.begin()+1,nums.end()-1)+nums.back(),nums[0]+nums.back()})<<endl;
        return ;
    }
    sort(nums.rbegin(),nums.rend());
    int sum=0;
    for(int i=0;i<=k;++i){
        sum+=nums[i];
    }
    cout<<sum<<endl;
    //If a red element has two blue neighbours, you can paint it blue.
    //需要有两个邻居

    //数组较小 
    //难道是当k==1？

    //区间 维护堆
    //除了指定区间内次小值 还可以指定两端
    /*int ans=0;
    for(int i=0;i<nums.size();++i){
        int sum=0;
        set<int> st;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        int minv=0;
        for(int j=i;j<nums.size();++j){
            sum+=nums[j];
            st.insert(j);
            pq.push({nums[j],j});
            if(pq.size()>k){
                vector<int> arr=pq.top();
                pq.pop();
                sum-=arr[0];
                st.erase(arr[1]);
                minv=max(minv,arr[0]);
            }
            int rst1=sum+minv;
            int rst2=-1;
            int rst3=-1;
            if(!st.count(0)){
                rst2=sum+nums[0];
            }
            if(!st.count(n-1)){
                rst3=sum+nums.back();
            }
            ans=max({ans,rst1,rst2,rst3});
        }
    }
    cout<<ans<<endl;*/
    //会不会是分类讨论
    /*vector<int> nums1=nums;
    //选头
    vector<int> nums2=nums;
    nums2.pop_back();
    //选尾
    vector<int> nums3=nums;
    nums3.erase(nums3.begin());
    //都不选
    vector<int> nums4=nums;
    nums4.erase(nums4.begin());
    nums4.pop_back();
    int ans=max(cal())*/
    /*if(k==1){
        if(nums.size()==2){
            cout<<nums[0]+nums[1]<<endl;
            return;
        }
        cout<<max({*max_element(nums.begin()+1,nums.end()-1)+nums[0],*max_element(nums.begin()+1,nums.end()-1)+nums.back(),nums[0]+nums.back()})<<endl;
        return ;
    }
    int ans=0;
    //指定两端
    vector<vector<int>> fuckyou(n,vector<int>(n,0));
    vector<vector<int>> fuckyou_too(n,vector<int>(n,0));
    for(int i=1;i<nums.size();++i){
        int sum=0;
        multiset<int> mst;
        for(int j=i;j+1<nums.size();++j){
            sum+=nums[j];
            mst.insert(nums[j]);
            if(mst.size()>k-1){
                auto p=mst.begin();
                sum-=*p;
                mst.erase(p);
            }
            fuckyou[i][j]=sum;
            fuckyou_too[i][j]=sum-*mst.begin();
        }
    }
    //for(auto arr:fuckyou)
    //    print(arr);
    for(int i=0;i<nums.size();++i){
        for(int j=i+1;j<nums.size();++j){
            ans=max(ans,nums[i]+nums[j]+fuckyou[i+1][j-1]);
            if(i!=0){
                ans=max(ans,nums[i]+nums[j]+fuckyou_too[i+1][j-1]+nums[0]);
            }
            if(i!=n-1){
                ans=max(ans,nums[i]+nums[j]+fuckyou_too[i+1][j-1]+nums.back());
            }
        }
    }
    cout<<ans<<endl;*/
    //不会又°假了把

    /*vector<vector<int>> s_arr;
    for(int i=0;i<nums.size();++i){
        s_arr.push_back({nums[i],i});
    }
    sort(s_arr.rbegin(),s_arr.rend());
    int sum=0;
    map<int,int> mp;
    int least_idx=-1;
    for(int i=0;i<k;++i){
        sum+=s_arr[i][0];
        ++mp[s_arr[i][0]];
        least_idx=s_arr[i][1];
    }
    map<int,int> tot_mp;
    for(int x:nums){
        ++tot_mp[x];
    }
    int least_val=nums[least_idx];
    if(tot_mp[least_val]==mp[least_val]||true){
        int maxv=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==least_val){
                if(i!=0&&nums[i-1]<least_val){
                    maxv=max(maxv,nums[i-1]);
                }
                if(i!=n-1&nums[i+1]<least_val){
                    maxv=max(maxv,nums[i+1]);
                }
            }
        }
        cout<<sum+maxv<<endl;
        return;
    }
    */
    /*int ans=0;
    for(int i=1;i+1<nums.size();++i){
        vector<int> nums1;
        for(int j=0;j<i;++j){
            nums1.push_back(nums[j]);
        }
        vector<int> nums2;
        for(int j=i+1;j<nums.size();++j){
            nums2.push_back(nums[j]);
        }
        sort(nums1.rbegin(),nums1.rend());
        sort(nums2.rbegin(),nums2.rend());
        while(nums1.size()>k){
            nums1.pop_back();
        }
        int sum=accumulate(nums1.begin(),nums1.end(),0ll);
        int index=0;
        while(nums1.size()&&index<nums2.size()){
            sum-=nums1.back();
            sum+=nums2[index];
            ++index;
            ans=max(ans,sum);
        }
    }
    vector<int> nums1=nums;
    nums1.pop_back();
    sort(nums1.rbegin(),nums1.rend());
    int sum=0;
    for(int i=0;i<k;++i){
        sum+=nums1[i];
    }
    ans=max(ans,sum+nums.back());
    vector<int> nums2=nums;
    nums2.erase(nums2.begin());
    sort(nums2.rbegin(),nums2.rend());
    sum=0;
    for(int i=0;i<k;++i){
        sum+=nums2[i];
    }
    ans=max(ans,sum+nums[0]);
    cout<<ans<<endl;*/
}