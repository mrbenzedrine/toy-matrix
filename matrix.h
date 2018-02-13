#include <vector>

class Matrix {

    public:
        Matrix(int ROWS, int COLUMNS, double value = 0.0);

    private:
        std::vector<double> matrix_data;
        std::vector<double*> row_ptrs;
        int rows, columns;

};
