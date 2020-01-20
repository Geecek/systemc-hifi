#!/bin/bash

SYSTEMC_HOME=/usr/local/systemc-2.3.3/ 

g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -o out main.cpp -lsystemc -lm
