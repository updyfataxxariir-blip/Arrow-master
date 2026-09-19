# Extract the ZIP
unzip arrow-master-complete.zip -d arrow-master
cd arrow-master/cpp

# Option A: Using Make
make
./arrow_master

# Option B: Direct compilation with g++
g++ -std=c++17 main.cpp -O2 -o arrow_master
./arrow_master

# Option C: Using CMake
cmake -B build
cmake --build build
./build/arrow_master