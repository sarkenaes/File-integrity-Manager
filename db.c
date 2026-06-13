#include <sqlite3.h>
#include <stdio.h>
int db_init(){
    sqlite3 *db;
    if (sqlite3_open("fim.db", &db) != SQLITE_OK)
    return -1;
    sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS files (filepath TEXT PRIMARY KEY,hash  TEXT NOT NULL);",NULL,NULL,NULL);
sqlite3_close(db);
return 0;
}
int db_store(const char *filepath,const  char *hash ){
sqlite3 *db;
sqlite3_stmt *stmt; 
if(sqlite3_open("fim.db",&db)!=SQLITE_OK){
    return -1;
}
   sqlite3_prepare_v2(db,"INSERT OR REPLACE INTO files (filepath,hash) VALUES (? ,?);", -1, &stmt,NULL);
   sqlite3_bind_text(stmt,1,filepath,-1,SQLITE_STATIC);
   sqlite3_bind_text(stmt,2,hash,-1,SQLITE_STATIC);
   sqlite3_step(stmt);
   sqlite3_finalize(stmt);
sqlite3_close(db);
return 0;
}