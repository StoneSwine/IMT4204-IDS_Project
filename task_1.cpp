#include <iostream>
#include <string>
#include <algorithm>    // std::min
#include <vector>

#ifdef DEBUG

#include <iomanip>

#endif

using namespace std;

/**
 * Dynamic programming approach to approximate search
 * O(nm) complexity with O(mn) space
 *
 * @param P
 * @param T
 * @param k
 * @return
 */
bool DPSearchWithFullMatrix(const string &P, const string &T, const uint k) {
    auto m = P.length() + 1, n = T.length() + 1;
    bool match = false;

    // Initialise the matrix
    int **M = new int *[m];
    for (int i = 0; i < m; ++i) {
        M[i] = new int[n]{0};
        M[i][0] = i;
    }

    printf("[DPSWFM]: Pattern: %s\n", P.c_str());

    // Operations on matrix.
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (P[i - 1] == T[j - 1]) { // match
                M[i][j] = M[i - 1][j - 1];
            } else {
                M[i][j] = 1 + min({M[i - 1][j - 1], M[i - 1][j], M[i][j - 1]});
            }
        }
        if (M[m - 1][j] <= k) {
            printf("\t[DPSWOC]: Match found for %s and %s, at pos. %d with the cost %d\n", P.c_str(), T.c_str(),
                   j - 1, k);
            match = true;
        }
    }

#ifdef DEBUG

    cout << "[DEBUG]" << endl << "\t\t";
    for (int i = 0; i < n; ++i) {
        cout << setfill(' ') << setw(to_string(m).length()) << T[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        if (i != 0) {
            cout << "\t" << P[i - 1];
        } else {
            cout << "\t ";
        }
        cout << " ";
        for (int j = 0; j < n; ++j) {
            cout << setfill('0') << setw(to_string(m).length()) << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << "[DEBUG]" << endl;

#endif

    //                        the size of the data + the size of the inner pointers + the size of the outer pointer
    printf("\t[DPSWFM]: Size of data-structure: %lu B\n", m * n * sizeof(int) + m * sizeof M[0] + sizeof M);

    // Free memory
    for (int i = 0; i < m; ++i)
        delete[] M[i];
    delete[] M;

    return match;
}

/**
 * Dynamic programming approach to approximate search
 * O(nm) complexity with O(m) space
 * @param P
 * @param T
 * @param k
 * @return
 */
bool DPSearchWithOnlyColumns(const string &P, const string &T, const uint k) {
    auto m = P.size() + 1, n = T.size() + 1;
    bool match = false;

    int *C = new int[m];
    int *Cpr = new int[m];
    // initialise the vectors
    for (int i = 0; i < m; ++i) {
        C[i] = Cpr[i] = i;
    }

    printf("[DPSWOC]: Pattern: %s\n", P.c_str());

    // operations on columns
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (P[i - 1] == T[j - 1]) { // match
                Cpr[i] = C[i - 1];
            } else {    //       substitution, deletion, insertion
                Cpr[i] = (1 + min({C[i - 1], Cpr[i - 1], C[i]}));
            }
        }

        if (Cpr[m - 1] <= k) {
            printf("\t[DPSWOC]: Match found for %s and %s, at pos. %d with the cost %d\n", P.c_str(), T.c_str(),
                   j - 1, k);
            match = true;
        }
        swap(C, Cpr);

    }
    //                                                 the size of the data   + the size of the outer pointer
    printf("\t[DPSWOC]: Size of data-structure: %lu B\n", m * sizeof(int) + sizeof C);

    delete[] C;
    delete[] Cpr;

    return match;
}


int main() {
    string patterns[] = {"tuned", "ThisIsTooDifferent"}; // Patterns (IDS DB)
    string T = "student"; // Search string
    uint k = 2; // amount of differences

    printf("[MAIN] Starting search with full matrix in memory\n");
    printf("[MAIN] Search string: %s\n", T.c_str());
    for (const auto &P : patterns) {
        if (!DPSearchWithFullMatrix(P, T, k)) {
            printf("[MAIN]: Match not found for %s and %s, with the cost %d\n", P.c_str(), T.c_str(), k);
        }
    }
    printf("- - - - - - - - - - - - - - - - \n");

    printf("[MAIN] Starting search with only columns in memory\n");
    printf("[MAIN] Search string: %s\n", T.c_str());
    for (const auto &P : patterns) {
        if (!DPSearchWithOnlyColumns(P, T, k)) {
            printf("[MAIN]: Match not found for %s and %s, with the cost %d\n", P.c_str(), T.c_str(), k);
        }
    }
    return 0;
}
