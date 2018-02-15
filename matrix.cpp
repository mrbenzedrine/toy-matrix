#include "matrix.h"

Matrix::Matrix(int ROWS, int COLUMNS, double value):rows(ROWS), columns(COLUMNS){

    for(int i = 0; i < ROWS * COLUMNS; i++){
        matrix_data.push_back(value);
    }

    for(int j = 0; j < ROWS; j++){
        row_ptrs.push_back(&matrix_data[j * COLUMNS]);
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

const double& Matrix::operator()(int i, int j) const{

    if(i < 1 || i > rows){
        throw std::out_of_range("Matrix row index is out of range");
    }

    if(j < 1 || j > columns){
        throw std::out_of_range("Matrix column index is out of range");
    }

    double *temp_row_ptr;
    temp_row_ptr = row_ptrs[i-1] + (j-1);

    const double& matrix_entry_value = *temp_row_ptr;

    return matrix_entry_value;

}

double& Matrix::operator()(int i, int j){

    if(i < 1 || i > rows){
        throw std::out_of_range("Matrix row index is out of range");
    }

    if(j < 1 || j > columns){
        throw std::out_of_range("Matrix column index is out of range");
    }

    double *temp_row_ptr;
    temp_row_ptr = row_ptrs[i-1] + (j-1);

    double& matrix_entry_value = *temp_row_ptr;

    return matrix_entry_value;

}

Matrix operator*(double scalar, const Matrix &rhs){

    Matrix result_matrix(rhs.rows, rhs.columns);

    for(int i = 0; i < rhs.rows * rhs.columns; i++){
        result_matrix.matrix_data[i] = rhs.matrix_data[i] * scalar;
    }

    return result_matrix;

}

Matrix operator*(const Matrix &lhs, double scalar){
    return scalar * lhs;
}

Matrix& Matrix::operator*=(double scalar){

    std::vector<double>::iterator iter;

    for(iter = matrix_data.begin(); iter != matrix_data.end(); iter++){
        *iter *= scalar;
    }

    return *this;

}
