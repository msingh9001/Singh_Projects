#include <stdio.h>
#include <stdlib.h>

#define MAX 10000


int main(int argc, char *argv[]){
    int buff[MAX];
    FILE *fp = fopen(argv[1], "rb");
    while(fgets(buff,MAX,fp)){
        //Only reading the files
    }
    fclose(fp);
    return 0;
}
