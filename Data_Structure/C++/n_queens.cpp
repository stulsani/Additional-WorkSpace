#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printsolution(vector< vector<int> >& board)
{
	for(int i = 0; i < board.size(); i++)
	{
    for(int j = 0; j < board[i].size(); j++)
      cout << board[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(vector< vector<int> >& board,int row,int col)
{
	int i, j;
  for (i = 0; i < col; i++)
  {
    if(board[row][i])
      return false;
  }
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if(board[i][j])
    	return false;
  }
  for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
  {
    if(board[i][j])
      return false;
  }
  return true;
}

bool nqueens(vector< vector<int> >& board,int col)
{
	if(col >= board.size()) return true;
	for(int i = 0;i < board.size();i++)
	{
		if(isSafe(board,i,col))
		{
			board[i][col] = 1;
			if(nqueens(board,col+1))
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}

int main()
{
	int n;
	cout << "Enter size of board" << endl;
	cin >> n;
	vector< vector<int> > board(n, vector<int>(n));
	if(nqueens(board,0))
		printsolution(board);
	else
		cout << "Solution does not exist" << endl;
	return 0;
}
