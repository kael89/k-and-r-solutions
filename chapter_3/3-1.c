/**
 * @description Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time. 
 */

#include <stdio.h>
#include <sys/time.h>
#include "../lib.h"

#define ONE_MILLION 1000000

int binsearch_original(int x, int v[], int n);
int binsearch_modified(int x, int v[], int n);
void print_test_suite(int v[], int n, int test_data[][2], int test_data_len);
void run_benchmarks();
double run_benchmark(int (*binsearch)(int x, int v[], int n), int x, int v[], int n);
void test_correctness();

int main()
{
    test_correctness();
    run_benchmarks();
}

void test_correctness()
{
    printf("Correctness Tests\n");
    printf("-----------------\n");

    int empty_v[] = {};
    int empty_v_data[2][2] = {{0, -1}, {1, -1}};
    print_test_suite(empty_v, 0, empty_v_data, 2);

    int unique_v[3] = {0, 1, 3};
    int unique_v_data[3][2] = {
        {1, 1},
        {3, 2},
        {4, -1},
    };
    print_test_suite(unique_v, 3, unique_v_data, 3);

    int less_than_min_v[3] = {5, 6, 7};
    int less_than_min_data[1][2] = {
        {3, -1},
    };
    print_test_suite(less_than_min_v, 3, less_than_min_data, 1);

    int greater_than_max_v[3] = {0, 1, 2};
    int test_data[1][2] = {
        {3, -1},
    };
    print_test_suite(greater_than_max_v, 3, test_data, 1);

    int duplicate_v[5] = {0, 0, 1, 1, 3};
    int duplicate_data[3][2] = {{0, 0}, {1, 2}};
    print_test_suite(duplicate_v, 5, duplicate_data, 3);
}

void run_benchmarks()
{
    printf("\n");
    printf("Benchmarks\n");
    printf("----------\n");

    int n = 100;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }

    int case_x[] = {0, n - 1, n / 2, n / 2 + 1, -1, n + 1};
    char descriptions[][20] = {"Left boundary", "Right boundary", "Middle", "Deep search", "Less than min", "Greater than max"};
    int case_count = sizeof(case_x) / sizeof(int);
    double results[case_count][2];

    for (int i = 0; i < case_count; i++)
    {
        int x = case_x[i];
        results[i][0] = run_benchmark(binsearch_original, x, v, n);
        results[i][1] = run_benchmark(binsearch_modified, x, v, n);
    }

    printf("|    Description   | Original | Modified |\n");
    printf("| ---------------- | -------- | -------- |\n");
    for (int i = 0; i < case_count; i++)
    {

        printf("| %-16s | %8d | %8d | \n", descriptions[i], (int)results[i][0], (int)results[i][1]);
    }
}

double run_benchmark(int (*binsearch)(int x, int v[], int n), int x, int v[], int n)
{
    struct timeval start, stop;
    gettimeofday(&start, NULL);

    for (long i = 0; i < 5 * ONE_MILLION; i++)
    {
        binsearch(x, v, n);
    }

    gettimeofday(&stop, NULL);
    double secs = (stop.tv_sec - start.tv_sec);
    double millisecs = (stop.tv_usec - start.tv_usec) / 1000;
    return secs * 1000 + millisecs;
}

void print_test_suite(int v[], int n, int test_data[][2], int test_data_len)
{
    printf("Array: ");
    print_int_array(v, n);
    printf("\n");

    for (int i = 0; i < test_data_len; i++)
    {
        int search = test_data[i][0];
        int expected = test_data[i][1];
        printf("Search: %2d, Expected: %2d", search, expected);
        test_equal_ints(binsearch_original(search, v, n), expected);
        printf("\n");
    }
    printf("\n");
}

int binsearch_modified(int x, int v[], int n)
{
    if (n < 1)
    {
        return -1;
    }

    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low < high && v[mid] != x)
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}

int binsearch_original(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1;
}
