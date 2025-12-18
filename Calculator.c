#include <stdio.h>
#include <stdlib.h>

float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float exponent(float num1, int num2);
int roundUp(float number);
int roundDown(float number);
int roundToNearest(float number);
int modulo(int num1, int num2);
void printUserMenu();
void printArithmeticMenu();

int main()
{
	char option = ' ';
	puts("Welcome to the Calculator!!");
	do
	{
		printUserMenu();
		scanf("%c", &option);
		if(option != 'a' && option != 'h' && option != 'q')
		{
			puts("Sorry! Your input is invalid.");
			scanf("%c", &option);
		}
	} while(option != 'a' && option != 'h' && option != 'q');

	while(option != 'q')
	{
		char arithmetic = ' ';
                float num1 = 0.0;
                float num2 = 0.0;
                float solution = 0.0;
		int value = 0;

		switch(option)
		{
			case 'h':
				printArithmeticMenu();
				break;

			default:
				do
				{
					scanf("%c", &option);
					printf("Enter your arithmetic in prefix format: ");
					scanf("%c", &arithmetic);
					scanf("%f", &num1);

					if(arithmetic != '\'' && arithmetic != '_' && arithmetic != '#')
					{
						scanf("%f", &num2);
					}
					
					if(arithmetic != '+' && arithmetic != '-' && arithmetic != 'x' && arithmetic != '/' && arithmetic != '^' && arithmetic != '\'' && arithmetic != '_' && arithmetic != '#' && arithmetic != '%')
					{
						puts("Sorry! Invalid arithmetic!");
					}
				} while(arithmetic != '+' && arithmetic != '-' && arithmetic != 'x' && arithmetic != '/' && arithmetic != '^' && arithmetic != '\'' && arithmetic != '_' && arithmetic != '#' && arithmetic != '%');

				switch(arithmetic)
				{
					case '+':
						solution = add(num1, num2);
						printf("%.3f + %.3f = %.3f\n\n", num1, num2, solution);

						break;
					
					case '-':
						solution = subtract(num1, num2);
                                                printf("%.3f - %.3f = %.3f\n\n", num1, num2, solution);
						break;

					case 'x':
						solution = multiply(num1, num2);
						printf("%.3f x %.3f = %.3f\n\n", num1, num2, solution);
						break;

					case '/':
						solution = divide(num1, num2);
                                                printf("%.3f / %.3f = %.3f\n\n", num1, num2, solution);
						break;

					case '^':
						solution = exponent(num1, (int) num2);
                                                printf("%.3f ^ %d = %.3f\n\n", num1, (int) num2, solution);
						break;

					case '%':
						value = modulo((int) num1, (int) num2);
                                                printf("%d mod %d = %d\n\n", (int) num1, (int) num2, value);
						break;

					case '\'':
						value = roundUp(num1);
						printf("%.3f' = %d\n\n", num1, value);
						break;

					case '_':
                                                value = roundDown(num1);
                                                printf("%.3f_ = %d\n\n", num1, value);
                                                break;

					default:
                                                value = roundToNearest(num1);
                                                printf("#%.3f = %d\n\n", num1, value);
                                                break;
				}
				break;
		}
		do
		{
			scanf("%c", &option);
			printUserMenu();
			scanf("%c", &option);
                	if(option != 'a' && option != 'h' && option != 'q')
                	{
                        	puts("Sorry! Your input is invalid.");
                	}
        	} while(option != 'a' && option != 'h' && option != 'q');
	}
	return 0;
}

float add(float num1, float num2)
{
	float sum = num1 + num2;
	return sum;
}

float subtract(float num1, float num2)
{
	float difference = num1 - num2;
	return difference;
}

float multiply(float num1, float num2)
{
	float product = num1 * num2;
	return product;
}

float divide(float num1, float num2)
{
	float quotient;
	if(num2 == 0)
	{
		perror("ERROR: Division by zero!");
		exit(EXIT_FAILURE);
	}
	else
	{
		quotient = num1 / num2;
	}
	return quotient;
}

float exponent(float num1, int num2)
{
	float power = 1.0;
	if(num2 >= 0)
	{
		for(int i = 0; i < num2; i++)
		{
			power = power * num1;
		}
	}
	else
	{
		float divisor = 1.0;
		num2 = num2 * -1;
		for(int i = 0; i < num2; i++)
		{
			divisor = divisor * num1;
		}
		power = 1 / divisor;
	}
	return power;
}

int roundUp(float number)
{
	int roundedNumber = (int) number + 1;
	return roundedNumber;
}

int roundDown(float number)
{
	return (int) number;
}

int roundToNearest(float number)
{
	int roundedNumber;
	float decimal = number - (int) number;

	if(decimal < 0.5)
	{
		roundedNumber = (int) number;
	}
	else
	{
		roundedNumber = (int) number + 1;
	}
	return roundedNumber;
}

int modulo(int num1, int num2)
{
	int mod;
	if(num2 == 0)
	{
		perror("ERROR: Modulo by zero is undefined!");
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = num1 % num2;
	}
	return mod;
}

void printUserMenu()
{
	puts("What would you like to do?");
	puts("h - Print MENU Help");
	puts("a - Start the Arithmetic");
	puts("q - Quit");
}

void printArithmeticMenu()
{
	printf("\n");
	puts("To enter an arithmetic, you must type it in prefix format.");
        puts("Example: + A B = A + B");
	puts("Use + for addition");
	puts("Use - for subtraction");
	puts("Use * for multiplication");
	puts("Use / for division");
	puts("Use ^ for exponent");
	puts("Use ' for rounding up");
	puts("Use _ for rounding down");
	puts("Use # for rounding to nearest integer");
	puts("Use \% for modulo");
	printf("\n");
}
