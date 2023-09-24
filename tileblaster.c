#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "distiling.h"
#include "stack.h"

int main(int argc, char *argv[]){

    int num_columns = 0;
    int num_rows = 0;
    int v = 0;
    int col_coord = 0;
    int row_coord = 0;
    int points = 0;
    int **tileset;
    FILE *file = NULL;

    file = open_file(argc, argv);

    while (fscanf(file, "%d %d %d %d %d", &num_rows, &num_columns, &v, &row_coord, &col_coord) == 5) {

        if ((num_rows < 1) || (num_columns < 1) || v < 1 || v > 2) {
            fprintf(stderr, "Invalid size\n");
            exit(1); 
        }

        else{

            tileset = read_store_tileset(file, row_coord, col_coord, num_rows, num_columns);

            switch(v){

                case 1: 
                    int points = score(coords_analyze(tileset, col_coord, row_coord, num_columns, num_rows));
                    //write in file
                    break;

                case 2:

                    break;

                default:
                    fprintf(stderr, "Invalid variation");
                    exit(1);
            }
            
        }    
                 
        free_tileset(tileset, num_rows);
    }
   
    fclose(file);
    printf("%d", points);
    return 0;
    }

