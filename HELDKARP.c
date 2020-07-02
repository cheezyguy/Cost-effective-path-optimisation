#include<stdio.h>

#define n 6
int ary[n][n],completed[n],cost=0;

void takeInput()
{
	int i,j,t;

	/*printf("Enter the number of villages: ");
	scanf("%d",&n);

	printf("\nEnter the Cost Matrix\n");

	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row: %d\n",i+1);

		for( j=0;j < n;j++)
			scanf("%d",&ary[i][j]);

		completed[i]=0;
	}
    ///SAMPLE TEST CASE 1

    t=1;
    printf("TEST CASE = %d SAMPLE SIZE = %d",t,n);
    int temp[n][n] ={

        {0, 2,   1,   0},
        {2,   0, 4,   3},
        {1,   4,   0, 2},
        {0, 3,   2,   0}
    };

    ///SAMPLE TEST CASE 2
     t=2;
    printf("TEST CASE = %d SAMPLE SIZE = %d",t,n);
    int temp[n][n] =
    {
        {0, 3,   1,   5,   8},
        {3,   0, 6,   7,   9},
        {1,   6,   0, 4,   2},
        {5,   7,   4,   0, 3},
        {8,   9,   2,   3,   0}
    };


     ///SAMPLE TEST CASE 3
*/
    t=3;
    printf("TEST CASE = %d SAMPLE SIZE = %d",t,n);
    int temp[n][n] =
    {

        {0, 5,   0, 6,   5,   4},
        {5,   0, 2,   4,   3,   0},
        {0, 2,   0, 1,   0, 0},
        {6,   4,   1,   0, 7,   0},
        {5,   3,   0, 7,   0, 3},
        {4,   0, 0, 0, 3,   0}
    };

/*
    ///SAMPLE TEST CASE 4
    t=4;
    printf("TEST CASE = %d SAMPLE SIZE = %d",t,n);
    int temp[n][n] =
    {
        {0, 5,   0, 6,   5,   4,    5},
        {5,   0, 2,   24,   3,   0,  8},
        {0, 2,   0, 1,   0, 0,  1},
        {6,   4,   11,   0, 37,   0,  4},
        {5,   3,   0, 7,   0, 13,    5},
        {4,   0, 0, 0, 3,   0,  1},
        {8,   55,   22,   1,   0,   3,  0}
    };

  /*
    ///SAMPLE TEST CASE 5
    t=5;
    printf("TEST CASE = %d SAMPLE SIZE = %d",t,n);
    int temp[n][n] =
    {
        {0, 5,   0, 6,   5,   4,    5,  2},
        {5,   0, 2,   24,   3,   0,  8,  1},
        {0, 2,   0, 1,   0, 0,  1,  6},
        {6,   4,   11,   0, 37,   0,  4,  7},
        {5,   3,   0, 7,   0, 13,    5,  9},
        {4,   0, 0, 0, 3,   0,  1,  4},
        {8,   55,   22,   1,   0,   3,  0,  7},
        {2,   7,   2,   7,   0,   32,  17, 0}
    };

/*
;*/

    for( i=0;i < n;i++)
	{
        for(j=0;j < n;j++)
			ary[i][j] = temp[i][j];

        completed[i]=0;
	}
	printf("\n\nThe cost list is:");

	for( i=0;i < n;i++)
	{
		printf("\n");

		for(j=0;j < n;j++)
			printf("\t%d",ary[i][j]);
	}
}



int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

	return nc;
}

void mincost(int city)
{
	int i,ncity;

	completed[city]=1;

	printf("%d--->",city+1);
	ncity=least(city);

	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=ary[city][ncity];

		return;
	}

	mincost(ncity);
}

int main()
{
	takeInput();

	printf("\n\nThe Path is:\n");
	mincost(0); //passing 0 because starting vertex

	printf("\n\nMinimum cost is %d\n ",cost);

	return 0;
}
