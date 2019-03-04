#include <iostream>
#include <fstream>

class pgm
{
	unsigned char** data;
	int width;
	int height;

public:
	pgm();
	pgm( int, int );
	~pgm();
	pgm( const pgm& );
	void read( const char* filename );
	void write( const char* filename );
	unsigned char& at( int, int );
};