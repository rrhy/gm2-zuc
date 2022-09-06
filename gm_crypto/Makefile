#SRC_DIR = .
#SRC =${wildcard $(SRC_DIR)/*.c}
GCCPATH=
CC=${GCCPATH}gcc
AR=${GCCPATH}ar
#MIPSEL_PATH=/home/tau/Desktop/buildroot/output/host/usr/bin/
#CC = ${MIPSEL_PATH}mipsel-linux-gcc
TARGET = libzgmssl.a
LINKS = -w
PRE_STD = -std=c99
COM_INC := -I.
OBJS = aes.o    \
	aes_modes.o    \
	asn1.o    \
	base64.o    \
	block_cipher.o    \
	chacha20.o    \
	cms.o    \
	debug.o    \
	des.o    \
	digest.o    \
	ec.o    \
	gcm.o    \
	gf128.o    \
	hash_drbg.o    \
	hex.o    \
	hkdf.o    \
	hmac.o    \
	md5.o    \
	pbkdf2.o    \
	pem.o    \
	pkcs8.o    \
	rand.o    \
	rc4.o    \
	rsa.o    \
	sha1.o    \
	sha256.o    \
	sha512.o    \
	sm2_alg.o    \
	sm2_key.o    \
	sm2_lib.o    \
	sm3.o    \
	sm3_hmac.o    \
	sm3_kdf.o    \
	sm4_common.o    \
	sm4_enc.o    \
	sm4_modes.o    \
	sm4_setkey.o    \
	sm9_alg.o    \
	sm9_key.o    \
	sm9_lib.o    \
	tlcp.o    \
	tls.o    \
	tls12.o    \
	tls13.o    \
	tls_ext.o    \
	tls_trace.o    \
	version.o    \
	x509_alg.o    \
	x509_cer.o    \
	x509_crl.o    \
	x509_ext.o    \
	x509_oid.o    \
	x509_req.o    \
	x509_str.o    \
	zuc.o    \
	zuc_modes.o
COM_INC += -I./sdf/
OBJS +=./sdf/sdf.o    \
	./sdf/sdf_dummy.o   \
	./sdf/sdf_ext.o   \
	./sdf/sdf_lib.o   \
	./sdf/sdf_meth.o   \
	./sdf/sdf_sansec.o

COM_INC += -I./sdf/
OBJS += 	./skf/skf.o   \
	./skf/skf_dummy.o   \
	./skf/skf_ext.o   \
	./skf/skf_lib.o   \
	./skf/skf_meth.o   \
	./skf/skf_prn.o   \
	./skf/skf_wisec.o

main:${OBJS}
	${AR} -crv ${TARGET} ${OBJS}
	@echo "DONE."

all: ${OBJS}
	${AR} -crv ${TARGET} ${OBJS}
	@echo "ALL DONE."
	
clean:
	rm -rf ${OBJS} ${TARGET}

clear:
	rm -f ${OBJS}
	rm -f ${TARGET}

#.c.o:
#	${CC} -o $*.o -c $<
${OBJS}: %.o:%.c
	${CC} ${PRE_STD} -c $< -o $@ ${COM_INC}
