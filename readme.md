# Tamagachi - C++

A `c++` Tamagachi. Eventually compiled to WASM.

## Compile to `.exe`:
`make clean`

~`g++ Tamagachi.cpp main.cpp -o tamagachi.exe`~

## Run:
`./tamagachi.exe`

## Compile to WASM:
`emcc Tamagachi.cpp main.cpp -o out/tamagachi.html`

## Resources
* [C++ language basics](https://www.w3schools.com/cpp/)
* [Makefile tutorial](https://www.youtube.com/watch?v=6Gw1rNyTJWA)
* [Compile to WASM](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)