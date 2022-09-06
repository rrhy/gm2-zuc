all:
	gcc -std=c99 gm_zuc_demo.c third_zuc.c -lzgmssl -L. -o atest -I./gm_crypto -w
