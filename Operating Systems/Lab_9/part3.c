#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int MAX = atoi(argv[2]);
    char buff[MAX];
    char dest[MAX];
    FILE *fp = fopen(argv[1], "rb");
    char filename[20];
    sprintf(filename, "%soutput%d.rtf", argv[1],MAX);
    FILE *wp = fopen(filename,"wb");
    while(fread(buff,MAX,1,fp)){
        fwrite(buff, MAX,1,wp);
    }
    fclose(fp);
    fclose(wp);
    return 0;
}
