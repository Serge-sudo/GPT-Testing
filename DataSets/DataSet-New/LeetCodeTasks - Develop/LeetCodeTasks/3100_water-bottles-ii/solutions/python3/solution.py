class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        total_drunk = 0
        empty_bottles = 0
        while numBottles > 0:
            # Drink all available bottles
            total_drunk += numBottles
            # Collect all bottles that have been drunk
            empty_bottles += numBottles
            # Reset the number of full bottles we have now
            numBottles = 0
            
            # Exchange empty bottles for new full bottles if possible
            if empty_bottles >= numExchange:
                numBottles = empty_bottles // numExchange
                empty_bottles %= numExchange
                numExchange += 1  # Increment the cost of the next exchange
                
        return total_drunk
