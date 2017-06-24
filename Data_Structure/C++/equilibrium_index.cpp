#include <iostream>
#include <vector>

using namespace std;

void equilibriumIndex(vector<int>& nums)
{
	if(nums.size() <= 1)
	{
		cout << "No such index present" << endl;
		return;
	}
	int sum=0,leftsum=0;
	for(auto i:nums) sum += i;
	for(int i=0;i < nums.size();i++)
	{
		sum -= nums[i];
		cout << "Sum: " << sum << " leftsum: " << leftsum << endl;
		if(sum == leftsum)
			cout << "The equilbrium index is: " << i << endl;
		leftsum += nums[i];
	}
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
	equilibriumIndex(arr);
	return 0;
}
