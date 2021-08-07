class Solution {
public:
  // Function to find maximum of each subarray of size k.
  vector<int> max_of_subarrays(int *arr, int n, int k) {
    int nge[n];
    stack<int> st;
    st.push(n - 1);
    nge[n - 1] = n;
    vector<int> ans;
    for (int i = n - 2; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] <= arr[i])
        st.pop();
      if (st.empty())
        nge[i] = n;
      else
        nge[i] = st.top();
      st.push(i);
    }
    int j = 0;
    for (int i = 0; i <= n - k; i++) {
      if (j < i) { // j=i;
        j = i;
      }
      while (nge[j] < i + k) { // inside window
        j = nge[j];
      }
      ans.push_back(arr[j]);
    }
    return ans;
  }
};