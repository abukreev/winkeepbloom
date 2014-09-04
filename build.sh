#!/bin/sh
g++ -DAPP main.cpp -o keepbloom
g++ -DLIB -shared -o inject.dll lib.cpp -Wl,--out-implib,inject.a

