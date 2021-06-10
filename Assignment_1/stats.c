/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief stats.c has necessary codes to evaluate statistical operations like mean,median
 *        also identify maximum, minimum value of given array & sort array in descending order
 *        
 *
 * <Add Extended Description Here>
 *
 * @author Add Kamalesh U
 * @date 6/4/2021
 *
 */

#include <stdio.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void find_mean(uint8_t* input, int size)
{
  float mean = 0;
  for (int i=0; i<size; i++) 
  {
    mean = input[i] + mean;
  }
  mean = mean/SIZE;
  printf("\nThe mean is %f\n", mean); 

}


void swap(uint8_t* p, uint8_t* q)
{
  uint8_t temp;
  temp = *p;
  *p = *q;
  *q = temp;
}


void sort_array(uint8_t* array, int n)
{
  int i,j;
  for (i=0; i<n; i++)
  {
    for (j=i+1; j<n; j++)
    {
      if (array[i] < array[j])
      {
        swap(&array[i], &array[j]);
      }
    }
  }
}

void find_median(uint8_t* array, int n)
{
  // even number
  if (n %2 == 0)
  {
    float median;
    median = (array[(n-1)/2] + array[n/2])/2;
    printf("\nThe median is %f\n", median);
  }
  // odd nmber
  else 
  {
    printf("\n The median is %f\n",(array[n/2]));
  }
}


void find_maximum(uint8_t* array, int n)
{
  int i, j;
  float max;
for (i=0; i<n; i++)
{
    if (array[i] > array[j])
    {
      max = array[i];
    }
    else 
    {
      max = array[j];
    }
}
printf("\n The maximum value is %f \n",max);
}

void find_minimum(uint8_t* array, int n)
{
  int i,j;
  float min;
  for (i=0; i<n; i++)
  {
    if (array[i] < array[j])
    {
      min = array[i];
    }
    else 
    {
      min = array[j];
    }
  }
   printf("\nThe minimum value is %f\n",min);
}

void print_array(uint8_t* array,int n)
{
  int i;
  for (i=0; i<n; i++)
  {
    printf("%d\t",array[i]);
  }
}

void print_statistics(uint8_t* array, int n)
{
  find_minimum(array, n);
  find_maximum(array, n);
  find_mean(array, n);
  find_median(array,n);

}

int main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                              7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
 
// Print array

print_array(test, SIZE);

//  // Mean
//  float mean;
//  mean = find_mean(test, SIZE);

 // Sorting in descending order
 sort_array(test , SIZE);
 for (int i=0; i<SIZE; i++)
 {
 printf("\n test[%d] = %d \n",i,test[i]);
 }

//  // Median
//  float median;
//  median = find_median(test, SIZE);


// // Maximum
// float maximum;
// maximum = find_maximum(test, SIZE);


// // Minimum
// float minimum;
// minimum = find_minimum(test, SIZE);

// statics
print_statistics(test, SIZE);


return 0;
}
/* Add other Implementation File Code Here */
