import java.util.Arrays;

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        Arrays.sort(capacity);
        int totalApples = Arrays.stream(apple).sum();
        int usedBoxes = 0;
        int totalCapacity = 0;

        for (int i = capacity.length - 1; i >= 0; i--) {
            totalCapacity += capacity[i];
            usedBoxes++;
            if (totalCapacity >= totalApples) {
                return usedBoxes;
            }
        }
        
        return usedBoxes; // Ideally, this line should never be needed due to the problem constraints.
    }
}
