/* 
 * CS:APP Data Lab 
 * 
 * <Lee Siwoo_2024312619>
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
   3. Has unpredictable behavior when shifting if the shift amount
      is less than 0 or greater than 31.
 
 
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
 
 For the problems that require you to implement floating-point operations,
 the coding rules are less strict.  You are allowed to use looping and
 conditional control.  You are allowed to use both ints and unsigneds.
 You can use arbitrary integer and unsigned constants. You can use any arithmetic,
 logical, or comparison operations on int or unsigned data.
 
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
   2. Each function has a maximum number of operations (integer, logical,
      or comparison) that you are allowed to use for your implementation
      of the function.  The max operator count is checked by dlc.
      Note that assignment ('=') is not counted; you may use as many of
      these as you want without penalty.
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
 /* Copyright (C) 1991-2022 Free Software Foundation, Inc.
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
    <https://www.gnu.org/licenses/>.  */
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
 /* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
    synchronized with ISO/IEC 10646:2017, fifth edition, plus
    the following additions from Amendment 1 to the fifth edition:
    - 56 emoji characters
    - 285 hentaigana
    - 3 additional Zanabazar Square characters */
 /* 
  * bitMatch - Create mask indicating which bits in x match those in y
  *            using only ~ and & 
  *   Example: bitMatch(0x7, 0xE) = 0x6
  *   Legal ops: ~ & |
  *   Max ops: 14
  *   Rating: 1
  */
 
  int bitMatch(int x, int y) {
   // 두 수 x와 y의 같은 위치의 비트가 같을 경우 1
   // x & y : 둘 다 1인 비트
   // ~x & ~y : 둘 다 0인 비트
   // 연산자 제한 -> 드모르간의 법칙으로 풀어서 표현
   return ~(~(x & y) & ~(~x & ~y));
 }
 
 /* 
  * fitsShort - return 1 if x can be represented as a 
  *   16-bit, two's complement integer.
  *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 8
  *   Rating: 1
  */
 
  int fitsShort(int x) {
   // x를 16비트 왼쪽으로 밀고 다시 16비트 오른쪽으로 밀었을 때, 값이 같으면 상위 비트가 모두 부호 비트와 같다는 의미
   return !(((x << 16) >> 16) ^ x);
 }
 
 /* 
  * evenBits - return word with all even-numbered bits set to 1
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 8
  *   Rating: 1
  */
 int evenBits(void) {
   // 0x55 = 01010101 (하위 8비트)이므로, 이를 왼쪽으로 밀면서 32비트 전체에 반복적으로 채운다
   int x = 0x55;
   x = x | (x << 8);
   x = x | (x << 16);
   return x;
 }
 /*
  * isSymmetric - return 1 if x is symmetrical, 0 otherwise
  * Example: isSymtetric(0x12341234) = 1 
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 7
  *   Rating: 2
  */
 int isSymmetric(int x) {
   // 32비트를 절반으로 나눠서 상위 16비트와 하위 16비트를 비교
   // 이때 같으면 대칭이므로 1, 아니면 0
   int mask = (0xFF << 8) | 0xFF; // 0xFFFF 만들기(숫자 범위 제한한)
   int a = (x >> 16) & mask;
   int b = x & mask;
   return !(a ^ b);
 }
 /* 
  * implication - return x -> y in propositional logic - 0 for false, 1
  * for true
  *   Example: implication(1,1) = 1
  *            implication(1,0) = 0
  *   Legal ops: ! ~ ^ |
  *   Max ops: 5
  *   Rating: 2
  */
 int implication(int x, int y) {
   // x가 0이면 무조건 참('무의의 참' 때문), x가 1이면 y도 1이어야 참
   return (!x) | y;
 }
 /* 
  * leastBitPos - return a mask that marks the position of the
  *               least significant 1 bit. If x == 0, return 0
  *   Example: leastBitPos(96) = 0x20
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 6
  *   Rating: 2 
  */
 int leastBitPos(int x) {
   // x와 -x를 AND 연산하면 가장 오른쪽 1비트만 남는다 (2의 보수 성질 이용)
   return x & (~x + 1);
 }
 /* 
  * oddBits - return word with all odd-numbered bits set to 1
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 8
  *   Rating: 2
  */
 int oddBits(void) {
   int x = 0xAA + (0xAA << 8); // 0xAAAA 만들기 -> 범위 제한으로 인해 shift 연산 사용용
   return x + (x << 16);       // 0xAAAAAAAA -> 또 shift 연산 사용용
 }
 
 /* 
  * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
  *  Round toward zero
  *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 15
  *   Rating: 2
  */
 int dividePower2(int x, int n) {
  int sign = x >> 31;                         // x가 음수면 sign = 0xFFFFFFFF, 양수면 0
  int bias = sign & ((1 << n) + ~0);          // bias는 음수일 때만 적용, (1 << n) - 1 형태, 음수를 나눌 때 기본적으로 내림이 되므로 bias를 더해서 결과를 0 쪽으로 반올림되게 함
  return (x + bias) >> n;                     // bias를 더한 뒤 시프트로 나눗셈 수행
}
 /* 
  * floatAbsVal - Return bit-level equivalent of absolute value of f for
  *   floating point argument f.
  *   Both the argument and result are passed as unsigned int's, but
  *   they are to be interpreted as the bit-level representations of
  *   single-precision floating point values.
  *   When argument is NaN, return argument..
  *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
  *   Max ops: 10
  *   Rating: 2
  */
 unsigned floatAbsVal(unsigned uf) {
  unsigned exp = (uf >> 23) & 0xFF; //지수 확인(8비트)
  unsigned frac = uf & 0x7FFFFF; // 가수 확인(23비트)

  // NaN이면 그대로 반환 (exp == 255, frac != 0)
  if (exp == 0xFF && frac != 0) return uf;

  // 부호 비트만 0으로 만들기
  return uf & 0x7FFFFFFF;
}
 /*
  * ezThreeFourths - multiplies by 3/4 rounding toward 0,
  *   Should exactly duplicate effect of C expression (x*3/4),
  *   including overflow behavior.
  *   Examples: ezThreeFourths(11) = 8
  *             ezThreeFourths(-9) = -6
  *             ezThreeFourths(1073741824) = -268435456 (overflow)
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 12
  *   Rating: 3
  */
 int ezThreeFourths(int x) {
  int y = x + (x << 1);        // x * 3 계산 (2x + x)
  int bias = (y >> 31) & 3;    // 음수일 경우에만 bias = 3 적용됨
  // 3은 4로 나눌 때 올림 보정을 위한 값 (3/4 = 0.75 → 반올림 위해 +3)
  return (y + bias) >> 2;      // bias를 더한 후 2비트 시프트로 나누기 (x * 3 / 4)
}
 
 /*
  * isAsciiAlpha - return 1 if 0x41 <= x <= 0x5a or 0x61 <= x <= 0x7a (ASCII
  * codes for characters 'a' to 'z' and 'A' to 'Z') Example:
  * isAsciiAlpha(0x45) = 1. isAsciiAlpha(0x3a) = 0. isAsciiAlpha(0x05) = 0.
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 20
  *   Rating: 3
  */
 int isAsciiAlpha(int x) {
   int negx = ~x + 1; // -x 구현(2의 보수)
   // 0x41 <= x <= 0x7A
   int range = !(((x + (~0x41 + 1)) >> 31) | ((0x7A + negx) >> 31));
   // 제외 범위: 0x5B ~ 0x60 (중간 제외 범위)
   int out   = !(((x + (~0x5B + 1)) >> 31) | ((0x60 + negx) >> 31));
   return range & (!out);
 }
 /* 
  * isGreater - if x > y  then return 1, else return 0 
  *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 24
  *   Rating: 3
  */
 int isGreater(int x, int y) {
   int sx = (x >> 31) & 1;
   int sy = (y >> 31) & 1;
   int sdiff = sx ^ sy; // 부호의 동일 여부 확인
   int sub = x + (~y + 1); // x - y 구현
   int sn = (sub >> 31) & 1; // 부호
   int nz = !!sub; // x != y일 때만 1
   int c1 = sdiff & sy; // x 양수, y 음수 → x > y
   int c2 = !sdiff & !sn & nz; // 같은 부호고 x > y
   return c1 | c2;
 }
 /* 
  * rotateRight - Rotate x to the right by n
  *   Can assume that 0 <= n <= 31
  *   Examples: rotateRight(0x87654321,4) = 0x18765432
  *   Legal ops: ~ & ^ | + << >> !
  *   Max ops: 25
  *   Rating: 3 
  */
 
 int rotateRight(int x, int n) {
  int left = x << ((~n + 1) + 32); // n만큼 오른쪽 이동한 값의 반대쪽 채우기
  int mask = ~(((1 << 31) >> n) << 1); // 최상위 비트 1을 n비트만큼 오른쪽으로 밀면 n번째 자리에 1이 있는 값이 됨
  // 다시 왼쪽으로 1칸 밀면 n+1번째 자리에 1이 있는 값이 됨 (하위 n비트는 모두 0)
  // ~를 씌우면 하위 n비트가 1인 값이 되고, 나머지는 0이 됨
  // 즉, 오른쪽 시프트 결과에서 하위 n비트만 남기고 상위 쓰레기 비트를 제거할 수 있게 해줌
  int right = (x >> n) & mask; // 오른쪽으로 시프트
  return left | right;         // 왼쪽 채운 부분과 오른쪽 시프트된 부분을 합쳐 회전 결과 완성
}
 /* 
  * collatz - returns 3x + 1 if x is odd, and x / 2 if x is even
  *   Examples: collatz(7) = 22, collatz(26) = 13
  *   You may assume 1 <= x <= (1 << 29), i.e., you don't need to handle overflow
  *   Legal ops: ! ~ & ^ | + << >>
  *   Max ops: 16
  *   Rating: 3
  */
 int collatz(int x) {
   int lsb = x & 1;
   int triple = (x << 1) + x + 1; //3x + 1 구현현
   int half = x >> 1;
   int flag = ~lsb + 1; // lsb가 1이면 -1, 아니면 0
   return (triple & flag) | (half & ~flag); // 조건에 따라 선택
 }
 
 /*
  * trueSevenSixteenths - multiplies by 7/16 rounding toward 0,
  *  avoiding errors due to overflow
  *  Examples: trueSevenSixteenths(11) = 4
  *            trueSevenSixteenths(-9) = -3
  *            trueSevenSixteenths(0x30000000) = 0x15000000
  *  Legal ops: ! ~ & ^ | + << >>
  *  Max ops: 25
  *  Rating: 4
  */
 int trueSevenSixteenths(int x) {
   int q = x >> 4; // 정수 몫 (/16)
   int r = x & 15; // 나머지
   int q7 = (q << 2) + (q << 1) + q; // q * 7 구현
   int r7 = (r << 2) + (r << 1) + r; // r * 7 구현
   int sign = x >> 31; // 부호 확인
   int bias = sign & 15; // 음수일 때만 반올림용 bias 설정정
   int adj = (r7 + bias) >> 4; // 보정 적용
   return q7 + adj;
 }
 /* 
  * floatFloat2Int - Return bit-level equivalent of expression (int) f
  *   for floating point argument f.
  *   Argument is passed as unsigned int, but
  *   it is to be interpreted as the bit-level representation of a
  *   single-precision floating point value.
  *   Anything out of range (including NaN and infinity) should return
  *   0x80000000u.
  *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
  *   Max ops: 30
  *   Rating: 4
  */
 int floatFloat2Int(unsigned uf) {
   int sign = uf >> 31;               // 부호 
   int exp = (uf >> 23) & 0xFF;       // 지수수 부분 추출 (8비트)
   int frac = uf & 0x7FFFFF;          // 가수 부분 추출 (23비트)
   int bias = 127;                    // bias
   int E = exp - bias;                // 실제 지수 계산 (지수 - bias)
   int result;
 
   if (exp == 0) return 0;   // 지수가 0이면 denormal 또는 0 → 정수로는 무조건 0
   if (E > 31 || exp == 255) return 0x80000000u; // 지수가 너무 크거나 지수가 255면 Infinity 또는 NaN → 변환 불가능(비정규)
 
   frac = frac | (1 << 23);  // 정규화 수니까 hidden bit 추가 
 
   if (E < 0) return 0;   // 실제 지수가 0보다 작으면 소수 부분밖에 없다는 뜻 → 정수 변환 시 0
   else if (E > 23) result = frac << (E - 23);  // 지수가 23보다 크면 왼쪽으로 시프트 (정수부 확장)
   else result = frac >> (23 - E);  // 지수가 작으면 오른쪽 쉬프트로 소수점 이하 제거
 
   if (sign) result = -result;  // 부호가 음수면 결과를 음수로 바꿔줌
   return result;
 }
 