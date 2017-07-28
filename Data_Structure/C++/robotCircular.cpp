
#include <iostream>
#include <string>
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

bool isRobotMovingCircular(string s)
{
  int direction = N,x = 0, y= 0;
  for(auto c: s)
  {
    if(c == 'R' || c == 'r')
      direction = (direction + 1) % 4;
    else if(c == 'L' || c == 'l')
      direction = (4 + direction - 1) % 4;
    else
    {
      if(direction == N)
        y++;
      else if(direction == E)
        x++;
      else if(direction == S)
        y--;
      else
        x--;
    }
  }
  return (x == 0 && y == 0);
}

int main()
{
  string s;
  cout << "Enter robot moves: " << endl;
  cin >> s;
  if(isRobotMovingCircular(s))
    cout << "Yes!!!" << endl;
  else
    cout << "No!!!" << endl;
  return 0;
}
