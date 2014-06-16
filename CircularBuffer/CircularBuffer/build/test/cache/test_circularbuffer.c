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

 CircularBuffer *cb = circularBufferNew(5);

 if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)18);;};

 if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->head)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)(_UP)((cb->buffer)), (_U_SINT)(_UP)((cb->tail)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX32);

 circularBufferDel(cb);

}



void test_CircularBufferAdd_given_value_6_should_add_into_the_first_buffer(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)34);;};

  if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((*(cb->head))), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)42);;

 }



    circularBufferDel(cb);

}



void test_CircularBufferAdd_given_6_7_should_get_7_6(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)57);;};

  if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)58);;};

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((7)), (_U_SINT)(_UP)((*(cb->head))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((6)), (_U_SINT)(_UP)((*(cb->tail))), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_HEX32);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)66);;

 }



 circularBufferDel(cb);



}



void test_CircularBufferAdd_given_6_7_8_should_get_8_7_6(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 int *temp = cb->buffer;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

  if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)84);;};

  if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)85);;};

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((*(temp))), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*(temp+1))), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((*(temp+2))), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((8)), (_U_SINT)(_UP)((*(cb->head))), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((6)), (_U_SINT)(_UP)((*(cb->tail))), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_HEX32);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)96);;

 }

 circularBufferDel(cb);

}





void test_CircularBufferAdd_given_value_6_7_8_9_should_get_9_8_7_6(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 int *temp = cb->buffer;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

  CircularBufferAdd(cb,9);

  if ((((cb)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)114);;};

  if ((((cb->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)115);;};

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((cb->length)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((*(temp))), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*(temp+1))), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((*(temp+2))), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((*(temp+3))), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((9)), (_U_SINT)(_UP)((*(cb->head))), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((6)), (_U_SINT)(_UP)((*(cb->tail))), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_HEX32);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){



  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Do not expect exception to be generated"), (_U_UINT)127);;

 }

 circularBufferDel(cb);

}



void test_CircularBufferAdd_given_buffer_is_full_but_trying_to_add_should_throw_ERR_BUFFER_IS_FULL(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,6);

  CircularBufferAdd(cb,7);

  CircularBufferAdd(cb,8);

  CircularBufferAdd(cb,9);

  CircularBufferAdd(cb,10);

  CircularBufferAdd(cb,11);

  UnityFail( ("Expect ERR_BUFFER_IS_FULL exception to be generated"), (_U_UINT)145);;

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_FULL)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

  printf("Caught a ERR_BUFFER_IS_FULL exception! Error code is: %i" , err);

 }

 circularBufferDel(cb);

}



void test_circularBufferRemove_given_empty_buffer_should_throw_ERR_BUFFER_IS_EMPTY(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 int value_been_removed ;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  value_been_removed = circularBufferRemove(cb);



 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_EMPTY)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);

 }

 circularBufferDel(cb);

}



void test_circularBufferRemove_given_13_should_return_13(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 int value_been_removed ;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,13);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_EMPTY)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

  printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);

 }

 circularBufferDel(cb);

}





void test_circularBufferRemove_given_33_7_should_return_33(void)

{

 unsigned int err;

 CircularBuffer *cb = circularBufferNew(5);

 int value_been_removed ;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  CircularBufferAdd(cb,33);

  CircularBufferAdd(cb,7);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((33)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*(cb->tail))), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((*(cb->head))), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

 }else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_BUFFER_IS_EMPTY)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

  printf("Caught a ERR_BUFFER_IS_EMPTY exception! Error code is: %i" , err);

 }

 circularBufferDel(cb);

}



void test_circularBufferRemove_given_3_4_5_remove_twice_should_get_5(void)

{

  int value_been_removed ;



  CircularBuffer *cb = circularBufferNew(5);

  CircularBufferAdd(cb,3);

  CircularBufferAdd(cb,4);

  CircularBufferAdd(cb,5);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((*(cb->tail))), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((*(cb->head))), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

}



void test_circularBuffer_add_3_4_into_buffer_then_remove_tail_and_add_5_6_then_remove_tail_should_get_head_is_6_and_tail_is_5(void)

{

  int value_been_removed ;



  CircularBuffer *cb = circularBufferNew(5);

  CircularBufferAdd(cb,3);

  CircularBufferAdd(cb,4);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

  CircularBufferAdd(cb,5);

  CircularBufferAdd(cb,6);

  value_been_removed = circularBufferRemove(cb);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((value_been_removed)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((cb->size)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((*(cb->tail))), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((*(cb->head))), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

}
