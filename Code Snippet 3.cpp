// test UTS Code Snippet 3
// thx to andre ganteng

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

struct data 
{ 
 char value[100]; 
 struct data *next; 
}; 

struct data *hashTables[31]; 

int hash(const char *str) 
{ 
 int length = strlen(str); 
 int base = 11; 
 int MOD = 31; 
 int key = 0; 
 for(int i = 0; i < length; i++) 
 { 
 key = (key * base) + (str[i] - 'a' + 1); 
 key = key % MOD; 
 } 
 return (key * base) % MOD; 
} 

void chaining(int idx,const char *str) { 
	struct data *newData = (struct data *) malloc(sizeof(struct data)); 
	strcpy(newData->value, str); 
	newData->next = NULL;
	
	if(hashTables[idx] == NULL) {
		hashTables[idx] = newData;
		return;
	}
	
	data* curr = hashTables[idx];
	while(curr->next != NULL) {
		curr= curr->next;
	}
	curr->next = newData;
} 

void viewAll() { 
	for(int i = 0; i < 31; i++) {
		bool flag = 0;
		data* curr = hashTables[i];
		if(curr != NULL) {
			printf("Index %d: ", i);
			while(curr) {
				if(flag == 0) {
					flag = 1;
					printf("%s", curr->value);
				}
				else {
					printf(" -> %s", curr->value);
				}
				curr = curr->next;
			}
			printf("\n");
		}
	}
}

void popAll() {
	for(int i = 0; i < 31; i++) {
		data* curr = hashTables[i];
		data* temp;
		while(curr != NULL) {
			temp = curr->next;
			free(curr);
			curr = temp;
		}
		hashTables[i] = NULL;
		
	}
}

void init() 
{ 
 for(int i = 0 ; i < 31 ; i++) 
 { 
 hashTables[i] = NULL; 
 } 
}

int main() 
{ 
 char data[][100] = 
 { 
 "roti", 
 "keju", 
 "coklat", 
 "durian", 
 "nasi", 
 "buncis", 
 "ayam", 
 "air", 
 "mie", 
 "tahu", 
 "tempe", 
 "susu", 
 "sapi", 
 "telur", 
 "biskuit", 
 "wortel", 
 "steak", 
 "kentang", 
 "apel", 
 "melon", 
 "ikan" 
 }; 
 
 init(); 
 
 int count = sizeof(data) / sizeof(data[0]); 
 
 for(int i = 0 ; i < count ; i++) 
 { 
 int idx = hash(data[i]); 
 chaining(idx,data[i]); 
 } 
 
 viewAll(); 
 popAll(); 
 viewAll();
 return 0; 
}
