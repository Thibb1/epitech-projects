#!/bin/bash
set C=$MY_LINE2-$MY_LINE1
cut -d: -f1 | tail -n +2 | sed -n '1~2p' | rev | sort -r | head -n $MY_LINE2 | tail -n +$MY_LINE1 | sed ':a;N;$!ba;s/\n/, /g' | awk '{ print $0 "."}'