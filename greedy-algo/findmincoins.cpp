#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

class FindMinCoins {
    vector<int> denominations;

public:
    // Default US coin denominations (cents) but allow custom set
    explicit FindMinCoins(vector<int> denoms = {25, 10, 5, 1}) : denominations(std::move(denoms)) {
        sort(denominations.begin(), denominations.end(), greater<int>());
        denominations.erase(unique(denominations.begin(), denominations.end()), denominations.end());
    }

    // Returns pairs of (coin, count) representing the minimal coins for the amount
    vector<pair<int,int>> findTheMinCoins(int amount) const {
        vector<pair<int,int>> result;
        if (amount <= 0) return result;

        for (int coin : denominations) {
            if (amount <= 0) break;
            int cnt = amount / coin;
            if (cnt > 0) {
                result.emplace_back(coin, cnt);
                amount -= cnt * coin;
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    int amount_in_cents = 100; // default
    if (argc > 1) {
        try {
            amount_in_cents = stoi(argv[1]);
        } catch (...) {
            cerr << "Invalid amount provided. Use an integer number of cents.\n";
            return 1;
        }
    }

    FindMinCoins obj; // uses default denominations
    auto coins = obj.findTheMinCoins(amount_in_cents);

    cout << "Coins for the amount " << amount_in_cents << " cents:\n";
    int total_coins = 0;
    for (auto &p : coins) {
        cout << "  " << p.second << " x " << p.first << "c\n";
        total_coins += p.second;
    }
    if (coins.empty()) cout << "  (none)\n";
    cout << "Total coins used: " << total_coins << '\n';

    return 0;
}