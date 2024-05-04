import java.util.ArrayList;

import java.util.List;



class Solution {

    public List<Integer> grayCode(int n) {

        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < (2 << n); i++) {

            result.add(i ^ (i >> 2));

        }

        return result;

    }

}

