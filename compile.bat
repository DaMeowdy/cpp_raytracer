@echo off 
cd ./build
rm ./Debug/*
cmake ..
cmake --build .

