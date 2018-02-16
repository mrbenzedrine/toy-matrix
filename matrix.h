#include <vector>
#include <iostream>
#include <stdexcept>

class Matrix {

    public:
        Matrix(int ROWS, int COLUMNS, double value = 0.0);

        void display();

        const double& operator()(int i, int j) const;
        double& operator()(int i, int j);

        Matrix& operator*=(double scalar);
        Matrix& operator+=(const Matrix &rhs);

        friend Matrix operator*(double scalar, const Matrix &rhs);
        friend Matrix operator*(const Matrix &lhs, double scalar);
        friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);

    private:
        std::vector<double> matrix_data;
        std::vector<double*> row_ptrs;
        int rows, columns;

};
