rm -f wa.txt dwa.txt sdwa.txt wadef.txt libcn.txt libcn.def	sdwanc.txt sdwan.txt libca.def dwa.sed
grep -r 'weak_alias (.*,.*)' */*.c  | sort -bd >wa.txt
sed -e "s,^.*(\(.*\)\, *\(.*\)).*$,s/QXYZ\2$/\1/," wa.txt >dwa.sed
echo "s/=QXYZ.*$//" >>dwa.sed
sed -e "s/EXPORTS//;s, *\(.*\) @.*$,\1=QXYZ\1," libc.def | sort -bd >libcn.txt
echo EXPORTS > libca.def
sed -f dwa.sed libcn.txt | sort -bd >>libca.def

a2dll libc.a -o libca.dll -d libca.def --no-stdlibs -lintl -liconv -lwsock32 -lole32 -luuid
cp -fp libc.dll.a libgw32c.dll.a
