Calculator: Calculator.o
	gcc -o Calculator Calculator.o

Calculator.o: Calculator.c
	gcc -c -g -Werror Calculator.c

clean:
	rm -f *.o Calculator
