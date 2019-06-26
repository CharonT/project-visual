#include"DanhSach.h"
void menu() {
	int choose;
	DanhSach* ds = new DanhSach();
	do
	{
		//_setmode(_fileno(stdout), _O_U16TEXT);
		//_setmode(_fileno(stdin), _O_U16TEXT);
		//_setmode(_fileno(stdout), _O_TEXT);
		system("cls");
		textcolor(228);
		gotoxy(35, 1);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L" HỌC PHẦN : THỰC TẬP CƠ SỞ";
		_setmode(_fileno(stdout), _O_TEXT);
		cout<< " \xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE" << endl;
		gotoxy(35, 2);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L" GIẢNG VIÊN : TÔ BÁ LÂM";
		_setmode(_fileno(stdout), _O_TEXT);
		cout<< "    \xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE" << endl;
		gotoxy(35, 4);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L" \t NHÓM :  \t   ";
		_setmode(_fileno(stdout), _O_TEXT);
		cout<<"\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE" << endl;
		gotoxy(35, 5);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L" 1)BÙI MINH TÚ-1651150032 ";
		_setmode(_fileno(stdout), _O_TEXT);
		cout<< "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE" << endl;
		gotoxy(35, 6);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE";
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L" 2)TRẦN PHƯỚC THÀNH-1651150034";
		_setmode(_fileno(stdout), _O_TEXT);
		cout<< "\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE\xCE" << endl;
		gotoxy(39, 8);
		textcolor(4);
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC" << endl;
		gotoxy(37, 9);
		cout << "\xEC\xEC\t\t\t\t\t\t       \xEC\xEC" << endl;
		gotoxy(31, 10);
		cout << "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\t     ";
		textcolor(14);
		cout << "MENU";
		textcolor(4);
		cout << "  \t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" << endl;
		gotoxy(37, 11);
		cout << "\xEC\xEC\t\t\t\t\t\t       \xEC\xEC" << endl;
		gotoxy(39, 12);
		cout << "\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC\xEC" << endl;

		textcolor(14);
		gotoxy(25, 13);
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"1 - ĐỌC FILE DANH SÁCH SINH VIÊN";
		gotoxy(25, 14);
		wcout << L"2 - SẮP XẾP SINH VIÊN";
		gotoxy(25, 15);
		wcout << L"3 - THÊM MỘT SINH VIÊN VÀO DANH SÁCH";
		gotoxy(25, 16);
		wcout << L"4 - XÓA MỘT HOẶC NHIỀU SINH VIÊN";
		gotoxy(25, 17);
		wcout << L"5 - TÌM KIẾM SINH VIÊN";
		gotoxy(25, 18);
		wcout << L"6 - MERGE MỘT DANH SÁCH SINH VIÊN MỚI";
		gotoxy(25, 19);
		wcout << L"7 - XUẤT RA FILE EXCEL";
		gotoxy(25, 20);
		wcout << L"8 - XUẤT DANH SÁCH SINH VIÊN RA MÀN HÌNH CONSOLE";
		gotoxy(25, 21);
		wcout << L"0 - THOÁT";
		gotoxy(30, 22);
		wcout << L"Nhập lựa chọn : "; 
		_setmode(_fileno(stdin), _O_TEXT);
		cin >> choose;
		textcolor(7);
		if (choose == 0) {
			system("cls");
			gotoxy(30, 1);
			textcolor(14);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L">>>>>>>>>>>>>>>>>>>>>>>ANH YÊU EM LINH<<<<<<<<<<<<<<<<<<<<<<"<<endl;
			textcolor(7);
			ds->~DanhSach();
			break;
		}
		switch (choose) {
		case 1:
			ds->getList();
			break;
		case 2:
			ds->sapXep();
			break;
		case 3:
			ds->addSinhVien();
			break;
		case 4:
			ds->xoa();
			break;
		case 5:
			ds->tim();
			break;
		case 6:
			ds->addList();
			break;
		case 7:
			ds->xuatFile();
			break;
		case 8:
			ds->show(0);
			break;
		default:
			gotoxy(30, 23);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"Bạn nhập sai lựa chọn"<<endl;
			system("pause");
			break;
		}
	} while (choose!=0);
}


int main() {
	menu();
	system("pause");
	return 0;
} 