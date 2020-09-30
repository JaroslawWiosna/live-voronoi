find src/ -iname *.hpp -o -iname *.cpp | xargs /opt/rh/llvm-toolset-7/root/usr/bin/clang-format -i -style=file
