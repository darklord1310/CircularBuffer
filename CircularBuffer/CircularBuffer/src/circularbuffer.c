#include "circularbuffer.h"
#include <malloc.h>	 // Need to include this function for the use of malloc
#include "CException.h"

void testing()
{
	CircularBuffer cb;	// This memory allocated will be destroyed after out of the function
	CircularBuffer *ptr2cb;
	
	ptr2cb = malloc(sizeof(CircularBuffer)); // Dynamic memory allocation, allocate the ptr2cb with 
											// the memory size of CircularBuffer structure
											
	free(ptr2cb);	// This will free the memory allocated (beware: data stored in it will lose)
					// if memory no free, it will still be there forever
}

CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) *length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	return circularBuffer;
}

void circularBufferDel(CircularBuffer *circularBuffer)
{
	free(circularBuffer);
}