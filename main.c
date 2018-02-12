#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int vsn( char *format, ... ){
	char 	 *cptr;
	int   	  tmp,     len;
	va_list   arg_ptr, arg_ptr1;
	
	va_start( arg_ptr, format );
	va_copy( arg_ptr1, arg_ptr );
	len = vsnprintf( (char*)&tmp, 0, format, arg_ptr );
	va_end( arg_ptr );
	++len;

	cptr = NULL;
	cptr = malloc( len );
	if( NULL == cptr ){
		perror( "malloc error:" );
		return 1;
	}
	memset( cptr, 0xFF, len );

	len = vsnprintf( cptr, len, format, arg_ptr1 );
	va_end( arg_ptr1 );
	printf( "len=%d\n", len );
	printf( "%s\n", cptr );
	
	for( tmp=0; tmp<=len; tmp++ ){
		printf( "%d\t", cptr[tmp] );
	}
	printf( "\n" );

	for( tmp=0; tmp<=len; tmp++ ){
		printf( "%c\t", cptr[tmp] );
	}
	printf( "\n" );

	free( cptr );
	
	return 0;
}

int main( int argc, char *argv[] ){
	int tmp;
	char buf[ 60 ];
	
	memset( buf, 0xff, 60 );
	tmp = sprintf( buf, "string is: %s\n", "test string" );
	tmp += sprintf( buf+tmp, "number is: %d\n", 100 );
	tmp += sprintf( buf+tmp, "character is %c\n", '?' );
	printf( "%d\n", tmp );
	printf( "%s\n", buf );
	for( tmp=0; tmp<=60; tmp++ ){
		printf( "%d\t", buf[tmp] );
	}
	printf( "\n" );
	for( tmp=0; tmp<=60; tmp++ ){
		printf( "%c\t", buf[tmp] );
	}
	printf( "\n" );

	//vsn( "%s, %d, %s, %c", "abc", 10, "xyz", 'A' );
	return 0;	
}