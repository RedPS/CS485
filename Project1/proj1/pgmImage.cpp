#include "pgmImage.h"

pgm::pgm()
{
	data = NULL;
	width = height = 0;
}
pgm::pgm( int h, int w )
{
	height = h;
	width = w;
	data = new unsigned char*[height];
	for( int i = 0; i < height; ++i )
	{
		data[i] = new unsigned char[width];
		for( int j = 0; j < width; ++j )
		{
			data[i][j] = 0;
		}
	}
}
pgm::~pgm()
{
	for( int i = 0; i < height; ++i )
	{
		delete[] data[i];
	}
	delete[] data;
	data = NULL;
	width = height = 0;
}
pgm::pgm( const pgm& src )
{
	width = src.width;
	height = src.height;
	data = new unsigned char*[ height ];
	for( int i = 0; i < height; ++i )
	{
		data[i] = new unsigned char[width];
		for( int j = 0; j < width; ++j )
		{
			data[i][j] = src.data[i][j];
		}
	}
}
void pgm::read( const char* filename )
{
	char temp[50];
	std::ifstream infile( filename );
	infile >> temp;
	infile >> width >> height >> temp;
	infile.get();
	data = new unsigned char*[ height ];
	for( int i = 0; i < height; ++i )
	{
		data[i] = new unsigned char[width];
		for( int j = 0; j < width; ++j )
		{
			data[i][j] = infile.get();
		}
	}
	infile.close();
}
void pgm::write( const char* filename )
{
	std::ofstream outfile( filename );
	outfile << "P5" << std::endl << width << ' ' << height << std::endl << "255" << std::endl;
	for( int i = 0; i < height; ++i )
	{
		for( int j = 0; j < width; ++j )
		{
			outfile << data[i][j];
		}
	}
	outfile.close();
}
unsigned char& pgm::at( int i, int j )
{
	if( i >= 0 and i < height and j >= 0 and j < width )
	{
		return data[i][j];
	}	
	else
	{
		throw "Invalid indexing ";
	}
}