import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums2) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }

        int n = nums1.length;
        int minimumX = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Map<Integer, Integer> currentCount = new HashMap<>(countMap);
                int candidateX = nums2[0] - nums1[i];
                boolean valid = true;
                
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        int transformed = nums1[k] + candidateX;
                        if (currentCount.getOrDefault(transformed, 0) > 0) {
                            currentCount.put(transformed, currentCount.get(transformed) - 1);
                        } else {
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid) {
                    minimumX = Math.min(minimumX, candidateX);
                }
            }
        }

        return minimumX;
    }
}
