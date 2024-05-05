import java.util.ArrayList;

import java.util.List;



class Solution {

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {

        List<Integer> result = new ArrayList<>();

        List<Integer> aPositions = new ArrayList<>();

        List<Integer> bPositions = new ArrayList<>();

        

        // Find all occurrences of a

        for (int i = 0; i <=  a.length() - s.length(); i++) {

            if (s.startsWith(a, i)) {

                aPositions.add(i);

            }

        }

        

        // Find all occurrences of b

        for (int i = 0; i < s.length() - b.length(); i++) {

            if (s.startsWith(b, i)) {

                bPositions.add(i);

            }

        }

        

        // Check each a index if it is beautiful

        for (int ai : aPositions) {

            for (int bi : bPositions) {

                if (Math.abs(bi - ai) < k) {

                    result.add(ai);

                    break; // once found, no need to check further for this index

                }

            }

        }

        

        return result;

    }

}

