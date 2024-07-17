#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int countAnalogousArrays(vector<int> consecutiveDifference, int lowerBound, int upperBound) {
    // Parameter validation
    if (consecutiveDifference.empty() || lowerBound > upperBound) {
        return 0;
    }

    int delta = 0;
    int maxDelta = INT_MIN;
    int minDelta = INT_MAX;

    for (int diff : consecutiveDifference) {
        delta += diff;
        maxDelta = max(maxDelta, delta);
        minDelta = min(minDelta, delta);
    }

    int maxDiff = maxDelta - minDelta;
    int boundGap = upperBound - lowerBound;

    // If max difference exceeds bound gap, no valid analogous arrays
    if (maxDiff > boundGap) {
        return 0;
    }

    return boundGap - maxDiff+1;
}

int main() {
    // Example usage
    vector<int> consecutiveDifference = {-2, -1, -2, 5};
    int lowerBound = 3;
    int upperBound = 10;

    int result = countAnalogousArrays(consecutiveDifference, lowerBound, upperBound);
    cout << "Number of analogous arrays: " << result << endl;

    return 0;
}
