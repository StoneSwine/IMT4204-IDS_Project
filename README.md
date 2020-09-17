# IMT4204-IDS_Project

## Installation: 
```bash
cmake .                   # Debug information disabled
cmake -DDEFINE_DEBUG=ON . # Debug information enabled
make 
./task_1
./task_4
```
 
## Quality assurance
- [x] valgrind
- [x] cppcheck

## Example output
Task 1:
```txt
$ ./task_1
[MAIN] Starting search with full matrix in memory
[MAIN] Search string: student
[DPSWFM]: Pattern: tuned
	[DPSWOC]: Match found for tuned and student, at pos. 3 with the cost 2
	[DPSWOC]: Match found for tuned and student, at pos. 4 with the cost 2
	[DPSWOC]: Match found for tuned and student, at pos. 5 with the cost 2
	[DPSWFM]: Size of data-structure: 248 B
[DPSWFM]: Pattern: ThisIsTooDifferent
	[DPSWFM]: Size of data-structure: 768 B
[MAIN]: Match not found for ThisIsTooDifferent and student, with the cost 2
- - - - - - - - - - - - - - - - 
[MAIN] Starting search with only columns in memory
[MAIN] Search string: student
[DPSWOC]: Pattern: tuned
	[DPSWOC]: Match found for tuned and student, at pos. 3 with the cost 2
	[DPSWOC]: Match found for tuned and student, at pos. 4 with the cost 2
	[DPSWOC]: Match found for tuned and student, at pos. 5 with the cost 2
	[DPSWOC]: Size of data-structure: 32 B
[DPSWOC]: Pattern: ThisIsTooDifferent
	[DPSWOC]: Size of data-structure: 84 B
[MAIN]: Match not found for ThisIsTooDifferent and student, with the cost 2
```
Task 4:
```txt
$ ./task_4
[MAIN]: Match found for tuned and student, at pos. 3 with the cost 2
[MAIN]: Match found for tuned and student, at pos. 4 with the cost 2
[MAIN]: Match found for tuned and student, at pos. 5 with the cost 2
[MAIN]: Match not found for ThisIsTooDifferent and student, with the cost 2
```
