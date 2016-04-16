#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *ofp;
	int i, j, c1, c2, count, m, n, min, loc, sum[10], d[10][10], a[100][10];
	char fname[30];
	printf("enter number of elements: ");
	scanf("%d", &m);
	printf("enter number of clustering algorithms: ");
	scanf("%d", &n);
	printf("enter output file name: ");
	scanf("%s", &fname);
	ofp = fopen(fname, "w");
	printf("enter the clusters and labels in %d * %d matrix form\n", m, n);
	for(i = 1; i <= m; i ++)
	{
		for(j = 1; j <= n; j ++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	for(c1 = 1; c1 <= n; c1 ++)
	{
		for(c2 = 1; c2 <= n; c2 ++)
		{
			count = 0;
			for(i = 1; i <= m; i ++)
			{
				for(j = i + 1; j <= m; j ++)
				{
					if((a[i][c1] == a[j][c1] && a[i][c2] != a[j][c2]) || (a[i][c1] != a[j][c1] && a[i][c2] == a[j][c2]))
					{
						count ++;
					}
				}
			}
			d[c1][c2] = count;
		}
	}
	fprintf(ofp, "the distance matrix is\n");
	for(i = 1; i <= n; i ++)
	{
		for(j = 1; j <= n; j ++)
		{
			fprintf(ofp, "%d\t", d[i][j]);
		}
		fprintf(ofp, "\n");
	}
	for(i = 1; i <= n; i ++)
	{
		count = 0;
		for(j = 1; j <= n; j ++)
		{
			count = count + d[i][j];
		}
		sum[i] = count;
	}
	fprintf(ofp, "\nsymmetric difference distance of\n");
	for(i = 1; i <= n; i ++)
	{
		fprintf(ofp, "\ncluster %d = %d\n", i, sum[i]);
	}
	min = sum[1];
	loc = 1;
	for(i = 2; i <= n; i ++)
	{
		if(sum[i] < min)
		{
			min = sum[i];
			loc = i;
		}
	}
	fprintf(ofp, "\nthe best cluster is %d\n", loc);
	for(i = 1; i <= m; i ++)
	{
		fprintf(ofp, "%d\n", a[i][loc]);
	}
	printf("see %s for output\n", fname);
	fclose(ofp);
	return 0;
}
