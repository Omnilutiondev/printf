#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define UNUSED(x) (void) (x)
#define BUFF_SIZE 1024

/* the flags */
#define F_ZERO 4
#define F_PLUS 2
#define F_MINUS 1
#define F_SPACE 16
#define F_HASH 8

/* the sizes */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fomt -  This is the struct operator
 * by ike
 *
 * @fomt: The format to be used
 * @funt: The function to be associated
 */

struct fomt
{
	char fomt;
	int (*funt)(va_list, char[], int, int, int, int)
};

/**
 * typdef struct fomt fomt_t - The Struct operators
 *
 * @fomt: The chosen format.
 * @fom_t: The function associated with the format.
 */
typedef struct fomt fomt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** The main functions ******************/

/* The main funtions to print chars and strings */
int prnt_chars(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);
#endif
