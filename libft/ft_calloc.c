/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjkim <hyunjkim@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:53 by hyunjkim          #+#    #+#             */
/*   Updated: 2025/04/22 15:20:55 by hyunjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size) // nmemb = number of elements to allocate, size = size (in bytes) of each element 
{
       void  *memory;
       size_t total;

       total = nmemb * size;
       memory = malloc(total);
       if (!memory)
              return (NULL);       
       ft_memset(memory, 0, total);
       return (memory);
}

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
     
       


       /*
       ASSERT(!ft_calloc(0, 0) == !calloc(0, 0));
       ASSERT(!ft_calloc(SIZE_MAX, 0) == !calloc(SIZE_MAX, 0));
       ASSERT(!ft_calloc(SIZE_MAX, 2) == !calloc(SIZE_MAX, 2));
       ASSERT(!ft_calloc(0, SIZE_MAX) == !calloc(0, SIZE_MAX));
       ASSERT(!ft_calloc(2, SIZE_MAX) == !calloc(2, SIZE_MAX));
       ASSERT(!ft_calloc(SIZE_MAX, SIZE_MAX) == !calloc(SIZE_MAX, SIZE_MAX));*/



/* The  calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a
       pointer to the allocated memory.  The memory is set to zero.  If nmemb or size is 0, then calloc()  re‐
       turns  either  NULL, or a unique pointer value that can later be successfully passed to free().  If the
       multiplication of nmemb and size would result in integer overflow, then calloc() returns an error.   By
       contrast,  an integer overflow would not be detected in the following call to malloc(), with the result
       that an incorrectly sized block of memory would be allocated:

           malloc(nmemb * size);
           
    The malloc() and calloc() functions return a pointer to the allocated memory, which is suitably aligned
    for any built-in type.  On error, these functions return NULL.  NULL may also be returned by a success‐
    ful  call to malloc() with a size of zero, or by a successful call to calloc() with nmemb or size equal
    to zero.

    The free() function returns no value.

    The realloc() function returns a pointer to the newly allocated memory, which is suitably  aligned  for
    any  built-in  type, or NULL if the request failed.  The returned pointer may be the same as ptr if the
    allocation was not moved (e.g., there was room to expand the allocation in-place),  or  different  from
    ptr  if  the  allocation  was moved to a new address.  If size was equal to 0, either NULL or a pointer
    suitable to be passed to free() is returned.  If realloc() fails, the original block is left untouched;
    it is not freed or moved.

    On  success,  the reallocarray() function returns a pointer to the newly allocated memory.  On failure,
    it returns NULL and the original block of memory is left untouched.

    If nmemb or size is 0, then calloc() returns a unique pointer value that can be successfully passed to free().*/
