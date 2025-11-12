#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearcg(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    }
    else if (x > v[mid]) {
     low = mid + 1;
    } 
    else {
     return mid;
    }
  }
  return -1;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (v[mid] < x) {
      low = mid + 1;
    }
    else { // x > v[mid]
      high = mid - 1;
    }
  }
  return (low < n && v[low] == x) ? low : -1; 
}
void test_case(const char *name, int x, int v[], int n, int expect) {
  int r1 = binsearcg(x, v, n);
  int r2 = binsearch(x, v, n);
  printf("%-12s x=%2d | orig=%2d new=%2d | %s\n",
         name, x, r1, r2,
         (r1 == expect && r2 == expect) ? "PASS" : "FAIL");
}
int main() {
  //
  // Exercise 3-1: Our binary search makes two tests inside the loop, when one would suffice (at the 
  // price of more tests outside.) Write a version with only one test inside the loop and measure 
  // the difference in run-time.
  //
  int *a1 = NULL;
  test_case("empty", 5, a1, 0, -1);

  int a2[] = {7};
  test_case("single ok", 7, a2, 1, 0);
  test_case("single miss", 3, a2, 1, -1);

  int a3[] = {1,3,5};
  test_case("odd begin", 1, a3, 3, 0);
  test_case("odd mid",   3, a3, 3, 1);
  test_case("odd end",   5, a3, 3, 2);
  test_case("odd miss",  4, a3, 3, -1);

  int a4[] = {2,4,6,8};
  test_case("even mid",  6, a4, 4, 2);
  test_case("even last", 8, a4, 4, 3);
  test_case("even <min", 1, a4, 4, -1);
  test_case("even >max", 9, a4, 4, -1);

  /* ---- timing benchmark ---- */

  const int N = 20000000; // 20 million
  int *big = malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) big[i] = i * 2;

  const int TRIALS = 2000000; // 2 million

  clock_t t1 = clock();
  for (int i = 0; i < TRIALS; i++)
    binsearcg(i * 2, big, N);
  clock_t t2 = clock();

  clock_t t3 = clock();
  for (int i = 0; i < TRIALS; i++)
    binsearch(i * 2, big, N);
  clock_t t4 = clock();

  double orig_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
  double new_time  = (double)(t4 - t3) / CLOCKS_PER_SEC;

  printf("\n--- Timing ---\n");
  printf("Original: %.4f sec\n", orig_time);
  printf("One-test: %.4f sec\n", new_time);
  printf("Speedup:  %.2fx faster\n", orig_time / new_time);

  free(big);
  return 0;
}
  
