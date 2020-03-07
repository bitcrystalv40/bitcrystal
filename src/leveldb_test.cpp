#include <iostream>
#include <sstream>
#include <string>
#include <leveldb/db.h>

using namespace std;

int main(int argc, char** argv)
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);
    assert(status.ok());

    return 0;
}
