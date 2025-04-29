/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/29 20:06:45 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// nmemb = number of elements to allocate
//size = size (in bytes) of each element 
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;
	size_t			total;

	total = nmemb * size;
	if (nmemb > 0 && size > 0 && total / nmemb != size)
		return (NULL);
	memory = malloc(total);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, total);
	return (memory);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // For proper SIZE_MAX
#include <string.h>  // For memset


int main()
{
    // Test 1: Zero-size allocation
    char *t1_calloc = calloc(0, 0);
    char *t1_ft_calloc = ft_calloc(0, 0);
    
    printf("Test 1: ");
    if ((t1_calloc == NULL && t1_ft_calloc == NULL) || 
        (t1_calloc != NULL && t1_ft_calloc != NULL)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    free(t1_calloc);
    free(t1_ft_calloc);

    // Test 2: Overflow case
    char *t2_calloc = calloc(SIZE_MAX, 2);
    char *t2_ft_calloc = ft_calloc(SIZE_MAX, 2);
    
    printf("Test 2: ");
    if (t2_calloc == NULL && t2_ft_calloc == NULL) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    // Test 3: Normal allocation
    size_t reasonable_size = 100;
    char *t3_calloc = calloc(reasonable_size, 1);
    char *t3_ft_calloc = ft_calloc(reasonable_size, 1);
    
    printf("Test 3: ");
    if (t3_calloc && t3_ft_calloc && 
        memcmp(t3_calloc, t3_ft_calloc, reasonable_size) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    free(t3_calloc);
    free(t3_ft_calloc);

    return 0;
}
*/
/* 
DESCRIPTION
The calloc() function allocates memory.
The allocated memory is aligned such that it can be used for any 
data type.The calloc() function contigously allocates enough space 
for count objects that are size bytes of memory each and returns a 
pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.
RETURN VALUES
If successful, calloc() returns a pointer to allocated memory. 
If there is an error, they return a NULL pointer and set errno to 
ENOMEM.

The  calloc() function allocates memory for an array of nmemb 
elements of size bytes each and returns a pointer to the allocated 
memory.  The memory is set to zero.  If nmemb or size is 0, 
then calloc()  returns  either  NULL, or a unique pointer value that 
can later be successfully passed to free().  If the
multiplication of nmemb and size would result in integer overflow, 
then calloc() returns an error.   
By contrast,  an integer overflow would not be detected in the 
following call to malloc(), with the result
that an incorrectly sized block of memory would be allocated:

    malloc(nmemb * size);
           
The malloc() and calloc() functions return a pointer to the 
allocated memory, which is suitably aligned for any built-in type.  
On error, these functions return NULL.  NULL may also be returned 
by a successful  call to malloc() with a size of zero, or by a 
successful call to calloc() with nmemb or size equal to zero.

If nmemb or size is 0, then calloc() returns a unique pointer 
value that can be successfully passed to free().*/
