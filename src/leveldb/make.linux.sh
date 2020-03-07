#!/bin/bash
OS="UBUNTU"
OS_VERSION="7.0"
PREFIX=""
WHOAMI_ROOT=$($PREFIX id -u);
if [ $WHOAMI_ROOT -ne 0 ]; then
    echo "Are you running this script under root?"
    exit 0;
fi

if [[ $OS == "UBUNTU" ]]; then
    PREFIX="sudo"
fi

make -j8
$PREFIX cp lib*.so /usr/lib/x86_64-linux-gnu/
$PREFIX cp lib*.a /usr/lib/x86_64-linux-gnu/
cd .. && g++ leveldb_test.cpp -o leveldb_test -L leveldb -lleveldb -lpthread -std=c++98 -Ileveldb/include
