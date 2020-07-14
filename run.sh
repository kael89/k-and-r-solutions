#!/bin/bash

set -e

PROGRAM_FILE="out"

chapter=$1
exercise=$2

gcc -Wall -o $PROGRAM_FILE "chapter_$chapter/$chapter-$exercise.c" \
    lib/char.c lib/number.c lib/stack.c lib/string.c \
    -lm
./$PROGRAM_FILE
rm $PROGRAM_FILE