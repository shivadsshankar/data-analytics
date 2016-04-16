#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 5300

int m, n, degree[MAX_VAL], label1[MAX_VAL], label2[MAX_VAL], label3[MAX_VAL], label4[MAX_VAL], label5[MAX_VAL], label6[MAX_VAL], edge[MAX_VAL][MAX_VAL]; 

int calDegree( );

int printResult( );

//--------------------------------------------------------------------------------------------------------------------------------------

int main( )
{	
	FILE *ifp, *ifp2, *ofp;
	
	int i, j, a, b, a1, a2, a3, a4, a5, a6, count;
	char ifname[50], ifname2[50];
	
	printf( "enter number of nodes: " );
	scanf( "%d", &m );
	
	printf( "enter number of algorithms: " );
	scanf( "%d", &n );
	
	printf( "enter input file name contains community labels as %d * %d matrix format: ", m, n );
	scanf( "%s", &ifname );
	
	for( i = 0; i < MAX_VAL; i ++ )
	{
		degree[i] = 0;
		label1[i] = label2[i] = label3[i] = label4[i] = label5[i]= 0;
		for( j = 0; j < MAX_VAL; j ++ )
		{
			edge[i][j] = 0;
		}
	}
	
	ifp = fopen( ifname, "r" );	
	if( ifp == NULL )
	{
		printf( "input file %s cannot be opened\n", ifname );
		return;
	}	
	
	i = 1;	
	while( fscanf( ifp, "%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5 ) != EOF ) //reads the file line by line and stores the values into variables.
	{		
		label1[i] = a1;
		label2[i] = a2;
		label3[i] = a3;
		label4[i] = a4;
		label5[i] = a5;
		//printf( "%d\t%d\t%d\t%d\t%d\t%d\n", label1[i],label2[i],label3[i],label4[i],label5[i],label6[i] );
		
		i ++;
	}	
	
	fclose( ifp ); //Closing input file.
	
	printf( "enter input file name that contains edgelist: " );
	scanf( "%s", &ifname2 );
	
	ifp2 = fopen( ifname2, "r" );
	if( ifp2 == NULL )
	{
		printf( "file %s cannot be opened\n", ifname2 );
		return;
	}
	
	while( fscanf( ifp2, "%d %d", &a, &b ) != EOF )
	{
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	
	fclose( ifp2 );
	
	calDegree( );
	
	printResult( );
	
	return 0;					
}

//--------------------------------------------------------------------------------------------------------------------------------------

int calDegree()
{
	FILE *ifp;
	
	char ifname[50];
	int i, a;
	
	printf( "enter file name that contains degrees: " );
	scanf( "%s", &ifname );
	
	ifp = fopen( ifname, "r" );
	if( ifp == NULL )
	{
		printf( "file %s cannot be opened\n", ifname );
		return;
	}
	
	i = 1; 
	while( fscanf( ifp, "%d", &a ) != EOF )
	{
		degree[i] = a;
		//printf( "%d\n", degree[i] );
		i ++;
	}	
	
	fclose( ifp );
	
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------

int printResult( ) //It gives the nodes which are overlapping. 
{	
	FILE *ofp;
	
	int i, j, count, count1, count2, count3, count4, count5, count6, count7, c, c1;	
	char ofname[50];
	
	printf( "enter output file name: " );
	scanf( "%s", &ofname );
	
	ofp = fopen( ofname, "w" );	
	if( ofp == NULL )
	{
		printf( "File %s cannot be opened\n", ofname );
		return;
	}		
	
	//fprintf( ofp, "\nOverlapping nodes by applying connectivity labels are\n" );
	
	for( i = 1; i <= m; i ++ )
	{
		count1 = count2 = count3 = count4 = count5 = 0;
		c = 0;
		
		for( j = 1; j <= m; j ++ )
		{
			if( edge[i][j] )
			{				
				if( label1[i] != label1[j] )
				{
					count1 ++;
				}
				if( label2[i] != label2[j] )
				{
					count2 ++;
				}
				if( label3[i] != label3[j] )
				{
					count3 ++;
				}
				if( label4[i] != label4[j] )
				{
					count4 ++;
				}
				if( label5[i] != label5[j] )
				{
					count5 ++;
				}							
			}
		}
		//printf( "%d\t%d\t%d\t%d\t%d\t%d\t%d\n", count1, count2, count3, count4, count5, count6, count7 );
		if( degree[i] % 2 != 0 )
		{
			count = degree[i] + 1;
		}
		else
		{
			count = degree[i];
		}
		
		//printf("%d\t%d\n", count, degree[i]);
		
		if( ( degree[i] > 1 ) && ( count1 >= count / 2 ) )
		{
			//fprintf(ofp, "%d\n", i);
			c ++;
		}
		if( ( degree[i] > 1 ) && ( count2 >= count / 2 ) )
		{
			c ++;
		}
		if( ( degree[i] > 1 ) && ( count3 >= count / 2 ) )
		{
			c ++;
		}
		if( ( degree[i] > 1 ) && ( count4 >= count / 2 ) )
		{
			c ++;
		}
		if( ( degree[i] > 1 ) && ( count5 >= count / 2 ) )
		{
			c ++;
		}				
		if( n % 2 != 0 )
		{
			c1 = n + 1;
		}
		else
		{
			c1 = n;
		}
		if( c >= c1 / 2 )
		{
			//printf( "%d\n", i );
			fprintf( ofp, "%d\n", i );
		}
	}	

	fclose( ofp );

	printf( "see %s for output\n", ofname );
	
	return 0;	
}

