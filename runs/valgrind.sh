mainName="main"
rm $mainName
files="../$mainName.cpp "`find ../tpg -type f -name "*.cpp"`
echo $files
flags="-rdynamic -lstdc++ -lpthread -lm -Winline -O1 -std=c++17"
clang $files $flags -o $mainName
valgrind --leak-check=full --show-leak-kinds=all ./main
