/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void);
extern void test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer(void);
extern void test_CircularBufferAdd_given_6_7_should_get_7_6(void);
extern void test_CircularBufferAdd_given_6_7_8_should_get_8_7_6(void);
extern void test_CircularBufferAdd_given_value_6_7_8_9_should_get_9_8_7_6(void);
extern void test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_ERR_BUFFER_IS_FULL(void);
extern void test_circularBufferRemove_given_empty_buffer_should_throw_ERR_BUFFER_IS_EMPTY(void);
extern void test_circularBufferRemove_given_13_should_return_13(void);
extern void test_circularBufferRemove_given_33_7_should_return_33(void);
extern void test_circularBufferRemove_given_3_4_5_remove_twice_should_get_5(void);
extern void test_circularBuffer_add_3_4_into_buffer_then_remove_tail_and_add_5_6_then_remove_tail_should_get_head_is_6_and_tail_is_5(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_circularbuffer.c";
  UnityBegin();
  RUN_TEST(test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6, 15);
  RUN_TEST(test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer, 27);
  RUN_TEST(test_CircularBufferAdd_given_6_7_should_get_7_6, 48);
  RUN_TEST(test_CircularBufferAdd_given_6_7_8_should_get_8_7_6, 73);
  RUN_TEST(test_CircularBufferAdd_given_value_6_7_8_9_should_get_9_8_7_6, 102);
  RUN_TEST(test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_ERR_BUFFER_IS_FULL, 132);
  RUN_TEST(test_circularBufferRemove_given_empty_buffer_should_throw_ERR_BUFFER_IS_EMPTY, 153);
  RUN_TEST(test_circularBufferRemove_given_13_should_return_13, 170);
  RUN_TEST(test_circularBufferRemove_given_33_7_should_return_33, 190);
  RUN_TEST(test_circularBufferRemove_given_3_4_5_remove_twice_should_get_5, 212);
  RUN_TEST(test_circularBuffer_add_3_4_into_buffer_then_remove_tail_and_add_5_6_then_remove_tail_should_get_head_is_6_and_tail_is_5, 229);

  return (UnityEnd());
}
