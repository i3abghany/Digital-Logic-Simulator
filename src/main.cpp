//#include <iostream>

//#include "Simulator.h"
#include <stdio.h>
#include <string.h>

void merge(int *arr, size_t l, size_t m, size_t r) {
    size_t s1 = 0;
    size_t s2 = 0;

    size_t n1 = m - l + 1;
    size_t n2 = r - m + 1;

    int L[n1], R[n2];
    memcpy(L, arr, sizeof(int) * (n1));
    memcpy(R, arr + n1, sizeof(int) * (n2));
    size_t idx = 0;
    while(s1 <= n1 && s2 <= n2) {
        if(L[s1] < R[s2]) {
            arr[l + idx] = L[s1];
            s1++;
        } else {
            arr[l + idx] = R[s2];
            s2++;
        }
        idx++;
    }
    for(; s1 <= n1; s1++) {
        arr[l + idx] = L[s1];
        idx++;
    }
    for(; s2 <= n2; s2++) {
        arr[l + idx] = R[s2];
        idx++;
    }
}

void merge_sort(int *arr, size_t l, size_t r) {
    if (l > r) {
        return;
    }

    size_t mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

void print_arr(int *a, size_t n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main () {
    int a[6] = {0, 5, 6, 1, 2, 3};
    merge_sort(a, 0, 5);
    print_arr(a, 6);


}
/*
int main(int argc, char *argv[]) {
    if (argc < 2) {
	  std::cout << "Please provide an input file." << std::endl;
	  exit(EXIT_FAILURE);
    }

    Simulator s;
    auto fN = std::string(argv[1]);
   // auto fN = "test.cir";
    s.load(fN);
    return EXIT_SUCCESS;
}
*/