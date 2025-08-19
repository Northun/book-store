#include "helper.h"

unsigned int GetDlgItemUInt(HWND hDlg, int editId, bool& success) {
	HWND hctrl = GetDlgItem(hDlg, editId);
	if (!hctrl) {
		success = false;
		return 0;
	}

	int len = GetWindowTextLengthW(hctrl);
	if (len <= 0) {
		success = false;
		return 0;
	}

	std::wstring number(len, L'\0');

	GetWindowTextW(hctrl, &number[0], len + 1);
	
	try {
		unsigned int value = static_cast<unsigned int>(std::stoul(number));
		success = true;
		return value;
	}
	catch (...) {
		success = false;
		return 0;
	}


}

unsigned int GetDlgItemDouble(HWND hDlg, int editId, bool& success) {
	HWND hctrl = GetDlgItem(hDlg, editId);
	if (!hctrl) {
		success = false;
		return 0;
	}

	int len = GetWindowTextLengthW(hctrl);
	if (len <= 0) {
		success = false;
		return 0;
	}

	std::wstring number(len, L'\0');

	GetWindowTextW(hctrl, &number[0], len + 1);

	try {
		double value = static_cast<double>(std::stod(number));
		success = true;
		return value;
	}
	catch (...) {
		success = false;
		return 0;
	}


}


