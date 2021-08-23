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

int countPathsInAMatrix(vector<vector<int>>&a,int i=0,int j=0) // only right down movement allowed
{
	// return 0 if we cross the boundary or move towards a blocked cell
	if(i>=a[0].size() || j>=a.size() ||a[i][j] == 1) 
		return 0;

	// return 1 if we reach the destination
	if(i==a[0].size()-1 and j==a.size()-1)
		return 1;

	int right = countPathsInAMatrix(a,i,j+1); // move right i.e across the column
	int left = countPathsInAMatrix(a,i+1,j); // move down i.e across the rows
	return left + right; // sum of count of paths possible
}

void printPathsInAMatrix(vector<vector<int>>&a,string osf="",int i=0,int j=0)
{
	if(i>=a[0].size() || j>=a.size() ||a[i][j] == 1)
		return;
	if(i==a[0].size()-1 and j==a.size()-1)
		cout<<osf<<"\n";

	printPathsInAMatrix(a,osf+'R',i,j+1);
	printPathsInAMatrix(a,osf+'D',i+1,j);
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
	vector<vector<int>>a(n,vector<int>(n,0));	
	a[1][1]=1; // blocked cell
	cout<<"Number of possible Paths: "<<countPathsInAMatrix(a)<<"\n";

	cout<<"The Paths are: \n";
	printPathsInAMatrix(a);
    return 0;
}

