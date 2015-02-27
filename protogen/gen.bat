cd commProtosrc
protoc.exe  -I=../ --cpp_out=../../src/proto/model  ../model_db.proto
protoc.exe  -I=../ --cpp_out=../../src/proto/model  ../model_comm.proto
protoc.exe  -I=../ --cpp_out=../../src/proto/  ../packmsg.proto
pause