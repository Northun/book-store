#pragma once
#include "framework.h"
#include <windows.h>
#include <string>


unsigned int GetDlgItemUInt(HWND hdlg, int editId, bool& success);
unsigned int GetDlgItemDouble(HWND hDlg, int editId, bool& success);