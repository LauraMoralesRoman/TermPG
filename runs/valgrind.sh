mainName="main"
rm $mainName
files="$mainName.cpp "`find ./lib -type f -name "*.cpp"`
echo $files
flags="-g -rdynamic -pthread -lstdc++"
clang $files $flags -o $mainName
valgrind --leak-check=full --show-leak-kinds=all ./main