#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif
 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>


int main(int argc, char **argv)
{
	char *p_a,*p_b,*p_c,*p_d,*p_e, *tmp ,*tmp2;
	char **pp;
	pp = (char**)calloc(sizeof(char*),5);
	p_a = malloc(5);
	p_b = malloc(5);
	p_c = malloc(5);
	p_d = malloc(5);
	p_e = malloc(5);
	for (int i = 0;i<4;i++)
	{
		p_a[i] = 'a';
		p_b[i] = 'a';
		p_c[i] = 'a';
		p_d[i] = 'a';
		p_e[i] = 'a';
	}
	pp[0] = p_a;
	pp[1] = p_b;
	pp[2] = p_c;
	pp[3] = p_d;
	pp[4] = p_e;
	tmp = strdup(p_a);
	tmp2 = strdup(p_b);
	free(p_a);
	pp++;
	pp[4] = tmp2;
	free(tmp);
	printf("%p %p %p %p", pp[4], pp[3], pp[2], tmp2);
	for (int i = 0;i<5;i++)
	{
		free(pp[i]);
	}
	pp--;
	free(pp);
}