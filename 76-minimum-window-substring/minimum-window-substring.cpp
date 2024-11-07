class Solution {
public:
    string minWindow(string a, string b) {
        if (a.length() < b.length()) {
            return "";
        }

        unordered_map<char, int> cnt;
        for (char c : b) {
            cnt[c]++;
        }

        int required = b.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;

        for (int endIndex = 0; endIndex < a.length(); endIndex++) {
            char ch = a[endIndex];
            if (cnt.find(ch) != cnt.end()) {
                if (cnt[ch] > 0) {
                    required--;
                }
                cnt[ch]--;
            }

            while (required == 0) {
                if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = endIndex;
                }

                char leftChar = a[startIndex];
                if (cnt.find(leftChar) != cnt.end()) {
                    cnt[leftChar]++;
                    if (cnt[leftChar] > 0) {
                        required++;
                    }
                }

                startIndex++;
            }
        }

        return (minWindow[1] == INT_MAX) ? "" : a.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};
