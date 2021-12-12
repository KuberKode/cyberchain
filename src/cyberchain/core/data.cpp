#include "data.h"

void Cyber::Data::Init(void){
	m_length = 0;
	m_data = 0;
	m_log_length = 0;
	m_log = 0;

	m_data_type = DataType::Text;
}

Cyber::Data::Data(){
	Init();
}

Cyber::Data::Data(int8* data, int32 length){
	Init();
	//copy data to memory
	this->CopyFrom(data, length);
}

Cyber::Data::Data(const Data& source){
	Init();
	if (this == &source) return;
	this->CopyFrom(source.m_data, source.m_length);

}

Cyber::Data::Data(int8* data){
	Init();
	int32 length = LengthOf(data);
	this->CopyFrom(data, length);
}

Cyber::Data::Data(char* data){
	Init();
	int32 length = LengthOf(data);
	this->CopyFrom((int8*)data, length);
}

Cyber::Data::Data(const char* data){
	Init();
	int32 length = LengthOf(data);
	this->CopyFrom((int8*)data, length);
}

Cyber::Data::Data(char* data, int32 length){
	Init();
	this->CopyFrom((int8*)data, length);
}

Cyber::Data::Data(const char* data, int32 length){
	Init();
	this->CopyFrom((int8*)data, length);
}


Cyber::Data& Cyber::Data::operator = (const Cyber::Data& right){
	// Handle self-assignment:
	if (this == &right) return *this;
	this->Init();
	this->CopyFrom(right.m_data, right.m_length);
	return *this;
}

Cyber::Data& Cyber::Data::operator += (const Cyber::Data& right){

	if (this == &right) return *this;

	int32 max_len = INT_MAX;
	int32 new_len = m_length + right.m_length;
	if (new_len >= max_len){ new_len = (max_len - 1); }

	int8* new_data = new int8[new_len + 1];
	new_data[new_len] = '\0';

	CopyInto(new_data, m_data, 0, m_length);
	CopyInto(new_data, right.m_data, m_length, right.m_length);

	CopyFrom(new_data, new_len);

	delete[] new_data;
	new_data = 0;
	return *this;
}

bool Cyber::Data::CopyInto(int8* destination, int8* from, int32 start, int32 length){
	try{
		if (start < 0){ start = 0; }

		int i = 0;
		while (i != start){
			i++;
			destination++;
		}

		i = length;
		while (i > 0 && *destination != '\0'){
			i--;
			*destination = *from;
			destination++;
			from++;
		}
		return true;
	}
	catch (...){
		Log((int8*)"Error on CopyInto\r\n");
	}
	return false;
};

int Cyber::operator == (const Data& left, const Cyber::Data& right){
	if (left.m_length != right.m_length){ return 0; }

	int8* ptrLeftWorker = left.m_data;
	int8* ptrRightWorker = right.m_data;

	int i = 1;

	while (*ptrLeftWorker && (*ptrLeftWorker == *ptrRightWorker)){
		ptrLeftWorker++;
		ptrRightWorker++;
	}

	if (*ptrLeftWorker && (*ptrLeftWorker != *ptrRightWorker)){ i = 0; }

	return i;
}

std::ostream& Cyber::operator << (std::ostream& os, const Cyber::Data& out){
	if (out.m_length > 0){ return os << out.m_data; }
	return os << "";
}

int32 Cyber::Data::LengthOf(char* source){  //Calculate length until null terminator found \0
	return LengthOf((int8*)source);
}

int32 Cyber::Data::LengthOf(const char* source){  //Calculate length until null terminator found \0
	return LengthOf((int8*)source);
}

int32 Cyber::Data::LengthOf(int8* source){  //Calculate length until null terminator found \0
	int32 length = 0;
	int32 max_len = INT_MAX;

	if (source == 0){ return 0; }

	int8* ptrSourceWorker = source;

	while (*ptrSourceWorker != '\0'){
		length++;
		if (length >= max_len){ length--; break; }
		ptrSourceWorker++;
	}

	return length;
}

bool Cyber::Data::CopyFrom(int8* source, int32 length){
	
	try{
		Clear();
		int8* ptrSourceWorker = source;
		int32 max_len = INT_MAX;

		if (length >= max_len){ length = (max_len - 1); }

		if (length <= 0){
			length = LengthOf(ptrSourceWorker);
		}
		if (length == 0){ return false; }
		m_data = new int8[length + 1];

		int8* ptrDataWorker = m_data;
		m_length = 0;
		while (*ptrSourceWorker != '\0'){
			*ptrDataWorker = *ptrSourceWorker;
			ptrDataWorker++;
			ptrSourceWorker++;
			m_length++;
			if (m_length == length){ break; }
		}

		*ptrDataWorker = '\0';

		return true;
	}catch (...){
		Log((int8*)"Error on CopyFrom\r\n");
	}
	return false;
}
bool Cyber::Data::CopyFrom(Data source){
	return CopyFrom((int8*)source.Get().c_str(), source.Length());
}
bool Cyber::Data::CopyFrom(Data* pSource){
	return CopyFrom((int8*)pSource->Get().c_str(), pSource->Length());
}

bool Cyber::Data::CopyFrom(const char* source){
	return CopyFrom((int8*)source, LengthOf(source));
}

bool Cyber::Data::Set(const char* data){
	return CopyFrom(data);
}

bool Cyber::Data::Set(int8* data, int32 length){
	return CopyFrom(data, length);
}

bool Cyber::Data::Set(const int8* data, int32 length){
	return CopyFrom((int8*) data, length);
}

bool Cyber::Data::Set(char** data, int32 length){
	return false;
}
bool Cyber::Data::Set(const char* data, int32 length){
	return CopyFrom((int8*)data, length);
}

bool Cyber::Data::SetType(DataType type){
	m_data_type = type;
	return true;
}
Cyber::DataType Cyber::Data::GetType(void){
	return m_data_type;
}

int32 Cyber::Data::Length(void){
	return m_length;
}

std::string Cyber::Data::Get(void){
	return std::string((char*)m_data);
}

void Cyber::Data::Clear(void){
	if (m_data != 0){
		for (int i = m_length; i >= 0; i--) { m_data[i] = '\0';	}
		delete[] m_data;
	}

	if (m_log != 0){
		for (int i = m_log_length; i >= 0; i--) { m_log[i] = '\0'; }
		delete[] m_log;
	}
	Init();
}

void Cyber::Data::Log(int8* text){
	int32 max_len = INT_MAX;
	int32 txtLen = LengthOf(text);
	int32 new_len = m_log_length + txtLen;
	if (new_len >= max_len){ new_len = (max_len - 1); }

	int8* new_log = new int8[new_len + 1];
	new_log[new_len] = '\0';

	CopyInto(new_log, m_log, 0, m_log_length);
	CopyInto(new_log, text, m_log_length, txtLen);

	if (m_log != 0){
		delete[] m_log;
	}
	m_log = 0;

	m_log_length = new_len;
	m_log = new int8[m_log_length + 1];
	m_log[m_log_length] = '\0';
	CopyInto(m_log, new_log, 0, m_log_length);

	for (int i = new_len; i >= 0; i--) { new_log[i] = '\0';	}
	delete[] new_log;
	new_log = 0;
}

Cyber::Data Cyber::Data::GetLog(void){
	return Data(m_log,m_log_length);
}

Cyber::Data::~Data(){

	//release data
	Clear();	
}