#include<bits/stdc++.h>
using namespace std;

void findPermute(vector<vector<int>>&ans,vector<int>&nums,int ind=0){
    if(ind==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[ind],nums[i]); // swap between possible indexes to find permutations
        findPermute(ans,nums,ind+1); // move to the next index
        swap(nums[ind],nums[i]); // backtracking step
    }
}


vector<vector<int>>permute(vector<int>&nums)
{
    vector<vector<int>>ans;
    findPermute(ans,nums);
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

    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    vector<vector<int>>ans;
    ans = permute(nums);
    for(auto it:ans)
    {
        for(auto it1:it)
            cout<<it1<<" ";
        cout<<"\n";
    }
    return 0;
}	
	
