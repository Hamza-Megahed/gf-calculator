/*
 ============================================================================
 Name        : gf-calculator.c
 Author      : Hamza Megahed
 Version     : 1.0
 Copyright   : Copyright 2014 Hamza Megahed
 Description : Galois Field 2^8 Calculator
 ============================================================================
 */
/*
 ============================================================================
   This file is part of gf-calculator.

    gf-calculator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    gf-calculator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with gf-calculator.  If not, see <http://www.gnu.org/licenses/>.
 ===========================================================================
*/
/********************************* Headers *********************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/*==========================================================================*/

/********************************* Functions *******************************/
uint8_t gfmul(uint8_t a, uint8_t b);
uint8_t gfadd(uint8_t a, uint8_t b);
uint8_t gfsub(uint8_t a, uint8_t b);
/*==========================================================================*/

int main(void)
{
    	int a,b;
		int option;
		start:

		printf("\n\n");
		printf("\t*************************************************\n");
	    printf("\t**** Welcome to Galois Field 2^8 Calculator ****\n");
	    printf("\t*************************************************\n");
	    printf("1. Addition\n2. Subtract\n3. Multiplication\n0. Exit\n");
	    printf("Enter your Selection : ");
	    scanf("%d",&option);
		while(option !=0)
		{
		if (option > 3)
	    		        {
	    printf("==================================================================\n");
	    printf("Wrong option .. please try again\n");
	    printf("==================================================================\n");
	    goto start;
	    		        }
	    printf("Enter The First Number\n");
	    scanf("%d",&a);
	    printf("Enter The Second Number\n");
	    scanf("%d",&b);

	    if (option == 1)
	    	    	printf("The addition result = %d\n",gfadd(a,b));
	    if (option == 2)
	    	    	printf("The subtraction result = %d\n",gfsub(a,b));
	    if (option == 3)
	    	printf("The multiplication result = %d\n",gfmul(a,b));
	    goto start;
}
	    if (option ==0)
	    	return EXIT_SUCCESS;

    	return (-1);

}





/******************************** gfadd *******************************/
/*Add two numbers in Galois Field 2^8 */

uint8_t gfadd(uint8_t a, uint8_t b) {
	return a ^ b;
}
/*====================================================================*/

/******************************** gfsub *******************************/
/*Subtract two numbers in Galois Field 2^8 */

uint8_t gfsub(uint8_t a, uint8_t b) {
	return a ^ b;
}
/*====================================================================*/

/******************************** gfmul *******************************/
/*Multiply two numbers in Galois Field 2^8 */
uint8_t gfmul(uint8_t a, uint8_t b) {
	uint8_t p = 0;
	uint8_t counter;
	uint8_t carry;
	for (counter = 0; counter < 8; counter++) {
		if (b & 1)
			p ^= a;
		carry = a & 0x80;
		a <<= 1;
		if (carry)
			a ^= 0x1B;
		b >>= 1;
	}
	return p;

}
/*====================================================================*/
