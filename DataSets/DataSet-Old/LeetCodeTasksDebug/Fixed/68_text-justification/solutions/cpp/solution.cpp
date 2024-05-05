#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int index = 0;

        while (index < words.size()) {
            int count = words[index].length();
            int last = index + 1;

            while (last < words.size()) {
                if (count + words[last].length() + 1 > maxWidth) break;
                count += words[last].length() + 1;
                last++;
            }

            std::string line = "";
            int diff = last - index - 1;

            // If last line or number of words in the line is 1, left-justify
            if (last == words.size() || diff == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += std::string(maxWidth - line.length(), ' ');
            } else {
                // Calculate even spaces and extra spaces
                int spaces = (maxWidth - count) / diff;
                int extra = (maxWidth - count) % diff;

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        int spaceToAdd = spaces + ((i - index) < extra ? 1 : 0);
                        line += std::string(spaceToAdd + 1, ' ');
                    }
                }
            }
            result.push_back(line);
            index = last;
        }

        return result;
    }
};
