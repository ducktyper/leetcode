#!/bin/bash

if [ "$1" = "-a" ]; then
    for line in $(find leetcode_*_test.c); do
        echo "\n$line "
        gcc -Wall helper.c $line && ./a.out
    done
    echo ''
    exit 0
fi

if [ "$1" = "helper" ]; then
    gcc -Wall helper.c helper_test.c && ./a.out
    echo ''
    exit 0
fi

file=$(find leetcode_$1*_test.c | head -n1)
if [ -z "$file" ]; then
    exit 1
fi

gcc -Wall helper.c $file && ./a.out
echo ''

if [ "$2" = "-b" ]; then
    printf "Benchmark: "
    now=$(date +%s)
    while [[ $(date +%s) -eq $now ]]; do
    :
    done

    duration=2
    n=0
    until=$(($now + duration))
    while [[ $(date +%s) -le $until ]]; do
        ./a.out &> /dev/null
        n=$((n+1))
    done
    echo "$n runs in $duration seconds"
fi
