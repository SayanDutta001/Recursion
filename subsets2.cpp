#include<bits/stdc++.h>
using namespace std;

void findSubset(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans,int ind=0)
{
    ans.push_back(temp);
    for(int i=ind;i<nums.size();i++)
    {
        if(i>ind && nums[i]==nums[i-1])
            continue;
        temp.push_back(nums[i]);
        findSubset(nums,temp,ans,i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>temp;
    findSubset(nums,temp,ans);
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
	// for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
    #endif

    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<vector<int>>ans;
    ans = subsets(arr);
    for(auto it:ans){
        for(auto it1:it)
            cout<<it1<<' ';
        cout<<"\n";
    }
    return 0;
}	
	
