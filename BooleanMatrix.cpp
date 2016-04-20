#include "BooleanMatrix.hpp"
// typedef bool matrix_element_type;
BooleanMatrix::BooleanMatrix(const BooleanMatrix & a) : Matrix(a) {}
BooleanMatrix::BooleanMatrix(int r, int c) : Matrix(r, c) {}
bool BooleanMatrix::replace(matrix_element_type e, int r, int c) {
    return Matrix::replace(e, r, c);
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix &a) {
    // int getRow() const;
    // int getColums() const;
    // matrix_element_type getElement(int r, int c) const;
    BooleanMatrix temp(row, columns);
    if (a.getRow() != row || a.getColums() != columns)
        return temp;
    for (int i = 1; i <= getRow(); i++) {
        for (int j = 1; j <= getColums(); j++) {
            if (getElement(i, j) && a.getElement(i, j))
                temp.replace(1, i, j);
            else
                temp.replace(0, i, j);
        }
    }
    return temp;
}
BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix &a) {
    BooleanMatrix temp(row, columns);
    if (a.getRow() != row || a.getColums() != columns)
        return temp;
    for (int i = 1; i <= getRow(); i++) {
        for (int j = 1; j <= getColums(); j++) {
            if (getElement(i, j) || a.getElement(i, j))
                temp.replace(1, i, j);
            else
                temp.replace(0, i, j);
        }
    }
    return temp;
}
BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix &a) const {
    BooleanMatrix temp(this->getRow(), a.getColums());
    if (a.getRow() != columns)
        return temp;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= a.getColums(); j++) {
            for (int k = 1; k <= columns; k++) {
                if (getElement(i, k) && a.getElement(k, j))
                    temp.replace(1, i, j);
            }
        }
    }
    return temp;
}
