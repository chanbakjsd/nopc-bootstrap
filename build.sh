#!/bin/bash

if [ ! -d "build" ]; then
	cmake -Bbuild -H. -GNinja
	cd build
	ninja
	
else
	if [ -f "build/build.ninja" ]; then
		cd build
		ninja
	else
		echo "Cannot find ninja.build in build directory"
	fi

fi
