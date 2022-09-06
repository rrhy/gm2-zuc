#include "gm_zuc_demo.h"
#include "gmssl/sm2.h"
#include "gmssl/error.h"
#include "third_zuc.h"
#include <time.h>

int zuc_encrypto(uint8_t * inbuf, size_t len, uint8_t *outbuf)
{
	zuc_context zuc_ctx;
	size_t olen = 0;
	unsigned char key[16] = {
		0xff,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
		0xfe,0x32,0xad,0x34,0x35,0x36,0x37,0x38,
	};
	unsigned char iv[16] = {
		0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,
		0x31,0x39,0x33,0x34,0x35,0x36,0x37,0x38,
	};
	third_zuc_init(&zuc_ctx, key, iv);
	third_zuc_encrypt(&zuc_ctx, len, inbuf, outbuf);
	return len;
}

#define zuc_decrypto zuc_encrypto

int main()
{
	uint8_t * tstring = "hello this is the first string, use sm2 to encrypt";
	uint8_t * p = tstring;
	size_t len = strlen(tstring);
	size_t olen = 0;
	
	printf("in len = %d\n", len);
	unsigned char plaintext[SM2_MAX_PLAINTEXT_SIZE];
	unsigned char ciphertext[SM2_MAX_CIPHERTEXT_SIZE];
	
	//zuc
	format_bytes(stdout, 0, 0, "zin", tstring, len);
	olen = zuc_encrypto(tstring, len, plaintext);
	format_bytes(stdout, 0, 0, "zen", plaintext, olen);
	olen = zuc_decrypto(plaintext, olen, ciphertext);
	format_bytes(stdout, 0, 0, "zde", ciphertext, olen);

	//gm2
	SM2_KEY sm2_key;
	SM2_KEY pub_key;
	sm2_key_generate(&sm2_key);
	memcpy(&pub_key, &sm2_key, sizeof(SM2_POINT));
	format_bytes(stdout, 0, 0, "tstring", tstring, len);
	sm2_encrypt(&pub_key, p, len, ciphertext, &len);
	format_bytes(stdout, 0, 0, "ciphertext", ciphertext, len);
	if (sm2_decrypt(&sm2_key, ciphertext, len, plaintext, &len) != 1) {
		fprintf(stderr, "error\n");
		return 1;
	}
	format_bytes(stdout, 0, 0, "t_out", plaintext, len);

	return 0;
}
