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



void test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(6);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)37);;

 }

   if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)39);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)40);;};

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((*(cb->head))), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

    circularBufferDel(cb);



}



void test_CircularBufferAdd_given_value_7_should_add_into_the_second_buffer(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(6);

 int *temp = cb->buffer;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)60);;

 }

 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)62);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)63);;};

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*(temp+1))), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((temp)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)(((temp+1))), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);



}



void test_CircularBufferAdd_given_value_8_should_add_into_the_third_buffer(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(6);

 int *temp = cb->buffer;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)86);;

 }

 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)88);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)89);;};

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((*(temp+2))), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((temp)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)(((temp+2))), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);

}







void test_CircularBufferAdd_given_value_9_should_add_into_the_fourth_buffer(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(4);

 int *temp = cb->buffer;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

  CircularBufferAdd(cb,9);



 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)115);;

 }



 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)118);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)119);;};

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((*(temp+3))), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((temp)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)(((temp+3))), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);

}



void test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_err(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(4);

 int *temp = cb->buffer;

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

  CircularBufferAdd(cb,9);

  CircularBufferAdd(cb,10);

  UnityFail( ("Expect exception to be generated"), (_U_UINT)140);;

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

  printf("Caught an exception");

 }

 circularBufferDel(cb);

}
