#ifndef CYBER_DATA_LIST_H
#define Cyber_DATA_LIST_H

#include "globals.h"
#include "data.h"

namespace Cyber{
	template<class T>
	class List{

		T* m_list;
		int32 m_count;

	public:

		List();

		int32 Count(void);

		int32 Add(T item);
		int32 Add(char* item);

		T Get(int32 key);
		T GetConstItem(int32 key) const;
		T operator[](int32 key);

		void Replace(int32 key, T item);

		void Clear(void);

		~List();
	
	};

	template<class T>
	Cyber::List<T>::List(){
		m_list = 0;
		m_count = 0;
	}

	template<class T>
	int32 Cyber::List<T>::Count(){
		return m_count;
	}

	template<class T>
	int32 Cyber::List<T>::Add(T item){

		T* tmpName = 0;

		if (m_count > 0){
			//create tempory array
			tmpName = new T[m_count];
			//copy strings to tempory array
			for (int32 i = 0; i < m_count; i++){
				tmpName[i] = m_list[i];
			}
			delete[] m_list;
			m_list = 0;
		}
		m_count++;
		m_list = new T[m_count];
		for (int32 i = 0; i < m_count - 1; i++){
			m_list[i] = tmpName[i];
		}
		delete[] tmpName;
		tmpName = 0;

		int32 i = m_count - 1;
		m_list[i] = item;

		return i;
	}

	template<class T>
	int32 Cyber::List<T>::Add(char* item){
		return Add(T(item));
	}

	template<class T>
	T Cyber::List<T>::Get(int32 key){
		if (key < 0){ key = 0; }
		if (key >= m_count){ key = (m_count-1); }

		return m_list[key];
	}

	template<class T>
	T Cyber::List<T>::GetConstItem(int32 key) const{
		if (key < 0){ key = 0; }
		if (key >= m_count){ key = (m_count - 1); }

		return m_list[key];
	}

	template<class T>
	T Cyber::List<T>::operator[](int32 key){

		return Get(key);

	}

	template<class T>
	void Cyber::List<T>::Replace(int32 key, T item){
		if (key < 0){ return; }
		if (key >= m_count){ return; }
		
		m_list[key] = item;
	}

	template<class T>
	void Cyber::List<T>::Clear(void){
		if (m_list){
			delete[] m_list;
			m_list = 0;
		}
		m_count = 0;
	}

	template<class T>
	Cyber::List<T>::~List(){
		Clear();
	}

}

#endif