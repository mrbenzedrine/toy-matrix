#include "matrix.h"

Matrix::Matrix(int ROWS, int COLUMNS, double value):rows(ROWS), columns(COLUMNS){

    for(int i = 0; i < ROWS * COLUMNS; i++){
        matrix_data.push_back(value);
    }

    for(int j = 0; j < ROWS; j++){
        row_ptrs.push_back(&matrix_data[j * ROWS]);
    }

}

void Matrix::display(){

    std::vector<double*>::const_iterator iter;
    double *temp_row_ptr;

    for(iter = row_ptrs.begin(); iter != row_ptrs.end(); iter++){

        temp_row_ptr = *iter;

        for(int j = 0; j < columns; j++, temp_row_ptr++){

            std::cout << *temp_row_ptr << " ";

        }
        std::cout << std::endl;
    }

}
