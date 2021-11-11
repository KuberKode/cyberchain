#ifndef CYBER_META_DATA_H
#define CYBER_META_DATA_H

#include "globals.h"
#include "data.h"
#include "list.h"

namespace Cyber{
	class MetaData{
		
		Cyber::List<Cyber::Data> m_names;
		Cyber::List<Cyber::Data> m_values;
		int32 m_count;
		
		void Init(void);
		void Clear(void);

		Cyber::Data m_log;

	public:
		MetaData();
		MetaData( const MetaData& source );
		MetaData& operator = ( const MetaData& right );
		const Cyber::Data& operator[](Cyber::Data key );
		int32 Add( Data name, Data value );
		int32 AddName( Data name );
		int32 SetValue( Data name, Data value );
		int32 Replace( Data name, Data value );
		int32 Replace( int32 key, Data value );

		int32 Remove( Data name );
		Cyber::Data Get( Data name );
		const Cyber::Data& GetReferenceToValue(Data name);
		
		Data GetName( int32 key ) const;
		Data GetValue( int32 key ) const;
		void CopyFrom( const MetaData& source );
		int32 Length( void ) const;

		void Log( Cyber::Data text );
		Cyber::Data GetLog( void );
		
		~MetaData();

	};
}

#endif
