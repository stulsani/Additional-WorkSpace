#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
  reverse(begin(matrix), end(matrix));
  for(int i = 0; i < matrix[0].size(); ++i)
  {
    for(int j = i; j < matrix[0].size(); ++j)
    {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  return matrix;
}

int main()
{
  //Get matrix element, just written actual logic
  return 0;
}
