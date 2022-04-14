#include <stdio.h>

int get_num(int* np, int* indx, int number, int nsize) {
    for (int i=0; i<nsize;i++){
        if (*np++ == number) {
            *indx=i;
        }
    }
}

int main() {
    int n[]={6,4,7,2,0,9,8,1,5,3};
    int* p=NULL;
    int* ap[10];
    int* tmp=NULL;
    int indx=-1;
    
    printf("No.1 ----------------------\n");
    
    get_num(n, &indx, 9, 10);
    p = &n[indx];
    if(indx>-1) {
        printf("&n[%d]->%p, n[%d]=%d; p->%p, *p = %d\n", indx, &n[indx], indx, n[indx], p, *p);
    } else {
        printf("No found.");
    }
    
    printf("No.2 ----------------------\n");
    
    for (int i=0;i<10;i++) {
        ap[i]=&n[i];
        
    }
    for (int i=0;i<10;i++) {
        for (int j=i+1;j<10;j++){
            if (*ap[i] > *ap[j]) {
                tmp = ap[i];
                ap[i] = ap[j];
                ap[j] = tmp;
            }
        }
    }
    
    for (int i=0; i<10;i++){
        get_num(n, &indx, *ap[i], 10);
        printf("&n[%d]->%p, n[%d]=%d; ap[%d]->%p, *ap[%d] = %d\n", 
        indx, &n[indx], indx, n[indx], i, &ap[i], i, *ap[i]);
    }
    return 0;
}