#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

int main(int argc, char const *argv[]) {
	struct date today;
	
	today.month = 07;
	today.day   = 31;
	today.year  = 2019;
	printf("Todat's date is %i-%i-%i.\n", today.year, today.month, today.day);
	
	return 0;
	
}
