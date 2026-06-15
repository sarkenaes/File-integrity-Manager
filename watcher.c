#include<sys/inotify.h>
#include <stdio.h>
#include <unistd.h>
#include "hasher.h"
#include "db.h"
#include <string.h>
void watch_file(const char *filepath){
    int fd = inotify_init();
    if(fd<0){
        printf("Error with inotify\n");
        return;
    }
    int wd =inotify_add_watch(fd,filepath,IN_MODIFY);
    if(wd<0){
            printf("Error with inotify\n");
            return;
        }
char buffer[4096];
while(1){
    int length = read(fd,buffer,sizeof(buffer));
    if(length<0){
        printf("Error reading event\n");
        return;
    }
     char out_hash[65];
char out_hex[65];

db_get(filepath, out_hash, sizeof(out_hash));
hash_file(filepath,out_hex,sizeof(out_hex));
if(strcmp(out_hash,out_hex)==0){
    printf("The file hasn't been altered\n");
}else{
    printf("The file has been altered\n");
}}}