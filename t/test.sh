#!/bin/bash

g++ -Wall -std=c++17 -I./ -o ./t/t_Token ./t/t_Token.cpp ./Token.cpp ./lex.cpp
./t/t_Token

if [ "$?" != 0 ]; then
  echo "err"
  exit 0
fi

echo "OK"