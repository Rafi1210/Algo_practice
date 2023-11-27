#include <iostream>
#include <vector>

using namespace std;

void minCoins(int amount) {
    vector<int> coins = {100, 25, 10, 5, 1}; // denominations in cents
    vector<int> coinCount(coins.size(), 0); // to store the count of each coin

    for (int i = 0; i < coins.size(); ++i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            coinCount[i]++;
        }
    }
int ans = 0;
    // Output the result
    cout << "Number of coins used:\n";
    for (int i = 0; i < coins.size(); ++i) {
        cout << coins[i] << " cents: " << coinCount[i] << " coins\n";
        ans = ans+ coinCount[i];
    }
    cout <<"Total coins used : "<< ans << endl;
}

int main() {
    int amount = 564; // $5.64 in cents
    cout << "Amount to return: $" << amount / 100.0 << "\n";
    minCoins(amount);

    return 0;
}
