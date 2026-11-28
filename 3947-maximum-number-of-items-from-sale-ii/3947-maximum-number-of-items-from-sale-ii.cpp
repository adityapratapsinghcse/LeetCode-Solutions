#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long minPrice = LLONG_MAX;
        vector<int> freq(n + 1, 0);

        for (const auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, (long long)item[1]);
        }

        // mult[v] = number of items whose factor is a multiple of v
        vector<int> mult = freq;
        for (int v = 1; v <= n; ++v) {
            if (freq[v] > 0) {
                for (int m = 2 * v; m <= n; m += v) {
                    mult[v] += freq[m];
                }
            }
        }

        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long rem = budget;
        long long total = 0;
        long long limit = 2 * minPrice;

        for (const auto& item : items) {
            long long price = item[1];
            if (price >= limit || price > rem) break;

            long long boosted = mult[item[0]] - 1;
            if (boosted > 0) {
                long long take = min(boosted, rem / price);
                total += 2 * take;
                rem -= take * price;
            }
        }

        total += rem / minPrice;
        return (int)total;
    }
};