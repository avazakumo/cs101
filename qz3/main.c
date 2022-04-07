#include <stdio.h>

void rec_dec (char *s) {
    if (s[0] == 0) return;
    printf ("%c,", s[0]);
    rec_dec (s + 1);
}

void hanoi_tower(int n, char A, char B, char C) {    
    FILE* fp = fopen("hanoi.txt", "ab");
    if(n == 1) {         
        fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);    
    }    
    else {        
        hanoi_tower(n-1, A, C, B);       
        fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);        
        hanoi_tower(n-1, B, A, C);    
     }
     fclose(fp);
}


int multiplication(int i, int j) {
    if(j==10){
        i++;
        j=1;
        printf("\n");
    } 
    if(i==10) return 0;
    printf("%d*%d=%d ", i, j,i*j );
    multiplication(i,j+1);
}

int main () {
    char s[] = "13456jisl7890";
    rec_dec (s);
    printf("fun#1-----------------------\n");
    hanoi_tower(16, 'A', 'B', 'C');
    printf("fun#2-----------------------\n");
    multiplication(1,1);
    printf("fun#3-----------------------\n");
    return 0;
}