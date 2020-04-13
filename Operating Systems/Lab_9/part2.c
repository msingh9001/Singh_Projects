#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int MAX = atoi(argv[2]);
    int buff[MAX];
    FILE *fp = fopen(argv[1], "rb");
    while(fgets(buff,MAX,fp)){
        
    }
    fclose(fp);
    return 0;
}
