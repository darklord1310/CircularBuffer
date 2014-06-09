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

 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)17);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);

}
