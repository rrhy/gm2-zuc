#!/bin/bash
cd gm_crypto
make
cp libzgmssl.a ..
cd ..
make
./atest
