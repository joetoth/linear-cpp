# linear-cpp
C++ Linear Algebra Library

Uses C++ operators intuitively (I think) so you can do things like:

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
