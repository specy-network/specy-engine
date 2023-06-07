/usr/local/bin/protoc --version

/usr/local/bin/protoc --proto_path=. --cpp_out=./untrusted/ Regulator.proto
/usr/local/bin/protoc --proto_path=. --cpp_out=./untrusted/ Register.proto


/usr/local/bin/protoc --proto_path=. --grpc_out=./untrusted/ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin Regulator.proto
/usr/local/bin/protoc --proto_path=. --grpc_out=./untrusted/ --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin Register.proto
