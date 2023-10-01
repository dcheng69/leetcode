# Project Description
## Goals
Practice on a daily basis and develop software engineering habits!

## Dependencies (Ubuntu)
**Note:**
1. Currently, the script is testified on a linux shell enviroment, welcome to create another branch for windows!!!
2. For windows enviroment, WSL2 is recommanded

**Dependencies for compilation**
1. gcc and g++ (7.0 higher version recomamnded)
```bash
sudo apt install gcc
sudo apt install g++
```
2. cmake and make (cmake version 3.14 or higher)
```bash
sudo apt install make
sudo apt install cmake
sudo apt isntall build-essensial
```

3. gdb (IDE is recommanded, choose whichever is the most familiar to you)
```bash
sudo apt install gdb
```

## Name conventions and other tutorials
1. googletest \
https://google.github.io/googletest/
2. cmake \
https://cmake.org/cmake/help/latest/index.html
3. Google C++ Style Guide \
https://google.github.io/styleguide/cppguide.html#Variable_Names
4. CPP library reference \
https://en.cppreference.com/w/
5. git log template please follow the old ones, but we are open to opions, welcome to discuss!

## Recommanded CLI tools (optional)
1. lazygit for git management \
https://github.com/jesseduffield/lazygit

## Usage
**Note：** \
**Please create a branch for each leetcode and create an merge request to proceed! Thank you!**
**currently no script generated for the tools folder, self development needed!**

1. auto generate code folder
``` bash
# shell script, accept two arguments
# the first argument is leetcode number, the second is the folder name
# below is an example
./new.sh 2 2_Add_Two_Numbers
# then hit y to proceed
```
2. auto build
```bash
# generate build folder with make files according to the cmake rules
# compile check
./build.sh
```

3. develop and test
```bash
# using cd or pushd
cd build/2_Add_Two_Numbers
make or ctest
```

4. debug and writing unit test code
```bash
# for each folder there is an unit_test folder
# using cd or pushd
cd build/2_Add_Two_Numbers/1_unit_test
# executable file "Debug1" is for gdb to debug, Test1 is for runing google test
gdb --quiet Debug1
# see the result of the test case
ctest
# see details
./Test1
```

## Finally
**Good luck and enjoy coding!**
