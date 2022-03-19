#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrange (char b[]) {
    for(int i = 0; i < 6; i++) {
        for(int j = i+1; j < 6; j++) {
            if(b[i]>b[j]){
            int tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
            }
        }
    }
}

int main(void) { 
    char b[6] = {0};
    int n;
    
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要購買幾組樂透彩：");
    scanf("%d",&n);
    if (n<=5) printf("\n已為您購買的%d組樂透組合輸出至 lotto.txt", n);
    
    time_t curtime;
    time(&curtime);
    FILE* fp;
    
    fp = fopen("lotto.txt", "w+");
    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp,"= %.*s=\n", 24, ctime(&curtime));
    srand((unsigned)time(NULL));
    
    for (int i = 1 ; i <= n ; i++) {
        if (n>5) {
            printf("限購5組喔");
            break;
        }
        fprintf(fp, " [%d]:", i);
        
        for (int j = 0 ; j < 6 ; j++ ) {
            int num = (rand()%69) + 1;
            b[j] = num;
            for (int k = j-1 ; k >= 0 ; k-- ) {
                if (b[k] == b[j]){
                    j-=1;
                    break;
                }
            }
        }
        arrange(b);
        
        for (int k = 0; k < 6; k++) {
            fprintf(fp, " %02d", b[k]);
        }
        fprintf(fp, " %02d\n", rand() % 10 + 1);
    }
    
    for(int i = 1 ; i <= 5-n ; i++) {
        fprintf(fp, " [%d]:", i+n);
        for (int j = 0 ; j < 6 ; j++ ) {
            fprintf(fp, " --");
        }
    fprintf(fp, " --\n");
    }
    
    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);
    return 0;
}
