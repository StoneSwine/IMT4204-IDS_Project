# IMT4204-IDS_Project

## Installation: 
```bash
cmake .                   # Debug information disabled
cmake -DDEFINE_DEBUG=ON . # Debug information enabled
make 
./task_1
```
 
## Quality assurance
- [x] valgrind
- [x] cppcheck

## Example output
```txt
[MAIN] Starting search with full matrix in memory
[MAIN] Search string: student
[DPSWFM]: Pattern --> tuned
[DPSWFM]: Size of data-structure: 248 B
[MAIN]: ed(tuned,student)=2
[DPSWFM]: Pattern --> ThisIsTooDifferent
[DPSWFM]: Size of data-structure: 768 B
- - - - - - - - - - - - - - - - 
[MAIN] Starting search with only columns in memory
[MAIN] Search string: student
[DPSWOC]: Pattern --> tuned
[DPSWOC]: Size of data-structure: 32 B
[MAIN]: ed(tuned,student)=2
[DPSWOC]: Pattern --> ThisIsTooDifferent
[DPSWOC]: Size of data-structure: 84 B
```
