#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize);

int main() {
    int rows = 4, columns = 4;
    int matrix[4][4] = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    
    int* grid[4];
    for (int i = 0; i < rows; i++) {
        grid[i] = matrix[i];
    }

    int perimeter = islandPerimeter(grid, rows, &columns);
    printf("Island perimeter is: %d\n", perimeter);

    return 0;
    
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < *gridColSize; j++) {
            if(grid[i][j] == 1) {
                count += 4;

                if(i > 0 && grid[i-1][j] == 1) {
                    count -= 2;
                }
                if(j > 0 && grid[i][j-1] == 1) {
                    count -= 2;
                }
            }
        }
    }
    return count;
}
