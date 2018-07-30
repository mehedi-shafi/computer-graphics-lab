#!/bin/bash

filename=$1
output=$2

c++ $filename -lGL -lGLU -lglut -o $output

./$output