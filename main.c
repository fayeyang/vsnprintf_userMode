#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int vsn( char *format, ... ){
	int   	 tmp;
	char 	 buf[20];
	va_list  arg_ptr, arg_ptr1;

	tmp = sizeof( int );
	for( tmp=0; tmp<20; tmp++ ){
		buf[tmp]=0xFF;
	}
	
	va_start( arg_ptr, format );
	va_copy( arg_ptr1, arg_ptr );
	tmp = vsnprintf( buf, 10, format, arg_ptr );
	va_end( arg_ptr );

	printf( "%s\n", buf );
	printf( "%d\n", tmp );

	for( tmp=0; tmp<10; tmp++ ){
		printf( "%d\t", buf[tmp] );
	}
	printf( "\n" );

	for( tmp=0; tmp<10; tmp++ ){
		printf( "%c\t", buf[tmp] );
	}
	printf( "\n" );

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