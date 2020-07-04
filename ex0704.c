#define _CRT_SECURE_NO_WARNINGS
#include "_arfneto.h"

void prepara_tela();

int main(int argc, char** argv)
{
    struct _INPUT_RECORD linha[40];
    HANDLE H = GetStdHandle(STD_INPUT_HANDLE);
    prepara_tela();
    int N = 0;
    int antes = N;
    while (1)
    {
        char c = 0;
        PeekConsoleInput(H, linha, 40, (LPDWORD)&N);
        if (N != antes)
        {   // se mudou algo nessa leitura
            gotoYX(10, 20);
            for (int i = 0; i < N; i += 1)
            {
                if (linha[i].EventType == KEY_EVENT)
                {
                    if (linha[i].Event.KeyEvent.bKeyDown)
                    {
                        c = linha[i].Event.KeyEvent.uChar.AsciiChar;
                        if ((isprint(c)) && (c != ' '))
                            printf("%4c", c);
                        else
                            printf("%4d'", c);
                    };	// if
                    if (c == '.')
                    {
                        Beep(600, 50);
                        FlushConsoleInputBuffer(H);
                        prepara_tela();
                        c = 0;
                    }
                    else
                        if (c == '/')
                        {
                            printf("\n\n\n\n");
                            return 0;
                        }
                };
            };
        };
        gotoYX(11, 8);
        Sleep(1000);
    };  // while()
    return 0;
};

void prepara_tela()
{
    cls();
    gotoYX(12, 8);
    mensagem_em_video_reverso("'.' limpa tudo, '/' termina");
    gotoYX(10, 8);
    mensagem_em_video_reverso("Para ler:");
};
// fim