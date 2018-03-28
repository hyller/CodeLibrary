
MagicBoxerps.dll: dlldata.obj MagicBoxer_p.obj MagicBoxer_i.obj
	link /dll /out:MagicBoxerps.dll /def:MagicBoxerps.def /entry:DllMain dlldata.obj MagicBoxer_p.obj MagicBoxer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MagicBoxerps.dll
	@del MagicBoxerps.lib
	@del MagicBoxerps.exp
	@del dlldata.obj
	@del MagicBoxer_p.obj
	@del MagicBoxer_i.obj
