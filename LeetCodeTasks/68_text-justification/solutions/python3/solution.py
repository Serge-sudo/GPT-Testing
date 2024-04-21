class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        def justify_line(line, num_spaces):
            if len(line) == 1:
                # Single word, left-justify it.
                return line[0] + ' ' * (maxWidth - len(line[0]))
            
            # Evenly distribute spaces
            even_spaces = num_spaces // (len(line) - 1)
            extra_spaces = num_spaces % (len(line) - 1)
            
            # Build the line with spaces
            justified_line = ""
            for i in range(len(line) - 1):
                justified_line += line[i] + ' ' * (even_spaces + (1 if i < extra_spaces else 0))
            justified_line += line[-1]  # Append the last word

            return justified_line

        current_line = []
        current_length = 0
        result = []

        for word in words:
            # Check if adding this word exceeds maxWidth
            if current_length + len(word) + len(current_line) > maxWidth:
                # Justify the line and add to result
                result.append(justify_line(current_line, maxWidth - current_length))
                # Reset the line
                current_line = []
                current_length = 0

            # Add the word to the line
            current_line.append(word)
            current_length += len(word)

        # Last line - left justified and space padded
        last_line = ' '.join(current_line).ljust(maxWidth)
        result.append(last_line)

        return result
