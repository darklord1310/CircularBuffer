#include "circularbuffer.h"
#include <malloc.h>	 // Need to include this function for the use of malloc
#include "CException.h"
#include <stdio.h>

void testing()
{
	CircularBuffer cb;	// This memory allocated will be destroyed after out of the function
	CircularBuffer *ptr2cb;
	
	ptr2cb = malloc(sizeof(CircularBuffer)); // Dynamic memory allocation, allocate the ptr2cb with 
											// the memory size of CircularBuffer structure
											
	free(ptr2cb);	// This will free the memory allocated (beware: data stored in it will loss)
					// if memory is not free, it will still be there forever
}

CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
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


/*  
 * Assume the buffer is always not empty
 */
void CircularBufferAdd(CircularBuffer *cb, int valueToAdd)
{
	if ( ((cb->size)+1) > (cb->length)) // if the size is larger than the length of the buffer, then throw err
	{
	   Throw(ERR_BUFFER_IS_FULL);
	}
	else
	{
	if( cb->size != 0)
		(cb->tail)++;
	*(cb->tail) = valueToAdd;

	cb->size++;
	cb->buffer++;
	}
}

int circularBufferRemove(CircularBuffer *cb)
{
	
}