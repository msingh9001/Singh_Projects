#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    int i;
    char **a;
} arguments;

void *go(void *arg) {
    arguments *argu = (arguments *) arg;
    int count = (*argu).i;
    int MAX = atoi((*argu).a[2]);
    int buff[MAX];
    char *file = (*argu).a[1];
    FILE *fp = fopen(file,"rb");
    char filename[20];
    sprintf(filename, "%d%spart4output%d.bin",count, file,MAX);
    FILE *wp = fopen(filename,"wb");
    while(fread(buff,MAX,1,fp)){
        fwrite(buff, MAX,1,wp);
    }
    fclose(fp);
    fclose(wp);
    return (NULL);
}

int main(int argc, char *argv[]){
    arguments argument;
    int x = atoi(argv[3]);
    pthread_t threads[x];
    int j;
    argument.a = argv;
    for (j = 0; j < x; j++){
        argument.i = j;
        pthread_create(&threads[j], NULL, go, &argument);
    }
    for (j = 0; j < x; j++)
        pthread_join(threads[j],NULL);
    return 0;
}
