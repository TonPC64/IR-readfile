#include<iostream>

using namespace std;
void search(char text[],int n,char pat[],int m);
int main(int argc, char *argv[]){
		

	char szBuf[2048];
	int c,i;
	FILE *fp;
	char fname[20], pat[10], method[2];
	
	
	switch(argc){
	case 1: 
		break;
	case 4: strcpy(method,argv[3]); 
		
	case 3: strcpy(pat,argv[2]); 
		
	case 2: strcpy(fname,argv[1]); 
		break;
	default :
		printf("usage:testfile [filename] pettern method \n");
		return 0;
	}
	
	if((fp=fopen(fname, "rb"))==NULL){
		printf("Error:can't open file.\n");
		return 0;
	}
	do{
		i=0;
		while((i<2048)&&((c=getc(fp))!=EOF)){
			szBuf[i]=c;
			//printf("%c",szBuf[i]);
			i++;
			
		}
	}while(c!=EOF);
	fclose(fp);
	printf("Pattern = %s\n", pat);
	printf("Method = %s\n", method);
	if(strcmp(method, "a")==0)
		search(szBuf,i,pat,strlen(pat));
	
	else printf("Good Bye\n");
	return 0;
}


void search(char text[],int n,char pat[],int m){
	int i=0, j, k, lim, count=0;

	printf("text = ");
	while(i<n){
	printf("%c",text[i]);
	i++;
	}
	i=0;
	printf("\npat =");
	while(i<m){
	printf("%c",pat[i]);
	i++;
	}
	printf("\n");
	lim = n-m+1;

	for(i=0;i<=lim-1;i++){
		k = i;
		for(j=0 ; j<= m-1 && text[k] ==pat[j]; j++){
			k++;
			
		}
		
		if(j > m-1){
			printf("Found at %d \n",(i));
			
		}
		else {
		count++;
		}
		
	}
	printf("count = %d\n",count);
}
