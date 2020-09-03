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
[DPSWFM] Searching for 'annealing' in 'Annual'
[DPSWFM] Size of data-structure: 344 B
[MAIN]: ed(Annual,annealing)=2
[DPSWFM] Searching for 'annealing' in 'Gral'
[DPSWFM] Size of data-structure: 248 B
[MAIN]: ed(Gral,annealing)=2
[DPSWFM] Searching for 'annealing' in 'Neal'
[DPSWFM] Size of data-structure: 248 B
[MAIN]: ed(Neal,annealing)=1
[DPSWFM] Searching for 'annealing' in 'ThisPatternIsWayTooDifferent'
[DPSWFM] Size of data-structure: 1400 B

- - - - - - - - - - - - - - - - 
[MAIN] Starting search with only columns in memory
[MAIN] Search string: annealing
[DPSWOC] Searching for 'annealing' in 'Annual'
[DPSWOC] Size of data-structure: 36 B
[MAIN]: ed(Annual,annealing)=2
[DPSWOC] Searching for 'annealing' in 'Gral'
[DPSWOC] Size of data-structure: 28 B
[MAIN]: ed(Gral,annealing)=2
[DPSWOC] Searching for 'annealing' in 'Neal'
[DPSWOC] Size of data-structure: 28 B
[MAIN]: ed(Neal,annealing)=1
[DPSWOC] Searching for 'annealing' in 'ThisPatternIsWayTooDifferent'
[DPSWOC] Size of data-structure: 124 B

Process finished with exit code 0
```
