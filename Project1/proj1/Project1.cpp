#include <iostream>
#include <string.h>
#include "pgmImage.cpp"
#include "solve_system.c"
#include "svbksb.c"
#include "svdcmp.c"

int main( int argc, char** argv )
{
    int X;
    int Y;

	pgm source;
	pgm dest(48, 40);

	float** Matrix_A;

	float XCoef[4];
    float YCoef[4];

	float KX[4];
	float KY[4];

    //arbitarry values... can be changed but these are ideal
	KX[1] = 8;
    KY[1] = 10;

	KX[2] = 31;
    KY[2] = 10;

	KX[3] = 20;
    KY[3] = 27;

	KX[4] = 20;
    KY[4] = 38;

	Matrix_A = new float*[5];
	for( int i = 0; i < 5; ++i )
	{
		Matrix_A[i] = new float[4];
	}

	source.read( argv[1] );

	Matrix_A[1][1] = atof( argv[2] );
	Matrix_A[1][2] = atof( argv[3] );
	Matrix_A[1][3] = 1.0f;

	Matrix_A[2][1] = atof( argv[4] );
	Matrix_A[2][2] = atof( argv[5] );
	Matrix_A[2][3] = 1.0f;

	Matrix_A[3][1] = atof( argv[6] );
	Matrix_A[3][2] = atof( argv[7] );
	Matrix_A[3][3] = 1.0f;
	
	Matrix_A[4][1] = atof( argv[8] );
	Matrix_A[4][2] = atof( argv[9] );
	Matrix_A[4][3] = 1.0f;

	std::cout << "The 'Matrix_A' Matrix" << std::endl;
	for( int i = 1; i <= 4; ++i )
	{
		std::cout << "| " << Matrix_A[i][1] << ' ' << Matrix_A[i][2] << ' ' << Matrix_A[i][3] << " |" << std::endl;
	}
	solve_system( 4, 3, Matrix_A, XCoef, KX );
	solve_system( 4, 3, Matrix_A, YCoef, KY );

	std::cout << "The 'X' Matrix (Affine Transformation Parameters)" << std::endl;
	std::cout << "[ X_Vector Y_Vector ]" << std::endl;
	for( int i = 1; i < 4; ++i )
	{
		std::cout << "| " << XCoef[i] << ' ' << YCoef[i] << " |" << std::endl; 
	}
	for( int i = 0; i < 112; ++i )
	{
		for( int j = 0; j < 92; ++j )
		{
			X = ( (j * XCoef[1]) + (i * XCoef[2]) + XCoef[3] );
			Y = ( (j * YCoef[1]) + (i * YCoef[2]) + YCoef[3] );
			if( X >= 0 and X < 40 and Y >= 0 and Y < 48 )
			{
				if( dest.at( Y, X ) == 0 )
				{
					dest.at( Y, X ) = source.at( i, j );
				}
				else
				{
					dest.at( Y, X ) = (source.at( i, j ) + dest.at( Y, X )) / 2;
				}
			}
		}
	}
    char TempFileName[128]; 
	int len = strlen( argv[1] );
	strcpy( TempFileName, argv[1] );
    strcpy( TempFileName + len - 4, "_Result.pgm" );
	dest.write( TempFileName );
	return 0;
}