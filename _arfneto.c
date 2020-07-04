#pragma once

#define         _CRT_SECURE_NO_WARNINGS
#define         _INTERVALO_   5000
#define         _ARFNETO_ CH2019
#define         _QUIT_  'q'

#include <windows.h>
#include "stdio.h"
#include "_arfneto.h"

int		cls()
{	// limpa a tela no windows, do jeito oficial
    CONSOLE_SCREEN_BUFFER_INFO		info;
    HANDLE		H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD		origem = { 0,0 };
    int			total;
    if (H == INVALID_HANDLE_VALUE) return -1;
    GetConsoleScreenBufferInfo(H, &info);
    int r = FillConsoleOutputCharacter(H, (TCHAR)' ',
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    int s = FillConsoleOutputAttribute(
        H, info.wAttributes,
        info.dwSize.X * info.dwSize.Y,
        origem, &total);
    SetConsoleCursorPosition(H, origem);
    return 0;
};	// end cls()

void	gotoYX(int linha, int coluna)
{
    static COORD	coord;
    HANDLE			H = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = coluna; coord.Y = linha;
    SetConsoleCursorPosition(H, coord);
    return;
};	// gotoXY

void	mensagem_em_video_reverso(char* mensagem)
{
    HANDLE	H = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO		info;
    GetConsoleScreenBufferInfo(H, &info);
    WORD foreground = info.wAttributes & 0xF;
    WORD background = info.wAttributes & 0xF0;
    text_color(background, foreground);
    printf("%s", mensagem);
    text_color(foreground, background);
    return;
}	// mensagem_em_video_reverso()

void	text_color(int letras, int fundo)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras | (fundo << 4));
}	// text_color
