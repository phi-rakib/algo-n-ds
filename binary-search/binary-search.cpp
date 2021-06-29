#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> &nums, int l, int r, int target)
{
  if (l > r)
    return -1;

  int mid = (l + r) / 2;

  if (nums[mid] == target)
    return mid;

  if (nums[mid] > target)
    return binarySearch(nums, l, mid - 1, target);

  return binarySearch(nums, mid + 1, r, target);
}

int search(vector<int> &nums, int target)
{
  int l = 0;
  int r = nums.size() - 1;
  return binarySearch(nums, l, r, target);
}

int main()
{
  vector<int> vec = vector<int>{1, 5, 12, 17, 22};

  int target = 12;
  int index = search(vec, target);

  cout << (index == -1 ? "Not Found" : "Found") << endl;

  return 0;
}
