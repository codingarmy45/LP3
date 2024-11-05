#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>&board, int n)
{
    int dupRow = row;
    int dupCol = col;

    while(col >= 0 && row >=0)
    {
        if(board[row][col] == 'Q')
        return false;
        col--;
        row--;
    }

    col = dupCol;
    row = dupRow;

    while(col >= 0)
    {
        if(board[row][col] == 'Q')
        return false;
        col--;
    }

    col = dupCol;
    row = dupRow;
    while(row < n && col >=0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<vector<string>>&ans, vector<string>&board, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++)
    {
        if(isSafe(row,col,board, n))
        {
            board[row][col] = 'Q';
            solve(col+1, ans, board, n);
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n;
    cin>>n;

    vector<vector<string>> ans;
    vector<string> board(n);

    string s(n,'.');

    for(int i=0; i<n; i++) board[i] = s;

    solve(0, ans, board, n);

    for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
}