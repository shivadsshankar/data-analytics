#include <stdio.h>

int main()
{
	int i, j, c1, c2, count, m, sum[4], d[5][5], a[4][10];
	printf("enter the clusters and labels in 10 * 4 matrix form\n");
	for(i = 1; i <= 10; i ++)
	{
		for(j = 1; j <= 4; j ++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	for(c1 = 1; c1 <= 4; c1 ++)
	{
		for(c2 = 1; c2 <= 4; c2 ++)
		{
			count = 0;
			for(i = 1; i <= 10; i ++)
			{
				for(j = i + 1; j <= 10; j ++)
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
	printf("the distance matrix is\n");
	for(i = 1; i <= 4; i ++)
	{
		for(j = 1; j <= 4; j ++)
		{
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
	for(i = 1; i <= 4; i ++)
	{
		count = 0;
		for(j = 1; j <= 4; j ++)
		{
			count = count + d[i][j];
		}
		sum[i] = count;
	}
	for(i = 1; i <= 4; i ++)
	{
		printf("sum = %d\n", sum[i]);
	}
	for(i = 1; i <= 10; i ++)
	{
		printf("%d\n", a[i][4]);
	}
	/*for(i = 1; i <= 3; i ++)
	{
		j = i + 1;
		if(sum[i] <= sum[j])
		{
			m = i;
		}
		else
		{
			m = i + 1;
		}
	}	
	printf("munimum = %d\n", sum[m]);
	for(i = 1; i <= 10; i ++)
	{
		printf("%d\n", a[i][m]);
	}*/
	return 0;
}
