#!/bin/sh
for dir in work cc
	do cd $dir 
	for file in *.[c]
		do ls $file
		done
		cd ..
	done

