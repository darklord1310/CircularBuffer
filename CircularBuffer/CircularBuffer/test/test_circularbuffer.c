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

void test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(6);
	Try
	{
		CircularBufferAdd(cb,6);
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
  	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(1, cb->size);
	TEST_ASSERT_EQUAL(6, *(cb->head));
    circularBufferDel(cb);

}

void test_CircularBufferAdd_given_value_7_should_add_into_the_second_buffer(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(6);
	int *temp = cb->buffer;
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(2, cb->size);
	TEST_ASSERT_EQUAL(7, *(temp+1));
	TEST_ASSERT_EQUAL_PTR(temp,cb->head);
	TEST_ASSERT_EQUAL_PTR((temp+1),cb->tail);
	circularBufferDel(cb);

}

void test_CircularBufferAdd_given_value_8_should_add_into_the_third_buffer(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(6);
	int *temp = cb->buffer;
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(3, cb->size);
	TEST_ASSERT_EQUAL(8, *(temp+2));
	TEST_ASSERT_EQUAL_PTR(temp,cb->head);
	TEST_ASSERT_EQUAL_PTR((temp+2),cb->tail);
	circularBufferDel(cb);
}



void test_CircularBufferAdd_given_value_9_should_add_into_the_fourth_buffer(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(4);
	int *temp = cb->buffer;
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
		CircularBufferAdd(cb,9);
				
	}Catch(err){
		
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		TEST_FAIL_MESSAGE("Do not expect exception to be generated");
	}
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(4, cb->length);
	TEST_ASSERT_EQUAL(4, cb->size);
	TEST_ASSERT_EQUAL(9, *(temp+3));
	TEST_ASSERT_EQUAL_PTR(temp,cb->head);
	TEST_ASSERT_EQUAL_PTR((temp+3),cb->tail);
	circularBufferDel(cb);
}

void test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_err(void)
{
	CEXCEPTION_T err;
	CircularBuffer *cb = circularBufferNew(4);
	int *temp = cb->buffer;
	Try
	{
		CircularBufferAdd(cb,6);
		CircularBufferAdd(cb,7);
		CircularBufferAdd(cb,8);
		CircularBufferAdd(cb,9);
		CircularBufferAdd(cb,10);
		TEST_FAIL_MESSAGE("Expect exception to be generated");
	}Catch(err){
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		printf("Caught an exception");
	}
	circularBufferDel(cb);
}
