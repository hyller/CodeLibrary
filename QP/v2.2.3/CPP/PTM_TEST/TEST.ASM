; Foo::g()
00401010   push        407040h
00401015   call        00401115
0040101A   pop         ecx
0040101B   ret

; Bar::g()
00401020   push        40704Ch
00401025   call        00401115
0040102A   pop         ecx
0040102B   ret

; main()
004010F0   mov         ecx,4078E8h
004010F5   call        dword ptr ds:[4078E4h]
004010FB   mov         ecx,4078E0h
00401100   jmp         dword ptr ds:[4078E4h]

; thunk
00401110   mov         eax,dword ptr [ecx]
00401112   jmp         dword ptr [eax+4]

; Foo::f()
00401E03   mov         eax,[00407E14]
00401E08   test        eax,eax
00401E0A   je          00401E0E
00401E0C   call        eax
00401E0E   push        407024h
00401E13   push        407014h
00401E18   call        00401EEB
00401E1D   push        407010h
00401E22   push        407000h
00401E27   call        00401EEB
00401E2C   add         esp,10h
00401E2F   ret

