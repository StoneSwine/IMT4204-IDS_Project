#include <iostream>
#include <string>
#include <algorithm>    // std::min
#include <vector>

using namespace std;

// #define DEBUG = 0


/* Dynamic programming approach to approximate search
 * O(nm) complexity with O(mn) space
 */
auto DPSearchWithFullMatrix(const string &p, const string &T, const int k) {
    auto m = p.length() + 1, n = T.length() + 1;
    u_long minDist = UINTMAX_MAX;
    // Initialise the matrix
    int **M = new int *[m];
    for (int i = 0; i < m; ++i) {
        M[i] = new int[n]{0};
        M[i][0] = i;
    }

    printf("[DPSWFM]: Pattern --> %s\n", p.c_str());

    // Operations on matrix.
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (p[i - 1] == T[j - 1]) { // match
                M[i][j] = M[i - 1][j - 1];
            } else {
                M[i][j] = 1 + min({M[i - 1][j - 1], M[i - 1][j], M[i][j - 1]});
            }
        }
        if (M[m - 1][j] <= k && M[m - 1][j] < minDist) {
            minDist = M[m - 1][j];
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

    //                        the size of the data + the size of the inner pointers + the size of the outer pointer
    printf("[DPSWFM]: Size of data-structure: %lu B\n", m * n * sizeof(int) + m * sizeof M[0] + sizeof M);

    // Free memory
    for (int i = 0; i < m; ++i)
        delete[] M[i];
    delete[] M;

    return minDist;
}


/* Dynamic programming approach to approximate search
 * O(nm) complexity with O(m) space
 */
auto DPSearchWithOnlyColumns(const string &p, const string &T, const int k) {
    auto m = p.size() + 1, n = T.size() + 1;
    u_long minDist = UINTMAX_MAX;
    int *C = new int[m];
    int *Cpr = new int[m];
    // initialise the vectors
    for (int i = 0; i < m; ++i) {
        C[i] = Cpr[i] = i;
    }

    printf("[DPSWOC]: Pattern --> %s\n", p.c_str());

    // operations on columns
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (p[i - 1] == T[j - 1]) { // match
                Cpr[i] = C[i - 1];
            } else {    //       substitution, deletion, insertion
                Cpr[i] = (1 + min({C[i - 1], Cpr[i - 1], C[i]}));
            }
        }

        if (Cpr[m - 1] <= k && Cpr[m - 1] < minDist) {
            minDist = Cpr[m - 1];
        }
        swap(C, Cpr);

    }
    //                                                 the size of the data   + the size of the outer pointer
    printf("[DPSWOC]: Size of data-structure: %lu B\n", m * sizeof(int) + sizeof C);

    delete[] C;
    delete[] Cpr;

    return minDist;
}

int main() {
    string patterns[] = {"Annual", "Gral", "Neal", "ThisPatternIsWayTooDifferent"}; // Patterns (IDS DB)
    string T = "annealing"; // Search string
    printf("[MAIN] Starting search with full matrix in memory\n");
    printf("[MAIN] Search string: %s\n", T.c_str());
    for (const auto &p : patterns) {
        auto retDist = DPSearchWithFullMatrix(p, T, 2);
        if (retDist != UINTMAX_MAX) {
            printf("[MAIN]: ed(%s,%s)=%lu\n", p.c_str(), T.c_str(), retDist);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - \n");

    printf("[MAIN] Starting search with only columns in memory\n");
    printf("[MAIN] Search string: %s\n", T.c_str());
    for (const auto &p : patterns) {
        auto retDist = DPSearchWithOnlyColumns(p, T, 2);
        if (retDist != UINTMAX_MAX) {
            printf("[MAIN]: ed(%s,%s)=%lu\n", p.c_str(), T.c_str(), retDist);
        }
    }
    return 0;
}
