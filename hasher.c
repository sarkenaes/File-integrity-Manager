#include<stdio.h>
#include<openssl/evp.h>
int hash_file(const char *filepath,char *out_hex,size_t out_len){
FILE *fp;
unsigned char buff[4096];
fp = fopen(filepath,"r");
if (fp==NULL)
    return -1;
int bytes_read;
EVP_MD_CTX *ctx = EVP_MD_CTX_new();
EVP_DigestInit_ex(ctx,EVP_sha256(),NULL);
while((bytes_read=fread(buff,1,4096,fp))>0){
    EVP_DigestUpdate(ctx,buff,bytes_read);}
    unsigned char hash[32];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx,hash,&hash_len);
    for(int i=0; i<32;i++){
        sprintf(out_hex +(i*2),"%02x",hash[i]);
    }
    out_hex[64]='\0';
    EVP_MD_CTX_free(ctx);
fclose(fp);
return 0;
}
int main() {
    char out_hex[65];
    int result = hash_file("/etc/hostname", out_hex, sizeof(out_hex));
    printf("HASH: %s\n", out_hex);
    return 0;
}