//
//void operation::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {
//	if (BST_CHECKED == SendDlgItemMessage(hwnd, IDC_AVERAGE, BM_GETCHECK, 0, 0)) {
//		INT Res = 0;
//		for (int i = 0; i < 20; i++) {
//			Res += nArr[i];
//		}
//		Res /= 20;
//		TCHAR str[100];
//		_stprintf_s(str, TEXT("%d"), Res);
//		SetWindowText(hEdit, str);
//	}
//	if (BST_CHECKED == SendDlgItemMessage(hwnd, IDC_SUM, BM_GETCHECK, 0, 0)) {
//		INT Res = 0;
//		for (int i = 0; i < 20; i++) {
//			Res += nArr[i];
//		}
//		TCHAR str[100];
//		_stprintf_s(str, TEXT("%d"), Res);
//		SetWindowText(hEdit, str);
//	}
//	if (BST_CHECKED == SendDlgItemMessage(hwnd, IDC_MULT, BM_GETCHECK,0,0)) {
//		INT Res = 1;
//		for (int i = 0; i < 20; i++) {
//			Res *= nArr[i];
//		}
//		TCHAR str[100];
//		_stprintf_s(str, TEXT("%d"), Res);
//		SetWindowText(hEdit, str);
//	}
//}