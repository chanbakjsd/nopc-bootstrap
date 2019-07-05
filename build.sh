#!/bin/bash

if [[ -x "$(command -v antlr4)" ]]; then
	antlr4 -Dlanguage=Cpp nop.g4 -o ./src/parser/
elif [[ -f /usr/local/bin/antlr4.jar ]]; then
	java -jar /usr/local/bin/antlr4.jar -Dlanguage=Cpp nop.g4 -o ./src/parser/
else
	echo "You must install antlr4, see README.md"
	exit 1
fi

declare build_dir="build"

if ! cmake -Bbuild -H. -GNinja; then
	echo "An error has occurred while generating ninja build file."
	echo "Please resolve it and rerun this script."
	exit 1
fi

ninja -C "${build_dir}"
