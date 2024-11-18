#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // check for two arguments, return error if incorrect
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc-1);
        return 0;
    }

    // convert arguments to int
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);


    // check if they are positive
    if (row <= 0 || col <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 1;
    }


    //  create dynamically allocated matrix array
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) { 
        matrix[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % (maxrand - minrand + 1) + minrand;
        }
    }
    
    // create and open file, show error if it didnt work
    FILE *fptr;
    fptr = fopen("matrix.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file");
    }


    // add matrix into file with whitespaces, new lines and carriage return and close
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fprintf(fptr, "%d ", matrix[i][j]);
            if (j < col - 1) {
                fprintf(fptr, " ");
            }
        }
        if (i != row - 1){
            fprintf(fptr, "\n");
        }

        fprintf(fptr, "\r");
    }
    fclose(fptr);

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

return 0;
}
