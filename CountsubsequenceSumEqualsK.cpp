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

int CountsubsequenceSumEqualsK(vector<int>&a,int k,int sum=0,int ind=0) // TC: O(2^N), SC: O(N)
{
	if(ind==a.size()) // when there are no further elements to pick 
			return (sum==k); // return 1 if we have a subsequence sum equals k else returns 0

	return CountsubsequenceSumEqualsK(a,k,sum+a[ind],ind+1) 	+          CountsubsequenceSumEqualsK(a,k,sum,ind+1);
	//	   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^				   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	// 			PICK AN ELEMENT AND UPDATE THE SUM  							 NON PICK AND NO UPDATE TO SUM
}

int32_t main()
{
	
	FIO;
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif

	int n,k;
	cin>>n>>k;
	
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<CountsubsequenceSumEqualsK(a,k);
    return 0;
}

