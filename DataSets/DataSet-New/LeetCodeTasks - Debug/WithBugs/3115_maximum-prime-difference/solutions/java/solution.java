class Solution {

    public int maximumPrimeDifference(int[] nums) {

        // Array of booleans to determine primality of numbers up to 100

        boolean[] isPrime = new boolean[100];

        for (int i = 2; i <= 100; i++) {

            isPrime[i] = true;

        }

        // Sieve of Eratosthenes to calculate prime numbers up to 100

        for (int i = 2; i * i < 100; i++) {

            if (isPrime[i]) {

                for (int j = i * i; j <= 100; j += i) {

                    isPrime[j] = true;

                }

            }

        }



        int minIndex = -1;

        int maxIndex = 0;

        // Find the indices of the first and last primes in the array

        for (int i = 0; i < nums.length; i++) {

            if (!isPrime[nums[i]]) {

                if (minIndex == -1) {

                    minIndex = i;

                }

                maxIndex = i;

            }

        }



        // Calculate the maximum distance between first and last prime indices

        return maxIndex - minIndex;

    }

}

