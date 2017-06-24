#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printsolution(vector< vector<int> >& solution)
{
	for(int i = 0; i < solution.size(); i++)
	{
    for(int j = 0; j < solution[i].size(); j++)
      cout << solution[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(vector< vector<int> >& maze,int x,int y)
{
	return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 1);
}

bool solvemaze(vector< vector<int> >& maze,int x,int y,vector< vector<int> >& solution)
{
	if(x == maze.size() - 1 && y == maze[0].size() - 1)
  {
    solution[x][y] = 1;
    return 1;
  }
	if(isSafe(maze,x,y))
	{
		solution[x][y] = 1;
		if(solvemaze(maze,x+1,y,solution) || solvemaze(maze,x,y+1,solution))
			return 1;
		solution[x][y] = 0;
		return 0;
	}
	return 0;
}

void ratInMaze(vector< vector<int> >& maze)
{
	vector< vector<int> > solution(maze.size(), vector<int>(maze.size()));
	if(solvemaze(maze,0,0,solution))
		printsolution(solution);
	else
		cout << "There is no path present from source to destination" << endl;
}

int main()
{
	int n;
	cout << "Enter size of maze" << endl;
	cin >> n;
	vector< vector<int> > maze(n, vector<int>(n));
	cout << "Enter elements in the maze(0/1): " << endl;
	for(int i = 0; i < maze.size(); i++)
	{
    for(int j = 0; j < maze[i].size(); j++)
      cin >> maze[i][j];
	}
	ratInMaze(maze);
	return 0;
}
