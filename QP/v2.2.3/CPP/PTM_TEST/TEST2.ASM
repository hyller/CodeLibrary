; Foo::g()
00401010   push        406040h
00401015   call        004010B0
0040101A   pop         ecx
0040101B   ret

; Bar::g()
00401020   push        40604Ch
00401025   call        004010B0
0040102A   pop         ecx
0040102B   ret

; main()
00401090   mov         ecx,4068E8h
00401095   call        dword ptr ds:[4068E4h]
0040109B   mov         ecx,4068E0h
004010A0   jmp         dword ptr ds:[4068E4h]

; Foo::f()
00401B96   mov         eax,[00406E14]
00401B9B   test        eax,eax
00401B9D   je          00401BA1
00401B9F   call        eax
00401BA1   push        406020h
00401BA6   push        406014h
00401BAB   call        00401C7E
00401BB0   push        406010h
00401BB5   push        406000h
00401BBA   call        00401C7E
00401BBF   add         esp,10h
00401BC2   ret
