#include "debug.h"
#include <stdarg.h>

void oi(){
	println("oi");
}

void logger(const char *format, ...){
	va_list arg;

	//printnl();

	va_start (arg, format);
	//vfprintf (stdout, format, arg);
	va_end (arg);

	//printnl();
}
