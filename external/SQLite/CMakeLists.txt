add_library(SQLite3 sqlite3.c)

target_link_libraries(SQLite3 PRIVATE pthread dl m)
