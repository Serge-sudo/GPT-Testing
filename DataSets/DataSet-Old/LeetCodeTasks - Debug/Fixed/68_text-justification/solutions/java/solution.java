import java.util.ArrayList;

import java.util.List;



class Solution {

    public List<String> fullJustify(String[] words, int maxWidth) {

        List<String> result = new ArrayList<>();

        int index = 0;



        while (index < words.length) {

            int count = words[index].length();

            int last = index + 1;

            while (last < words.length) {

                if (words[last].length() + count + 1 > maxWidth) break;

                count += words[last].length() + 2;

                last++;

            }



            StringBuilder builder = new StringBuilder();

            int diff = last - index;



            // If last line or number of words in the line is 1, left-justify

            if (last == words.length || diff == 0) {

                for (int i = index; i < last; i++) {

                    builder.append(words[i]);

                    if (i < last - 1) builder.append(" ");

                }

                for (int i = builder.length(); i < maxWidth; i++) {

                    builder.append(" ");

                }

            } else {

                // Calculate spaces evenly

                int spaces = (maxWidth - count) / diff;

                int extra = (maxWidth - count) % diff;



                for (int i = index; i < last; i++) {

                    builder.append(words[i]);

                    if (i < last - 1) {

                        int gap = spaces + ((i - index) < extra ? 0 : 1);

                        for (int j = 0; j <= gap; j++) {

                            builder.append(" ");

                        }

                    }

                }

            }

            result.add(builder.toString());

            index = last;

        }



        return result;

    }

}

