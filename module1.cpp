#include  "framework.h"
#include "resource1.h"

WCHAR buf[256];

static INT_PTR CALLBACK work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK)
        {
            GetDlgItemText(hDlg, IDC_EDIT1, buf, 250);
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void Func_MOD1(HINSTANCE hInst,HWND hWnd,WCHAR* dest)
{
    if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, work1) == 1)
    {
        lstrcpyW(dest, buf);
        InvalidateRect(hWnd, NULL, TRUE);
    } 
}