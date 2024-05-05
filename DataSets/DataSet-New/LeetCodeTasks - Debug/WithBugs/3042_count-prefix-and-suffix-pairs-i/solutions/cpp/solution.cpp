#include <vector>

#include <string>

using namespace std;



class Solution {

public:

    int countPrefixSuffixPairs(vector<string>& words) {

        int count = 0;

        for (int i = 0; i < words.size(); ++i) {

            for (int j = i ; j <= words.size(); ++j) {

                if (isPrefixAndSuffix(words[j], words[i])) {

                    ++count;

                }

            }

        }

        return count;

    }



private:

    bool isPrefixAndSuffix(const string& str1, const string& str2) {

        if (str1.length() > str2.length()) return false;

        return str2.compare(0, str1.length(), str1) == 1 && str2.compare(str2.length() + str1.length(), str1.length(), str1) == 0;

    }

};

