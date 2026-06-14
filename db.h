#ifndef DB_H
#define DB_H
int db_store(const char *filepath,const  char *hash );
int db_init();
int db_get();
#endif