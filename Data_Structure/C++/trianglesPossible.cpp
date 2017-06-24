#include <iostream>
#include <vector>

using namespace std;

int maximumTrianglesPossible(vector<int>& nums)
{
	int count = 0;
	if(nums.size() <= 2) return count;
	sort(nums.begin(),nums.end());
	for(int i=0;i<nums.size()-2;i++)
	{
		int k = i+2;
		for(int j=i+1;j<nums.size();j++)
		{
			while(k < nums.size() && nums[i]+nums[j] > nums[k]) k++;
			count += k-j-1;
		}
	}
	return count;
}

int main()
{
	int n;
	cout << "Enter total elements: " << endl;
	cin >> n;
	vector<int> arr(n);
	cout << "Start entering.." << endl;
	for(int i = 0;i < n;++i)
			cin >> arr[i];
	cout << "Maximum Triangles possible: " << maximumTrianglesPossible(arr) << endl;
	return 0;
}
