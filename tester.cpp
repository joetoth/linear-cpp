#include "gtest/gtest.h"


#include <map>
#include <math.h>       /* pow */
#include "Matrix.h"

using namespace std;

//template<class T, size_t ROW, size_t COL> using Matrix = std::array<std::array<T, COL>, ROW>;
//template <class T, size_t ROW, size_t COL> using NativeMatrix = T[ROW][COL];
//
//
//template<typename T, unsigned long N>
//array<T, N> &operator+=(array<T, N> &thi, const array<T, N> &oth) {
//    for (int i = 0; i < N; ++i)
//        thi.at(i) += oth.at(i);
//    return thi;
//}
//
//template<typename T, unsigned long N>
//array<T, N> operator+(const array<T, N> &a, const array<T, N> &b) {
//    array<T, N> sum = a;
//    sum += b;
//    return sum;
//}

string parseline(std::string line) {

    long count = stol(line);
    unsigned long long m = (unsigned long long) (pow(10, 9) + 7);
//    long umm = pow(1000000, 3);
//    printf("\ncount=%lu, pow=%ldx\n", count, umm);
    double p = pow(count, 2);
    cout << p << endl;
    unsigned long long a = 2;
//    printf("%d mod %lu = %lu\n", p, m, a);
    return std::to_string(a);
}

int parsemain(istream &is) {

    int cases = 0;
    for (std::string line; std::getline(is, line);) {
        if (cases == 0) {
            cases = atoi(line.c_str());
            continue;
        }
        cout << parseline(line) << endl;
    }

    return 0;
}

// https://www.hackerrank.com/challenges/linear-algebra-foundations-6-the-nsupthsup-power-of-a-matrix
TEST(Dummy, find_x_and_y) {
    Matrix<int> m1({{1, 1, 0},
                    {0, 1, 0},
                    {0, 0, 1}});

    Matrix<int> I({{1, 0, 0},
                   {0, 1, 0},
                   {0, 0, 1}});


    int x1, y1 = 0;

    for (int x = -10; x < 10; ++x) {
        for (int y = -10; y < 10; ++y) {
            auto sol = (m1 ^ 2) + (m1 * x) + (I * y);
            if (sol == 0) {
                cout << "FOUND" << endl;
                x1 = x;
                y1 = y;
                x, y = 10;
            }
        }
    }

    m1.print();
    cout << endl << x1 << "," << y1 << endl;
}


TEST(Dummy, foobar) {
    Matrix<long> m1({{-2, 9},
                     {1,  4}});

//    auto m3 = Matrix<long>(m1);
//    for (int i = 0; i < 4; ++i) {
//        m3 = m1 * m3;
//        m3.print();
//
// }

    for (int i = 0; i < 11; ++i) {
        (m1 ^ i).print();
    }

    // A2 + xA + yI = 0
}

TEST(Dummy, eigenvalue) {
    Matrix<long> m1({{0,  1},
                     {-2, -3}});



}
