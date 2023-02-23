#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "../include/sqlcpp.h"
#include "../include/sqlite3.h"
// gcc main.cpp -o main -lsqlite3 -- you can use this command to compile or update the tasks.json file in .vscode folder to compile when running the program


int main () {

    printf("sqlite3 version: %s\n", sqlite3_libversion());
    printf("sqlite3 sourceid: %s\n", sqlite3_sourceid());
    printf("DB_PATH: %s\n", DB_PATH);
    return 0;
}
