#include<bits/stdc++.h>
using namespace std;

// TC:O((target/min(candidates[i]))^candidates.size())*k)
// SC:O(target/min(candidates[i]))
void sum(vector<int>&candidates,vector<int>&ds,vector<vector<int>>&store,int s,int ind=0) 
{
    if(s==0)
    {
        store.push_back(ds);
        return;
    }
    for(int i=ind;i<candidates.size();i++)
    {
        if(i>ind and candidates[i]==candidates[i-1])
            continue;
        if(candidates[i]>s)
            break;
        ds.push_back(candidates[i]);
        sum(candidates,ds,store,s-candidates[i],i+1);
        ds.pop_back();
    }
}

    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    vector<vector<int>>store;
    vector<int>ds;
    sort(candidates.begin(),candidates.end());
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
    s = combinationSum2(a,sum);
    for(auto it:s){
            for(auto it1:it)
                cout<<it1<<" ";
            cout<<endl;
        }return 0;

    return 0;
}	
	
