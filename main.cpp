#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include<windowsx.h>
#include<ctime>
HWND hEdit, hList , hDialog;

INT MIN = -10, MAX = 10;
INT nArr[20];
BOOL isStarted = FALSE;

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpszCmdLine, int nCmdShow) {
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wp, LPARAM lp) {
	switch (message) {
		case WM_INITDIALOG:
		{
			hEdit = GetDlgItem(hwnd, IDC_EDIT1);
			hList = GetDlgItem(hwnd, IDC_LIST1);
			
			
			return TRUE;
		}
		case WM_CLOSE:
		{
			EndDialog(hwnd, 0);
		}
		case WM_COMMAND:
		{
			if (LOWORD(wp) == IDC_START) {
				isStarted = TRUE;
				srand(time(NULL));
				TCHAR buff[4];
				INT num = 0;
				for (int i = 0; i < 20; i++) {
					num = rand() % (MAX - MIN) + MIN;
					if (num == 0) {
						i--;
						continue;
					}
					_stprintf_s(buff, TEXT("%d"), num);
					nArr[i] = num;
					SendMessage(hList, LB_ADDSTRING, 0, LPARAM(buff));
				}
			}
			if (isStarted == 1) {
				if (LOWORD(wp) == IDC_AVERAGE) {
					DOUBLE Res = 0;
					for (int i = 0; i < 20; i++) {
						Res += nArr[i];
					}
					Res /= 20;
					TCHAR str[100];
					_stprintf_s(str, TEXT("%f"), Res);
					SetWindowText(hEdit, str);
				}
				if (LOWORD(wp) == IDC_SUM) {
					INT Res = 0;
					for (int i = 0; i < 20; i++) {
						Res += nArr[i];
					}
					TCHAR str[100];
					_stprintf_s(str, TEXT("%d"), Res);
					SetWindowText(hEdit, str);
				}
				if (LOWORD(wp) == IDC_MULT) {
					INT Res = 1;
					for (int i = 0; i < 20; i++) {
						Res *= nArr[i];
					}
					TCHAR str[100];
					_stprintf_s(str, TEXT("%d"), Res);
					SetWindowText(hEdit, str);
				}
			}
		}
	}
	return FALSE;
}