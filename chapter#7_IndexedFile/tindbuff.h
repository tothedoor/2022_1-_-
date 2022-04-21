//tindbuff.h
#ifndef TINDBUFF_H
#define TINDBUFF_H

#include "textind.h"
#include "fixfld.h"

// class TextIndexBuffer supports reading and writing index records from
//	class TextIndex
// each record is consistent in its maximum size

// TextIndex를 file에 write하고 file에서 read할 때 사용되는 Buffer Class
// - TextIndexBuffer는 FixedFieldBuffer를 상속한다.
//	 => 이유는 IndexTable의 record들(key, key의 address)은 고정된 길이를 가지기 때문이다. 
class TextIndexBuffer: public FixedFieldBuffer
{public:
	TextIndexBuffer(int keySize, int maxKeys = 100, 
		int extraFields = 0, int extraSize=0);
	// extraSize is included to allow derived classes to extend
	// the buffer with extra fields. 
	// Required because the buffer size is exact.
	int Pack (const TextIndex &);
	int Unpack (TextIndex &);
	void Print (ostream &) const;
protected:
	int MaxKeys;
	int KeySize;
	char * Dummy; // space for dummy in pack and unpack
};

#endif
