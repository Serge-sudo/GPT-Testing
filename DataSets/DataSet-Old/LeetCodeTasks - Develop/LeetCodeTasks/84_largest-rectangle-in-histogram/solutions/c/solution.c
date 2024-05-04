#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int*) malloc(sizeof(int) * heightsSize);
    int top = -1;
    int maxArea = 0;
    int i = 0;
    
    while (i <= heightsSize) {
        int h = (i == heightsSize ? 0 : heights[i]);
        if (top == -1 || heights[stack[top]] <= h) {
            stack[++top] = i++;
        } else {
            int height = heights[stack[top--]];
            int width = (top == -1 ? i : i - stack[top] - 1);
            maxArea = (maxArea > height * width ? maxArea : height * width);
        }
    }
    
    free(stack);
    return maxArea;
}
