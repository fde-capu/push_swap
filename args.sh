#!/bin/bash

shuf &&
{
seq $1 | shuf | tr '\n' ' '
exit ;
}

seq $1 | sort -R | tr '\n' ' '
