#include <iostream>
#include <string>
#include <algorithm>    // std::min
#include <vector>

using namespace std;

/* Dynamic programming approach to approximate search
 * O(nm) complexity with (O2m) space
 */
auto DPSearch(const string &p, const string &T, const int k) {
    auto m = p.size() + 1, n = T.size() + 1;
    vector<int> ret;
    vector<int> C(m);
    vector<int> Cpr(m);
    // initialise the vectors
    for (int i = 0; i <= m; ++i) {
        C[i] = Cpr[i] = i;
    }

    // operations on columns
    for (int j = 1; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (p[i - 1] == T[j - 1]) { // match
                Cpr[i] = C[i - 1];
            } else {    //       substitution, deletion, insertion
                Cpr[i] = (1 + min({C[i - 1], Cpr[i - 1], C[i]}));
            }
        }

        if (Cpr[m - 1] <= k) {
            ret.push_back(Cpr[m - 1]);
        }
        swap(C, Cpr);
    }

    cout << // the size of the data
         C.size() * sizeof(int) +

         // the size of the vector object
         sizeof C
         << "B";


    return ret;
}

int main() {
    string patterns[] = {"annual", "Neal", "gral"}; // Patterns (IDS DB)
    string T = "annealing"; // Search string
    for (const auto &p : patterns) {
        printf("%s\t", p.c_str());
        for (auto i : DPSearch(p, T, 2)) {
            printf(" %d ", i);
        }
        printf("\n");
    }
    return 0;
}
