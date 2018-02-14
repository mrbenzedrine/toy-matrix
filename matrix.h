#include <vector>
#include <iostream>

class Matrix {

    public:
        Matrix(int ROWS, int COLUMNS, double value = 0.0);

        void display();

        const double& operator()(int i, int j) const;

    private:
        std::vector<double> matrix_data;
        std::vector<double*> row_ptrs;
        int rows, columns;

};
