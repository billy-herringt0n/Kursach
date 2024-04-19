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
    char A[] = ("\n1. Добавить адрес\n");
    char B[] = ("2. Удалить адрес\n");
    char C[] = ("3. Просмотреть все адреса\n");
    char F[] = ("4. Редактировать адрес\n");
    char G[] = ("5. Найти адрес\n");
    char H[] = ("6. Запись в базу данных\n");
    char L[] = ("7. Чтение из базы данных\n");
    char K[] = ("8. Выход\n");
    char P[] = ("Выберите действие: ");
    printf("Курсовая работа\nПо дисциплине\"Программирование\"\nНа тему: \"Адресная книга\"\n\nВыполнил студент группы : \nПринял: к.т.н. доцент Токарев А.Н.\n\n");
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
        case 1: // добавление адреса
            input();
            break;
        case 2: // удаление адреса
            delete();
            break;
        case 3: // просмотр всех адресов
            look();
            break;
        case 4: // редактирование адреса
            red();
            break;
        case 5: // поиск адреса
            search();
            break;
        case 6: // запись в файл
            write();
            break;
        case 7: // чтение из файла
            read();
            break;
        case 8: // выход
            system("cls");
            printf("До свидания!\n");
            break;
        default:
            printf("Некорректный выбор!\n");
            break;
        }
    } while (choice != 8);

    return 0;
}