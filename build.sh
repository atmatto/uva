#!/bin/bash

g++ -Wall -Wextra -O3 -static -std=c++17 -o test $@ # https://oi.edu.pl/l/28oi_ustalenia_techniczne/
# g++ -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -o test $@ # UVa