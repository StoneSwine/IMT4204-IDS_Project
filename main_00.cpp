#include <iostream>
#include <string>
#include <algorithm>    // std::min

using namespace std;

auto edSearch(const string &p, const string &T, uint64_t k = 2) {
    auto iLen = p.length() + 1, jLen = T.length() + 1;
    // Initialise the matrix
    int **M = new int *[iLen];
    for (int i = 0; i < iLen; ++i) {
        M[i] = new int[jLen]{0};
        M[i][0] = i;
    }

    // Operations on matrix.
    // Can possibly do this in a clever way to prevent the whole matrix from staying in memory at the same time...
    for (int i = 1; i < iLen; ++i) {
        for (int j = 1; j < jLen; ++j) {
            if (p[i - 1] == T[j - 1]) {
                M[i][j] = M[i - 1][j - 1];
            } else {
                M[i][j] = 1 + min({M[i - 1][j - 1], M[i - 1][j], M[i][j - 1]});
            }
        }
    }

    for (int j = 1; j < jLen; ++j) {
        if (M[iLen - 1][j] <= k) {
            printf("%d ", M[iLen - 1][j]);
        }
    }

    // Free memory
    for (int i = 0; i < iLen; ++i)
        delete[] M[i];
    delete[] M;

    return 0;
}

int main() {
    string p, T;
    p = "annual";
    T = "annealing";
    printf("%d", edSearch(p, T, 2));
    return 0;
}
