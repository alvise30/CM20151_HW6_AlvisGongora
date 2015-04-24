#include <stdio.h>
#include <stdlib.h>


#define SHELLSCRIPT "\
#/bin/bash \n\
grep 'tierra' | grep 'x' | awk {'print $3'} > icb.txt \n\
grep 'tierra' | grep 'y' | awk {'print $3'} >> icb.txt \n\
grep 'tierra' | grep 'z' | awk {'print $3'} >> icb.txt \n\
grep 'tierra' | grep 'x' | awk {'print $4'} >> icb.txt \n\
grep 'tierra' | grep 'y' | awk {'print $4'} >> icb.txt \n\
grep 'tierra' | grep 'z' | awk {'print $4'} >> icb.txt \n\
grep 'sol' | grep 'x' | awk {'print $3'} >> icb.txt \n\
grep 'sol' | grep 'y' | awk {'print $3'} >> icb.txt \n\
grep 'sol' | grep 'z' | awk {'print $3'} >> icb.txt \n\
grep 'sol' | grep 'x' | awk {'print $4'} >> icb.txt \n\
grep 'sol' | grep 'y' | awk {'print $4'} >> icb.txt \n\
grep 'sol' | grep 'z' | awk {'print $4'} >> icb.txt \n\
grep 'luna' | grep 'x' | awk {'print $3'} >> icb.txt \n\
grep 'luna' | grep 'y' | awk {'print $3'} >> icb.txt \n\
grep 'luna' | grep 'z' | awk {'print $3'} >> icb.txt \n\
grep 'luna' | grep 'x' | awk {'print $4'} >> icb.txt \n\
grep 'luna' | grep 'y' | awk {'print $4'} >> icb.txt \n\
grep 'luna' | grep 'z' | awk {'print $4'} >> icb.txt \n\
grep 'asteroide' | grep 'x' | awk {'print $3'} >> icb.txt \n\
grep 'asteroide' | grep 'y' | awk {'print $3'} >> icb.txt \n\
grep 'asteroide' | grep 'z' | awk {'print $3'} >> icb.txt \n\
grep 'asteroide' | grep 'x' | awk {'print $4'} >> icb.txt \n\
grep 'asteroide' | grep 'y' | awk {'print $4'} >> icb.txt \n\
grep 'asteroide' | grep 'z' | awk {'print $4'} >> icb.txt \n\
"
