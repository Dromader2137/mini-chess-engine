#!/usr/bin/env bash

FILES_TO_DELETE=(`find \
	-name "Makefile" -or \
	-name "cmake_install.cmake" -or \
	-name "CMakeCache.txt" -or \
	-name "CMakeFiles" -or \
	-name "engine" -type f \
	`)

echo "Files marked for deletion: ${FILES_TO_DELETE[@]}"

echo -n "Do you want to proceed? [y/n] "

read ANS

if [[ "$ANS" == "y" ]]; then
	rm -rf "${FILES_TO_DELETE[@]}"
else
	echo "Ok, doing nothing."
fi
