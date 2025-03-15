#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline "\n"
int a[1005];
int dp[1005][1005];
bool subset_sum(int i, int sum)
{
    if(i < 0){
        if(sum == 0) return true;
        else return false;
    }
    if(dp[i][sum] != -1)
        return dp[i][sum];

    if(a[i] <= sum){
        bool op1 = subset_sum(i-1, sum - a[i]);
        bool op2 = subset_sum(i-1, sum);
        return dp[i][sum] = op1 || op2;
    }
    else{
        return dp[i][sum] = subset_sum(i-1, sum);
    }
}
int main() 
{
    int n; cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int sum; cin>>sum;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    if(subset_sum(n-1, sum))
        cout<<"YES";
    else 
        cout<<"NO";
}