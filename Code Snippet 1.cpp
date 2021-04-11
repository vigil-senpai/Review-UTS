// test UTS Code Snippet 1

#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

int m = 23;

struct tnode{ 
	char value[10]; 
	int step; 
}*ND[25]; 

int hashing(char value[10]){ 
	
	int key = 0;
	int len = strlen(value);
	for(int i = 0; i < len; i++) {
		key += value[i];
	}
	key = key % m;
	return key;
}

struct tnode *newData(char value[10]){ 
	tnode* ND = (tnode*)malloc(sizeof(tnode));
	strcpy(ND->value, value);
	ND->step = 0;
	
	return ND; 
} 

void insert(char value[10]){ 
	struct tnode *N_Data = newData(value); 
	int key = hashing(value); 
	
	if(ND[key] == NULL) {
		ND[key] = N_Data;
		return;
	}
	
	N_Data->step += 1;
	
	int i = key + 1;
	while(ND[i] != NULL) {
		if(i == key) {
			printf("TABLE IS FULL\n");
			return;
		}
		N_Data->step += 1;
		i += 1;
		i %= m;
	}
	ND[i] = N_Data;
	return;
} 

void view(){ 
	for(int i=0;i<m;i++){ 
	if(ND[i]) printf("[%d]\t%s (%d step(s))\n", i, ND[i]->value, ND[i]->step+1); 
	else printf("[%d]\tNULL\n", i); 
	}
}


int main(){ 
	for(int i=0;i<m;i++) { 
		ND[i] = NULL; 
	} 
 
	insert("AAAAA"); 
	insert("BBBBB"); 
	insert("CCCCC"); 
	insert("AAABB"); 
	insert("BABAA"); 
	insert("BAABA"); 
	insert("BBAAA"); 
	insert("ABBAA");
 
	view(); 
	return 0; 
}
