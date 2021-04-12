// test UTS Code Snippet 4

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
struct data { 
 int date, month, year; 
 char name[100]; 
 struct data *next, *prev; 
}*head=NULL, *tail=NULL, *temp=NULL; 

void popHead(); 
void popAll(); 
void printAll(); 
void addData(); 
void priorityPush(int, int, int, char*); 
int getMonthNumber(char*); 
char* getMonthName(int); 
long getDateNumber(int, int, int); 
struct data *createNode(int, int, int, char*); 
long getDateNumber(int date, int month, int year) { 
 return (long)(year*10000)+(month*100)+date; 
} 

int getMonthNumber(char *month) { 
 if(!strcmp(month, "january"))return 1; 
 if(!strcmp(month, "february"))return 2; 
 if(!strcmp(month, "march"))return 3; 
 if(!strcmp(month, "april"))return 4; 
 if(!strcmp(month, "may"))return 5; 
 if(!strcmp(month, "june"))return 6; 
 if(!strcmp(month, "july"))return 7; 
 if(!strcmp(month, "august"))return 8; 
 if(!strcmp(month, "september"))return 9; 
 if(!strcmp(month, "october"))return 10; 
 if(!strcmp(month, "november"))return 11; 
 if(!strcmp(month, "december"))return 12; 
}

char* getMonthName(int month) { 
 switch(month) { 
 case 1: return "january"; 
 case 2: return "february"; 
 case 3: return "march"; 
 case 4: return "april"; 
 case 5: return "may"; 
 case 6: return "june"; 
 case 7: return "july"; 
 case 8: return "august"; 
 case 9: return "september"; 
 case 10: return "october"; 
 case 11: return "november"; 
 case 12: return "december"; 
 } 
} 

void popAll() { 
 while(head) 
 popHead();
} 

void printAll() { 
 temp = head; 
 while(temp != NULL) { 
 printf("%d %s %d - %s\n", temp->date, 
getMonthName(temp->month), temp->year, temp->name); 
 temp = temp->next; 
 } 
} 

void addData() { 
 int date, year; 
 char month[100], name[100]; 
 scanf("%d %s %d - %[^\n]", &date, &month, &year, &name); 
getchar(); 
 priorityPush(date, getMonthNumber(month), year, name); 
} 

struct data *createNode(int date, int month, int year, char *name) {
	temp = (data*)malloc(sizeof(data));
	temp->date = date;
	temp->month = month;
	temp->year = year;
	strcpy(temp->name, name);
	temp->next = NULL;
	temp->prev = NULL;
	
	return temp;
} 

void priorityPush(int date, int month, int year, char *name) { 
	data* curr = createNode(date, month, year, name);
	if(head == NULL) {
		head = tail = curr;
		return;
	}
	if(year < head->year || (year <= head->year && month < head->month) || (year <= head->year && month <= head->month && date < head->date)) {
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	else {
		data* temp = head;
		while(temp->next != NULL && (temp->next->year < year || (temp->next->year <= year && temp->next->month < month) || (temp->next->year <= year && temp->next->month <= month && temp->next->date < date))) {
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
		temp->next->prev = curr;
		curr->prev = temp;
	}
} 
void popHead() { 
	if(head == NULL) {
		return;
	}
	if(head->next ==  NULL) {
		free(head);
		head = tail = NULL;
		return;
	}
	data* temp = head;
	head = head->next;
	free(temp);
	temp->next = NULL;
	temp->prev = NULL;
	head->prev = NULL;
	return;
}

int main() { 
 int totalPatients, totalCure; 
 scanf("%d %d", &totalPatients, &totalCure); getchar(); 
 for(int i=0; i<totalPatients; i++) 
 addData(); 
 
 for(int i=0; i<totalCure; i++) 
 popHead();
  if(totalPatients < totalCure || totalPatients == totalCure) 
 printf("All patients get the cure, %d cure left\n", totalCure - totalPatients); 
 else if(totalPatients > totalCure) 
 printf("Need %d more cure\n", totalPatients - totalCure); 
 
 printAll(); 
 popAll(); 
}

/*
7 5 
2 august 1970 - Virginia Walter 
14 february 1980 - Ronald Rich 
18 december 1965 - Camron 
30 july 1990 - Rosie Hawkins 
1 august 1970 - Yvonne 
28 january 1985 - Safa Daly 
4 november 1991 - Lorcan Craig Montes
*/
