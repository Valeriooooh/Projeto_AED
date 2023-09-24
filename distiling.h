#include <stdio.h>
#include <stdio.h>
#include <string.h>
#ifndef dist_h_
#define dist_h_

struct Coordinates {
    int row;
    int col;
};

/* functions */
FILE* open_file(int argc, char *argv[]);
int **read_store_tileset(FILE *file, int row_coord, int col_coord, int num_rows, int num_columns);
void free_tileset(int **tileset, int numRows);
void solve_tileset(int **tileset, int num_Rows, int num_columns);
int coords_analyze(int** tileset, int x, int y, int n_col, int n_row);
int score(int n_tiles);

#endif