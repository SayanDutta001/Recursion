#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> 
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// Recursion Rule : 
// 1. Convert to a indexed based problem 
// 2. Start with Indexes
// 3. Analyse what to do in that index -> can be a part (pick)/ not be a part(non-pick)
// 4. Move to next index


// arr[] = {3,1,2}
// SubArrays -> Order follow and contigious eg: {3},{3,1},{3,1,2},{1},{1,2},{2}
// Subsequences - > Order Follow and non contigious eg: {},{2},{1},{1,2},{3},{3,2},{3,1},{3,1,2}
// Subsets -> order follow/ non order follow depends on the question

// use set when the subsequences are needed to be passes in a lexographical order else we can just print the contents if ds when i == a.size()
// note: pass set s,vector ds via reference else nothing will be stored(there's gonna be an overhead) since each function call will contain different sets and vectors

// printing subsequences 
// Method 1:  
set<vector<int>> subsetsGeneration(vector<int>&a,vector<int>&ds,set<vector<int>>&s,int i=0) // TC : O(2^N), SC:O(N)
{
	if(i==a.size())
	{
		s.insert(ds);
		return s;
	}
	
	// pick the item
	ds.push_back(a[i]); 
	subsetsGeneration(a,ds,s,i+1);
	
	// to unpick the item 
	ds.pop_back(); // back-tracking step
	subsetsGeneration(a,ds,s,i+1);
	return s;
}

// Method 2:
// whenever there is a function call, print the subsequence

void printSubsequences(vector<int>a,vector<int>&d,int ind=0) // TC: O(2^N*N)
{
	// rule 1: whenever there is a funtion call print the subsequence
	for(auto it:d) 	cout<<it<<" ";
	cout<<"\n";
	
	// rule 2: pick every index once and store that in d from ind to n-1(a.size()-1)
	for(int i=ind;i<a.size();i++) // the base case is handled by the loop
	{
		d.push_back(a[i]);
		printSubsequences(a,d,i+1);
		d.pop_back();
	} 
}

int32_t main()
{
	
	FIO;
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif

	int n;
	cin>>n;
	
	vector<int>a,ds,d;
	set<vector<int>>si;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	subsetsGeneration(a,ds,si);
	for(auto it:si)
	{
		for(auto it1:it)
			cout<<it1<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	printSubsequences(a,d);
    return 0;
}

