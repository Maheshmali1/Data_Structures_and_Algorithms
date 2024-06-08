/*
Problem: Minimum Sum
Description:
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum
possible sum of two numbers formed using the elements of the array. All digits in the given
array must be used to form the two numbers.

Example:
Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed
by numbers 358 and 246.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
To find the minimum possible sum of two numbers formed using the elements of the array,
we need to minimize the value of each digit in the numbers. To achieve this, we can sort
the array in non-decreasing order. We then form two numbers by alternatively selecting
digits from the sorted array starting from the end (to maximize the digit's value).
After forming the two numbers, we add them digit by digit while considering carry.
Finally, we construct the resultant number string by appending non-zero digits in reverse
order (to preserve the order of the digits).
*/

// Function to add two arrays representing numbers digit by digit
class Solution
{
public:
  vector<int> addTwoArr(vector<int> arr1, vector<int> arr2)
  {
    int size1 = arr1.size();
    int size2 = arr2.size();

    vector<int> ans;

    int ind1 = 0;
    int ind2 = 0;
    int carry = 0;
    while (ind1 < size1 && ind2 < size2)
    {
      int num = arr1[ind1] + arr2[ind2] + carry;
      carry = num / 10;
      int rem = num % 10;
      ans.push_back(rem);
      ind1++;
      ind2++;
    }

    while (ind1 < size1)
    {
      int num = arr1[ind1] + carry;
      carry = num / 10;
      int rem = num % 10;
      ans.push_back(rem);
      ind1++;
    }

    while (ind2 < size2)
    {
      int num = arr2[ind2] + carry;
      carry = num / 10;
      int rem = num % 10;
      ans.push_back(rem);
      ind2++;
    }

    if (carry)
    {
      ans.push_back(carry);
    }
    return ans;
  }
  // Function to solve the problem
  string solve(int arr[], int n)
  {
    // Sorting the array
    sort(arr, arr + n);
    // Vector to store digits for the two numbers
    vector<int> num1, num2;

    vector<int> ans;
    // Forming two numbers from the sorted array
    for (int i = n - 1; i >= 0; i -= 2)
    {
      num1.push_back(arr[i]);
      if (i > 0)
      {
        num2.push_back(arr[i - 1]);
      }
    }

    // Adding the two numbers
    ans = addTwoArr(num1, num2);
    int ind = ans.size() - 1;

    // Constructing the resultant number string
    while (ind >= 0 && ans[ind] == 0)
    {
      ind--;
    }

    string ansStr = "";
    for (int i = ind; i >= 0; i--)
    {
      ansStr += to_string(ans[i]);
    }
    // If the resultant number is empty, return "0"
    return ansStr.size() == 0 ? "0" : ansStr;
  }
};

int main()
{
  int arr[] = {6, 8, 4, 5, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  Solution obj;
  cout << obj.solve(arr, n) << endl;
  return 0;
}

/*
Time Complexity:
Sorting the array takes O(N*log(N)) time. Forming the two numbers takes O(N) time, and
adding them digit by digit takes O(N) time. So, the overall time complexity is O(N*log(N)).

Space Complexity:
O(N) extra space is used.
*/
