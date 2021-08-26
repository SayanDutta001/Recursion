#include<bits/stdc++.h>
using namespace std;

void findPermute(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,unordered_map<int,int>&visited){
    if(temp.size()==nums.size()) // store the permutation in the ans vector only when the permutation is equal to the size of the nums array
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++) // pick every index from 0 to num.size()-1
    {
        if(visited.find(nums[i])==visited.end()) // but pick only if it is unpicked before
        {
            temp.push_back(nums[i]); // pick the element
            visited[(nums[i])]; // to mark the presence of it being picked before, we store it in a map
            findPermute(ans,temp,nums,visited); // call for the next element of the permuatation
            visited.erase(nums[i]); // backtracking step where we unmark the presence of the number being visited
            temp.pop_back(); // we pop out the lastly inserted number
        }
    }
}


vector<vector<int>>permute(vector<int>&nums)
{
    vector<vector<int>>ans; // store the ans
    vector<int>temp; // store the permutation temporarily
    unordered_map<int,int>visited; // to check the presence of the digit in the permutation
    findPermute(ans,temp,nums,visited);
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
	
