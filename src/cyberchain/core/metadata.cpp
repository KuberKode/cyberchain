#include "metadata.h"

Cyber::MetaData::MetaData(){
	Init();
}

Cyber::MetaData::MetaData(const Cyber::MetaData& source){
	try{
		if (this == &source) return;
		Init();
		CopyFrom(source);
	}
	catch (...){
		Log("Error on MetaData() with source");
	}
}

Cyber::MetaData& Cyber::MetaData::operator = (const Cyber::MetaData& right){
	try{
		// Handle self-assignment:
		if (this == &right) return *this;
		CopyFrom(right);
	}
	catch (...){
		Log("Error on =");
	}
	return *this;
}

const Cyber::Data& Cyber::MetaData::operator[](Cyber::Data key){
	return GetReferenceToValue(key);
}


int32 Cyber::MetaData::Add(Data name, Data value){
	try{
		//todo: if name already exist.

		m_names.Add(name);
		m_values.Add(value);
		m_count++;

		return  m_count - 1;
	}
	catch (...){
		Log("Error on Add");
	}
	return -1;
}

int32 Cyber::MetaData::AddName(Data name){
	try{
		//todo: if name already exist.
		m_names.Add(name);
		m_values.Add(Data());
		m_count++;
	}
	catch (...){

	}
	return -1;
}
int32 Cyber::MetaData::SetValue(Data name, Data value){
	try{
		if (m_count > 0){
			for (int i = 0; i < m_count; i++){
				Cyber::Data listName = m_names[i];
				if (listName == name){
					m_values.Replace(i, value);
					return i;
				}
			}
			Log("Name not found");
			//Create name, set value
			return Add(name, value);
		}
	}
	catch (...){
		Log("Error on SetValue");
	}
	return -1;
}

int32 Cyber::MetaData::Replace(Data name, Data value){
	if (m_count > 0){
		for (int i = 0; i<m_count; i++){
			Cyber::Data listName = m_names[i];
			if (listName == name){
				m_values.Replace(i, value);
				return i;
			}
		}
		Log("Name not found");
	}
	return -1;
}

int32  Cyber::MetaData::Replace(int32 key, Data value){
	if (key < 0){ return -1;  }
	if (key >= m_count){ return -1; }

	m_values.Replace(key, value);
	return key;
}

int32 Cyber::MetaData::Remove(Data name){
	//TODO
	return 0;
}

Cyber::Data Cyber::MetaData::Get(Data name){
	try{
		if (m_count > 0){
			for (int i = 0; i<m_count; i++){
				Cyber::Data listName = m_names[i];
				if (listName == name){
					return m_values[i];
				}
			}
		}
	}
	catch (...){
		Log("Error on Get");
	}
	return Cyber::Data();
}

const Cyber::Data& Cyber::MetaData::GetReferenceToValue(Data name) {
	try {
		if (m_count > 0) {
			for (int i = 0; i<m_count; i++) {
				Cyber::Data listName = m_names[i];
				if (listName == name) {
					return m_values[i];
				}
			}
		}
	}
	catch (...) {
		Log("Error on Get");
	}
	return Cyber::Data();

}

Cyber::Data Cyber::MetaData::GetName(int32 key) const{
	try{
		if (key <= 0){ key = 0; }
		if (key>m_count){ key = (m_count - 1); }

		Cyber::Data val = m_names.GetConstItem(key);

		return Cyber::Data(val);
	}
	catch (...){
	}
	return Cyber::Data();
}

Cyber::Data Cyber::MetaData::GetValue(int32 key) const{
	try{
		if (key <= 0){ key = 0; }
		if (key>m_count){ key = (m_count - 1); }

		Cyber::Data val = m_values.GetConstItem(key);

		return Cyber::Data(val);
	}
	catch (...){  }
		
	return Cyber::Data();
}

void Cyber::MetaData::CopyFrom(const MetaData& source){
	try{
		Clear();

		int size = source.Length();
		for (int i = 0; i<size; i++){
			Add(source.GetName(i), source.GetValue(i));
		}
	}
	catch (...){
		Log("Error on CopyFrom");
	}
}

int32 Cyber::MetaData::Length(void) const{
	return m_count;
}

void Cyber::MetaData::Log(Cyber::Data log){
	m_log += log;
	m_log += "\r\n";
}

Cyber::Data Cyber::MetaData::GetLog(void){
	return m_log;
}

void Cyber::MetaData::Init(void){
	m_names.Clear();
	m_values.Clear();
	m_count = 0;
}

void Cyber::MetaData::Clear(void){
	Init();
}

Cyber::MetaData::~MetaData(){
	Clear();
}
