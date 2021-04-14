#!/bin/bash

shuf -e 1 2> /dev/null 1> /dev/null &&
{
	seq $1 | shuf | tr '\n' ' ' > txt
	exit ;
}
seq $1 | sort -R | tr '\n' ' ' > txt
