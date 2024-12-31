#ifndef __3DES_H_
#define __3DES_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define ERR_DES_INVALID_INPUT_LENGTH    -1
/*
 * 3DES decrypt
 */
unsigned int des3_cbc_decrypt(unsigned char *pout, unsigned char *pdata, unsigned int nlen, unsigned char *pkey, unsigned int klen, unsigned char *piv);

/*
 * 3DES encrypt
 */
unsigned int des3_cbc_encrypt(unsigned char *pout, unsigned char *pdata, unsigned int nlen, unsigned char *pkey, unsigned int klen, unsigned char *piv);

/*
 * 3DES-ECB buffer encryption API
 */

unsigned int des3_ecb_encrypt(unsigned char *pout, unsigned char *pdata, unsigned int nlen, unsigned char *pkey, unsigned int klen);


/*
 * 3DES-ECB buffer decryption API
 */
unsigned int des3_ecb_decrypt(unsigned char *pout, unsigned char *pdata, unsigned int nlen, unsigned char *pkey, unsigned int klen);


/* User Define */
void xor_arrays(const uint8_t *a, const uint8_t *b, uint8_t *result, int length);
void process_macdata(uint8_t key[], uint8_t macdata[], int length, uint8_t iv[],uint8_t des[8]);
void removeFirstChar(char cardNoStr[]);
void hexArrayToString(unsigned char *hexArray, char *result, int length);
void StringToHex(char *factor, uint8_t *factor_hex);
void appendArray(uint8_t src[], uint8_t dest[], size_t len); 

#endif
