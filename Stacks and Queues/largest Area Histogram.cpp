//  Logic - consider each bar and it can only expand before its right smallest
//  (on right) abd left smallest (on left)

// Approach 1 - Naive
// Pepcoding video
class Solution {
public:
  // Function to find largest rectangular area possible in a given histogram.
  long long getMaxArea(long long arr[], int n) {

    long long res = 0;

    for (int i = 0; i < n; i++) {
      long long count = arr[i];
      for (int j = i - 1; j >= 0; j--) {
        if (arr[j] >= arr[i])
          count += arr[i];
        else
          break;
      }

      for (int j = i + 1; j < n; j++) {
        if (arr[j] >= arr[i])
          count += arr[i];
        else
          break;
      }
      res = max(res, count);
    }
    return res;
  }
};

// Approach 2 - Better --- TC & SC : O(N)
// Run at interviewBit

int Solution::largestRectangleArea(vector<int> &arr) {
  int n = arr.size();

  if (n == 1)
    return arr[0];

  int lb[n]; // nearest smallest on left
  int rb[n]; // nearest smallest onleft

  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {

    while (!st.empty() && arr[i] <= arr[st.top()])
      st.pop();

    rb[i] = (st.empty()) ? n : st.top();

    st.push(i);
  }

  while (st.empty() == false)
    st.pop();

  for (int i = 0; i < n; i++) {

    while (!st.empty() && arr[i] <= arr[st.top()])
      st.pop();

    lb[i] = (st.empty()) ? -1 : st.top();

    st.push(i);
  }

  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int width = rb[i] - lb[i] - 1;
    int area = arr[i] * width;
    if (maxArea < area)
      maxArea = area;
  }
  return maxArea;
}