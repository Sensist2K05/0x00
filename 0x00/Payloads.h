#pragma once
#include "0x00.h"

INT w = GetSystemMetrics(0);
INT h = GetSystemMetrics(1);

RECT wRect;
POINT wPt[3];

DWORD WINAPI GDIPayload1(LPVOID Void)
{
	HDC desk = GetDC(0);
	while (1) {
		desk = GetDC(0);
		SeedXorshift32(__rdtsc());
		GetWindowRect(GetDesktopWindow(), &wRect);
		wPt[0].x = wRect.left - 90;
		wPt[0].y = wRect.top + 90;
		wPt[1].x = wRect.right - 90;
		wPt[1].y = wRect.top - 90;
		wPt[2].x = wRect.left + 90;
		wPt[2].y = wRect.bottom + 90;
		PlgBlt(desk, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
		Sleep(10);
	}
}

DWORD WINAPI GDIPayload2(LPVOID Void)
{
        HDC hdc = GetDC(0);
        INT i = 0;
        INT ws = w / 14;
	INT hs = h / 14;
        while (true) {
            HDC mdc = CreateCompatibleDC(hdc);
            RGBQUAD *rgb;
            BITMAPINFO lpbmi = bmicrt(w, h);
            HSV hsv; // HUE. SATURATION. VIBRANCE.
            HBITMAP hbit = CreateDIBSection(hdc, &lpbmi, DIB_RGB_COLORS, (DIBSECTIONBITS)&rgb, NULL, 0);
            SelectObject(mdc, hbit); 
            StretchBlt(mdc, 0, 0, w, h, hdc, 0, 0, w, h, SRCCOPY); 
            DOUBLE angle = 2.f;
            for (INT x = 0; x < w; x++) {
                for (INT y = 0; y < h; y++) {
                    INT INDEX = y * w + x;
                    RGBQUAD rgb2 = rgb[INDEX];
                    hsv = rgbQuadToHSV(rgb2);
   		    int cx = abs(x - (ws / 2));
		    int cy = abs(y - (hs / 2));
		    int zx = cos(angle) * cx - sin(angle) * cy;
		    int zy = sin(angle) * cx + cos(angle) * cy;
                    int fx = (zx + i) & (zy + i);
                    hsv.h = fmod((fx / 500.f) + y / h * .02f, 1);
                    hsv.s = 1.f;
                    rgb[INDEX] = hsvToRGB(hsv);
                }
            }
            i++; angle += 1.f;
            StretchBlt(hdc, 0, 0, w, h, mdc, 0, 0, w, h, SRCCOPY);
            Sleep(10);
        }
        ReleaseDC(0, hdc);
}

DWORD WINAPI GDIPayload3(LPVOID Void)
{
    INT ws, hs;
    while (true) {
        HDC hdc = GetDC(0);
        int sel = rand() % 1 + 1;
        double wave = 0; 
        double i = 0;
        if (sel == 1) {
            ws = 0, hs = rand() % h;
            for (; ws < w; ws += 3) {
                DrawIcon(hdc, ws, hs + wave * cos(i), LoadIcon(0, MAKEINTRESOURCE(32512 + (rand() % 7))));
                i += 1;
                wave += 1;
                Sleep(10);
            }
        }
        ReleaseDC(0, hdc);
    }
}
