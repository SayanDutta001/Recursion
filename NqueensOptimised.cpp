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

void findPos(vector<vector<string>>&ans,vector<string>&board,int n,vector<int>&currentRow,
    vector<int>&leftLowerDiagonal,vector<int>&leftUpperDiagonal,int col=0)
{
    if(col==n)
    {
        ans.push_back(board);
        return;       
    }
    for(int row = 0;row<n;row++)
    {   
        // if there are no queen placed in the current row, or the diagonals doesn't contain any queen then we can place a queen in the current position 
        if(currentRow[row]==0 and leftLowerDiagonal[row + col]==0 and leftUpperDiagonal[n - 1 + col - row]==0) 
        {
            board[row][col] = 'Q'; // mark the position of the queen as Q
            currentRow[row] = 1; // mark the presence of a queen at the current row
            leftLowerDiagonal[row + col] = 1; // mark the presence of diagonals it can affect 
            leftUpperDiagonal[n - 1 + col - row] = 1; 
            findPos(ans,board,n,currentRow,leftLowerDiagonal,leftUpperDiagonal,col+1); // jump to next recursion
            board[row][col] = '.'; // backtracking step
            currentRow[row] = 0;
            leftLowerDiagonal[row + col] = 0;
            leftUpperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>>nQueens(int n)
{
    vector<vector<string>>ans; // to store the possible permutations of placing the queens
    vector<string>board; // the board where the queen needs to be placed
    string s(n,'.'); 
    for(int i=0;i<n;i++)
        board.push_back(s); // filling the board with '.' which means the position is empty

    vector<int>currentRow(n,0); //used for hashing if there's already a queen placed in the current row
    vector<int>leftUpperDiagonal(2*n-1,0); // used for hasing if there's already a queen placed the left Upper Diagonal
    vector<int>leftLowerDiagonal(2*n-1,0); // used for hashing if there's alerady a queen placed in the left lower diagonal
    findPos(ans,board,n,currentRow,leftLowerDiagonal,leftUpperDiagonal);
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
	
