#include "unity.h"
#include "circularbuffer.h"
#include "CException.h"
	

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->tail);
	circularBufferDel(cb);
}