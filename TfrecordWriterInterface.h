#pragma once

#include <string>
#include <vector>
#include <list>

#ifdef DLL_EXPORTS
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

namespace Darker {
	
	typedef enum _TFRecordDataType_ {
		TYPE_BytesList = 0,
		TYPE_FloatList = 1,
		TYPE_Int64List = 2
	}TFRecordDataType;

	typedef struct _TFRecordDataBlock_ {
		TFRecordDataType type;
		int dataSize;
		void* data;
		char dataName[64];
	}TFRecordDataBlock;

	/// <summary>
	/// 初始化 tfrecordWriter  filePath 各级目录需要使用者自己创建   
	///       path/to/save/data.tfrecords   
	///       path,to,save文件夹需要使用创建
	/// </summary>
	/// <param name="filePath">保存的  文件路径/名称.tfrecords  </param>
	/// <returns>NULL 路径存在异常</returns>
	EXPORT_API void* InitTFRecordWriter(std::string filePath);

	/// <summary>
	/// 写数据块
	/// </summary>
	/// <param name="env">由InitTFRecordWriter 得到</param>
	/// <param name="inDataBlocks">多个数据块</param>
	EXPORT_API void TFRecordWriteDataBlock(void* env, std::vector<TFRecordDataBlock>& inDataBlocks);

	/// <summary>
	/// 释放环境
	/// </summary>
	/// <param name="env">由InitTFRecordWriter 得到</param>
	EXPORT_API void TFRecordWriterClose(void* env);

}  // AlvaSystems