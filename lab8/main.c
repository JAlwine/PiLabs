#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5000
#define MAX_COLUMNS 5000

struct array_info
{
  int	rows;
  int	columns;
  int order;
		char *base_pointer; /* pointer to array of bytes. In this array, float numbers will be stored (4 bytes each) */
};

struct array_info* init(int, int, int);
void store(struct array_info*, int, int, float);
float fetch(struct array_info*, int, int);
double calc_time_to_read(struct array_info*);

int main()
{
 int n_rows, n_columns, order, row_index, column_index;
 float out_value, in_value;
 int in;
 struct array_info *matrix;
 printf("Enter the total number of rows: \t");
 scanf("%d", &n_rows);
 printf("Enter the total number of columns: \t");
 scanf("%d", &n_columns);
 printf("Select the order (0-Row major order, 1-Column major order): \t");
 scanf("%d", &order);
 matrix = init(n_rows, n_columns, order);
 if(matrix == NULL)
 {
     printf("\n Error Creating the Array\n");
     return 0;
 }
 printf("\n 2-D Array has been initialized\n");
 while(1)
 {
     printf("\n 1 - Store a value \n 2 - Fetch a value \n 3 - Calculate time to read the entire array  \n 4 - Exit\n Enter your choice:\t");
     scanf("%d", &in);
     switch(in)
     {
         case 1:
         printf("Enter row number, column number and a value with spaces between them:\t");
         scanf("%d %d %f", &row_index, &column_index, &in_value);
         store(matrix, row_index, column_index, in_value);
         printf("Value stored successfully\n");
         break;
         case 2:
         printf("Enter row number and column number with spaces between them:\t");
         scanf("%d %d", &row_index, &column_index);
         out_value=fetch(matrix, row_index, column_index);
         printf("Fetched value at (%d, %d)= %f\n", row_index, column_index, out_value);
         break;
         case 3:
         printf("Time to read the entire array is %f secs\n", calc_time_to_read(matrix));
         break;
         case 4:
         default:
         return 0;
     }
 }
}
struct array_info* init(int rows, int columns, int order)
{
  /* Allocate the required memory for the 2D array to store float values (Ex: 1.45) with "rows" and "columns" */
  /* Make sure the size is within 1 to MAX_ROWS and 1 to MAX_COLUMNS specified in main.c. If not return null pointer */
  /* Initialize the 2D array to the all zeroes (0.0) */
  /* Assign suitable values to all the elements of the structure and return the struct pointer */
 if (rows > MAX_ROWS || columns > MAX_COLUMNS)
  return NULL; 
	//Malloc storage for array info struct
struct array_info *ai;
ai = malloc(sizeof(struct array_info));
	//set values
ai->rows = rows;
ai->columns = columns;
ai->order = order;
	//malloc space for matrix
char* tbl = calloc(sizeof(float), (rows*columns));
ai->base_pointer = tbl;
}

void store(struct array_info *array, int row_index, int column_index, float value)
{
   /* Store the "value" to the location (row_index, column_index) of the array whose details are in struct pointer *array */
   /* Assume row-major order if "order"=0 and column-major order if "order"=1 */
 int offset = 0;

 if (array->order == 0){
	//store in row major order
     offset = (column_index*array->columns) + row_index;
 } 
 else{
	//store in column major order
     offset = (row_index*array->rows) + column_index;
 }

 float *base = (float*) array->base_pointer;
 *(base + offset) = value;

}

float fetch(struct array_info *array, int row_index, int column_index)
{ 
	    /* Fetch the value from the location (row_index, column_index) of the array whose details are in struct pointer *array */
	    /* Assume row-major order if "order"=0 and column-major order if "order"=1 */
	    /* Return the fetched value */
	int offset = 0;
  if (array->order == 0){
		//store in row major order
      offset = (column_index*array->columns) + row_index;
  }

  else{
		//store in column major order
      offset = (row_index*array->rows) + column_index;
  }
  return *((float*)array->base_pointer + offset);	
}

double calc_time_to_read(struct array_info* array)
{
 clock_t begin, end;
 long int i,j;
 float value;
 int offset;

 begin = clock();
     /* Fetch back the whole array in the order 10, 20, 30, 40, 50, 60 assuming the 2x3 array given above irrespective of the order */
     /* Do not print the values, just fetch them and keep discarding. */
     /* We just need to evaluate the time to read from memory, not verifying the correctness of the content */
if (array->order == 0){ 
for (i=0; i < array->columns; i++){
	for (j=0; j < array->rows; j++){
		offset = (i*array->columns)+j;
		value = *((float*)array->base_pointer + offset);
		}
	}
}

else {
for (i=0; i < (array->rows); i++){
	for (j=0; j < (array->columns); j++){ 
		offset = (j*array->columns) + i;
		value = *((float*)array->base_pointer + offset);
		}
	}
}
 end = clock();
 return (double)(end - begin)/CLOCKS_PER_SEC;
}
