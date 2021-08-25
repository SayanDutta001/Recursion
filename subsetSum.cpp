#include<bits/stdc++.h>
using namespace std;

void findSum(vector<int>&arr,vector<int>&ans,int sum=0,int ind=0)
{
    if(ind==arr.size())
    {
        ans.push_back(sum);
        return;
    }
        
    findSum(arr,ans,sum+arr[ind],ind+1);
    findSum(arr,ans,sum,ind+1);
    return;
}

vector<int> subsetSums(vector<int>&arr, int N)
{
    // Write Your Code here
    vector<int>ans;
    findSum(arr,ans);
    sort(ans.begin(),ans.end());
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
    vector<int>ans;
    ans = subsetSums(arr,n);
    for(auto it:ans)
        cout<<it<<"\n";
    return 0;
}	
	
