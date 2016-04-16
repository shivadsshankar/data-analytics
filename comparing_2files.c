#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 5000

int main()
{

	FILE *ifp1, *ifp2, *ofp;
	char ifname1[100], ifname2[100], ofname[100];
	int a, b, i, j, file1[MAX_VAL], file2[MAX_VAL];
	
	for( i = 0; i < MAX_VAL; i ++ )
	{
		file1[i] = 0;
		file2[i] = 0;
	}
	
	printf( "enter original overlapping input file name by community.dat file: " );
	scanf( "%s", &ifname1 );
	
	ifp1 = fopen( ifname1, "r" );
	if( ifp1 == NULL )
	{
		printf( "file %s cannot be opened\n", ifname1 );
		return;
	}
	
	printf( "enter generated input file name with our experiment that need to compare: " );
	scanf( "%s", &ifname2 );
	
	ifp2 = fopen( ifname2, "r" );
	if( ifp2 == NULL )
	{
		printf( "file %s cannot be opened\n", ifname2 );
		return;
	}
	
	printf( "enter output file name: " );
	scanf( "%s", &ofname);	

	ofp = fopen( ofname, "w" );
	if( ofp == NULL )
	{
		printf( "file %s cannot be opened\n", ofname );
		return;
	}
	
	i = 1;	
	while( fscanf( ifp1, "%d", &a ) != EOF )
	{
		file1[i] = a;
		i ++;
	}

	i = 1;
	while( fscanf( ifp2, "%d", &b ) != EOF )
	{
		file2[i] = b;
		i ++;
	}
	
	for( i = 1; i < MAX_VAL; i ++ )
	{		
		if( file1[i] )
		{
			a = file1[i];
			for( j = 1; j < MAX_VAL; j ++ )
			{
				if( file2[j] )
				{
					if( a == file2[j] )
					{
						fprintf( ofp, "%d\t%d\n", a, file2[j] );
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			break;
		}
	} 
		
	printf( "see %s for output\n", ofname );
	
	fclose( ifp1 );
	fclose( ifp2 );
	fclose( ofp );
	
	return 0;

}
