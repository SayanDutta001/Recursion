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

void subsequenceSumEqualsK(vector<int>&a,vector<int>&ds,int k,int sum=0,int ind=0)
{
	if(ind==a.size())
	{
			if(sum==k)
			{
				for(auto it:ds)
					cout<<it<<" ";
				cout<<"\n";
			}
			return;
	}

  // pick the array[ind] and add it to the sum varaible
	ds.push_back(a[ind]);
	subsequenceSumEqualsK(a,ds,k,sum+a[ind],ind+1);
  
  // don't pick the array[ind] and let the sum be as it is, no update
	ds.pop_back();
	subsequenceSumEqualsK(a,ds,k,sum,ind+1);
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
	
	vector<int>a,d;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	subsequenceSumEqualsK(a,d,k);
  return 0;
}

