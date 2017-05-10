#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int countStrings(int num)
{
	int temp1[num], temp2[num], index;
	temp1[0] = temp2[0] = 1;
	for(index = 1; index < num; index++)
    {
        temp1[index] = temp1[index-1] + temp2[index-1];
        cout << "Index: " << index << " temp1: " <<temp1[index] << " ";
        temp2[index] = temp1[index-1];
        cout << " temp2: " << temp2[index] << endl;
    }
    return temp1[num-1] + temp2[num-1];
}

int main()
{
	int num;
	printf("Enter a number\n");
	scanf("%d", &num);
  int result = countStrings(num);
	cout << "The number of binary strings withou consecutive 0's = " << result << endl;
	return 0;
}

//Time complexity: O(n)
//Space complexity: O(n)
