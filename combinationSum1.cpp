#include<bits/stdc++.h>
using namespace std;

void sum(vector<int>&candidates,vector<int>&ds,vector<vector<int>>&store,int s,int ind=0) 
// TC: O(max(sum/a[i])^n)
// SC:O(max(sum/a[i]))
{
    if(ind==candidates.size()){
        if(s==0)
            store.push_back(ds);
        return;
    }
    
    if(candidates[ind]<=s)
    {
        s-=candidates[ind];
        ds.push_back(candidates[ind]);
        sum(candidates,ds,store,s,ind);
        s+=candidates[ind];
        ds.pop_back();
    }

    sum(candidates,ds,store,s,ind+1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>>store;
    vector<int>ds;
    sum(candidates,ds,store,target);
    return store;
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

    int n,sum;
    cin>>n>>sum;

    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    vector<vector<int>>s;
    s = combinationSum(a,sum);
    for(auto it:s){
            for(auto it1:it)
                cout<<it1<<" ";
            cout<<endl;
        }return 0;
}	
	
