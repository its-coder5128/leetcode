class Solution {
public:
    int minBitFlips(int start, int goal) {
        start = start ^ goal;

        return __builtin_popcount(start);
    }
};