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

/* The main functions to print numbers */
int prnt_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_hex_upr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int prnt_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* The main function to print non printable chars */
int prnt_non_prntable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* The main function to print memory the address */
int prnt_pntr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* The main functions to handle other specifiers */
int get_flg(const char *format, int *i);
int get_wdt(const char *format, int *i, va_list list);
int get_preci(const char *format, int *i, va_list list);
int get_sz(const char *format, int *i);

/* The main function to print strings in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*The main function to print a string in rot 13*/
int print_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* The main width handler */
int hndl_rite_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int rite_num(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int rite_pntr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int rite_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** MAIN UTILS ******************/
int is_prntble(char);
int app_hexa_code(char, char[], int);
int is_digit(char);

long int cnvrt_size_num(long int num, int size);
long int cnvrt_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
