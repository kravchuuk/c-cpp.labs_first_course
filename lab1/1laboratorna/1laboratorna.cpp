#include<stdio.h>
#include<math.h>

int main() {
	float x, y, z;
	scanf_s("%%f", &x);
	scanf_s("%%f", &y);
	z = 137 * pow(x, 3) + cos((pow(y, 3) / pow(x, 4)) + tan(14 * y) - 7 * pow(x, 6));
	printf("%f", z);
	
	return 0;
} 