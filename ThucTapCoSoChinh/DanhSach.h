#pragma once
#include"SinhVien.h"
class DanhSach
{
private:
	vector<SinhVien*> listSv;
	int DSchoose;
	int DSchoose2;

	void nameFile(wstring&);
	void getDate(int&, int&, int&, wstring);
	long int getNumS(wstring);
	bool soSanhDate(wstring, wstring);
	void merge(int, int, int, int, int);
	void test();
	int getNumC(int, wstring data);
	void mergeSort(int, int, int, int);
	
public:
	DanhSach();
	~DanhSach();
	void getList();
	void sapXep();
	void addSinhVien();
	void xoa();
	void tim();
	void addList();
	void xuatFile();
	void show(int);
};

