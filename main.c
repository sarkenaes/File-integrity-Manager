#include"hasher.h"
#include"db.h"
#include<stdio.h>
#include<string.h>
#include"watcher.h"
int main(int argc, char *argv[]){
    if(argc<3){
        printf("please enter a valid input");
        return 1;
    }
char out_hash[65];
char out_hex[65];
db_init();
if(strcmp(argv[1],"--baseline")==0){
hash_file(argv[2], out_hex, sizeof(out_hex));
db_store(argv[2], out_hex);
printf("Baseline stored for %s : %s\n",argv[2], out_hex);}
if(strcmp(argv[1],"--watch")==0)
    watch_file(argv[2]);
return 0;
}

