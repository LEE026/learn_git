#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define SUBJECT_NUM 3



struct Subject { // ���� ����
	char SubName[30]; // �����̸�
	int Hakjum; // ��������
	char Grade[10]; // ������
	float GPA; // ���� ����
};
struct Student {
	// �л� ����
	char StdName[30]; // �л� �̸�
	int Hakbun; // �й�
	Subject Sub[SUBJECT_NUM]; // ����
	float AveGPA; // ������ ��� ����
};


void student_input(Student* student);
//=================================
void printmenu();//3
void calcGPA(Subject& Sub);//4
float CalcAveGPA(Subject* Sub);//5
void PrintAllData(const Student* pSt, int StudentNum);//6
void PrintOneData(const Student& rSt);//7
Student* StdSearch(Student *pSt, int StudentNum);//8

int main(void) {
	int menu;
	Student student[2];
	Student* SearchStd;
	int StdNum = 2;


	while (1)
	{
		printmenu();
		cout << "���ϴ� ����� �Է��ϼ��� : ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
			student_input(student);
			break;

		case 2:
			PrintAllData(student, StdNum);
			break;

		case 3:
			SearchStd = StdSearch(student, StdNum);
			if (SearchStd!=NULL)
			{
				PrintOneData(*SearchStd);
			}
			else
			{
				cout << "���� �л��Դϴ�." << endl << endl;
			}
			break;

		case 4:
			return 0;
		default:
			break;
		}

	}

}

void printmenu() {
	cout << "=====�޴�=====" << endl;
	cout << "1. �л� ���� �Է�" << endl;
	cout << "2. ��ü �л� ���� ����" << endl;
	cout << "3. �л� �̸� �˻�" << endl;
	cout << "4. ���α׷� ����" << endl << endl;
}

void student_input(Student* student) {
	for (int i = 0; i < 2; i++) {
		cout << "* " << i + 1 << " ��° �л��� �̸��� �й��� �Է��ϼ���." << endl;
		cout << "�̸� : ";	cin >> student[i].StdName;
		cout << "�й� : ";	cin >> student[i].Hakbun;
		cout << endl << endl << endl;

		cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���." << endl;

		for (int j = 0; j < SUBJECT_NUM; j++)
		{
			cout << "������� : ";	cin >> student[i].Sub[j].SubName;
			cout << "���������� : ";	cin >> student[i].Sub[j].Hakjum;
			cout << "������(A+ ~ F) : ";	cin >> student[i].Sub[j].Grade;
			cout << endl;

			//�������� ���
			calcGPA(student[i].Sub[j]);

		}

		//�������
		student[i].AveGPA = CalcAveGPA(student[i].Sub);
		cout << endl << endl << endl;

	}
}

void calcGPA(Subject& Sub) {
	if (strcmp(Sub.Grade, "A+") == 0)
		Sub.GPA = Sub.Hakjum * 4.5;

	else if (strcmp(Sub.Grade, "A") == 0 || strcmp(Sub.Grade, "A0") == 0)
		Sub.GPA = Sub.Hakjum * 4.0;

	else if (strcmp(Sub.Grade, "B+") == 0)
		Sub.GPA = Sub.Hakjum * 3.5;

	else if (strcmp(Sub.Grade, "B") == 0 || strcmp(Sub.Grade, "B0") == 0)
		Sub.GPA = Sub.Hakjum * 3.0;

	else if (strcmp(Sub.Grade, "C+") == 0)
		Sub.GPA = Sub.Hakjum * 2.5;

	else if (strcmp(Sub.Grade, "C") == 0 || strcmp(Sub.Grade, "C0") == 0)
		Sub.GPA = Sub.Hakjum * 2.0;

	else if (strcmp(Sub.Grade, "D+") == 0)
		Sub.GPA = Sub.Hakjum * 1.5;

	else if (strcmp(Sub.Grade, "D") == 0 || strcmp(Sub.Grade, "D0") == 0)
		Sub.GPA = Sub.Hakjum * 1.0;

	else if (strcmp(Sub.Grade, "F") == 0)
		Sub.GPA = Sub.Hakjum * 0.0;

}

float CalcAveGPA(Subject* Sub) {
	float sum=0;
	for (int i = 0; i < SUBJECT_NUM; i++)
	{
		sum += Sub[i].GPA;
	}
	
	return sum / SUBJECT_NUM;
}

void PrintAllData(const Student* pSt, int StudentNum) {
	cout.width(20);
	cout << "��ü �л����� ����" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < StudentNum; i++)
	{
		PrintOneData(pSt[i]);

	}
}

void PrintOneData(const Student& rSt) {
	cout << "�̸� : " << rSt.StdName << " �й� : " << rSt.Hakbun << endl;
	cout << "==================================================================" << endl;
	cout.width(10);
	cout << "�����";
	cout.width(10);
	cout << "��������";
	cout.width(10);
	cout << "������";
	cout.width(10);
	cout << "��������" << endl;
	cout << "==================================================================" << endl;
	for (int j = 0; j < SUBJECT_NUM; j++) {
		cout.width(10);
		cout << rSt.Sub[j].SubName;
		cout.width(10);
		cout << rSt.Sub[j].Hakjum;
		cout.width(10);
		cout << rSt.Sub[j].Grade;
		cout.width(10);
		cout.precision(2); cout << fixed;
		cout << rSt.Sub[j].GPA << endl;
	}
	cout << "==================================================================" << endl;
	cout.width(30);
	cout << "�������";
	cout.width(10);
	cout.precision(2); cout << fixed;
	cout << rSt.AveGPA << endl << endl;
}

Student* StdSearch(Student *pSt, int StudentNum) {
	char Name[30];
	cout << "�˻� �� �л� �̸� : "; cin >> Name;

	for (int i = 0; i < StudentNum; i++)
	{
		if (strcmp(Name, pSt[i].StdName) == 0) {
			return pSt + i;
		}
	}
	return NULL;
}