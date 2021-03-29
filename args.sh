#!/bin/bash

shuf -e 1 > /dev/null &&
{
seq $1 | shuf | tr '\n' ' '
exit ;
}

seq $1 | sort -R | tr '\n' ' '
