/*
 * This program based on OpenSSL Project, just for study and research.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

/*
 * Visual Studio: inline is available in C++ only, however
 * __inline is available for C, see
 * http://msdn.microsoft.com/en-us/library/z8y1yy88.aspx
 */
# define ossl_inline __inline

# define SM4_ENCRYPT     1
# define SM4_DECRYPT     0

# define SM4_BLOCK_SIZE    16
# define SM4_KEY_SCHEDULE  32

typedef struct SM4_KEY_st {
	uint32_t rk[SM4_KEY_SCHEDULE];
} SM4_KEY;

int SM4_set_key(const uint8_t *key, SM4_KEY *ks);

void SM4_encrypt(const uint8_t *in, uint8_t *out, const SM4_KEY *ks);

void SM4_decrypt(const uint8_t *in, uint8_t *out, const SM4_KEY *ks);

