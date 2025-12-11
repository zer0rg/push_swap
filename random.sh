#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Uso: $0 <cantidad> <min> <max>"
    exit 1
fi

count=$1
min=$2
max=$3

range=$(( max - min + 1 ))

# Comprobamos que hay suficientes números en el rango
if [ $range -lt $count ]; then
    echo "Error: el rango [$min, $max] no tiene suficientes valores para generar $count números únicos."
    exit 1
fi

declare -A used
numbers=""

while [ ${#used[@]} -lt $count ]; do
    num=$(( RANDOM % (range) + min ))

    if [ -z "${used[$num]}" ]; then
        used[$num]=1
        numbers="$numbers $num"
    fi
done


./push_swap $numbers
