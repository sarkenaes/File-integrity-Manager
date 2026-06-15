#include"hasher.h"
#include"db.h"
#include<stdio.h>
#include<string.h>
#include"watcher.h"
int main(){
char out_hash[65];
char out_hex[65];
db_init();
hash_file("test.txt", out_hex, sizeof(out_hex));
db_store("test.txt", out_hex);
printf("Baseline stored for test.txt: %s\n", out_hex);
watch_file("test.txt");
return 0;
}

