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

// Backtracking -> Print One Answer/ Print all Answers
// When we need to perform one valid answers and our code has two recursive calls, if we get the valid answer 
// via the first recursive call , we won't perform the second recursive call and return the answer, if one return
// valid answer we won't explore further

// Pattern for printing one subsequence : 
// if(way1 == true) return true;
// if(way2 == true) return true;
// if(way3 == true) return true;
// return way4; will return true if way1,way2,way3 returns true else returns false
// Try all the ways and if there is no true returned then ultimately false is returned

bool subsequencesWithSumS(vector<int>&a,vector<int>&ds,int sum,int s=0,int ind=0)
{
	if(ind==a.size())
	{
		if(sum == s){
			for(auto it:ds)
				cout<<it<<" ";
			cout<<endl;
			return true;
		}
		else
			return false;
	}
	ds.push_back(a[ind]);
	s +=a[ind];
	if(subsequencesWithSumS(a,ds,sum,s,ind+1)==true) // if this gets a true i.e reaches a valid answer it won't move further and return true
		return true;
	s-=a[ind];
	ds.pop_back();
	return subsequencesWithSumS(a,ds,sum,s,ind+1);
}


int32_t main()
{
	
	FIO;
	#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
    #endif

	int n,sum;
	cin>>n>>sum;

	vector<int>a,ds;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}

	subsequencesWithSumS(a,ds,sum);
	return 0;
}

