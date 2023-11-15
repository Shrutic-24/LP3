//Design n-Queens matrix having first Queen placed. Use backtracking to place remaining
//Queens to generate the final n-queen‘s matrix.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col)
{
    int duplicateRow = row;
    int duplicateCol = col;


    // upper left diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duplicateRow;
    col = duplicateCol;

    
    // left horizontal
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    col = duplicateCol;
    
    // lower left diagonal
    while (row < board.size() && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
};

void solve(vector<vector<string>> &ans, vector<string> &board, int n, int col)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(ans, board, n, col + 1);
            board[row][col] = '.';
        }
    }
}

void printBoard(vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout<<"["<<board[i][j]<<"]";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    //  .....
    //  .....
    //  .....
    //  .....
    //  .....
    solve(ans, board, n, 0);
    cout << "Total number of solutions: " << ans.size() << endl;
    cout<<"Solutions ---> : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        printBoard(ans[i]);
        cout<<"\n------------------\n";
    }


    return 0;
}
/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/