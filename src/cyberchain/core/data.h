#pragma once
#ifndef CYBER_CORE_DATA_H
#define CYBER_CORE_DATA_H

#include "globals.h"
#include <limits.h>

namespace Cyber{

	enum DataType
	{
		Integer, //Number that cannot contain decimal places, can contain negative numbers
		Number, //Number with decimal places, can contain negative numbers
		Text, //String of text
		DateTime //Date and Time
	};
	
	class Data{

		int32 m_length;
		int8* m_data;
		int8* m_log;
		int32 m_log_length;
		DataType m_data_type; //conversion Type. E.g. DateTime, Integer, Number, DateTime

		bool CopyInto(int8* destination, int8* from, int32 start, int32 length);
		void Init(void);		

	public:

		Data();
		Data(int8* data);
		Data(char* data);
		Data(const char* data);
		Data(int8* data, int32 length);
		Data(char* data, int32 length);
		Data(const int8* data, int32 length);
		Data(const char* data, int32 length);
		Data(const Data& source);

		bool CopyFrom(int8* source, int32 length);
		bool CopyFrom(Data source);
		bool CopyFrom(Data* pSource);
		bool CopyFrom(const char* source);

		bool CopyTo(Data& target);
		bool CopyTo(std::string& target);

		Data& operator = (const Data& right);
		Data& operator += (const Data& right);
		friend int operator==(const Data& left, const Data& right);
		friend std::ostream& operator << (std::ostream& os, const Data& out);

		int32 LengthOf(int8* source);
		int32 LengthOf(char* source);
		int32 LengthOf(const char* source);
		int32 Length(void);
		std::string Get( void );

		bool Set(const char* data);
		bool Set(int8* data, int32 length);
		bool Set(char** data, int32 length);
		bool Set(const int8* data, int32 length);
		bool Set(const char* data, int32 length);

		bool SetType(DataType type);
		DataType GetType(void);

		void Log(int8* text);
		Data GetLog(void);
		
		void Clear(void);
		~Data();
	};

	extern int operator == (const Data& left, const Cyber::Data& right);
	extern std::ostream& operator << (std::ostream& os, const Data& out);

}

#endif
