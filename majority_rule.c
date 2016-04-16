#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *ofp;
	int i, j, m, n, a1, count = 0, arr1[100][10];
	char fname[30];
	float arr2[100][10];
	printf("enter number of nodes: ");
	scanf("%d", &m);
	printf("enter number of algorithms: ");
	scanf("%d", &n);
	
	printf("enter output file name: ");
	scanf("%s", &fname);
	ofp = fopen(fname, "w");
	if(ofp == NULL)
	{
		printf("file cannot be opened\n");
		return;
	}
	printf("enter the data in the form of %d * %d matrix: ", m, n);
	for(i = 1; i <= m; i ++)
	{
		for(j = 1; j <= n; j ++)
		{
			scanf("%d", &arr1[i][j]);
			arr2[m][n] = 0;
		}
	}
	for(i = 1; i <= m; i ++)
	{
		for(j = 1; j <= m; j ++)
		{
			for(a1 = 1; a1 <= n; a1 ++)
			{
				if(arr1[i][a1] != arr1[j][a1])
				{
					count ++;
				}
			}
			arr2[i][j] = count;
			count = 0;	
		}
	}
	printf("dissimilarity matrix is\n");
	for(i = 1; i <= m; i ++)
	{
		for(j = 1; j <= m; j ++)
		{
			fprintf(ofp, "%f\t", arr2[i][j]/n);
		}
		fprintf(ofp, "\n");
	}
	printf("see %s for output\n", fname);
	return 0;
}
