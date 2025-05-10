#!/usr/bin/env bash

if [[ -z "${1}" ]]; then
    echo "Missing required version parameter"
    exit
fi

[[ -d "build" ]] && rm -rf build
cmake -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build
cmake -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build

[[ -d "dist" ]] && rm -r dist
mkdir -p dist/{debug,release}/{lib,include}

xargs -n 1 cp -v README.md LICENSE <<< "dist/debug dist/release"
find src -type f -name "*.h" -print0 | xargs -0 -I{} sh -c 'cp -v "{}" dist/debug/include/; cp -v "{}" dist/release/include/'

output_name="clog"

find build -type f -name "lib${output_name}d.*" -exec cp -v {} dist/debug/lib \;
find build -type f -name "lib${output_name}.*" -exec cp -v {} dist/release/lib \;

(cd dist/debug && tar --transform='s|^\./||' -aczvf ../${output_name}-${1}_linux_x86-64_debug.tar.gz *)
(cd dist/release && tar --transform='s|^\./||' -aczvf ../${output_name}-${1}_linux_x86-64.tar.gz *)

unset output_name
