#include "debug.h"
#include <stdarg.h>

void oi(){
	println("oi");
}

void logger(const char *format, ...){
	va_list arg;
	//int done;

	va_start (arg, format);
	//done = printf (format, arg);
	printf (format, arg);
	va_end (arg);

	//return done;
}
