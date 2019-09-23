.PHONY: cppclient
cppclient:
	protoc --proto_path=protobuf \
		--cpp_out=src/protobuf \
		--grpc_out src/protobuf \
		--plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
		protobuf/faiss.proto

 .PHONY: pyclient
 pyclient:
	mkdir -p python
	python -m grpc_tools.protoc --proto_path=protobuf \
		--python_out=python \
		--grpc_python_out=python \
		protobuf/faiss.proto

.PHONY: goclient
goclient:
	mkdir -p go
	protoc --proto_path=protobuf --go_out=plugins=grpc:go protobuf/faiss.proto

