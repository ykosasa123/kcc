#!/bin/bash

cpp="g++ -Wall -std=c++17 -I./ -o"
source="./Token.cpp ./lex.cpp"

do_test () {
    $cpp $1 $2 $source
    $1

    if [ "$?" != 0 ]; then
        echo "err"
        exit 0
    fi
}

do_test ./t/t_Token ./t/t_Token.cpp
do_test ./t/t_lex ./t/t_lex.cpp

echo "OK"