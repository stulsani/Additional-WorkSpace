#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

int SET_BIT(int var, int pos)
{
  return (var) | (1<<(pos));
}

int CLEAR_BIT(int var,int pos)
{
  return ((var) & ~(1<<(pos)));
}

int TOGGLE_BIT(int var,int pos)
{
  return ((var) ^ (1 << (pos)));
}

int total_bits_set(int var)
{
  int count = 0;
  while(var != 0)
  {
    if(var % 2 != 0)
      count++;
    var = var/2;
  }
  return count;
}

bool ispoweroftwo(int val)
{
  return (val && !(val & (val - 1)));
}

int higherpoweroftwo(int val)
{
  int count = 0;
  while(val != 0)
  {
    val = val >> 1;
    count++;
  }
  val = (1 << (count));
  return val;
}

bool ispoweroffour(int val)
{
  while(val % 4 == 0)
  {
    val = val/4;
  }
  if(val == 1)
    return true;
  return false;
}

int multiplybyseven(int val)
{
  int x = val;
  val = val << 3;
  return val = val - x;
}

int main()
{
  int x = 11;
  bool result = CHECK_BIT(x, 3);
  if(result)
    cout << "True" << endl;
  else
    cout << "False" << endl;
  x = SET_BIT(x,2);
  cout << "X now after seeting the bit: " << x << endl;
  x = CLEAR_BIT(x,2);
  cout << "X now after clearing the bit: " << x << endl;
  x = TOGGLE_BIT(x,0);
  cout << "X now after toggling the bit: " << x << endl;
  int count = total_bits_set(x);
  cout << "Total bits active in X: " << count << endl;
  int num = 8;
  result = ispoweroftwo(num);
  if(result)
    cout << "Is a power of two!!" << endl;
  else
    cout << "Is not a power of two!!" << endl;
  num = 10;
  int ans = higherpoweroftwo(num);
  cout << "The next higher power of two is: " << ans << endl;
  num = 16;
  result = ispoweroffour(num);
  if(result)
    cout << "The number is power of 4" << endl;
  else
    cout << "The number is not power of 4" << endl;
  num = 7;
  ans = multiplybyseven(num);
  cout << "After multiplication the number is: " << ans << endl;
  return 0;
}
