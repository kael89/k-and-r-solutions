#!/bin/bash

DIR=$(dirname "$0")
. ${DIR}/utils.sh

function run_all() {
    log_success "Running all exercises..."

    local chapter_folders=$(ls | grep chapter_)
    local passed=0
    local skipped=0
    local failed=0

    for folder in ${chapter_folders[@]}; do
        local ex_files=$(ls $folder | grep .c)
        for ex_file in ${ex_files[@]}; do
            print_filename $ex_file

            local exec_path="$folder/$ex_file"
            cat $exec_path | grep @interactive >/dev/null 2>&1
            if [[ $? = 0 ]]; then
                log_info "  Interactive program, skipping..."
                skipped=$((skipped + 1))
            else
                run_one $exec_path
                if [[ $? > 0 ]]; then
                    failed=$((failed + 1))
                else
                    passed=$((passed + 1))
                fi
            fi
            echo
        done
    done

    print_results $passed $skipped $failed

    if [[ $failed > 0 ]]; then
        exit 1
    fi
    exit 0
}

function print_results() {
    local passed=$1
    local skipped=$2
    local failed=$3

    log_success "-------"
    log_success "Results"
    log_success "-------"
    log_success "Passed:  $passed"
    log_warn "Skipped: $skipped"
    log_error "Failed:  $failed"
}

function run_one() {
    local exec_path="out"
    gcc -Wall -o $exec_path $1 \
        lib/char.c lib/number.c lib/stack.c lib/string.c lib/test.c \
        -lm

    ./$exec_path
    result=$?

    rm $exec_path
    return $result
}

function print_filename() {
    log_success "* $1"
}

if [ "$#" = 0 ]; then
    run_all
fi

chapter=$1
exercise=$2
folder="chapter_$chapter"
ex_file="$chapter-$exercise.c"

print_filename $ex_file
run_one "$folder/$ex_file"
exit $?
