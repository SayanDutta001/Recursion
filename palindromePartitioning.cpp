#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int start,int end)
{
    while(start<end)
    {
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}

void part(string s,vector<vector<string>>&ans,vector<string>&temp,int ind = 0)
{
    if(ind==s.size())
    {
        ans.push_back(temp);
        return;
    }

    for(int i=ind;i<s.size();i++)
    {
        if(isPalindrome(s,ind,i))
        {
            temp.push_back(s.substr(ind,i-ind+1));
            part(s,ans,temp,i+1);
            temp.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>>ans;
    vector<string>temp;
    part(s,ans,temp);
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
	// for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
    #endif

    string s;
    cin>>s;

    vector<vector<string>>ans;
    ans = partition(s);

    if(!ans.empty())
    {
        for(auto it:ans)
        {
            cout<<'{';
            for(auto it1:it)
                cout<<it1<<' ';
            cout<<'}';
            cout<<endl;
        }
    }
    return 0;
}	
	
