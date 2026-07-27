#include <bits/stdc++.h>
using namespace std;
//You need to assign each workload unit to either Processor A or B to minimize the maximum completion time.
// Function to check if all data can be processed within time T
bool canProcess(const vector<int>& data, int processTimeA, int processTimeB, long long T) {
    int totalData = accumulate(data.begin(), data.end(), 0);
    // dp[s] = true if we can achieve sum 's' for Processor A
    // using some subset of data items
    vector<bool> dp(totalData + 1, false);
    dp[0] = true;  // Empty subset gives sum 0
    // Subset Sum DP: Find all possible sums for Processor A
    for (int x : data) {
        // Process backwards to avoid reusing same item
        for (int s = totalData; s >= x; s--) {
            dp[s] = dp[s] || dp[s - x];
        }
    }
    // Check all possible sums (s = data assigned to A)
    for (int s = 0; s <= totalData; s++) {
        if (!dp[s]) continue;  // This sum is not achievable
        // If A gets 's' units, B gets (totalData - s) units
        long long timeA = 1LL * s * processTimeA;                    // Time for A
        long long timeB = 1LL * (totalData - s) * processTimeB;      // Time for B
        
        // Both processors must finish within T
        if (timeA <= T && timeB <= T)
            return true;
    }
    
    return false;
}

// Main function to find minimum processing time
int getMinProcessingTime(vector<int> data, int processTimeA, int processTimeB) {
    int totalData = accumulate(data.begin(), data.end(), 0);
    // Binary search on answer (time)
    // low = 0 (best case), high = worst case (all data on slower processor)
    long long low = 0;
    long long high = 1LL * totalData * max(processTimeA, processTimeB);
    while (low < high) {
        long long mid = low + (high - low) / 2;
        // Check if we can finish within 'mid' time
        if (canProcess(data, processTimeA, processTimeB, mid))
            high = mid;      // Try to find even smaller time
        else
            low = mid + 1;   // Need more time
    }
    
    return (int)low;
}

// Driver code
int main() {
    vector<int> data = {2, 3, 1};
    int processTimeA = 2;
    int processTimeB = 3;
    
    cout << "Minimum processing time: " << getMinProcessingTime(data, processTimeA, processTimeB) << endl;
    return 0;
}