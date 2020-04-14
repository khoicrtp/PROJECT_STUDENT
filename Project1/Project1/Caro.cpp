#include "Caro.h"

void read_csv(const char* in)
{
	//char temp[100];
	FILE* f1 = fopen(in, "r");
	int count;
	char buf[max_buf];
	do {
		count = fread(buf, 1, max_buf, f1);
		cout << count;
	} while (count == max_buf);

	fclose(f1);
}