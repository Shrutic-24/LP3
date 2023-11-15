//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and
//bound strategy.
#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int w, vector<vector<int>> &dp, vector<int> &val, vector<int> &wt)
{
    if (idx == wt.size() || w <= 0)
    {
        return 0;
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    int nottake = 0 + solve(idx + 1, w, dp, val, wt);
    int take = 0;
    if (wt[idx] <= w)
    {
        take = val[idx] + solve(idx + 1, w - wt[idx], dp, val, wt);
    }
    dp[idx][w]=max(take, nottake);
    return dp[idx][w];
}

int main()
{

    int n, W;
    cout<<"Enter the number of items and the capacity of the knapsack"<<endl;
    cin >> n >> W;
    vector<int> wt(n);
    vector<int> val(n);

    cout<<"Enter the weights of the items"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout<<"Enter the values of the items"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int a = solve(0, W, dp, val, wt);
    cout <<"answer ---> "<< a << endl;

    return 0;
}


// n=3 w=4
// wt  = 4 5 1
// val = 1 2 3



// ans = 3

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/