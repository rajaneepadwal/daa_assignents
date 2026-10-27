#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCuttingDP(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter rod length: ";
    cin >> n;

    vector<int> price(n);

    cout << "Enter prices for each length: ";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << "Maximum profit using DP = "
         << rodCuttingDP(price, n) << endl;

    return 0;
}
