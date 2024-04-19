#include "Header.h"

struct struc { // ��������� ��� ������
    char name[50]; // ��� ��������
    char surname[50]; // ������� ��������
    char adress[50]; // ����� �������� ��������
};

struct struc adressbook[100]; // ������� ������ �������� ��� ��������
int n = 0; // ���������� ������� � �������� �����
int index;
char n_file[49];
FILE* F;

int inputNumber() {
    int a;
    int input_success = 0;

    while (!input_success) {
        // ������� ������� �����
        if (scanf("%d", &a) != 1) {
            // ���� �� ������� ������� �����
            printf("\n������������ ����! ����������, ���������� �����: ");
            // ������� ������ ����� �� ������������ ��������
            while (getchar() != '\n');
        }
        else {
            // �������� ������� ������ �������� � ������ �����
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            if (c != '\n') {
                printf("\n������������ ����! ����������, ������� ������ �����: ");
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
        fgets(str, maxLength + 2, stdin); // +2 ��� ����� ������� ����� ������ � ������� ����� ������
        if (str[strlen(str) - 1] != '\n') { // ��������, ���� �� ������� ������, ����������� ����� maxLength
            printf("������: ��������� ������ ��������� ������������ �����.\n");
            while (getchar() != '\n'); // ������� ������ ����� �� ������ ��������
            str[0] = '\0'; // �������� ������
        }
        else {
            str[strcspn(str, "\n")] = '\0'; // ������� ������ ����� ������ �� ������
        }
    } while (strlen(str) == 0);
}

void input() { // ����������
    printf("������� ���: ");
    inputString(adressbook[n].name, 50);
    printf("������� �������: ");
    inputString(adressbook[n].surname, 50);
    printf("������� �����: ");
    inputString(adressbook[n].adress, 50);
    n++;
    printf("������ ��������!\n");

}

void delete() { // ��������
    if (n == 0) {
        printf("�������� ����� �����!\n");
        exit;
    }
    printf("������� ������ ������, ������� ����� ������� (�� 1 �� %d): ", n);

    index = inputNumber();
    if (index < 1 || index > n) {
        printf("������������ ������!\n");
        exit;
    }
    else {
        for (int i = index - 1; i < n - 1; i++) {
            strcpy(adressbook[i].name, adressbook[i + 1].name);
            strcpy(adressbook[i].surname, adressbook[i + 1].surname);
            strcpy(adressbook[i].adress, adressbook[i + 1].adress);
        }
        n--;
        printf("����� ������!\n");
    }
}
void look() { // ��������
    if (n == 0) {
        printf("�������� ����� �����!\n");
        exit;
    }
    else {
        printf("��� ������:\n");
        for (int i = 0; i < n; i++) {
            printf("%d. %s %s: %s\n", i + 1, adressbook[i].name, adressbook[i].surname, adressbook[i].adress);
        }
    }
}

void red() { // ��������������
    printf("������� ������ ������ ������ ������ �������� (�� 1 �� %d): ", n);
    index = inputNumber();
    if (index < 1 || index > n) {
        printf("������������ ������!\n");
        exit;
    }
    int what;
    printf("1. �������� ���\n");
    printf("2. �������� �������\n");
    printf("3. �������� �����\n");
    printf("4. �������� ��\n");
    printf("�������� ��������: ");
    what = inputNumber();
    switch (what) {
    case 1: // ��������� �����
        printf("������� ���: ");
        inputString(adressbook[index - 1].name, 50);
        printf("����� ������!\n");
        break;
    case 2: // ��������� �������
        printf("������� �������: ");
        inputString(adressbook[index - 1].surname, 50);
        printf("����� ������!\n");
        break;
    case 3: // ��������� ������
        printf("������� �����: ");
        inputString(adressbook[index - 1].adress, 50);
        printf("����� ������!\n");
        break;
    case 4: // ��������� �����
        printf("������� ���: ");
        inputString(adressbook[index - 1].name, 50);
        printf("������� �������: ");
        inputString(adressbook[index - 1].surname, 50);
        printf("������� �����: ");
        inputString(adressbook[index - 1].adress, 50);
        printf("����� ������!\n");
        break;
    default:
        printf("������������ �����!\n");
        break;
    }
}
void search() { // �����
    if (n == 0) {
        printf("�������� ����� �����!\n");
        exit;
    }
    char search[50];
    printf("������� ���, ������� ��� ����� �������� (����� ������ ��������� ���� ��� ����): ");
    inputString(search, 50);
    printf("���������� ������:\n");

    for (int i = 0; i < n; i++) {
        if (strstr(adressbook[i].name, search) != NULL || strstr(adressbook[i].surname, search) != NULL || strstr(adressbook[i].adress, search) != NULL) {
            printf("%d. %s %s: %s\n", i + 1, adressbook[i].name, adressbook[i].surname, adressbook[i].adress);
        }
    }
}
void write() { // ������ � ����
    int i = 0;
    printf("������� ��� ����� ��� ������ � ���� ������:");
    inputString(n_file, 49);

    if ((F = fopen(n_file, "w")) == NULL)
    {
        printf("\n���������� ������� ��� ������ ����%s\n", n_file);
        _getch();
        return;
    }
    fprintf(F, "%d\n", n);
    for (i = 0; i < n; i++)
        fprintf(F, "%s\n%s\n%s\n", adressbook[i].name, adressbook[i].surname, adressbook[i].adress);

    fclose(F);
    printf("������ ������� ��������!");
}
void read() { // ������ �� �����
    printf("������� ��� ����� ��� �������� ������ �� ����:");
    inputString(n_file, 49);
    if ((F = fopen(n_file, "r+")) == 0)
    {
        printf("���������� ������� ���� ��� ������ %s\n", n_file);
        _getch();
        return;
    }
    fscanf(F, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(F, "%s%s%s", &adressbook[i].name, &adressbook[i].surname, &adressbook[i].adress);
    }
    fclose(F);
    printf("������ ������� ���������!");
}
