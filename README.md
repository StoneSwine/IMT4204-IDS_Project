# IMT4204-IDS_Project

## Installation: 
```bash
cmake . 
make
./task_1
```
 
## Quality assurance
- [x] valgrind
- [x] cppcheck

## Example output
```txt
[MAIN] Starting search with full matrix in memory
[MAIN] Search string: annealing
[DPSWFM]: Pattern --> Annual
[DPSWFM]: Size of data-structure: 344 B
[MAIN]: ed(Annual,annealing)=2
[DPSWFM]: Pattern --> Gral
[DPSWFM]: Size of data-structure: 248 B
[MAIN]: ed(Gral,annealing)=2
[DPSWFM]: Pattern --> Neal
[DPSWFM]: Size of data-structure: 248 B
[MAIN]: ed(Neal,annealing)=1
[DPSWFM]: Pattern --> ThisPatternIsWayTooDifferent
[DPSWFM]: Size of data-structure: 1400 B

- - - - - - - - - - - - - - - - 
[MAIN] Starting search with only columns in memory
[MAIN] Search string: annealing
[DPSWOC]: Pattern --> Annual
[DPSWOC]: Size of data-structure: 36 B
[MAIN]: ed(Annual,annealing)=2
[DPSWOC]: Pattern --> Gral
[DPSWOC]: Size of data-structure: 28 B
[MAIN]: ed(Gral,annealing)=2
[DPSWOC]: Pattern --> Neal
[DPSWOC]: Size of data-structure: 28 B
[MAIN]: ed(Neal,annealing)=1
[DPSWOC]: Pattern --> ThisPatternIsWayTooDifferent
[DPSWOC]: Size of data-structure: 124 B
```
