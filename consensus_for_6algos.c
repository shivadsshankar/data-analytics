#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 5300

int m, n, degree[MAX_VAL],edge[MAX_VAL][MAX_VAL]; 

//--------------------------------------------------------------------------------------------------------------------------------------

int main( )
{
	
	FILE *ifp, *ofp;
	
	int i, i1, j, a, a0, a1, a2, a3, a4, a5, a6, a7, count, arr[MAX_VAL][6];
	char ifname[50], ofname[50];
	
	printf( "enter number of nodes: " );
	scanf( "%d", &m );
	
	printf( "enter number of algorithms: " );
	scanf( "%d", &n );
	
	printf( "enter input file name contains community labels as %d * %d matrix format: ", m, n );
	scanf( "%s", &ifname );
	
	ifp = fopen( ifname, "r" );
	
	if( ifp == NULL )
	{
		printf( "input file %s cannot be opened\n", ifname );
		return;
	}	
	
	printf( "enter output file name: " );
	scanf( "%s", &ofname );
	
	ofp = fopen( ofname, "w" );
	if( ofp == NULL )
	{
		printf( "file %s cannot be opened\n", ofname );
		return;
	}
	
	for( a = 0; a < MAX_VAL; a ++ )
	{
		degree[a] = 0;
		edge[a][a] = 0;
	}
	
	i = 0;	
	while( fscanf( ifp, "%d %d %d %d %d %d", &a0, &a1, &a2, &a3, &a4, &a5 ) != EOF ) //reads the file line by line and stores the values into variables.
	{
		arr[i][0] = a0;
		arr[i][1] = a1;
		arr[i][2] = a2;
		arr[i][3] = a3;
		arr[i][4] = a4;
		arr[i][5] = a5;
			
		//printf( "%d\t%d\t%d\t%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5] );
		//printf("%d\n", i);		
		i++;	
			
	}
	
	for( i = 0; i < m; i ++ )  //checking for consensus, for each pair of vertices how mny algorithms says to be in same community.
	{
		for( i1 = 0; i1 < m; i1 ++ )
		{
			if( i != i1 )
			{
				count = 0;
				for( j = 0; j < n; j ++ )
				{
					if( arr[i][j] == arr[i1][j] )
					{
						count ++;
					}
				}
			}
			if( count == n )  //checking whether all algorithms says the pair of vertices are in same community or not.
			{				
				edge[i][i1] = 1; 
			}
		}
	}
	
	for( i = 0; i < m; i ++ )
	{
		for( i1 = 0; i1 < m; i1 ++ )
		{
			if( edge[i][i1] )
			{
				break;
			}
		}
		if( i1 == m )
			fprintf( ofp, "%d\n", i + 1 );
	}
	
	printf( "see %s for output\n", ofname );
		
	fclose( ifp ); //Closing input file.	
	fclose( ofp ); //Closing output file.
	
	return 0;					
}

//--------------------------------------------------------------------------------------------------------------------------------------


