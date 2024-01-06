#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

void *calloc(uint nmemb, uint size)
{
    uint total_size = nmemb * size;
    uchar *new_memory;

    // Use sbrk to allocate memory
    new_memory = (uchar *)sbrk(total_size);

    // check if sbrk failed
    if ((long)new_memory == -1)
    {
        return 0;
    }

    // initialize memory to 0
    for (uint i = 0; i < total_size; i++)
    {
        new_memory[i] = 0;
    }

    return new_memory;
}
