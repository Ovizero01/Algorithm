/*Similar as 0-1 Knapsack*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline "\n"
int val[1005], weight[1005], dp[1005][1005];
int knapsack(int i, int mx_weight)
{
    if(i < 0 || mx_weight <= 0) return 0;

    if(dp[i][mx_weight] != -1) return dp[i][mx_weight];

    if(weight[i] <= mx_weight){
        int op1 = knapsack(i,mx_weight-weight[i]) + val[i];  /*just one change here
        we can take the same weight*/
        int op2 = knapsack(i-1,mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }

    else
        return dp[i][mx_weight] = knapsack(i-1,mx_weight);
}
int main() 
{
	int n; cin>>n;
	
	for(int i = 0; i < n; i++) cin>>val[i];
	for(int i = 0; i < n; i++) cin>>weight[i];
	
	int mx_weight; cin>>mx_weight;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;

	cout<<knapsack(n-1,mx_weight);
}