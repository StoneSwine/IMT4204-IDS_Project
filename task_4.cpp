
#include <iostream>

#ifdef DEBUG

#include <bitset>

#endif

#define ASCII = 255
using namespace std;

/**
 * Implementation of the Fast bit-vector algorithm for approximate search. Runs in O(nm/w) time.
 * Myers, G., 1999. A fast bit-vector algorithm for approximate string matching based on dynamic programming. Journal of the ACM (JACM) 46, 395–415.
 * @return
 */
int main() {
    // Variables
    uint8_t sigma ASCII;  // Length of the alphabet
    string patterns[] = {"annual", "SomethingTooDifferent"};// P[m]/i
    string T = "annealing"; // T[n]/j
    uint8_t k = 2;           // amount of allowed differences

    int score;
    uint64_t Pv, Mv, Ph, Mh, Xv, Xh;

    // Process all the patterns
    for (const auto &P : patterns) {
        bool match = false;
        auto m = P.size(), n = T.size();
        /*
         * Step 0 - Alphabet preprocessing
         * O(ASCII + m) time.
         * Formula (5)
         */
        uint64_t Peq[sigma];
        uint64_t Eq;
        for (uint s = 0; s < sigma; ++s) {
            Peq[s] = 0;
        }
        for (uint j = 0; j < m; ++j) {
            Peq[P[j]] |= (1ull << (j));
        }
        /*
         * initialize variables
         * 32 bit word (uint32_t) m <= 32.
         * Formula (6)
         */
        Pv = (~0ull); // 1
        Mv = 0ull;    // 0
        score = m;

        for (int j = 1; j <= n; ++j) {

#ifdef DEBUG
            cout << "[DEBUG]: STAGE 0" << endl;
            cout << "\tj_:" << j-1 << endl;
            cout << "\tTi:" << T[j-1] << endl;
            cout << "\tPv:" << bitset<64>(Pv) << endl;
            cout << "\tMv:" << bitset<64>(Mv) << endl;
#endif

            /*
             * Step 1: (Mv, Pv) Dv_{j-1} are used to compute (Mh, Ph) Dh_{i}
             * Formula (8,10)
             */
            Eq = Peq[T[j - 1]];
            Xv = Eq | Mv;
            Xh = (((Eq & Pv) + Pv) ^ Pv) | Eq;

            Ph = Mv | ~(Xh | Pv); // Formula (4b)
            Mh = Pv & Xh;         // Formula (7)


#ifdef DEBUG
            cout << "[DEBUG]: STAGE 1" << endl;
            cout << "\tXv:" << bitset<64>(Xv) << endl;
            cout << "\tXh:" << bitset<64>(Xh) << endl;
            cout << "\tEq:" << (u_char) Eq << endl;

#endif

            /*
             * Score is checked in between the steps (bottom horizontal delta)
             */
            if (Ph & (1ull << (m - 1))) {
                score += 1;
            } else if (Mh & (1ull << (m - 1))) {
                score -= 1;
            }

#ifdef DEBUG
            cout << "[DEBUG]: score:" << endl;
            cout << "\tPh:" << bitset<64>(Ph) << endl;
            cout << "\tMh:" << bitset<64>(Mh) << endl;
            cout << "\tmd:" << bitset<64>((1u << (m - 1))) << endl;

#endif

            /*
             * Step 2: (Mh, Ph) Dh_{i-1} are used to compute (Mv, Pv) Dv_{j}
             * Formula (4a)
             */

            Ph <<= 1ull;
            Mh <<= 1ull;

            Pv = Mh | ~(Xv | Ph);
            Mv = Ph & Xv;

            if (score <= k) {
                printf("[MAIN]: Match found for %s and %s, at pos. %d with the cost %d\n", P.c_str(), T.c_str(),
                       j - 1, score);
                match = true;
            }

#ifdef DEBUG
            cout << "[DEBUG]: STAGE 2" << endl;
            cout << "\tPv:" << bitset<64>(Pv) << endl;
            cout << "\tMv:" << bitset<64>(Mv) << endl;
            cout << "\tSc:" << score << endl << endl;

#endif

        }
        if (!match) {
            printf("[MAIN]: Match not found for %s and %s, with the cost %d\n", P.c_str(), T.c_str(), k);
        }
    }
    return 0;
}