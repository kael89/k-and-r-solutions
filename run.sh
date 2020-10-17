#!/bin/bash

DIR=$(dirname "$0")
. ${DIR}/utils.sh

function get_exer_path() {
    chapter=$1
    exer=$2
    echo "chapter_$chapter/$chapter-$exer.c"
}

function print_exer_name() {
    chapter=$1
    exer=$2
    log_success "* $chapter-$exer.c"
}

function run_all() {
    log_success "Running all exercises..."

    local chapters=$(ls | grep chapter_ | sed -e 's/chapter_\(.*\)/\1/' | sort -n)
    local passed=0
    local skipped=0
    local failed=0

    for chapter in ${chapters[@]}; do
        local exers=$(ls "chapter_$chapter" | sed -e 's/.*-\(.*\).c/\1/' | sort -n)
        for exer in ${exers[@]}; do
            print_exer_name $chapter $exer

            local exer_path=$(get_exer_path $chapter $exer)
            cat $exer_path | grep @interactive >/dev/null 2>&1
            if [[ $? = 0 ]]; then
                log_info "  Interactive program, skipping..."
                skipped=$((skipped + 1))
            else
                run_one $exer_path
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

    output=$(./$exec_path)
    result=$?
    echo "$(echo "$output" | sed -e 's/\(.*\)/  \1/')"

    rm $exec_path
    return $result
}

if [ "$#" = 0 ]; then
    run_all
fi

print_exer_name $1 $2
run_one $(get_exer_path $1 $2)
exit $?
