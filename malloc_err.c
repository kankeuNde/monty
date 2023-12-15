#include "monty.h"
/**
 * raise_malloc_error - Handles malloc failure operation
 */
void raise_malloc_error(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}
