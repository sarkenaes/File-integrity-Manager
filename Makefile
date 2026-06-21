fim: main.c hasher.c db.c watcher.c
	gcc main.c hasher.c db.c watcher.c -lssl -lcrypto -lsqlite3 -0 fim