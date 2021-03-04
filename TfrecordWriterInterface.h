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
	/// ��ʼ�� tfrecordWriter  filePath ����Ŀ¼��Ҫʹ�����Լ�����   
	///       path/to/save/data.tfrecords   
	///       path,to,save�ļ�����Ҫʹ�ô���
	/// </summary>
	/// <param name="filePath">�����  �ļ�·��/����.tfrecords  </param>
	/// <returns>NULL ·�������쳣</returns>
	EXPORT_API void* InitTFRecordWriter(std::string filePath);

	/// <summary>
	/// д���ݿ�
	/// </summary>
	/// <param name="env">��InitTFRecordWriter �õ�</param>
	/// <param name="inDataBlocks">������ݿ�</param>
	EXPORT_API void TFRecordWriteDataBlock(void* env, std::vector<TFRecordDataBlock>& inDataBlocks);

	/// <summary>
	/// �ͷŻ���
	/// </summary>
	/// <param name="env">��InitTFRecordWriter �õ�</param>
	EXPORT_API void TFRecordWriterClose(void* env);

}  // AlvaSystems