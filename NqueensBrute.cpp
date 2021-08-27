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
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());     

bool isSafe(int row,int col,int n,vector<string>&board)
{
    int dupRow = row;
    int dupCol = col;

    while(row>=0 and col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while(col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;
    while(row<n and col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void findPos(vector<vector<string>>&ans,vector<string>&board,int n,int col=0)
{
    if(col==n)
    {
        ans.push_back(board);
        return;       
    }
    for(int row = 0;row<n;row++)
    {
        if(isSafe(row,col,n,board))
        {
            board[row][col]='Q';
            findPos(ans,board,n,col+1);
            board[row][col]='.';
        }
    }
}

vector<vector<string>>nQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>board;
    string s(n,'.');
    for(int i=0;i<n;i++)
        board.push_back(s);
    findPos(ans,board,n);
    return ans;
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
    vector<vector<string>>s;
    s = nQueens(n);
    if(!s.empty())
    {
        for(auto it:s)
        {
            for(auto it1:it){
                {
                    for(auto it2:it1)
                        cout<<it2<<" ";
                }
            cout<<"\n";}
            cout<<"\n";
        }
    }
    else
        cout<<"No possible way of placing "<<n<<" Queens\n";
    return 0;
}	
	
