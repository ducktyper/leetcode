#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define assertInt(a, b) (helperAssertInt(a, b) || helperPrint(__FILE__, __LINE__))
#define assertDouble(a, b) (helperAssertDouble(a, b) || helperPrint(__FILE__, __LINE__))
#define assertLong(a, b) (helperAssertLong(a, b) || helperPrint(__FILE__, __LINE__))
#define assertString(a, b) (helperAssertString(a, b) || helperPrint(__FILE__, __LINE__))
#define assertIntArray(a, b) (helperAssertIntArray(a, b) || helperPrint(__FILE__, __LINE__))

/* Primitive data */
int helperAssertInt(int expect, int actual);
int helperAssertLong(long expect, long actual);
int helperAssertDouble(double expect, double actual);
int helperAssertString(char * expect, char * actual);

/* Array */
int countArrayInString(char * array); /* [1,2] => 2 */
int * stringToIntArray(char * string);
char * intArrayToString(int * array, int size);
char * intArrayOfArrayToString(int ** array, int arraySize, int arrayInSize);
int helperAssertIntArray(char * expect, int * actual);

/* Other */
int helperPrint(char * file, int line);
