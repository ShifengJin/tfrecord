在本目录下打开终端  cmd

执行: 
    protobuf/bin/protoc.exe --cpp_out=./ feature.proto
    protobuf/bin/protoc.exe --cpp_out=./ example.proto
    
    会在当前目录下生成
    feature.pb.h
    feature.pb.cc
    example.pb.h
    example.pb.cc
    
添加代码:
    feature.pb.h    
    411 行 添加   void add_values(float* value, int length);
    1446 行添加
    inline void FloatList::add_values(float* value, int length)
    {
        value_.Add(value, value+length);
    }


1. 需要编译protobuf
2. 需要编译absl

