/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int z = (~x) | (~y); 
  return ~z;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {	
  n = n<<3; 
  x = x >> n; 
  return x & 0xff;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	return (~x)+1;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) { 
  int MSB = x >> 31;  
  //printf("MSB is %#x \n", MSB);
  int negate = ~x + 1; 
  int MSBn =  negate >> 31; 
  //printf("MSBn is %#x \n", MSBn);
  int bang = (MSB | MSBn) + 1; 
  //printf("bang is %#x \n", bang);
  return bang; 

  // return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  x = x>>n; // shift x
  int a = (1<< 31) >> n; 
  a = a << 1; // gets rids of MSB
  a = ~a; 
  return x&a;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !((x&(1<<31)) | !x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) { // sat

	// checks if signs of x and y are same or different
	int sign = x ^ y; 
	// get MSB of sign: 0 if same sign, 1 if diff sign
	int signMSB = (sign >> 31) & 1; 

	// -x+y
	int diff = (~x+1) + y; 
	// if diff is pos or 0, <=; if diff is neg, >
	
	// get sign of diff
	int diffSign = (diff >> 31) & 1; 
	// diffSign 0 if <=, diffSign 1 if >


	// make mask based on sign of x: 0000... if pos, 11111 if neg
   	int mask = ((1<<31) & x) >> 31;
 
	int a = signMSB & mask;
	// a is 1 when mask is 111.... (x is neg) and signMSB is 1 (x and y are different signs) (<=); else 0....
	int b = !diffSign & !signMSB; 
	// b is 1 when diffSign is 0 (<=) and when signMSB is 0 (x and y same sign); else 0

	return a | b;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) { 
    int multFive = (x << 2) + x; // multiply by 5

    int denomEight = (1 << 3); 
    //printf("denom is %#x \n", denom);
    int b = (1<<31)>>31;; // 1111......
    //printf("b is %#x \n", b);
    int c = denomEight+b;
    //printf("mask is %#x \n", mask); 

    // // Use & operator on mask and sign bit of x 
    int sign = multFive >> 31; 
    // printf("c is %#x \n", c);
    int d = sign & c;
    // printf("eq is %#x \n", equalizer); 

    // // Adds 1 if x was originally negative
    // // Adds 0 if x was originally positive
    int ans = multFive + d; 
    // printf("ans is %#x \n", ans);
    int divideEight = ans >> 3; 
    // printf("ans2 is %#x \n", ans2); */
    return divideEight;    
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) { 
    int denom = (1 << n); 
    int b = (1<<31)>>31; // 1111......
    int c = denom+b; 

    int sign = x >> 31; // 0000... if pos, 11111... if neg 
    int d = sign & c; // d = 0 if pos, d = c if neg

    int ans = (x + d); 
    int divide = ans >> n; 
    return divide;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) { 
	// calcaulate log

  return 2;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) { //mon
  //return 2;
  // int sum, overflow_mask, sum_, max;
  // sum = x+y;
  // overflow_mask = ((sum^x) & (sum^y))>>31; // all ones  if overflow , all zeros if not
  // sum_ = sum & ~overflow_mask;       // all zeros if overflow , sum       if not
  // max = overflow_mask & ((1<<31) + (sum>>31)); // 10000... + either 0 or -1
  // return sum_ | max;

 //  	int sx = (x>>31)&0x1;
	// int sy = (y>>31)&0x1;
	// int sxay = ((x+y)>>31)&0x1;
	// int answer1 = ((((sx^sy)+(!((sx^sy)|(sxay^sx))))<<31)>>31)&(x+y);
	// int answer2 = ((((!(sx^sy))&(sx^sxay))<<31)>>31)&(((0x1<<31)+(~1)+1)+sx);
	// return answer1|answer2;
//return 2; 
	/*int sum = x + y; 

	//same as addOk
  int sum = x + y;
  int xsign = x >> 31;
  int ysign = y >> 31;
  int xysign = sum >> 31;
  int overflow = (~(xsign ^ ysign)) & (xsign ^ xysign);
  
  //the positive overflow occured if the sign of x is negative and overflow occured
  int positive = overflow & (~(xsign ^ 0));
  
  //negative overflow occured if the sign of x is positive and overflow occured
  int negative = ~(overflow & (~(xsign^0)));
  
  //1000000000000000000000000
  int minimum = 1 << 31;
  
  //0111111111111111111111111
  //largest positive number
  int maximum = ~minimum;
  
  int final = (~overflow & sum) | (overflow & ((positive & maximum) | (negative & minimum)));
  return final; */

/*In order to have a overflow, there must be an extra bit. 
	* Case 1: 1....+1.... and yield an overflow, then the result could be (1)0....or (1)1...
	* Case 2: 1....+0....no overflow
	* Case 3: 0 + 0 -> postive overflow
	*/
	int overNegResult, overPosResult;
	int sum = x + y;
	int tmin = 1 << 31; 
	int xMSB = x >> 31; 
	int yMSB = y >> 31; 
	int sumMSB = sum >> 31; 
	// testOF
	int check = (sumMSB ^ xMSB ) & (sumMSB ^ yMSB); // 111... if overflow , 000.... if not
	//return 2; 
	sum = sum & ~check; // 0... if OF, x+y if no OF

	// int max = check & ((1<<31) + sumMSB); // 10000... + either 0 or -1
 //    max = overflow_mask & ((1<<31) + (sum>>31)); // 10000... + either 0 or -1
 //    return sum | max;

	// sum  = sum & ~check; // sum = 0 if there's overflow (or the sum is 0), sum = x+y if no overflow
	// // (((1 << 31)& check)) returns 0x80000 when check is 111
	// // also need to check whether the sum is neg or pos overflow (x >> 31 is all 1s iff first digit of x is 1)
	
	// overNegResult = (((1 << 31) & check))& (x >>31);
	// overPosResult = (((~(1 << 31)) & check))&(~(x >> 31));
 	// return sum | overNegResult| overPosResult;

 	overNegResult = (tmin & check) & (xMSB);
	overPosResult = (((~(tmin)) & check)) & (~xMSB);
 	return sum | overNegResult| overPosResult;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) { //mon
  //return 2;
  //uf = 0xfefea4cb; 
  // uf =0x80015b1a; 
  // printf("uf is %#x \n", uf);
  /*unsigned significand = ; 
  unsigned exp; 
  unsigned sign; */
  


  /*unsigned exp= uf>>23&0xFF;
  printf("exp is %#x \n", exp);
  unsigned fra= uf<<9;
  printf("fra is %#x \n", fra); 
  unsigned a= 0x1<<31;
  printf("a is %#x \n", a);

  if ((exp==0xFF)&&(!!fra))
  {
    printf("ans is %#x \n", uf);
    //return uf;
    return 2; 
      
  }

 
  printf("ans is %#x \n", uf^a);*/
   //return uf^a;
  return 2; 

}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) { // mon
  return 2;
}
