// ledger.h
#ifndef LEDGER_H
#define LEDGER_H

#include <fstream>
#include <string.h>
#include "iobuffer.h"

// ���� Ŭ����
class Ledger
{public:
	int Acct; // ���� ��ȣ
	char Title [30]; // ���� �̸�
	double Balances[12]; // ���� �ܾ�
	int Pack(IOBuffer & buffer) const;
	int Unpack (IOBuffer & buffer);
	ostream & Print (ostream &);
	ostream & PrintHeader (ostream &); 
	Ledger ();
	Ledger (int, char *, double, double, double);
};

ostream & PrintBalances (ostream & stream, double PreviousBalance, double CurrentBalance);

// ���� Ŭ���� (���忡 �����ϴ� ���¿� ���� transaction�� ��Ÿ���ٰ� ���� ��)
class Journal
{public:
	int Acct; // ���� ��ȣ 
	int CheckNum; // ó�� ��ȣ
	char Date[10]; // transaction ó�� ��¥
	char Description[30]; // ����(���γ���)
	double Amount; // ó�� �ݾ�
	int Pack (IOBuffer &) const;
	int Unpack (IOBuffer &);
	ostream & PrintLine (ostream &);
	Journal ();
	Journal (int, int, char*, char*, double);
};

#endif