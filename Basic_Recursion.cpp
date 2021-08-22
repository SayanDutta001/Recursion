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

void fun1(int n) // Bottom - Up
{
	if(n==0)
		return;
	fun1(n-1);
	cout<<n<<"\n";
} 

void fun2(int n) // Top Down
{
	if(n==0)
		return;
	cout<<n<<"\n";
	fun2(n-1);
}

void fun3(int n)
{
	if(n==0)
		return;
	cout<<n<<"\n";
	fun3(n-1);
	cout<<n<<"\n";
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
	
	cout<<"Executing fun1\n";
	fun1(n);
	cout<<"\nExecuting fun2\n";
	fun2(n);
	cout<<"\nExecuting fun3\n";
	fun3(n);
    return 0;
}

