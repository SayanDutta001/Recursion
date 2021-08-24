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

// Rat In A Maze
// TC:O(8^n*m) for 8 directions, SC:O(n*m)
// Explanation: 
// if we move across any cell that is blocked we return and move to the next recursive call so on and so forth
// we come acorss a valid path we print it

// pseudo code:
// printPaths(arr[][],vis[][],i,j,str)
// if(i<0||j<0||i>=n||j>=m||vis[i][j]==1||arr[1][j]==1) blocked,visited, out of bound -> siimply return
// 		return;
// if(i==n-1 and j==m-1) // target reached print str and return
//		cout<<s<<"\n";return;
// vis[i][j]=1;
// printPaths(arr,vis,i,j+1,str+'R') // move right
// printPaths(arr,vis,i+1,j,str+'D') // move down
// printPaths(arr,vis,i,j-1,str+'L') // move left
// printPaths(arr,vis,i-1,j,str+'U') // move up
// vis[i][j]=0; // to stop getting trapped in an infinite loop, backtracking process



int di[]={0,1,0,-1,1,-1,-1,1};
int dj[]={1,0,-1,0,-1,-1,1,1};
string dir = "RDLUrdlu"; 
// R -> Right, D -> Down, L->Left, U -> Up
// r ->Left Lower Diagonal, d->Left Upper Diagonal, l -> Right Upper Diagonal, u-> Right Lower Diagonal

// 1.print multiple paths
void printPaths(vector<vector<int>>&arr,vector<vector<int>>&vis,int n,vector<string>&store,int i=0,int j=0,string osf="")
{
    if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==1 || arr[i][j]==0)
   		return;
   	if(i==arr.size()-1 and j==arr[0].size()-1)
   	{
   		store.push_back(osf);
       	return ;
   	}
   	vis[i][j]=1; // to mark the cell visited 

	for(int k=0;k<8;k++)
	{
		printPaths(arr,vis,n,store,i+di[k],j+dj[k],osf+dir[k]);
	}
        
    vis[i][j]=0; // unmark the cell
    return;
}

// 2. print only one path
bool printOnePath(vector<vector<int>>&arr,vector<vector<int>>&vis,int n,vector<string>&store,int i=0,int j=0,string osf="")
{
    if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==1 || arr[i][j]==0)
   		return false;
   	if(i==arr.size()-1 and j==arr[0].size()-1)
   	{
   		store.push_back(osf);
       	return true;
   	}
   	vis[i][j]=1; // to mark the cell visited 

	for(int k=0;k<8;k++)
	{
		if(printPaths(arr,vis,n,store,i+di[k],j+dj[k],osf+dir[k]))
			return true;
	}
        
    vis[i][j]=0; // unmark the cell
    return false;
}

// 3. to print the ouput in lexicographical order:
// Method 1: store the paths in a set
// Method 2: Lexicographically Recursive Calls
// The lexicographical order of recursive call : 
// printPaths(arr,vis,i+1,j,str+'D') // move down
// printPaths(arr,vis,i,j-1,str+'L') // move left
// printPaths(arr,vis,i,j+1,str+'R') // move right
// printPaths(arr,vis,i-1,j,str+'U') // move up

vector<string> findPath(vector<vector<int>> &m, int n) 
{
    // Your code goes here
    vector<string>store; // to store the paths
    vector<vector<int>>vis(n,vector<int>(n,0)); // visited matrix to check the cells if we have visited it to tackle infinite loops
    printPaths(m,vis,n,store);
    sort(store.begin(), store.end());
    return store;
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
	vector<vector<int>>m;
	for(int i=0;i<n;i++)
	{
		vector<int>temp;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		m.push_back(temp);
		temp.clear();
	}
	
	vector<string>sto;
	sto=findPath(m,n);
	if(!sto.empty())
	{
		for(auto it:sto)
			cout<<it<<"\n";
	}
	else
		cout<<-1;
	return 0;
}
