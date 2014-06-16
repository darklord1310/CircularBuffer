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


/*
 * Delete the Stack object
 *
 *Input :
 *					Stack is the stack object to delete
 * Error checking:
 *					will throw error if try to pop when the stack is empty
 */
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
	if( cb->size == cb->length)
		Throw(ERR_BUFFER_IS_FULL);
	else
	{
		if( cb->size == 0)
		{
			*(cb->tail) = valueToAdd;
			cb->size++;
		}
		else
		{
			cb->buffer++;
			*(cb->buffer) = valueToAdd;
			cb->head = cb->buffer;
			cb->size++;
		}
	}	
}

int circularBufferRemove(CircularBuffer *cb)
{
	int removed_value;
	
	if( cb->size == 0)
		Throw(ERR_BUFFER_IS_EMPTY);
	else
	{
			removed_value = *(cb->tail);
			cb->size--;
			cb->tail++;
	}
	return removed_value;
}