#include <stdio.h>
int main ()
{
	float vector[4][4]= 
	{
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,
	};
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			printf("%f\n",vector[i][j]);
		}
		
	}
	
}