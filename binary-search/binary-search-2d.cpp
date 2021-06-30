#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>> &a, int l, int r, int target, int m)
{
  if (l > r)
    return false;

  int mid = (l + r) / 2;
  int i = (mid / m);
  int j = mid % m;

  if (a[i][j] == target)
    return true;

  if (a[i][j] > target)
    return binarySearch(a, l, mid - 1, target, m);
  return binarySearch(a, mid + 1, r, target, m);
}

int main()
{

  return 0;
}