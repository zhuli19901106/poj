#include <stdio.h>

int adj[8][2] = {
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, -1},
	{0, 1},
	{1, -1},
	{1, 0},
	{1, 1}
};

int flooded[22][22];

void flood(int object[][22], int grid[][22], int clickrow, int clickcol, int row, int col)
{
	int i;

	if(grid[clickrow][clickcol] == 1)
	{
		object[clickrow][clickcol] = 1;
		flooded[clickrow][clickcol] = 1;
		for(i = 0; i < 8; i++)
		{
			if(flooded[clickrow + adj[i][0]][clickcol + adj[i][1]] == 0)
			{
				if(
					(clickrow + adj[i][0] >= 1 && clickrow + adj[i][0] <= row)
					&&
					(clickcol + adj[i][1] >= 1 && clickcol + adj[i][1] <= col)
					)
				{
					if(grid[clickrow + adj[i][0]][clickcol + adj[i][1]] == 1)
					{
						flood(object, grid, clickrow + adj[i][0], clickcol + adj[i][1], row, col);
					}
				}
			}
		}
	}
	else
	{
		return;
	}
}


int main()
{
	int grid[22][22];
	int object[22][22];
	int row;
	int col;
	int i;
	int j;
	int perimeter;
	int clickrow;
	int clickcol;
	char line[500];

	while(1)
	{
		gets(line);
		sscanf(line, "%d%d%d%d", &row, &col, &clickrow, &clickcol);
		if(row == 0 && col == 0 && clickrow == 0 && clickcol == 0)
		{
			break;
		}

		for(i = 0; i < 22; i++)
		{
			for(j = 0; j < 22; j++)
			{
				grid[i][j] = 0;
			}
		}

		for(i = 1; i <= row; i++)
		{
			gets(line);
			for(j = 1; j <= col; j++)
			{
				if(line[j - 1] == '.')
				{
					grid[i][j] = 0;
				}
				else if(line[j - 1] == 'X')
				{
					grid[i][j] = 1;
				}
			}
		}

		if(grid[clickrow][clickcol] == 0)
		{
			printf("0\n");
			continue;
		}

		for(i = 0; i < 22; i++)
		{
			for(j = 0; j < 22; j++)
			{
				object[i][j] = 0;
				flooded[i][j] = 0;
			}
		}

		flood(object, grid, clickrow, clickcol, row, col);
		/*
		for(i = 1; i <= row; i++)
		{
			for(j = 1; j <= col; j++)
			{
				if(object[i][j] == 0)
				{
					printf(".");
				}
				else if(object[i][j] == 1)
				{
					printf("X");
				}
			}
			printf("\n");
		}
		*/
		perimeter = 0;
		for(i = 1; i <= row; i++)
		{
			for(j = 1; j <= col; j++)
			{
				if(object[i][j] == 1)
				{
					if(object[i - 1][j] == 0)
					{
						perimeter++;
					}
					if(object[i + 1][j] == 0)
					{
						perimeter++;
					}
					if(object[i][j - 1] == 0)
					{
						perimeter++;
					}
					if(object[i][j - 1] == 0)
					{
						perimeter++;
					}
				}
			}
		}

		printf("%d\n", perimeter);
	}

	return 0;
}

