#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{
    int pageno;
}ref_page;

int main(int argc, char *argv[]){
	int C_SIZE = atoi(argv[1]);
    ref_page cache[C_SIZE];
    char pageCache[100];
    int i, j;
    int totalFaults = 0, totalRequests = 0, currentPos = 0;
    
    for (i = 0; i < C_SIZE; i++)
        cache[i].pageno = -1;

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache);
        totalRequests++;
        for (j = 0; j < C_SIZE; j++){
            if (page_num == cache[j].pageno)
                break;
            if (j == C_SIZE - 1){
                printf("Page %d caused a page fault.\n", page_num);
                totalFaults++;
                cache[currentPos].pageno = page_num;
                currentPos++;
                if (currentPos == C_SIZE)
                    currentPos = 0;
            }
        }
    }

    printf("\n%d Total Page Faults\n", totalFaults);
    printf("FIFO Hit rate = %f\n", (totalRequests-totalFaults)/(double)totalRequests);
    return 0;
}
