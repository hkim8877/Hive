#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{

}

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
    it returns NULL and the original block of memory is left untouched. */