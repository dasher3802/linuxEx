#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20000
#define NAME 10

typedef struct _student{
	char name[NAME];
	unsigned char kor;
	float ave;
	unsigned char eng;
	unsigned char math;
	unsigned char germ;
	short tot;
	
}Student;

void init(){
	srand((unsigned)time(NULL));
}

int main(){
	int i;
	char buffer[NAME];
	Student s[SIZE];
	
	init();
	printf("이름\t\t국어\t영어\t수학\t독일어\t총점\t평균\n");
	for(i = 0; i < SIZE; i++){
		sprintf(buffer,"name%05d", i);
		strcpy(s[i].name, buffer);

		s[i].kor = rand()%101;
		s[i].eng = rand()%101;
		s[i].math = rand()%101;
		s[i].germ = rand()%101;
		s[i].tot = 
				s[i].kor +
				s[i].eng +
				s[i].kor +
				s[i].kor;
		s[i].ave = s[i].tot / 4.0;

		printf("%s\t%d\t%d\t%d\t%d\t%d\t%.2f\n",
						s[i].name,
						s[i].kor,
						s[i].eng,
						s[i].math,
						s[i].germ,
						s[i].tot,
						s[i].ave);	
	}

	return 0;
}
