#include"hasher.h"
#include"db.h"
#include<stdio.h>
#include<string.h>
int main(){
char out_hash[65];
char out_hex[65];
db_init();
db_get("test.txt", out_hash, sizeof(out_hash));
hash_file("test.txt",out_hex,sizeof(out_hex));
if(strlen(out_hash)==0){
db_store("test.txt",out_hex);
printf("Baseline stored for test.txt: %s\n", out_hex);}
else{
if(strcmp(out_hash,out_hex)==0){
    printf("The file hasn't been altered\n");
}else{
    printf("The file has been altered\n");
}
printf("original: %s, new : %s\n",out_hex,out_hash);
return 0;}}
