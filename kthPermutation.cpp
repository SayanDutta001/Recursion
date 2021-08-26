#include<bits/stdc++.h>
using namespace std;

string kthPermutation(int n,int k)
{
    vector<int>nums;
    int fact = 1; // the factorial of nums.size()-1 
    k--; // for zero based indexing
    for(int i=1;i<n;i++) // 
    {
        fact*=i;
        nums.push_back(i);
    }
    nums.push_back(n); // storing all the numbers from 1 to n in nums

    string ans; // to store the ans
    while(nums.size()!=1)
    {
        ans+=(to_string(nums[k/fact])); // find out the group and append the starting element
        nums.erase(nums.begin()+ k/fact); // remove the element from the nums to since one digit can occur only once
        k%=fact; // update since k will no longer be in the previous range
        fact/=nums.size(); // update fact to move to the next group which is reqd. for the next digit
    }
    ans+=to_string(nums[0]);
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

    int n,k;
    cin>>n>>k;

    string ans;
    ans = kthPermutation(n,k);
    cout<<ans;
    return 0;
}	
	
