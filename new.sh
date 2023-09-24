#!/bin/bash
# this script is for adding new folder

funWithParam(){
    echo "creating the folder named $2 ..."
    mkdir $2

    basepath=$(cd `dirname $0`; pwd)
    workpath=$basepath/$2
    # echo "work directory is $workpath"

    echo "add_subdirectory($2)">>CMakeLists.txt

    cd $workpath

    touch CMakeLists.txt
    echo "add_library($1_solution Solution$1.cc)">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_link_libraries($1_solution PUBLIC">>CMakeLists.txt
    echo "        tools">>CMakeLists.txt
    echo "        )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_include_directories($1_solution PUBLIC">>CMakeLists.txt
    echo "        \"\${PROJECT_SOURCE_DIR}/$2\"">>CMakeLists.txt
    echo "        \"\${PROJECT_SOURCE_DIR}/tools\"">>CMakeLists.txt
    echo "        )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "add_subdirectory($1_unit_test)">>CMakeLists.txt

    touch Solution$1.h
    echo "#ifndef SOLUTION$1_H_">>Solution$1.h
    echo "#define SOLUTION$1_H_">>Solution$1.h
    echo "class Solution {">>Solution$1.h
    echo "    public:">>Solution$1.h
    echo "        void test();">>Solution$1.h
    echo "};">>Solution$1.h
    echo "">>Solution$1.h
    echo "#endif">>Solution$1.h

    touch Solution$1.cc
    echo "#include <iostream>">>Solution$1.cc
    echo "#include \"Solution$1.h\"">>Solution$1.cc
    echo "using namespace std;">>Solution$1.cc
    echo "">>Solution$1.cc
    echo "void test() {">>Solution$1.cc
    echo "    cout << \"test!\" << endl;">>Solution$1.cc
    echo "    return;">>Solution$1.cc
    echo "}">>Solution$1.cc

    mkdir $1_unit_test
    testpath=$workpath/$1_unit_test
    cd $testpath

    touch CMakeLists.txt
    echo "# add test for $2">>CMakeLists.txt
    echo "add_executable(Test$1">>CMakeLists.txt
    echo "    Test$1.cc">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_link_libraries(Test$1 PUBLIC">>CMakeLists.txt
    echo "    GTest::gtest_main">>CMakeLists.txt
    echo "    gmock_main">>CMakeLists.txt
    echo "    1_solution">>CMakeLists.txt
    echo "    tools">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_include_directories(Test$1 PUBLIC">>CMakeLists.txt
    echo "     \"\${PROJECT_SOURCE_DIR}/$2\"">>CMakeLists.txt
    echo "     \"\${PROJECT_SOURCE_DIR}/tools\"">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "include(GoogleTest)">>CMakeLists.txt
    echo "gtest_discover_tests(Test$1)">>CMakeLists.txt
    echo "">>CMakeLists.txt

    echo "# add debug for $2">>CMakeLists.txt
    echo "add_executable(Debug$1">>CMakeLists.txt
    echo "    Debug$1.cc">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_link_libraries(Debug$1 PUBLIC">>CMakeLists.txt
    echo "    $1_solution">>CMakeLists.txt
    echo "    tools">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt
    echo "target_include_directories(Debug$1 PUBLIC">>CMakeLists.txt
    echo "     \"\${PROJECT_SOURCE_DIR}/$2\"">>CMakeLists.txt
    echo "     \"\${PROJECT_SOURCE_DIR}/tools\"">>CMakeLists.txt
    echo "    )">>CMakeLists.txt
    echo "">>CMakeLists.txt

    touch Test$1.cc
    echo "#include <gtest/gtest.h>">>Test$1.cc
    echo "#include <gmock/gmock.h>">>Test$1.cc
    echo "#include \"Solution$1.h\"">>Test$1.cc
    echo "using namespace std;">>Test$1.cc
    echo "TEST(Test$1, Check) {">>Test$1.cc
    echo "    Solution s;">>Test$1.cc
    echo "}">>Test$1.cc

    touch Debug$1.cc
    echo "#include <iostream>">>Debug$1.cc
    echo "#include \"Solution$1.h\"">>Debug$1.cc
    echo "using namespace std;">>Debug$1.cc
    echo "">>Debug$1.cc
    echo "int main(int argc, char* argv[]) {">>Debug$1.cc
    echo "    cout << \"Enjoy debuging!\" << endl;">>Debug$1.cc
    echo "    return 0;">>Debug$1.cc
    echo "}">>Debug$1.cc
}

checkValiadeParam(){
    check_redundancy='eval ls | grep $2'
    if [ -d "$2" ]
    then
        echo "Thre is Redundancy! which is:"
        $check_redundancy
    else
        funWithParam $1 $2
        echo "folder created! compeletion needed!"
    fi
}

# start of the script
echo "The folder id is $1"
echo "The folder name is $2"
echo "Continue? y/n/c"

read Arg
case $Arg in
    Y|y|YES|yes)
        checkValiadeParam $1 $2
        ;;
    N|n|NO|no)
        echo "exit now!"
        exit
        ;;
    C|c|check|CheckCHECK)
        checkValiadeParam $1 $2
        echo "check done!"
        ;;
    "")  #Autocontinue
        echo "nothing done, exit now!"
        ;;
esac
