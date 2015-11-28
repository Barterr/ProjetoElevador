#!/bin/bash

CXX=/home/ufsc/eda/sparc-newlib-elf/bin/sparc-newlib-elf-g++
CC=/home/ufsc/eda/sparc-newlib-elf/bin/sparc-newlib-elf-gcc
SPECSFILE="/home/ufsc/eda/sparc-newlib-elf/sparc-newlib-elf/lib/archc"

read -p "PATH to source file: " -i "./" -e path
read -p "Compiling for host or sparc? (sparc(s)/host(h)) " target

filename=$(basename "$path")
filename="${filename%.*}"

if [ "$target" == "h" ] || [ "$target" == "host" ]; then
    read -p "flags?: " flags
    gcc $path -o $filename.x86 $flags 
    echo "Output is $filename.x86"
elif [ "$target" == "s" ] || [ "$target" == "sparc" ]; then 
    read -p "flags?: " flags
    #$CC -specs=${SPECSFILE} $path -static -o $filename.x $flags -ggdb
    $CXX -specs=${SPECSFILE} $path -static -o $filename.x $flags -O0 -ggdb -fvar-tracking -gdwarf-3 -fvar-tracking-assignments
    echo "Output is $filename.x"
    objdump -t $filename.x > $filename.symboltable
else 
    echo "You must answer s for sparc OR h for host"
fi





# CC=/home/paludo/Downloads/sparc-newlib-elf/bin/sparc-newlib-elf-gcc
# SPECSFILE="/home/paludo/Downloads/sparc-newlib-elf/sparc-newlib-elf/lib/archc"

# $CC -specs=${SPECSFILE} cda.c -static -o cda.x -lm -ggdb
