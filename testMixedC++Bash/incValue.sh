#!/bin/bash
###################################################################
# Filename:       incValue.sh
# Author:         Austin Anderson
# Class:          CSI 3336
# Date Modified:  2016-03-17
#   -File Created
# Description:   
# 
####################################################################

i=$1
echo "before $i (outside program)"
f=$(./a.out $i)
echo "program wrote $f"
echo "program returned $?"
echo "after  $i (outside program)"
