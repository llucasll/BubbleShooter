#include "debug.h"
#include <stdarg.h>

void oi(){
	println("oi");
}

void logger(const char *format, ...){
	va_list arg;

	va_start (arg, format);
	vfprintf (format, arg);
	va_end (arg);
}
