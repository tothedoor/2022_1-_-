// ledger.h
#ifndef LEDGER_H
#define LEDGER_H

#include <fstream>
#include <string.h>
#include "iobuffer.h"

// 원장 클래스
class Ledger
{public:
	int Acct; // 계좌 번호
	char Title [30]; // 계좌 이름
	double Balances[12]; // 계좌 잔액
	int Pack(IOBuffer & buffer) const;
	int Unpack (IOBuffer & buffer);
	ostream & Print (ostream &);
	ostream & PrintHeader (ostream &); 
	Ledger ();
	Ledger (int, char *, double, double, double);
};

ostream & PrintBalances (ostream & stream, double PreviousBalance, double CurrentBalance);

// 일지 클래스 (원장에 존재하는 계좌에 대한 transaction을 나타낸다고 봐도 됨)
class Journal
{public:
	int Acct; // 계좌 번호 
	int CheckNum; // 처리 번호
	char Date[10]; // transaction 처리 날짜
	char Description[30]; // 설명(세부내용)
	double Amount; // 처리 금액
	int Pack (IOBuffer &) const;
	int Unpack (IOBuffer &);
	ostream & PrintLine (ostream &);
	Journal ();
	Journal (int, int, char*, char*, double);
};

#endif