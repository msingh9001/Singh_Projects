#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int pageno;
    int count;
} ref_page;

int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]);
    ref_page cache[C_SIZE];
    char pageCache[100];
    int i, j, k, l, m;
    int totalFaults = 0, totalRequests = 0, currentPos = 0;
    
    for (i = 0; i < C_SIZE; i++){
        cache[i].pageno = -1;
        cache[i].count = 100;
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache);
        totalRequests++;
        int least_rec = cache[j].count;
        for (j = 0; j < C_SIZE; j++){
            if (page_num == cache[j].pageno){
                for (k = 0; k < C_SIZE; k++)
                    if (cache[k].count < cache[j].count)
                        cache[k].count++;
                cache[j].count = 0;
                break;
            }

            if (j == C_SIZE - 1){
                for (l = 0; l < C_SIZE; l++)
                    cache[l].count = cache[l].count++;
                for (m = 0; m < C_SIZE; m++){
                    if (least_rec < cache[m].count){
                        least_rec = cache[m].count;
                        currentPos = m;
                    }
                }
                printf("Page %d caused a page fault.\n", page_num);
                totalFaults++;
                cache[currentPos].pageno = page_num;
                cache[currentPos].count = 0;
                j++;
                if (j == C_SIZE - 1)
                    j = 0;
            }
        }
    }

    printf("%d Total Page Faults\n", totalFaults);
    printf("LRU Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
    return 0;
}
