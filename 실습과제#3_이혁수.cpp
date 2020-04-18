#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#define SUBJECT_NUM 3



struct Subject { // 과목 정보
	char SubName[30]; // 과목이름
	int Hakjum; // 과목학점
	char Grade[10]; // 과목등급
	float GPA; // 과목 평점
};
struct Student {
	// 학생 정보
	char StdName[30]; // 학생 이름
	int Hakbun; // 학번
	Subject Sub[SUBJECT_NUM]; // 과목
	float AveGPA; // 교과목 평균 평점
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
		cout << "원하는 기능을 입력하세요 : ";
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
				cout << "없는 학생입니다." << endl << endl;
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
	cout << "=====메뉴=====" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 학생 성적 보기" << endl;
	cout << "3. 학생 이름 검색" << endl;
	cout << "4. 프로그램 종료" << endl << endl;
}

void student_input(Student* student) {
	for (int i = 0; i < 2; i++) {
		cout << "* " << i + 1 << " 번째 학생의 이름과 학번을 입려하세요." << endl;
		cout << "이름 : ";	cin >> student[i].StdName;
		cout << "학번 : ";	cin >> student[i].Hakbun;
		cout << endl << endl << endl;

		cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;

		for (int j = 0; j < SUBJECT_NUM; j++)
		{
			cout << "교과목명 : ";	cin >> student[i].Sub[j].SubName;
			cout << "과목학점수 : ";	cin >> student[i].Sub[j].Hakjum;
			cout << "과목등급(A+ ~ F) : ";	cin >> student[i].Sub[j].Grade;
			cout << endl;

			//과목평점 계산
			calcGPA(student[i].Sub[j]);

		}

		//평균평점
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
	cout << "전체 학생성적 보기" << endl;
	cout << "==================================================================" << endl;
	for (int i = 0; i < StudentNum; i++)
	{
		PrintOneData(pSt[i]);

	}
}

void PrintOneData(const Student& rSt) {
	cout << "이름 : " << rSt.StdName << " 학번 : " << rSt.Hakbun << endl;
	cout << "==================================================================" << endl;
	cout.width(10);
	cout << "과목명";
	cout.width(10);
	cout << "과목학점";
	cout.width(10);
	cout << "과목등급";
	cout.width(10);
	cout << "과목평점" << endl;
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
	cout << "평균평점";
	cout.width(10);
	cout.precision(2); cout << fixed;
	cout << rSt.AveGPA << endl << endl;
}

Student* StdSearch(Student *pSt, int StudentNum) {
	char Name[30];
	cout << "검색 할 학생 이름 : "; cin >> Name;

	for (int i = 0; i < StudentNum; i++)
	{
		if (strcmp(Name, pSt[i].StdName) == 0) {
			return pSt + i;
		}
	}
	return NULL;
}