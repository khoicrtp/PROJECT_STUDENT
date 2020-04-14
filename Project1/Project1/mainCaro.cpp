#include "Caro.h"

int main()
{
	//char list[30];
	//FILE* in = fopen("input.csv", "r");

	char x = (char)"input.csv";
	char* px = &x;
	read_csv(px);
	return 0;
}