#include "Header.h"

#define vvod(var, msg) \
__asm lea edx, msg \
__asm push edx \
__asm call printf \
__asm pop edx \
__asm lea eax, var \
__asm push eax \
__asm lea ebx, I \
__asm add esp, 4 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    int a, b, c, d, e, f, g, h, l, k, p;
    char I[] = ("%i");
    char A[] = ("\n1. �������� �����\n");
    char B[] = ("2. ������� �����\n");
    char C[] = ("3. ����������� ��� ������\n");
    char F[] = ("4. ������������� �����\n");
    char G[] = ("5. ����� �����\n");
    char H[] = ("6. ������ � ���� ������\n");
    char L[] = ("7. ������ �� ���� ������\n");
    char K[] = ("8. �����\n");
    char P[] = ("�������� ��������: ");
    printf("�������� ������\n�� ����������\"����������������\"\n�� ����: \"�������� �����\"\n\n�������� ������� ������ : \n������: �.�.�. ������ ������� �.�.\n\n");
    system("PAUSE");
    system("cls");
    do {
        vvod(a, A); // 1
        vvod(b, B); // 2
        vvod(c, C); // 3
        vvod(f, F); // 4
        vvod(g, G); // 5
        vvod(h, H); // 6
        vvod(l, L); // 7
        vvod(k, K); // 8
        vvod(p, P);
        choice = inputNumber();

        switch (choice) {
        case 1: // ���������� ������
            input();
            break;
        case 2: // �������� ������
            delete();
            break;
        case 3: // �������� ���� �������
            look();
            break;
        case 4: // �������������� ������
            red();
            break;
        case 5: // ����� ������
            search();
            break;
        case 6: // ������ � ����
            write();
            break;
        case 7: // ������ �� �����
            read();
            break;
        case 8: // �����
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 8);

    return 0;
}