#include <stdio.h>
#include <stdlib.h>

int const BLOCK_SIZE = 20;

typedef struct {
	int* array;
	int size;
} ARRAY;

ARRAY array_create(int init_size);
void array_free(ARRAY* a);
int array_size(const ARRAY* a);
void array_inflate(ARRAY* a, int more_size);
int array_get(const ARRAY* a, int index);
void array_set(ARRAY* a, int index, int value);



ARRAY array_create(int init_size) {
	ARRAY a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int) * a.size);
	return a;
}



void array_free(ARRAY* a) {
	free(a->array);
	a->array = NULL;
	a->size = 0;
}



int array_size(const ARRAY* a) {
	return a->size;
}



int array_get(const ARRAY* a, int index) {
	return a->array[index];
}



void array_set(ARRAY* a, int index, int value) {
	if (index >= a->size) {
		array_inflate(a, (index / BLOCK_SIZE+1)*BLOCK_SIZE - a->size);
	}
	a->array[index] = value;
}





void array_inflate(ARRAY* a, int more_size) {

	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
	int i;
	for (i = 0; i < a->size; i++)
		p[i] = a->array[i];
	free(a->array);
	a->array = p;
	a->size += more_size;

}



int main(int argc, char const* argv[]) {

	int cnt = 0;
	int number = 0;
	
	ARRAY a = array_create(100);
	printf("%d\n", array_size(&a));
	array_set(&a, 0, 123);
	printf("%d\n", array_get(&a, 0));
	
	while (number != -1) {
		scanf("%d", &number);
		if (number != -1)
			array_set(&a, cnt++, number);
	}
	
	array_free(&a);
	return 0;
}

