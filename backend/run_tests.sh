cmake -S . -B build
cd build
cmake --build .
ctest
cd ..
rm -r build
