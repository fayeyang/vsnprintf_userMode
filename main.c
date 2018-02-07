#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int vsn( char *format, ... ){
	int   	 tmp;
	char 	 buf[20];
	va_list  arg_ptr;

	tmp = sizeof( int );
	for( tmp=0; tmp<20; tmp++ ){
		buf[tmp]=0xFF;
	}
	
	va_start( arg_ptr, format );
	tmp = vsnprintf( buf, 10, format, arg_ptr );
	va_end( arg_ptr );

	printf( "%s\n", buf );
	printf( "%d\n", tmp );

	return 0;
}

int main( void ){

	char *str1 = "abc";
	char *str2 = "xyz";
	int m = 10;
	int n = 1000;

	vsn( "%s,%d,%s,%d", "abc", 10, "xyz", 1000 );
	return 0;	
}