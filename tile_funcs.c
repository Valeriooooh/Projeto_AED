#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "distiling.h"
#include "stack.h"

int score(int n_tiles){

    static int _score = 0;

    for(int i = n_tiles; i > 0; i--){
        _score += i*(i - 1);
    }

    return _score;
}

int coords_analyze(int** tileset, int row, int col, int n_col, int n_row) {

    static int drow[] = { 0, 0, -1, 1 };
    static int dcol[] = { -1, 1, 0, 0 };
    int tile_n = tileset[row][col];
    int n_adj = 1;

    struct Stack *front = newStack();

    if(tile_n == -1) return 0;

     for (int i = 0; i < 4; i++) {
            int adj_row = col + drow[i];
            int adj_col = row + dcol[i]; //problem here

            // Check if the new coordinates are within bounds
            if ((0 < adj_col <=n_col) && (0 < adj_row <= n_row)) {
                if (tileset[adj_row][adj_col] == tile_n) {

                    n_adj++;
                    struct Coordinates aux = {
                        adj_row, adj_col                   
                    };

                    push(front, aux);
                                                    
                }
            }
     }
    while(!empty(front)){


    // Iterate over the adjacent tiles and check their values
        for (int i = 0; i < 4; i++) {
            int adj_col = row + dcol[i]; //problem here
            int adj_row = col + drow[i];

            // Check if the new coordinates are within bounds 0 < adj_x < n_col
            if ((0 < adj_col <= n_col) && (0 < adj_row <= n_row))  {
                if (tileset[adj_row][adj_col] == tile_n) {

                    n_adj++;
                    
                    struct Coordinates aux = {
                        adj_row, adj_col                   
                    };

                    push(front, aux);
                                                    
                }
            }
        }
        tileset[row][col] = -1;

        struct Coordinates new = pop(front);

        row = new.row;
        col = new.col;   
    }
    free(front);
    return n_adj;
}
