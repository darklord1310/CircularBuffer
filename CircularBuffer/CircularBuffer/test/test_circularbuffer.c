#include "unity.h"
#include "circularbuffer.h"
#include "CException.h"

#define length_of_buffer 5

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void)
{
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(length_of_buffer, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer,cb->tail);
	circularBufferDel(cb);
}

void test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	Try
	{
		CircularBufferAdd(cb,6);
		TEST_ASSERT_NOT_NULL(cb);
		TEST_ASSERT_NOT_NULL(cb->buffer);
		TEST_ASSERT_EQUAL(length_of_buffer, cb->length);
		TEST_ASSERT_EQUAL(1, cb->size);
		TEST_ASSERT_EQUAL(6, *(cb->head));
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}

    circularBufferDel(cb);
}

void test_CircularBufferAdd_given_6_7_should_get_7_6(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);

	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		TEST_ASSERT_NOT_NULL(cb);
		TEST_ASSERT_NOT_NULL(cb->buffer);
		TEST_ASSERT_EQUAL(length_of_buffer, cb->length);
		TEST_ASSERT_EQUAL(2, cb->size);
		TEST_ASSERT_EQUAL_PTR(7, *(cb->head) );
		TEST_ASSERT_EQUAL_PTR(6, *(cb->tail) );
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}

	circularBufferDel(cb);

}

void test_CircularBufferAdd_given_6_7_8_should_get_8_7_6(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	int *temp = cb->buffer;  // to return the buffer pointer to its initial position
	
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
		TEST_ASSERT_NOT_NULL(cb);
		TEST_ASSERT_NOT_NULL(cb->buffer);
		TEST_ASSERT_EQUAL(length_of_buffer, cb->length);
		TEST_ASSERT_EQUAL(3, cb->size);
		TEST_ASSERT_EQUAL(6, *(temp));
		TEST_ASSERT_EQUAL(7, *(temp+1));
		TEST_ASSERT_EQUAL(8, *(temp+2));
		TEST_ASSERT_EQUAL_PTR(8, *(cb->head) );
		TEST_ASSERT_EQUAL_PTR(6, *(cb->tail) );
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
	circularBufferDel(cb);
}


void test_CircularBufferAdd_given_value_6_7_8_9_should_get_9_8_7_6(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	int *temp = cb->buffer;   // to return the buffer pointer to its initial position
	
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
		CircularBufferAdd(cb,9);
		TEST_ASSERT_NOT_NULL(cb);
		TEST_ASSERT_NOT_NULL(cb->buffer);
		TEST_ASSERT_EQUAL(length_of_buffer, cb->length);
		TEST_ASSERT_EQUAL(4, cb->size);
		TEST_ASSERT_EQUAL(6, *(temp));
		TEST_ASSERT_EQUAL(7, *(temp+1));
		TEST_ASSERT_EQUAL(8, *(temp+2));
		TEST_ASSERT_EQUAL(9, *(temp+3));
		TEST_ASSERT_EQUAL_PTR(9, *(cb->head) );
		TEST_ASSERT_EQUAL_PTR(6, *(cb->tail) );
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
	circularBufferDel(cb);
}

void test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_ERR_BUFFER_IS_FULL(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
		CircularBufferAdd(cb,9);
		CircularBufferAdd(cb,10);
		CircularBufferAdd(cb,11);
		TEST_FAIL_MESSAGE("Expect ERR_BUFFER_IS_FULL exception to be generated");
	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		printf("Caught a ERR_BUFFER_IS_FULL exception! Error code is: %i" , err);
	}
	circularBufferDel(cb);
}

void test_circularBufferRemove_given_empty_buffer_should_throw_ERR_BUFFER_IS_EMPTY(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	int value_been_removed ;

	Try
	{
		value_been_removed = circularBufferRemove(cb);

	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);
	}
	circularBufferDel(cb);
}

void test_circularBufferRemove_given_13_should_return_13(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	int value_been_removed ;

	Try
	{
		CircularBufferAdd(cb,13);
		value_been_removed = circularBufferRemove(cb);
		TEST_ASSERT_EQUAL(13, value_been_removed);
		TEST_ASSERT_EQUAL(0, cb->size);
	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);
	}
	circularBufferDel(cb);
}


void test_circularBufferRemove_given_33_7_should_return_33(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(length_of_buffer);
	int value_been_removed ;

	Try
	{
		CircularBufferAdd(cb,33);
		CircularBufferAdd(cb,7);
		value_been_removed = circularBufferRemove(cb);
		TEST_ASSERT_EQUAL(1, cb->size);
		TEST_ASSERT_EQUAL(33, value_been_removed);
		TEST_ASSERT_EQUAL(7, *(cb->tail) );
		TEST_ASSERT_EQUAL(7, *(cb->head) );
	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);
	}
	circularBufferDel(cb);
}
