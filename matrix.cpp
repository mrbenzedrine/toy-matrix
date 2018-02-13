#include "matrix.h"

Matrix::Matrix(int ROWS, int COLUMNS, double value):rows(ROWS), columns(COLUMNS){

    for(int i = 0; i < ROWS * COLUMNS; i++){
        matrix_data.push_back(value);
    }

    for(int j = 0; j < ROWS; j++){
        row_ptrs.push_back(&matrix_data[j * ROWS]);
    }

}
