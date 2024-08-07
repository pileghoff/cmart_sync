#!/bin/bash
set -e
gcc ./src/cmart_sync.c ./src/example.c -I./src -pthread -g
valgrind ./a.out