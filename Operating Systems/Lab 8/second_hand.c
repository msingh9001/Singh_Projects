#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int pageno;
    int refbit;
} ref_page;

int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]);
    ref_page cache[C_SIZE];
    int totalFaults = 0, totalRequests = 0;
    int nf = 0;
    int n, i, j, k = 0;
    
    for (n = 0; n < C_SIZE; n++){
        cache[n].pageno = -1;
        cache[n].refbit = 0;
    }
    char cache2[1000];
    while (fgets(cache2,100,stdin)){
        int page_num = atoi(cache2);
        totalRequests++;
        for (i = 0; i < C_SIZE; i++){
            if (page_num == cache[i].pageno){
                cache[i].refbit = 1;
                nf = 0;
                break;
            }
            if (i == C_SIZE - 1)
                nf = 1;
        }
        if (nf == 1){
            totalFaults++;
            printf("Page %d caused a page fault.\n", page_num);
            for (j = k ; j < C_SIZE; j++){
                if (cache[j].refbit == 1){
                    cache[j].refbit = 0;
                    k++;
                    if (k == C_SIZE){
                        k = 0;
                        j = -1;
                    }
                }
                else{
                    cache[j].pageno = page_num;
                    cache[j].refbit = 0;
                    k++;
                    if (k == C_SIZE){
                        k = 0;
                    }
                    break;
                }

            }
        }
    }

    printf("%d Total Page Faults", totalFaults);
    printf("\nSecond Chance Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
    return 0;
}
