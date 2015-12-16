//
// Created by joetoth on 12/9/15.
//

#ifndef MYPROJECT_MATRIX_H
#define MYPROJECT_MATRIX_H

#include <stddef.h>
#include <bits/c++config.h>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template<typename Condition>
using EnableIf = typename std::enable_if<Condition::value>::type;

template<class T>
class Matrix {
    int rows;
    int columns;
    vector<vector<T>> matrix;

public:
//    template<class T, size_t ROW, size_t COL> using NativeMatrix = T[ROW][COL];

    Matrix(const int rows, const int columns) : rows(rows), columns(columns), matrix(rows, vector<T>(columns)) {
    }

    Matrix(initializer_list<std::initializer_list<T>> data) {
        rows = data.size();
        columns = data.begin()->size();
        matrix = vector<vector<T>>(rows, vector<T>(columns));

        int row = 0;
        for (auto data_row : data) {
            int col = 0;
            for (auto data_col : data_row) {
                matrix[row][col] = data_col;
                col++;
            }
            row++;
        }
    }

    vector<T> &operator[](std::size_t idx) {
        return matrix[idx];
    }

    vector<T> const &operator[](std::size_t idx) const {
        return matrix[idx];
    }


    void print() {
        cout << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

//    value_t& operator[](std::size_t idx)       { return mVector[idx]; };
//    const value_t& operator[](std::size_t idx) const { return mVector[idx]; };
    Matrix<T> operator^(int pow) {
        Matrix tmp(*this); // copy
        for (int i = 0; i < pow - 1; ++i) {
            tmp = tmp * *this;
        }
        return tmp;
    }

    Matrix<T> operator-(Matrix<T> &o) {
        Matrix m(rows, columns);
        // TODO: validation
        for (int i = 0; i < o.rows; ++i) {
            for (int j = 0; j < o.columns; ++j) {
                m[i][j] = matrix[i][j] - o.matrix[i][j];
            }
        }
//        Matrix tmp(*this); // copy
        return m;   // return old value
    }

    bool operator==(T number) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (matrix[i][j] != number) {
                    return false;
                }
            }
        }

        return true;
    }

    Matrix<T> operator*(T number) {
        Matrix m(rows, columns);
        // TODO: validation
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                m[i][j] = matrix[i][j] * number;
            }
        }
        return m;
    }

    Matrix<T> operator+(Matrix<T> o) {
        Matrix m(rows, columns);
        // TODO: validation
        for (int i = 0; i < o.rows; ++i) {
            for (int j = 0; j < o.columns; ++j) {
                m[i][j] = matrix[i][j] + o.matrix[i][j];
            }
        }
//        Matrix tmp(*this); // copy
        return m;   // return old value
    }

    Matrix<T> operator*(Matrix<T> &o) {
        assert(o.columns == rows || (fprintf(stderr, "lhs rows: %d, rhs columns: %d\n", rows, o.columns) && 0));
        assert(o.rows == columns || (fprintf(stderr, "lhs columns: %d, rhs rows: %d\n", columns, o.rows) && 0));

        int x = max(o.columns, o.rows);

        Matrix m(x, x);
        for (int m1row = 0; m1row < rows; ++m1row) {
            for (int m2col = 0; m2col < o.columns; ++m2col) {
                T val = 0;
                for (int z = 0; z < columns; ++z) {
                    val += matrix[m1row][z] * o.matrix[z][m2col];
                }
                m[m1row][m2col] = val;
            }
        }
        return m;   // return old value
    }

};


#endif //MYPROJECT_MATRIX_H
