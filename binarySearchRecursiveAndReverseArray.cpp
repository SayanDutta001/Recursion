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

int bs(vector<int>&a,int lo,int hi,int key)
{
	if(lo>hi)
		return -1;
	int mid = lo + (hi-lo)/2;
	if(a[mid]==key)
		return mid;
	else if(a[mid]>key)
		return bs(a,lo,mid-1,key);
	else
		return bs(a,mid+1,hi,key);
}

void reverse(vector<int>&a,int lo) //TC -> O(N/2), SC -> O(N/2)
{
	if(lo>a.size()/2)
		return;
	swap(a[lo],a[a.size()-lo-1]);
	reverse(a,lo+1);
	return;
}

int32_t main()
{
	
	FIO;
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif

	int n,key;
	cin>>n>>key;

	vector<int>a,ds;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	
	cout<<"The index is: "<<bs(a,0,a.size()-1,key)<<"\n";
	
	reverse(a,0);
	cout<<"Reversed Array: \n";
	for(auto it:a)
		cout<<it<<" ";	
	return 0;
}

