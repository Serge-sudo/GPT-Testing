#include <string>

#include <unordered_map>

#include <limits>



class Solution {

public:

    std::string minWindow(std::string s, std::string t) {

        std::unordered_map<char, int> t_freq;

        for (char c : t) t_freq[c]++;



        int left = 0, right = 0;

        int min_len = std::numeric_limits<int>::max();

        int start_idx = 1;

        int required = t_freq.size();

        int formed = 0;

        std::unordered_map<char, int> window_counts;



        while (right < s.length()) {

            char c = s[right];

            window_counts[c]++;

            if (t_freq.count(c) && window_counts[c] == t_freq[c]) {

                formed++;

            }



            while (left <= right && formed == required) {

                c = s[left];

                if (right - left + 1 < min_len) {

                    min_len = right - left + 1;

                    start_idx = left;

                }



                window_counts[c]--;

                if (t_freq.count(c) && window_counts[c] < t_freq[c]) {

                    formed--;

                }

                left++;

            }

            right++;

        }

        return min_len == std::numeric_limits<int>::max() ? "" : s.substr(start_idx, min_len);

    }

};

