/**
 * @description Our binary search makes two tests inside the loop, when one would suffice (at
 * the price of more tests outside.) Write a version with only one test inside the loop and
 * measure the difference in run-time.
 */

#include <stdio.h>
#include <sys/time.h>
#include "../lib.h"

#define ONE_MILLION 1000000

double benchmark(int (*binsearch)(int x, int v[], int n), int x, int v[], int n);
int binsearch_original(int x, int v[], int n);
int binsearch_modified(int x, int v[], int n);
void run_benchmarks();
bool run_tests();
bool test(int v[], int n, int test_data[][2], int test_data_len);

int main()
{
    bool success = run_tests();
    run_benchmarks();
    return success ? 0 : 1;
}

bool run_tests()
{
    printf("Tests\n");
    printf("-----\n");

    bool success = TRUE;

    int empty_v[] = {};
    int empty_v_data[2][2] = {{0, -1}, {1, -1}};
    success &= test(empty_v, 0, empty_v_data, 2);

    int unique_v[3] = {0, 1, 3};
    int unique_v_data[3][2] = {
        {1, 1},
        {3, 2},
        {4, -1},
    };
    success &= test(unique_v, 3, unique_v_data, 3);

    int less_than_min_v[3] = {5, 6, 7};
    int less_than_min_data[1][2] = {
        {3, -1},
    };
    success &= test(less_than_min_v, 3, less_than_min_data, 1);

    int greater_than_max_v[3] = {0, 1, 2};
    int test_data[1][2] = {
        {3, -1},
    };
    success &= test(greater_than_max_v, 3, test_data, 1);

    int duplicate_v[5] = {0, 0, 1, 1, 3};
    int duplicate_data[3][2] = {{0, 0}, {1, 2}};
    success &= test(duplicate_v, 5, duplicate_data, 3);

    return success;
}

bool test(int v[], int n, int test_data[][2], int test_data_len)
{
    printf("Array: ");
    print_int_array(v, n);
    printf("\n");

    bool success = TRUE;
    for (int i = 0; i < test_data_len; i++)
    {
        int search = test_data[i][0];
        int expected = test_data[i][1];
        char description[50] = "";
        sprintf(description, "%2d", search);
        success &= test_equal_ints(description, binsearch_original(search, v, n), expected);
    }

    return success;
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
        results[i][0] = benchmark(binsearch_original, x, v, n);
        results[i][1] = benchmark(binsearch_modified, x, v, n);
    }

    printf("|    Description   | Original | Modified |\n");
    printf("| ---------------- | -------- | -------- |\n");
    for (int i = 0; i < case_count; i++)
    {

        printf("| %-16s | %8d | %8d | \n", descriptions[i], (int)results[i][0], (int)results[i][1]);
    }
}

double benchmark(int (*binsearch)(int x, int v[], int n), int x, int v[], int n)
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
