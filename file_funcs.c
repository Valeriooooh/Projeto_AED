#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
*
*/
FILE* open_file(int argc, char *argv[]) {

    /* must have at least one argument besides the executable name */
    if (argc < 2) {
        printf("Must have a single argument!");
        exit(1);
    }

    /* must have .tilewalls1 extension */

    char *valid_ext = (char *)malloc(strlen(".tilewalls1") + 1);

    strcpy(valid_ext, ".tilewalls1");

    const char *file_extension = strrchr(argv[1], '.');

    if (file_extension == NULL || strcmp(file_extension, valid_ext) != 0) {
        fprintf(stderr, "Invalid file extension. The file must have a '.tilewalls1' extension.\n");
        exit(1);
    }

    free(valid_ext);

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file");
        exit(1);
    }

    return file; // Return the file pointer
}

/*
*
*/
void free_tileset(int **tileset, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        free(tileset[i]);
    }
    free(tileset);
}

int **read_store_tileset(FILE *file, int row_coord, int col_coord, int num_rows, int num_columns) {
    int **tileset;

    // Check for invalid coordinates
    if ((row_coord < 1) || (row_coord > num_rows) || (col_coord < 1) || (col_coord > num_columns)) {
        fprintf(stderr, "Invalid coordinates");
        exit(1);
    }

    // Allocate memory for the tileset
    tileset = (int **)malloc(num_rows * sizeof(int *));
    if (tileset == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    // Allocate memory for each row
    for (int i = 0; i < num_rows; i++) {
        tileset[i] = (int *)malloc(num_columns * sizeof(int));
        if (tileset[i] == NULL) {
            free_tileset(tileset, i);
            fprintf(stderr, "Memory allocation failed");
            exit(1);
        }
    }

    // Read and store tileset data, skipping [0][0]
    for (int i = num_rows - 1; i >= 0; i--) {
        for (int j = 0; j < num_columns; j++) {
            if (fscanf(file, "%d", &tileset[i][j]) != 1) {
                free_tileset(tileset, num_rows);
                fprintf(stderr, "Error reading tileset data");
                exit(1);
            }
            
        }
    }

    return tileset;
}




