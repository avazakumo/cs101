#include <stdio.h>

int swap(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

int swapArray(int* sources, int* dests, int* size) {
    int s,d;
    for (int i = 0; i<*size; i++) {
        s = *(sources+i);
        d = *(dests+i);
        swap(&s, &d);
        *(sources+i) = s;
        *(dests+i) = d;
    }
    return 0;
}

int printArray(int* array, int asize) {
    for (int i = 0; i < asize-1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[asize-1]);
    return 0;
}

char* copy_string(char* s) {
    int size = 0;
    while(s[size++]);
    char* cp_str = (char*)calloc(size, sizeof(char));
    for(int i = 0; i < size - 1; i++) {
    cp_str[i] = s[i];
    }
    cp_str[size] = '\0';
    return cp_str;
}

int main() {
    printf("No.1 ----------------------\n");
    int n, m;
    n = 1;
    m = 2;
    printf("after swap, n = %d, m = %d\n", n, m);
    swap(&n, &m);
    
    printf("No.2 ----------------------\n");
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    swapArray(source, dest, &size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    
    printf("No.3 ----------------------\n");
    char str[] ="IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    return 0;
}
