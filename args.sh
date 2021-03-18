#!/bin/bash

seq $1 | shuf | tr '\n' ' '
