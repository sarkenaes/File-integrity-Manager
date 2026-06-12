#include <sqlite3.h>
int db_init(){
    sqlite3 *db;
    if (sqlite3_open("fim.db", &db) != SQLITE_OK)
    return -1;
    sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS files (filepath TEXT PRIMARY KEY,hash  TEXT NOT NULL);",NULL,NULL,NULL);
sqlite3_close(db);
return 0;
}