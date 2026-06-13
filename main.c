#include"hasher.h"
#include"db.h"
#include<stdio.h>
int main(){
char out_hex[65];
hash_file("/etc/passwd",out_hex,sizeof(out_hex));
db_init();
db_store("etc/passwd",out_hex);
printf("Baseline stored for /etc/passwd: %s\n", out_hex);
}