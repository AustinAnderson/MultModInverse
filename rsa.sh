#!/bin/bash
###################################################################
# Filename:       rsa.sh
# Author:         Austin Anderson
# Class:          CSI 3336
# Date Modified:  2016-03-17
#   -File Created
# Description:   
# 
####################################################################

echo "p=$1, q=$2, e=$3, M=$4"

n=$(($1*$2))
echo "n=p*q=$1*$2=$n"
phiN=$(($(($1-1))*$(($2-1))))
echo "phi(n)=(p-1)*(q-1)=$(($1-1))*$(($2-1))=$phiN"
d=$(./a.out $3 $phiN)
echo "d=$d"
echo "C=M^e mod n=$4^$3 mod $n=$(($4**$3)) mod $n=$(($(($4**$3))%$n))"
C=$(($(($4**$3))%$n))
echo "M=C^d mod n=$C^$d mod $n=$4"
