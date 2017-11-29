/*
 * passgen.c

 *
 *  Created on: Nov 28, 2017
 *      Author: Ying_Zhou
 */
#include "md5.h"
#include <string.h>
#include <stdio.h>
int main(int argc, char** argv)
{
	int i, j, count = 0;
	unsigned char twisted_md5sum[32], product[32];
	if (argc == 1) {
		fprintf(stdout, "Tests\n");
		mbedtls_md5_self_test(1);
	}
	mbedtls_md5_twisted(argv[1], strlen(argv[1]), twisted_md5sum);
	count = twisted_md5sum[12] + twisted_md5sum[14];
	for (j = 0 ; j < 32; j++) {
		product[j] = twisted_md5sum[31-j];
	}
	for (i = 0; i < count; i++) {
		mbedtls_md5_twisted(product, 32, product);
		for (j = 0 ; j < 32; j++) {
			product[j] = product[31-j];
		}
	}
	for (i = 0; i < 32; i++) {
		fprintf(stdout, "%c", product[i]);
	}
	fprintf(stdout, "\n");
	return 0;
}
