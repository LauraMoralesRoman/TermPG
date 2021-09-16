mainName="main"
rm $mainName
files="$mainName.cpp "`find ./lib -type f -name "*.cpp"`
echo $files
flags="-pg -g -lstdc++ -rdynamic -pthread -O2"
clang $files $flags -o $mainName
./main
gprof -b ./main gmon.out > pdata.txt
nano pdata.txt
rm pdata.txt
rm gmon.out


