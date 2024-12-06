#include <stdio.h>

/*print Fahrenheit-Celsius table for fahr = 0, 20,..., 300*/
/*main() no longer supported in gcc v.11 and above, choose int main(), 
or int main(void), or void main(), void main(void)*/
int main()
{
	/*all variables must be declared before they are used,
	usually at the beginning of the function before any executable statements*/
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0; /*lower limit of temperature scale*/
	upper = 300; /*upper limit of temperature scale*/
	step = 20; /*step size*/
	
	fahr = lower;
	
	while(fahr <= upper)
	{
		celsius = 5*(fahr-32)/9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}