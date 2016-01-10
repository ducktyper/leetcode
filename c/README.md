## Solutions in C

### Run test
Execute test.sh with problem number to run test.

e.g. Run leetcode_001_two_sum_test.c having 5 assertions
```
sh test.sh 001
.....
```
Add -a to run all tests (except helper).

```
sh test.sh all
leetcode_001_two_sum_test.c 
.....
leetcode_002_add_two_numbers_test.c 
....
```

Add -b to run benchmark (Shows how many runs in 2 seconds).

e.g. Run leetcode_001_two_sum_test.c having 5 assertions with benchmark
```
sh test.sh 001 -b
.....
Benchmark: 225 runs in 2 seconds
```

e.g. Test helper.c
```
sh test.sh helper
```
