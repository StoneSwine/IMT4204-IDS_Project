# IMT4204-IDS_Project

## Installation: 
```bash
cmake .                   # Debug information disabled
cmake -DDEFINE_DEBUG=ON . # Debug information enabled
make 
./bin/task_1
./bin/task_4
```
 
## Quality assurance
- [x] valgrind
- [x] cppcheck

## Example output (without debug information enabled)
Task 1:
```txt
$ ./bin/task_1
[MAIN] Starting search with full matrix in memory
[MAIN] Search string: annealing
[DPSWFM]: Pattern: annual
	[DPSWOC]: Match found for annual and annealing, at pos. 4 with the cost 2
	[DPSWOC]: Match found for annual and annealing, at pos. 5 with the cost 1
	[DPSWOC]: Match found for annual and annealing, at pos. 6 with the cost 2
	[DPSWFM]: Size of data-structure: 344 B
[DPSWFM]: Pattern: SomethingTooDifferent
	[DPSWFM]: Size of data-structure: 1064 B
[MAIN]: Match not found for SomethingTooDifferent and annealing, with the cost 2
- - - - - - - - - - - - - - - - 
[MAIN] Starting search with only columns in memory
[MAIN] Search string: annealing
[DPSWOC]: Pattern: annual
	[DPSWOC]: Match found for annual and annealing, at pos. 4 with the cost 2
	[DPSWOC]: Match found for annual and annealing, at pos. 5 with the cost 1
	[DPSWOC]: Match found for annual and annealing, at pos. 6 with the cost 2
	[DPSWOC]: Size of data-structure: 36 B
[DPSWOC]: Pattern: SomethingTooDifferent
	[DPSWOC]: Size of data-structure: 96 B
[MAIN]: Match not found for SomethingTooDifferent and annealing, with the cost 2
```
Task 4:
```txt
$ ./bin/task_4
[MAIN]: Match found for annual and annealing, at pos. 4 with the cost 2
[MAIN]: Match found for annual and annealing, at pos. 5 with the cost 1
[MAIN]: Match found for annual and annealing, at pos. 6 with the cost 2
[MAIN]: Match not found for SomethingTooDifferent and annealing, with the cost 2
```
