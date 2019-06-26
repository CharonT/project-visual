#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<libxl.h>
#include<vector>
#include<sstream>
#include<fcntl.h>
#include <io.h>
#include"graphics.h"
using namespace std;
using namespace libxl;
#pragma warning(disable:4996)
class SinhVien
{
private:
	wstring email;
	wstring cmnd;
	wstring diaChi;
	wstring hoVaTen;
	wstring mssv;
	wstring ngaySinh;
	wstring queQuan;

public:
	SinhVien();
	~SinhVien();
	void setHoVaTen(wstring);
	void setMssv(wstring);
	void setNgaySinh(wstring);
	void setQueQuan(wstring);
	void setEmail(wstring);
	void setCmnd(wstring);
	void setDiaChi(wstring);

	wstring getHoVaTen();
	wstring getMssv();
	wstring getNgaySinh();
	wstring getQueQuan();
	wstring getEmail();
	wstring getCmnd();
	wstring getDiaChi();


	void infor();
	void show(int);
};

