mainName="main"
rm $mainName
files="$mainName.cpp "`find ./lib -type f -name "*.cpp"`
echo $files
flags="-g -lstdc++ -rdynamic -pthread "
clang $files $flags -o $mainName
gdb ./main
