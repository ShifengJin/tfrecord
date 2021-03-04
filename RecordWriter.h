#pragma once
#include "absl/strings/string_view.h"
#include "TfrecordWriterInterface.h"


namespace Darker {

	using StringPiece = absl::string_view;

	class RecordWriter {

	public:
		static constexpr size_t kHeaderSize = sizeof(unsigned __int64) + sizeof(unsigned int);
		static constexpr size_t kFooterSize = sizeof(unsigned int);
		static const unsigned int kMaskDelta = 0xa282ead8ul;
		RecordWriter(std::string fName);
		~RecordWriter();
		bool IsInited();
		int WriteRecord(StringPiece data);
		void Close();

	private:
		inline void PopulateHeader(char* header, const char* data, size_t n);
		inline void PopulateFooter(char* footer, const char* data, size_t n);
		inline unsigned int MaskedCrc(const char* data, size_t n) {
			return Mask(Value(data, n));
		}
		inline unsigned int Value(const char* data, size_t n) { return Extend(0, data, n); }
		inline unsigned int Mask(unsigned int crc) {
			return ((crc >> 15) | (crc << 17)) + kMaskDelta;
		}
		inline unsigned int LE_LOAD32(const unsigned char* p) {
			return DecodeFixed32(reinterpret_cast<const char*>(p));
		}

		unsigned int Extend(unsigned int crc, const char* buf, size_t size);
		void EncodeFixed64(char* buf, unsigned __int64 value);
		void EncodeFixed32(char* buf, unsigned int value);
		unsigned int DecodeFixed32(const char* ptr);
		unsigned short DecodeFixed16(const char* ptr);
		unsigned __int64 DecodeFixed64(const char* ptr);

	private:
		FILE* fp = NULL;
	};
}