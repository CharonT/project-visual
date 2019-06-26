#include "SinhVien.h"
#include"graphics.cpp"


SinhVien::SinhVien()
{
}
void SinhVien::setHoVaTen(wstring hoVaTen) {
	this->hoVaTen = hoVaTen;
}
void SinhVien::setMssv(wstring mssv) {
	this->mssv = mssv;
}
void SinhVien::setNgaySinh(wstring ngaySinh) {
	this->ngaySinh = ngaySinh;
}
void SinhVien::setQueQuan(wstring queQuan) {
	this->queQuan = queQuan;
}
void SinhVien::setEmail(wstring email) {
	this->email = email;
}
void SinhVien::setCmnd(wstring cmnd) {
	this->cmnd = cmnd;
}
void SinhVien::setDiaChi(wstring diaChi) {
	this->diaChi = diaChi;
}

wstring SinhVien::getHoVaTen() {
	return hoVaTen;
}
wstring SinhVien::getMssv() {
	return mssv;
}
wstring SinhVien::getNgaySinh() {
	return ngaySinh;
}
wstring SinhVien::getEmail() {
	return email;
}
wstring SinhVien::getQueQuan() {
	return queQuan;
}
wstring SinhVien::getDiaChi() {
	return diaChi;
}
wstring SinhVien::getCmnd() {
	return cmnd;
}
void SinhVien::infor() {
	system("cls");
	_setmode(_fileno(stdout), _O_U16TEXT);
	bool check;
	wstring sday, smonth, syear;
	int iday,imonth,iyear;
	cin.ignore();
	wcout << L"===============Nhập thông tin==============="<<endl;
	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"Họ và tên : ";
		_setmode(_fileno(stdin), _O_U16TEXT);
		getline(wcin, this->hoVaTen);
		if (this->hoVaTen.length()==0) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
			_setmode(_fileno(stdout), _O_TEXT);
			cout<<"\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
		
	} while (!check);

	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"MSSV : "; getline(wcin, this->mssv);
		if (this->mssv.length() == 0) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
		else {
			for (int i = 0; i < this->mssv.length(); i++) {
				if (this->mssv[i]<'0' || this->mssv[i]>'9') {
					textcolor(6);
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xAF\xAF\xAF\xAF";
					_setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"CẢNH BÁO:Chỉ được nhập số";
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xB2\xB2" << endl;
					textcolor(7);
					check = false;
					break;
				}

			}
		}
		

	} while (!check);
	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true; 
		wcout << L"Nhập ngày sinh : "; 
		_setmode(_fileno(stdin), _O_TEXT); 
		cin >> iday;
		wcout << endl;
		wcout << L"Nhập tháng sinh: ";
		_setmode(_fileno(stdin), _O_TEXT);
		cin >> imonth; 
		wcout << endl;
		wcout << L"Nhập năm sinh: "; 
		_setmode(_fileno(stdin), _O_TEXT);
		cin >> iyear; 
		wcout << endl;
		if ((iday <= 0 || iday > 31) || (imonth <= 0 || imonth > 12) || (iyear <= 0)) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Bạn nhập sai";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
		else if(imonth==4|| imonth == 6|| imonth == 9|| imonth == 11) { //4 6 9 11
			if (iday == 31) {
				textcolor(6);
				_setmode(_fileno(stdout), _O_TEXT);
				cout << "\xAF\xAF\xAF\xAF";
				_setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"CẢNH BÁO:Bạn nhập sai";
				_setmode(_fileno(stdout), _O_TEXT);
				cout << "\xB2\xB2" << endl;
				textcolor(7);
				check = false;
			}
		}
		else if (imonth == 2) {
			if (iyear % 4 == 0) {
				if (iday > 29) {
					textcolor(6);
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xAF\xAF\xAF\xAF";
					_setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"CẢNH BÁO:Bạn nhập sai";
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xB2\xB2" << endl;
					textcolor(7);
					check = false;
				}
			}
			else {
				if (iday > 28) {
					textcolor(6);
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xAF\xAF\xAF\xAF";
					_setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"CẢNH BÁO:Bạn nhập sai";
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xB2\xB2" << endl;
					textcolor(7);
					check = false;
				}

			}
		}
		if (check) {
			if (iday >= 1 && iday <= 9) {
				sday = to_wstring(iday);
				sday = L"0" + sday;
			}
			else
				sday = to_wstring(iday);
			if (imonth > 0 && imonth < 10) {
				smonth = to_wstring(imonth);
				smonth = L"0" + smonth;
			}else
				smonth = to_wstring(imonth);
			
			syear = to_wstring(iyear);
			this->ngaySinh = sday + L"/" + smonth + L"/" + syear;

		}
	} while (!check);
	cin.ignore();

	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"Quê quán : "; 
		_setmode(_fileno(stdin), _O_U16TEXT); 
		getline(wcin, this->queQuan);
		if (this->queQuan.length() == 0) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
	} while (!check);
	
	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"Email : "; getline(wcin, this->email);
		if (this->email.length() == 0) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
		else {
			if (this->email.find(L"@", 0) == -1) {
				textcolor(6);
				_setmode(_fileno(stdout), _O_TEXT);
				cout << "\xAF\xAF\xAF\xAF";
				_setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"CẢNH BÁO:Bạn nhập sai";
				_setmode(_fileno(stdout), _O_TEXT);
				cout << "\xB2\xB2" << endl;
				textcolor(7);
				check = false;
			}
		}
		
	} while (!check);
	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"CMND : "; getline(wcin, this->cmnd);
		if (this->cmnd.length() != 9) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:CMND phải đủ 9 số";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
		else {
			for (int i = 0; i < this->cmnd.length(); i++) {
				if (this->cmnd[i]<'0' || this->cmnd[i]>'9') {
					textcolor(6);
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xAF\xAF\xAF\xAF";
					_setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"CẢNH BÁO:Bạn chỉ được nhập số";
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xB2\xB2" << endl;
					textcolor(7);
					check = false;
					break;
				}
			}
		}
		

	} while (!check);

	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		wcout << L"Địa Chỉ : ";
		_setmode(_fileno(stdin), _O_U16TEXT);
		getline(wcin, this->diaChi);
		if (this->diaChi.length() == 0) {
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			check = false;
		}
	} while (!check);
	system("pause");
}
void SinhVien::show(int choose) {
	_setmode(_fileno(stdout), _O_U16TEXT);
	if (choose == 0) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		wcout << L"MSSV :" << this->mssv << endl << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê quán:" << this->queQuan << endl;
		wcout << L"email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		wcout << L"Địa chỉ :" << this->diaChi << endl;
	}
	if (choose == 1) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << "Ho va ten  :" << this->hoVaTen << endl;
		wcout<< L"MSSV :" << this->mssv << endl;
		textcolor(11);
		wcout << L"Ngày Sinh:" << this->ngaySinh << endl;
		textcolor(7);
		wcout << L"Quê Quán:" << this->queQuan << endl;
		wcout << L"Email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		wcout<< L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 2) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		wcout << L"MSSV :" << this->mssv << endl << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê Quán:" << this->queQuan << endl;
		wcout << L"Email:" << this->email << endl;
		textcolor(11);
		wcout<< L"CMND:" << this->cmnd << endl;
		textcolor(7);
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 3) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		textcolor(11);
		wcout << L"MSSV :" << this->mssv << endl;
		textcolor(7);
		wcout << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê Quán:" << this->queQuan << endl;
		wcout << L"Email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 4) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		textcolor(11);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		textcolor(7);
		wcout << L"MSSV :" << this->mssv << endl;
		wcout << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê Quán:" << this->queQuan << endl;
		wcout << L"Email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 5) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		wcout << L"MSSV :" << this->mssv << endl;
		wcout << L"Ngày Sinh:" << this->ngaySinh << endl;
		textcolor(11);
		wcout << L"Quê Quán:" << this->queQuan << endl;
		textcolor(7);
		wcout << L"Email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 6) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		wcout << L"MSSV :" << this->mssv << endl << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê Quán:" << this->queQuan << endl;
		textcolor(11);
		wcout << L"Email:" << this->email << endl;
		textcolor(7);
		wcout << L"CMND:" << this->cmnd << endl;
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
	}
	if (choose == 7) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"Họ và tên  :" << this->hoVaTen << endl;
		wcout << L"MSSV :" << this->mssv << endl;
		wcout << L"Ngày Sinh:" << this->ngaySinh << endl;
		wcout << L"Quê Quán:" << this->queQuan << endl;
		wcout << L"Email:" << this->email << endl << L"CMND:" << this->cmnd << endl;
		textcolor(11);
		wcout << L"Địa Chỉ :" << this->diaChi << endl;
		textcolor(7);
	}
	
}

