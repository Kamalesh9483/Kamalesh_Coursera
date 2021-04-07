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
 * @file stats.h
 * @brief stats.h has the necessary functions to perform statistical operations on at
 *        given array
 * <Add Extended Description Here>
 *
 * @author Kamalesh U
 * @date 6/4/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Function that evaluates and prints the mean of a given array
 *
 * @param input should be an array of type unsigned 8-bit integers
 * @param size is the number of elements in the input array
 *
 * @return void
 */
void find_mean(uint8_t* input, int size);


/**
 * @brief Function that swaps the value of two given arguments
 *
 * @param p should be an array of type unsigned 8-bit integer
 * @param q hould be an array of type unsigned 8-bit integer
 *
 * @return void
 */
void swap(uint8_t* p, uint8_t* q);


/**
 * @brief Function that sorts elements of array in descending order as per their magnitude
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void sort_array(uint8_t* array, int n);


/**
 * @brief Function that evaluates median of given set of array which is in descending order 
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void find_median(uint8_t* array, int n);


/**
 * @brief Function that identifies maximum value of given set of array 
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void find_maximum(uint8_t* array, int n);


/**
 * @brief Function that identifies minimum value of given set of array 
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void find_minimum(uint8_t* array, int n);


/**
 * @brief Function that prints array to the screen
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void print_array(uint8_t* array,int n);


/**
 * @brief Function that prints minimum, maximum, mean, median of given array of elements
 *
 * @param array should be an array of type unsigned 8-bit integer
 * @param n is the number of elements in the input array
 *
 * @return void
 */
void print_statistics(uint8_t* array, int n);


#endif /* __STATS_H__ */
