/*
 * This program based on OpenSSL Project, just for study and research.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include "sm4.h"

void print_block(uint8_t *block)
{
	int i;
	for (i = 0; i != SM4_BLOCK_SIZE; ++i)
		printf("%02x", block[i]);
	printf("\n");
}

int main()
{
	static const uint8_t k[SM4_BLOCK_SIZE] = {
	0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
	0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10
	};

	static const uint8_t input[SM4_BLOCK_SIZE] = {
		0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
		0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10
	};

	/*
	 * This test vector comes from Example 1 of GB/T 32907-2016,
	 * and described in Internet Draft draft-ribose-cfrg-sm4-02.
	 */
	static const uint8_t expected[SM4_BLOCK_SIZE] = {
		0x68, 0x1e, 0xdf, 0x34, 0xd2, 0x06, 0x96, 0x5e,
		0x86, 0xb3, 0xe9, 0x4f, 0x53, 0x6e, 0x42, 0x46
	};

	/*
	 * This test vector comes from Example 2 from GB/T 32907-2016,
	 * and described in Internet Draft draft-ribose-cfrg-sm4-02.
	 * After 1,000,000 iterations.
	 */
	static const uint8_t expected_iter[SM4_BLOCK_SIZE] = {
		0x59, 0x52, 0x98, 0xc7, 0xc6, 0xfd, 0x27, 0x1f,
		0x04, 0x02, 0xf8, 0x04, 0xc3, 0x3d, 0x3f, 0x66
	};

	int i;
	SM4_KEY key;
	uint8_t block[SM4_BLOCK_SIZE];

	SM4_set_key(k, &key);
	memcpy(block, input, SM4_BLOCK_SIZE);

	SM4_encrypt(block, block, &key);
	
	print_block(block);

	for (i = 0; i != 999999; ++i)
		SM4_encrypt(block, block, &key);

	print_block(block);

	for (i = 0; i != 1000000; ++i)
		SM4_decrypt(block, block, &key);

	print_block(block);	
	getchar();

	return 0;
}
