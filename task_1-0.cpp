#include <iostream>
#include <string>
#include <algorithm>    // std::min
#include <vector>

using namespace std;

// #define DEBUG = 0

auto edSearch(const string &p, const string &T, uint64_t k = 2) {
    auto m = p.length() + 1, n = T.length() + 1;
    vector<int> ret;
    // Initialise the matrix
    int **M = new int *[m];
    for (int i = 0; i < m; ++i) {
        M[i] = new int[n]{0};
        M[i][0] = i;
    }

    // Operations on matrix.
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (p[i - 1] == T[j - 1]) { // match
                M[i][j] = M[i - 1][j - 1];
            } else {
                M[i][j] = 1 + min({M[i - 1][j - 1], M[i - 1][j], M[i][j - 1]});
            }
        }
        if (M[m - 1][j] <= k) {
            ret.push_back(M[m - 1][j]);
        }
    }

#ifdef DEBUG
    cout << endl << "<DEBUG>" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "</DEBUG>" << endl;
#endif

    cout << // the size of the data
         m * n * sizeof(int) +

         // the size of the inner pointers / objects
         m * sizeof M[0] +

         // the size of the outer pointer
         sizeof M << "B";

    // Free memory
    for (int i = 0; i < m; ++i)
        delete[] M[i];
    delete[] M;

    return ret;
}

int main() {
    string patterns[] = {"annual", "Neal", "gral"}; // Patterns (IDS DB)
    string T = "annealing"; // Search string
    for (const auto &p : patterns) {
        printf("%s\t", p.c_str());
        for (auto i : edSearch(p, T, 2)) {
            printf(" %d ", i);
        }
        printf("\n");
    }
    return 0;
}
