#ifndef circularbuffer_H
#define circularbuffer_H

typedef enum {ERR_NO_ERROR, ERR_BUFFER_IS_FULL, ERR_BUFFER_IS_EMPTY}ErrorCode;

typedef struct
{
	int *head;
	int *tail;
	int size;
	int length;
	int *buffer;
}CircularBuffer;

CircularBuffer *circularBufferNew(int length);
void CircularBufferAdd(CircularBuffer *cb, int valueToAdd);
void circularBufferDel(CircularBuffer *circularBuffer);

	
#endif // circularbuffer_H
