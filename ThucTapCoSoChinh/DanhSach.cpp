#include "DanhSach.h"
DanhSach::DanhSach() {
	this->DSchoose = -1;
	this->DSchoose2 = -1;


}
DanhSach::~DanhSach() {
	this->listSv.clear();
}

void DanhSach::nameFile(wstring& name) {
	textcolor(3);
	cin.ignore();
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\t>>>>>>>>>>>>>>Mời bạn nhập file excel (.xlsx) :";
	textcolor(7);
	getline(wcin, name);
	if (name.find(L".xlsx") == -1)
		name += L".xlsx";

}

void DanhSach::getList() {
	if (!this->listSv.empty()) {
		this->listSv.clear();
	}
	wstring name;
	this->nameFile(name);
	Book* book = xlCreateXMLBook();
	SinhVien *sv;
	int j;
	int i;
	int size;
	int soLuong = 0;
	vector<int> dsSoLuong;
	if (book) {
		if (book->load(name.c_str())) {
			Sheet *sheet = book->getSheet(0);
			if (sheet) {
				size = sheet->lastRow();//=100
				if (sheet->lastCol() != 256) {
					if (size <= 44) {
						for (i = 1; i < sheet->lastRow(); i++) {
							sv = new SinhVien();
							j = 0;
							do {
								switch (j) {
								case 0:
									sv->setMssv(sheet->readStr(i, j));
									j++;
								
								case 1:
									sheet->readStr(i, j);
									sv->setHoVaTen(sheet->readStr(i, j));
									j++;
								
								case 2:
									sv->setCmnd(sheet->readStr(i, j));
									j++;
									
								case 3:
									sv->setNgaySinh(sheet->readStr(i, j));
									j++;
								
								case 4:
									sv->setQueQuan(sheet->readStr(i, j));
									j++;
									
								case 5:
									sv->setEmail(sheet->readStr(i, j));
									j++;
								
								case 6:
									sv->setDiaChi(sheet->readStr(i, j));
									j++;
								
								default:break;
								}

							} while (j < sheet->lastCol());
							listSv.push_back(sv);
						}
					}
					else {
						size = sheet->lastRow();
						do {
							size -= 41;
							if (size > 0) {
								soLuong++;
								dsSoLuong.push_back(soLuong);
							}
							else if (size < 0)
								break;


						} while (true);
						size = sheet->lastRow();
						i = 2;
						int k = 0;
						do {
							Book* bookTemp = xlCreateXMLBook();
							if (bookTemp->load(name.c_str())) {
								Sheet* sheetTemp = bookTemp->getSheet(0);
								for (i; i < 41 * dsSoLuong[k]; i++) {
									sv = new SinhVien();
									j = 0;
									do {
										switch (j) {
										case 0:
											sv->setMssv(sheetTemp->readStr(i, j));
											j++;
											
										case 1:
											sv->setHoVaTen(sheetTemp->readStr(i, j));
											j++;
											
										case 2:
											sv->setCmnd(sheetTemp->readStr(i, j));
											j++;
										
										case 3:
											sv->setNgaySinh(sheetTemp->readStr(i, j));
											j++;
											
										case 4:
											sv->setQueQuan(sheetTemp->readStr(i, j));
											j++;
											
										case 5:
											sv->setEmail(sheetTemp->readStr(i, j));
											j++;
											
										case 6:
											sv->setDiaChi(sheetTemp->readStr(i, j));
											j++;
										
										default:break;
										}
										if (j == 7)
											break;

									} while (j < sheetTemp->lastCol());
									listSv.push_back(sv);
									if (i == 41 * dsSoLuong[k] - 1) {
										bookTemp->release();
										size -= 41;
									}
								}
								k++;
							}
						} while (k < dsSoLuong.size());

						if (size != 0) {
							Book* bookTemp1 = xlCreateXMLBook();
							if (bookTemp1->load(name.c_str())) {
								Sheet* sheetTemp1 = bookTemp1->getSheet(0);
								for (i; i < sheetTemp1->lastRow(); i++) {
									sv = new SinhVien();
									j = 0;
									do {
										switch (j) {
										case 0:
											sv->setMssv(sheetTemp1->readStr(i, j));
											j++;
											
										case 1:
											sv->setHoVaTen(sheetTemp1->readStr(i, j));
											j++;
											
										case 2:
											sv->setCmnd(sheetTemp1->readStr(i, j));
											j++;
											
										case 3:
											sv->setNgaySinh(sheetTemp1->readStr(i, j));
											j++;
											
										case 4:
											sv->setQueQuan(sheetTemp1->readStr(i, j));
											j++;
											
										case 5:
											sv->setEmail(sheetTemp1->readStr(i, j));
											j++;
										
										case 6:
											sv->setDiaChi(sheetTemp1->readStr(i, j));
											j++;
										
										default:break;
										}
										if (j == 7)
											break;
									} while (j < sheet->lastCol());
									listSv.push_back(sv);
								}
								bookTemp1->release();
							}

						}
						book->release();
					}
				}
				else {
					size = sheet->lastRow();//100
					if (size <= 44) {
						for (i = 2; i < sheet->lastRow(); i++) {
							j = 0;
							sv = new SinhVien();
							do {
								switch (j) {
								case 0:
									sv->setMssv(wstring(sheet->readStr(i, j)));
									break;
								case 1:
									sv->setHoVaTen(wstring(sheet->readStr(i, j)));
									break;
								case 2:
									sv->setCmnd(wstring(sheet->readStr(i, j)));
									break;
								case 3:
									sv->setNgaySinh(wstring(sheet->readStr(i, j)));
									break;
								case 4:
									sv->setQueQuan(wstring(sheet->readStr(i, j)));
									break;
								case 5:
									sv->setEmail(wstring(sheet->readStr(i, j)));
									break;
								case 6:
									sv->setDiaChi(wstring(sheet->readStr(i, j)));
									break;
								default:break;
								}
								j++;
								if (j == 7) {
									break;
								}
							} while (true);
							listSv.push_back(sv);
						}
						book->release();
					}
					else {
						size = sheet->lastRow();//size=194
						do {
							size -= 42;
							if (size > 0) {
								soLuong++;
								dsSoLuong.push_back(soLuong);
							}
							else if (size < 0)
								break;


						} while (true);
						size = sheet->lastRow();
						i = 2;
						int k = 0;
						do {
							Book* bookTemp = xlCreateXMLBook();
							if (bookTemp->load(name.c_str())) {
								Sheet* sheetTemp = bookTemp->getSheet(0);
								for (i; i < 42 * dsSoLuong[k]; i++) {
									sv = new SinhVien();
									j = 0;
									do {
										switch (j) {
										case 0:
											sv->setMssv(sheetTemp->readStr(i, j));
											j++;
											
										case 1:
											sv->setHoVaTen(sheetTemp->readStr(i, j));
											j++;
											
										case 2:
											sv->setCmnd(sheetTemp->readStr(i, j));
											j++;
											
										case 3:
											sv->setNgaySinh(sheetTemp->readStr(i, j));
											j++;
											
										case 4:
											sv->setQueQuan(sheetTemp->readStr(i, j));
											j++;
											
										case 5:
											sv->setEmail(sheetTemp->readStr(i, j));
											j++;
											
										case 6:
											sv->setDiaChi(sheetTemp->readStr(i, j));
											j++;
										
										default:break;
										}
										if (j == 7)
											break;

									} while (j < sheetTemp->lastCol());
									listSv.push_back(sv);
									if (i == 42 * dsSoLuong[k] - 1) {
										bookTemp->release();
										size -= 42;
									}
								}
								k++;
							}
						} while (k < dsSoLuong.size());

						if (size != 0) {
							Book* bookTemp1 = xlCreateXMLBook();
							if (bookTemp1->load(name.c_str())) {
								Sheet* sheetTemp1 = bookTemp1->getSheet(0);
								for (i; i < sheetTemp1->lastRow(); i++) {
									sv = new SinhVien();
									j = 0;
									do {
										switch (j) {
										case 0:
											sv->setMssv(sheetTemp1->readStr(i, j));
											j++;
											
										case 1:
											sv->setHoVaTen(sheetTemp1->readStr(i, j));
											j++;
											
										case 2:
											sv->setCmnd(sheetTemp1->readStr(i, j));
											j++;
											
										case 3:
											sv->setNgaySinh(sheetTemp1->readStr(i, j));
											j++;
											
										case 4:
											sv->setQueQuan(sheetTemp1->readStr(i, j));
											j++;
											
										case 5:
											sv->setEmail(sheetTemp1->readStr(i, j));
											j++;
										
										case 6:
											sv->setDiaChi(sheetTemp1->readStr(i, j));
											j++;
											
										default:break;
										}
										if (j == 7)
											break;
									} while (j < sheet->lastCol());
									listSv.push_back(sv);
								}
								bookTemp1->release();
							}

						}
						book->release();
					}
				}
			}

		}
		else {
			//_setmode(_fileno(stdout), _O_U16TEXT);
			//_setmode(_fileno(stdin), _O_U16TEXT);
			//_setmode(_fileno(stdout), _O_TEXT);
			textcolor(6);
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xAF\xAF\xAF\xAF";
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"CẢNH BÁO:File không tìm thấy hoặc không tồn tại";
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "\xB2\xB2" << endl;
			textcolor(7);
			system("pause");
		}


	}
	else {
		textcolor(6);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\t\xB2";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"CẢNH BÁO:Không thể mở file!!!" << endl;
		textcolor(7);
		system("pause");
	}
}
void DanhSach::getDate(int& day, int& month, int& year, wstring date) {
	int dem1 = 0, dem = 0, k = 0;
	wstring sDay, sMonth, sYear;
	for (int i = 0; i < date.length(); i++) {
		dem1++;
		if (date[i] == '/') {
			dem++;
			dem1--;
			if (dem == 1) {
				k = i;
				sDay = date.substr(0, dem1);
				dem1 = 0;
			}
			else {
				if (dem == 2) {
					sMonth = date.substr(k + 1, dem1);
					sYear = date.substr(i + 1, date.length() - 1 - i);
					break;
				}
			}
		}

	}
	wstringstream sso, sso1, sso2;
	sso << sDay;
	sso >> day;
	sso1 << sMonth;
	sso1 >> month;
	sso2 << sYear;
	sso2 >> year;

}
long int DanhSach::getNumS(wstring s) {
	wstringstream sso;
	sso << s;
	long int num;
	sso >> num;
	return num;
}
bool DanhSach::soSanhDate(wstring sDay1, wstring sDay2) {
	int day1, month1, year1, day2, month2, year2;
	this->getDate(day1, month1, year1, sDay1);
	this->getDate(day2, month2, year2, sDay2);
	bool check;
	if (year1 == year2) {
		if (month1 == month2) {
			check = (day1 <= day2) ? true : false;
		}
		else {
			check = month1 < month2 ? true : false;
		}
	}
	else {
		check = year1 < year2 ? true : false;
	}
	return check;
}
void DanhSach::merge(int l, int m, int h, int choose, int choose2) {
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = h - m;
	vector<SinhVien*> L;
	vector<SinhVien*> R;
	for (i = 0; i < n1; i++) {
		L.push_back(this->listSv[l + i]);
	}
	for (j = 0; j < n2; j++) {
		R.push_back(this->listSv[m + j + 1]);
	}
	if (choose == 1) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1) {
				this->listSv[k++] = (this->soSanhDate(L[i]->getNgaySinh(), R[j]->getNgaySinh())) ? L[i++] : R[j++];
			}
			else if (choose2 == 2)
				this->listSv[k++] = (this->soSanhDate(L[i]->getNgaySinh(), R[j]->getNgaySinh())) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 2) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (this->getNumS(L[i]->getCmnd()) <= this->getNumS(R[j]->getCmnd())) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (this->getNumS(L[i]->getCmnd()) <= this->getNumS(R[j]->getCmnd())) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 3) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (this->getNumS(L[i]->getMssv()) <= this->getNumS(R[j]->getMssv())) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (this->getNumS(L[i]->getMssv()) <= this->getNumS(R[j]->getMssv())) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 4) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (wcsicmp(L[i]->getHoVaTen().c_str(),R[j]->getHoVaTen().c_str())<=0) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (wcsicmp(L[i]->getHoVaTen().c_str(), R[j]->getHoVaTen().c_str())<=0) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 5) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (wcsicmp(L[i]->getQueQuan().c_str(), R[j]->getQueQuan().c_str()) <= 0) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (wcsicmp(L[i]->getQueQuan().c_str(), R[j]->getQueQuan().c_str()) <= 0) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 6) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (wcsicmp(L[i]->getEmail().c_str(), R[j]->getEmail().c_str()) <= 0) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (wcsicmp(L[i]->getEmail().c_str(), R[j]->getEmail().c_str()) <= 0) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}
	if (choose == 7) {
		i = 0, j = 0;
		while (i < n1&&j < n2) {
			if (choose2 == 1)
				this->listSv[k++] = (wcsicmp(L[i]->getDiaChi().c_str(), R[j]->getDiaChi().c_str()) <= 0) ? L[i++] : R[j++];
			else if (choose2 == 2)
				this->listSv[k++] = (wcsicmp(L[i]->getDiaChi().c_str(), R[j]->getDiaChi().c_str()) <= 0) ? R[j++] : L[i++];

		}
		while (i < n1) {
			this->listSv[k++] = L[i++];

		}
		while (j < n2) {
			this->listSv[k++] = R[j++];
		}
	}

}
void DanhSach::test() {
	int day, month, year;
	this->getDate(day, month, year, L"1/2/1997");
	cout << day << month << year;
}
void DanhSach::mergeSort(int l, int h, int choose, int choose2) {
	if (l < h) {
		int m = l + (h - l) / 2;
		mergeSort(l, m, choose, choose2);
		mergeSort(m + 1, h, choose, choose2);
		merge(l, m, h, choose, choose2);

	}

}
void DanhSach::sapXep() {
	int l = 0;
	int h = this->listSv.size() - 1;
	int choose;
	int choose2;
	do {
		system("cls");
		_setmode(_fileno(stdout), _O_U16TEXT);
		textcolor(3);
		wcout << L"1-Sắp xếp tăng dần" << endl;
		wcout << L"2-Sắp xếp giảm dần" << endl;
		wcout << L"0-Quay lại" << endl;
		wcout << L"\t>>>>>>>>>>>>>>Nhập lựa chọn : ";
		textcolor(7);
		_setmode(_fileno(stdin), _O_TEXT);
		cin >> choose2;
		if (choose2 == 0)
			break;
		do {
			system("cls");
			textcolor(3);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"1-Sắp xếp theo ngày tháng năm sinh" << endl;
			wcout << L"2-Sắp xếp theo CMND" << endl;
			wcout << L"3-Sắp xếp theo MSSV" << endl;
			wcout << L"4-Sắp xếp theo Họ và Tên" << endl;
			wcout << L"5-Sắp xếp theo Quê quán" << endl;
			wcout << L"6-Sắp xếp theo Email" << endl;
			wcout << L"7-Sắp xếp theo Địa chỉ" << endl;
			wcout << L"0-Quay lại" << endl;
			wcout << L"\t>>>>>>>>>>>>>>Nhập lựa chọn : ";
			textcolor(7);
			_setmode(_fileno(stdin), _O_TEXT);
			cin >> choose;
			if (choose != 0) {
				this->mergeSort(l, h, choose, choose2);

				this->show(choose);
				this->DSchoose = choose;
			}
			else
				break;
		} while (true);
		if (choose2 != 0)
			this->DSchoose2 = choose2;
	} while (true);
}
void DanhSach::addSinhVien() {
	SinhVien* sv = new SinhVien();
	sv->infor();
	this->listSv.push_back(sv);
	if (this->DSchoose != -1 && this->DSchoose2 != -1) {
		this->mergeSort(0, this->listSv.size() - 1, this->DSchoose, this->DSchoose2);
	}
	this->show(this->DSchoose);


}
int DanhSach::getNumC(int a, wstring data) {
	int num;
	int index;
	if (a == 1) {
		index = 0;
		num = 0;
		wstring name;
		for (int i = 0; i < this->listSv.size(); i++) {
			index = this->listSv[i]->getHoVaTen().find(data);
			if (index < this->listSv[i]->getHoVaTen().length()) {
				num++;
			}
		}

		/*for (int i = 0; i < this->listSv.size(); i++) {
			for (int j = this->listSv[i]->getHoVaTen().length() - 1; j >= 0; j--) {
				if (this->listSv[i]->getHoVaTen().at(j) == ' ') {
					name = this->listSv[i]->getHoVaTen().substr(j + 1, this->listSv[i]->getHoVaTen().length() - j - 1);
					if (name == data) {
						num++;
					}
					break;
				}

			}
		}*/
	}
	if (a == 2) {
		index = 0;
		num = 0;
		wstring name;
		for (int i = 0; i < this->listSv.size(); i++) {
			index = this->listSv[i]->getNgaySinh().rfind('/');
			name = this->listSv[i]->getNgaySinh().substr(index + 1, this->listSv[i]->getNgaySinh().length() - index - 1);
			if (!wcsicmp(data.c_str(), name.c_str())) {
				num++;
			}
		}
	}
	return num;
}
void DanhSach::xoa() {
	cin.ignore();
	int num;
	int index;
	bool check;
	wstring name;
	wstring day;
	int choose = 1;
	wstring data;
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\t>>>>>>>>>>>>>>Nhập chuỗi cần xóa: ";
	_setmode(_fileno(stdin), _O_U16TEXT);
	getline(wcin, data);
	for (int i = 0; i < data.length(); i++) {
		if (data[i] >= '0'&&data[i] <= '9') {
			textcolor(4);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"\t\tBạn nhập năm sinh" << endl;
			choose = 2;
			textcolor(7);
			break;
		}
	}
	if (choose == 1) {
		textcolor(4);
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"\t\tBạn nhập một chuỗi" << endl;
		textcolor(7);
	}
	num = this->getNumC(choose, data);
	if (num == 0) {
		textcolor(6);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xAF\xAF\xAF\xAF";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"CẢNH BÁO:Không tìm thấy dữ liệu";
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xB2\xB2" << endl;
		textcolor(7);
		system("pause");
	}
	do {
		if (choose == 1) {
			index = 0;
			check = false;
			for (int i = 0; i < this->listSv.size(); i++) {
				index = this->listSv[i]->getHoVaTen().find(data);
				if (index < this->listSv[i]->getHoVaTen().length()) {
					this->listSv.erase(this->listSv.begin() + i);
					num--;
					_setmode(_fileno(stdout), _O_U16TEXT);
					textcolor(4);
					wcout << L"Đã Xóa" << endl;
					textcolor(7);
					break;
				}
			}
		}
		if (choose == 2) {
			index = 0;
			check = false;
			for (int i = 0; i < this->listSv.size(); i++) {
				index = this->listSv[i]->getNgaySinh().rfind('/');
				name = this->listSv[i]->getNgaySinh().substr(index + 1, this->listSv[i]->getNgaySinh().length() - index - 1);
				if (!wcsicmp(data.c_str(), name.c_str())) {
					this->listSv.erase(this->listSv.begin() + i);
					num--;
					_setmode(_fileno(stdout), _O_U16TEXT);
					textcolor(4);
					wcout << L"Đã Xóa" << endl;
					textcolor(7);
					break;
				}
			}
		}
	} while (num > 0);
	system("pause");

}
void DanhSach::tim() {
	bool check;
	wstring data;
	do {
		_setmode(_fileno(stdout), _O_U16TEXT);
		check = true;
		textcolor(3);
		wcout << L"\t>>>>>>>>>>>>>>Nhập MSSV cần tìm: ";
		cin.ignore();
		textcolor(7);
		_setmode(_fileno(stdin), _O_U16TEXT);
		getline(wcin, data);
		if (data.length() == 0) {
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
			for (int i = 0; i < data.length(); i++) {
				if (data[i]<'0' || data[i]>'9') {
					textcolor(6);
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xAF\xAF\xAF\xAF";
					_setmode(_fileno(stdout), _O_U16TEXT);
					wcout << L"CẢNH BÁO:Thông tin không được bỏ trống";
					_setmode(_fileno(stdout), _O_TEXT);
					cout << "\xB2\xB2" << endl;
					textcolor(7);
					check = false;
					break;
				}

			}
		}


	} while (!check);
	check = false;
	_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i < this->listSv.size(); i++) {
		if (this->listSv[i]->getMssv() == data) {
			check = true;
			textcolor(4);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"\t>>>>>>>>>>>Thông tin sinh viên thứ " << i + 1 << "<<<<<<<<<<<" << endl;
			textcolor(7);
			this->listSv[i]->show(3);
			system("pause");
			break;
		}
	}
	if (!check) {
		textcolor(6);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xAF\xAF\xAF\xAF";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"CẢNH BÁO:Không tìm thấy dữ liệu";
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xB2\xB2" << endl;
		textcolor(7);
		system("pause");
	}
}
void DanhSach::addList() {
	DanhSach* list = new DanhSach();
	list->getList();
	this->listSv.insert(this->listSv.end(), list->listSv.begin(), list->listSv.end());

}
void DanhSach::xuatFile() {
	wstring nameFile;
	this->nameFile(nameFile);
	Book* book = xlCreateXMLBook(); // xlCreateXMLBook() for xlsx
	if (book)
	{
		Sheet* sheet = book->addSheet(L"DanhSach");
		int row = this->listSv.size();
		int col = 7;
		int rowH = 1;

		if (sheet)
		{
			int i = 0;
			do {
				switch (i)
				{
				case 0:
					sheet->writeStr(rowH, i, L"MSSV");
					i++;
					break;
				case 1:
					sheet->writeStr(rowH, i, L"Họ và Tên");
					i++;
					break;
				case 2:
					sheet->writeStr(rowH, i, L"Số CMND");
					i++;
					break;
				case 3:
					sheet->writeStr(rowH, i, L"Ngày Tháng Năm Sinh");
					i++;
					break;
				case 4:
					sheet->writeStr(rowH, i, L"Quê Quán");
					i++;
					break;
				case 5:
					sheet->writeStr(rowH, i, L"Email");
					i++;
					break;
				case 6:
					sheet->writeStr(rowH, i, L"Địa chỉ hiện tại");
					i++;
					break;

				}
			} while (i < col);
			i = rowH + 1;
			row = row + rowH + 1;
			int j;

			for (int k = 0; k < this->listSv.size(); k++) {
				while (i < row) {
					j = 0;
					do {
						switch (j)
						{
						case 0:
							sheet->writeStr(i, j, this->listSv[k]->getMssv().c_str());
							j++;
							
						case 1:
							sheet->writeStr(i, j, this->listSv[k]->getHoVaTen().c_str());
							j++;
							
						case 2:
							sheet->writeStr(i, j, this->listSv[k]->getCmnd().c_str());
							j++;
							
						case 3:
							sheet->writeStr(i, j, this->listSv[k]->getNgaySinh().c_str());
							j++;
							
						case 4:
							sheet->writeStr(i, j, this->listSv[k]->getQueQuan().c_str());
							j++;
							
						case 5:
							sheet->writeStr(i, j, this->listSv[k]->getEmail().c_str());
							j++;
							
						case 6:
							sheet->writeStr(i, j, this->listSv[k]->getDiaChi().c_str());
							j++;
							
						}
					} while (j < col);
					if (j == col) {
						i++;
						break;
					}

				}


			}
			sheet->setAutoFitArea(rowH, 0, sheet->lastRow(), 7); //hnag bat dau , col bat dau,hang cuoi,col cuoi
		}
		book->save(nameFile.c_str());
		book->release();
	}


}
void DanhSach::show(int choose) {
	system("cls");
	textcolor(4);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\t=============Danh Sách Sinh Viên ================" << endl;
	textcolor(7);
	for (int i = 0; i < listSv.size(); i++) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		textcolor(4);
		wcout << L"\t>>>>>>>>>>>Thông tin sinh viên thứ " << i + 1 << "<<<<<<<<<<<" << endl;
		textcolor(7);
		listSv[i]->show(choose);
	}
	system("pause");
}
