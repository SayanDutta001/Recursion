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

// We need to fill each row and each column with exactly one queen and in a way that no two queens attack each other
// Approach would be to place every queen columnwise by making sure of certain conditions.

bool isSafe(int row,int col,int n,vector<string>&board)
{
    int dupRow = row;
    int dupCol = col;

    // since we are placing every queen columnwise, so checking in the right directions, upper, lower directions doesn't make any sense
    // because the columns right to the current column would be only be filled once the current column is filled.
    // Instead we only need to check the current row, the left upper diagonal and the left lower diagonal


    // check for left upper diagonal
    while(row>=0 and col>=0)
    {
        // if at any instance we find there's a Queen in the diagonal we return false, i.e the current column isn't safe
        if(board[row][col]=='Q') 
            return false;

        // left upper diagonal means moving backward both in terms of row and column
        row--; 
        col--;
    }

    // restoring the previous values of row and col, since during the check the row and column values would be exhausted
    row = dupRow; 
    col = dupCol;

    // check for the current row
    while(col>=0)
    {
        if(board[row][col]=='Q')
            return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    // check for the left lower diagonal
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
        if(isSafe(row,col,n,board)) // if the column is a safe one we place a queen
        {
            board[row][col]='Q'; // Mark the empty position to mean the queen is placed
            findPos(ans,board,n,col+1); // move to next column if the current one is filled
            board[row][col]='.'; // backtracking step
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
	
