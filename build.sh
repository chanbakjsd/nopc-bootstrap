#!/bin/bash

declare build_dir="build"

if [[ ! -d "${build_dir}" ]]; then
	cmake -Bbuild -H. -GNinja
fi

ninja -C "${build_dir}"
