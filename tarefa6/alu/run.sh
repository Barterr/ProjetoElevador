#!/bin/sh
top_e_file="tb_extensions.e"
dut_files="top.vhd alu.vhd"
SN_PATH="../.."
TOP_ENTITY="top"
#seed="random"
seed="random"

irun   -gui -nosncomp -access +rwc -linedebug           \
     -snseed $seed                                      \
     -snpath $SN_PATH                                   \
     -snset "trace objection"                           \
     -snload $top_e_file                                \
     $dut_files                                         \
     -top $TOP_ENTITY                                   \
     -smartorder                                        \
     -v93