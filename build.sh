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

if [[ ! -d "${build_dir}" ]]; then
	cmake -Bbuild -H. -GNinja
fi

ninja -C "${build_dir}"
