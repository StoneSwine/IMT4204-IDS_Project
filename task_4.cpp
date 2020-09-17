
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
    // Misc variables
    uint8_t delta ASCII;   // Length of the alphabet
    string patterns[] = {"tuned", "ThisIsTooDifferent"}; // P[m]/i --> tuned
    string T = "student"; // T[n]/j
    uint k = 2;         // amount of allowed differences

    int score;

    /*
     * Step 0: initialize deltas:
     * Horizontal delta: Dh[i,j] at (i,j) as C[i,j] - C[i,j-1]
     * Vertical delta:   Dv[i,j] as C[i,j] - C[i-1,j] for all (i,j) in [1,m]x[1,n]
     */
    uint32_t Pv;
    uint32_t Ph;
    uint32_t Mv;
    uint32_t Mh;
    uint32_t Xv;
    uint32_t Xh;

    // Process all the patterns
    for (const auto &P : patterns) {
        bool match = false;
        auto m = P.size(), n = T.size();
        /*
         * Step 1 - Alphabet preprocessing
         * O(ASCII + m) time.
         * Formula (5)
         */
        uint8_t Peq[delta];
        for (u_char s = 0; s < delta; ++s) {
            Peq[s] = 0;
        }
        for (u_char i : P) {
            Peq[i] = 1;
        }

        /*
         * Step 2 - initialize variables
         * 32 bit word (uint32_t) m <= 32.
         * Formula (6)
         */
        Pv = ~(~0u << m);
        Mv = 0;
        score = m;

        for (int j = 1; j <= n; ++j) {
            /*
             * Step 3 - The X-factors
             * Formula (8,10)
             */

            uint8_t Eq = Peq[T[j - 1]];
            Xv = Eq | Mv;
            Xh = (((Eq & Pv) + Pv) ^ Pv) | Eq;

            // Formula (4b)
            // Formula (7)
            Ph = Mv | ~(Xh | Pv);
            Mh = Pv & Xh;


            if (Ph & (1u << (m - 1u))) {
                score += 1;
            } else if (Mh & (1u << (m - 1u))) {
                score -= 1;
            }

            // Formula (4a)
            Ph <<= 1u;
            Ph <<= 1u;
            Pv = Mh | ~(Xv | Ph);
            Mv = Ph & Xv;

            if (score <= k) {
                printf("[MAIN]: Match found for %s and %s, at pos. %d with the cost %d\n", P.c_str(), T.c_str(),
                       j - 1, k);
                match = true;
            }
#ifdef DEBUG
            cout << "[DEBUG]" << endl;
            cout << "\tPv:" << bitset<32>(Pv) << endl;
            cout << "\tPh:" << bitset<32>(Ph) << endl;
            cout << "\tMv:" << bitset<32>(Mv) << endl;
            cout << "\tMh:" << bitset<32>(Mh) << endl;
            cout << "\tXv:" << bitset<32>(Xv) << endl;
            cout << "\tXh:" << bitset<32>(Xh) << endl;
            cout << "[DEBUG]" << endl;

#endif

        }
        if (!match) {
            printf("[MAIN]: Match not found for %s and %s, with the cost %d\n", P.c_str(), T.c_str(), k);
        }
    }
    return 0;
}