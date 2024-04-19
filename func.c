#include "Header.h"

struct struc { // структура для адреса
    char name[50]; // имя контакта
    char surname[50]; // фамилия контакта
    char adress[50]; // номер телефона контакта
};

struct struc adressbook[100]; // создаем массив структур для адрресов
int n = 0; // количество адресов в адресной книге
int index;
char n_file[49];
FILE* F;

int inputNumber() {
    int a;
    int input_success = 0;

    while (!input_success) {
        // Попытка считать число
        if (scanf("%d", &a) != 1) {
            // Если не удалось считать число
            printf("\nНекорректный ввод! Пожалуйста, попробуйте снова: ");
            // Очистка буфера ввода от некорректных символов
            while (getchar() != '\n');
        }
        else {
            // Проверка наличия лишних символов в буфере ввода
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            if (c != '\n') {
                printf("\nНекорректный ввод! Пожалуйста, введите только число: ");
            }
            else {
                input_success = 1;
            }
        }
    }

    return a;
}

void inputString(char* str, int maxLength) {
    do {
        fgets(str, maxLength + 2, stdin); // +2 для учета символа новой строки и символа конца строки
        if (str[strlen(str) - 1] != '\n') { // Проверка, была ли введена строка, превышающая длину maxLength
            printf("Ошибка: введенная строка превышает максимальную длину.\n");
            while (getchar() != '\n'); // Очистка буфера ввода от лишних символов
            str[0] = '\0'; // Обнуляем строку
        }
        else {
            str[strcspn(str, "\n")] = '\0'; // Удаляем символ новой строки из строки
        }
    } while (strlen(str) == 0);
}

void input() { // добавление
    printf("Введите имя: ");
    inputString(adressbook[n].name, 50);
    printf("Введите фамилию: ");
    inputString(adressbook[n].surname, 50);
    printf("Введите адрес: ");
    inputString(adressbook[n].adress, 50);
    n++;
    printf("Адресс добавлен!\n");

}

void delete() { // удаление
    if (n == 0) {
        printf("Адресная книга пуста!\n");
        exit;
    }
    printf("Введите индекс адреса, который нужно удалить (от 1 до %d): ", n);

    index = inputNumber();
    if (index < 1 || index > n) {
        printf("Некорректный индекс!\n");
        exit;
    }
    else {
        for (int i = index - 1; i < n - 1; i++) {
            strcpy(adressbook[i].name, adressbook[i + 1].name);
            strcpy(adressbook[i].surname, adressbook[i + 1].surname);
            strcpy(adressbook[i].adress, adressbook[i + 1].adress);
        }
        n--;
        printf("Адрес удален!\n");
    }
}
void look() { // просмотр
    if (n == 0) {
        printf("Адресная книга пуста!\n");
        exit;
    }
    else {
        printf("Все адреса:\n");
        for (int i = 0; i < n; i++) {
            printf("%d. %s %s: %s\n", i + 1, adressbook[i].name, adressbook[i].surname, adressbook[i].adress);
        }
    }
}

void red() { // редактирование
    printf("Введите индекс адреса котрый хотите изменить (от 1 до %d): ", n);
    index = inputNumber();
    if (index < 1 || index > n) {
        printf("Некорректный индекс!\n");
        exit;
    }
    int what;
    printf("1. Поменять имя\n");
    printf("2. Поменять фамилию\n");
    printf("3. Поменять адрес\n");
    printf("4. Поменять всё\n");
    printf("Выберите действие: ");
    what = inputNumber();
    switch (what) {
    case 1: // изменение имени
        printf("Введите имя: ");
        inputString(adressbook[index - 1].name, 50);
        printf("Адрес изменён!\n");
        break;
    case 2: // изменение фамилии
        printf("Введите фамилию: ");
        inputString(adressbook[index - 1].surname, 50);
        printf("Адрес изменён!\n");
        break;
    case 3: // изменение адреса
        printf("Введите адрес: ");
        inputString(adressbook[index - 1].adress, 50);
        printf("Адрес изменён!\n");
        break;
    case 4: // изменение всего
        printf("Введите имя: ");
        inputString(adressbook[index - 1].name, 50);
        printf("Введите фамилию: ");
        inputString(adressbook[index - 1].surname, 50);
        printf("Введите адрес: ");
        inputString(adressbook[index - 1].adress, 50);
        printf("Адрес изменён!\n");
        break;
    default:
        printf("Некорректный выбор!\n");
        break;
    }
}
void search() { // поиск
    if (n == 0) {
        printf("Адресная книга пуста!\n");
        exit;
    }
    char search[50];
    printf("Введите имя, фамилию или адрес человека (можно ввести несколько букв или цифр): ");
    inputString(search, 50);
    printf("Результаты поиска:\n");

    for (int i = 0; i < n; i++) {
        if (strstr(adressbook[i].name, search) != NULL || strstr(adressbook[i].surname, search) != NULL || strstr(adressbook[i].adress, search) != NULL) {
            printf("%d. %s %s: %s\n", i + 1, adressbook[i].name, adressbook[i].surname, adressbook[i].adress);
        }
    }
}
void write() { // запись в файл
    int i = 0;
    printf("Введите имя файла для записи в него данных:");
    inputString(n_file, 49);

    if ((F = fopen(n_file, "w")) == NULL)
    {
        printf("\nНевозможно открыть для записи файл%s\n", n_file);
        _getch();
        return;
    }
    fprintf(F, "%d\n", n);
    for (i = 0; i < n; i++)
        fprintf(F, "%s\n%s\n%s\n", adressbook[i].name, adressbook[i].surname, adressbook[i].adress);

    fclose(F);
    printf("Данные успешно записаны!");
}
void read() { // чтение из файла
    printf("Введите имя файла для загрузки данных из него:");
    inputString(n_file, 49);
    if ((F = fopen(n_file, "r+")) == 0)
    {
        printf("Невозможно открыть файл для чтения %s\n", n_file);
        _getch();
        return;
    }
    fscanf(F, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(F, "%s%s%s", &adressbook[i].name, &adressbook[i].surname, &adressbook[i].adress);
    }
    fclose(F);
    printf("Данные успешно прочитаны!");
}
