/*
 * pollard-rho.c
 *  Created on: Dec 20, 2011
 *      Author: martani
 */

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

mpz_t xSquared, a, n;

double my_gettimeofday()
{
  struct timeval tv;
  return tv.tv_sec + (tv.tv_usec * 1.0e-6L);
}

//rop <- (rop² + a) mod n
void f(mpz_t rop)
{
	mpz_pow_ui(xSquared, rop, 2);
	mpz_add(xSquared, xSquared, a);
	mpz_mod(rop, xSquared, n);
}

int main(int argc, char **argv)
{
	mpz_t g, gMul, s, u, v, uMinusV;
	mpz_t nMinus3, nMinus1;

	gmp_randstate_t rnd_state;
	int found=0, finished=0;
	double start, end;

	mpz_init(n); mpz_init(xSquared);

	if(argc < 2)
	{
		printf("Use %s N\n", argv[0]);
		exit(2);
	}

        //if p q are provided
	if(argc == 3)
	{
		mpz_t p, q;
		mpz_init_set_str(p, argv[1], 10);
		mpz_init_set_str(q, argv[2], 10);

		mpz_addmul(n, p, q);
	}
	else if(mpz_set_str(n, argv[1], 10) == -1)
	{
		printf("Cannot load %s\n", argv[1]);
		exit(2);
	}

	printf("Factoring %s ..\n", mpz_get_str(NULL, 10, n));

	//a belongs to [1, n-2]
	//u, v <-> s belongs to [0, n-1]
	mpz_init_set(nMinus3, n);
	mpz_sub_ui(nMinus3, nMinus3, 4);

	mpz_init_set(nMinus1, n);
	mpz_sub_ui(nMinus1, nMinus1, 1);

//[1 choose seeds]
	gmp_randinit_default(rnd_state);
	mpz_init(a); mpz_init(s);

	//mpz_urandomm(a, rnd_state, nMinus3);
	//mpz_add_ui(a, a, 1);

	//a is set to 1, comment this if you want it random
	mpz_set_ui(a, 1);
	mpz_urandomm(s, rnd_state, nMinus1);

	mpz_init_set(u, s);
	mpz_init_set(v, s);

	mpz_init(uMinusV); mpz_init(g); mpz_init_set_ui(gMul, 1);

	//Pollard's rho cannot tell if a number is prime, test before getting into an infinite loop
	if(mpz_probab_prime_p(n, 5) > 0)
	{
		printf("%s is prime\n", mpz_get_str(NULL, 10, n));
		exit(0);
	}

	unsigned long steps = 0;
	start = my_gettimeofday();

	while(!finished)
	{
//[Factor search]
	while(!found)
	{
		f(u);
		f(v);
		f(v);

		mpz_set(uMinusV, u);
		mpz_sub(uMinusV, uMinusV, v);
		mpz_abs(uMinusV, uMinusV);

		//We don't calculate gcd everytime, we do 100 multiplications and use the result to
		//extract the gcd, since it must be among the product
		mpz_mul(gMul, gMul, uMinusV);

		if(steps%100 == 0)
		{
			mpz_gcd(g, gMul, n);

			if(mpz_cmp_ui(g, 1) != 0)
			{
				found = 1;
			}

			mpz_set_ui(gMul, 1);
		}

		steps++;
	}

	printf("Testing GCD: %s\n", mpz_get_str(NULL, 10, g));

//[Bad seed]
	if(mpz_cmp(g, n) != 0)
		finished = 1;
	}

	end = my_gettimeofday();

	printf("Found divisor g = %s in %lu steps [%.3f s]\n", mpz_get_str(NULL, 0, g), steps,
			end - start);

        //mpz_clear stuff here
}
