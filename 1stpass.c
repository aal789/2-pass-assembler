#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
FILE *input,*optab,*symtab,*output,*leng;
int locctr,sttadd,fstopn,opcode,len; 
char mnem[20],label[20],operand[20],instruct[20]; 
input=fopen("input.txt","r");
symtab=fopen("symtab.txt","w");
output=fopen("int.txt","w");
leng=fopen("length.txt","w");
fscanf(input,"%s %s %d",label,mnem,&fstopn);
if(strcmp(mnem,"START")==0)
{
 sttadd=fstopn;
 locctr=sttadd;
 //printf("\t%s\t%s\t%d\n",label,mnem,fstopn);
 fprintf(output,"-\t%s\t%s\t%d",label,mnem,fstopn);
 fprintf(symtab,"\n%d\t%s\n",locctr,label);
 }
 else
 locctr=0;
 fscanf(input,"%s %s",label,mnem);
while(!feof(input))
{
 fscanf(input,"%s",operand);
 //printf("\n%d\t%s\t%s\t%s\n",locctr,label,mnem,operand);
 fprintf(output,"\n%d\t%s\t%s\t%s",locctr,label,mnem,operand);
 if(strcmp(label,"-")!=0)
 {
 fprintf(symtab,"\n%d\t%s\n",locctr,label);
 }
 optab=fopen("optab.txt","r");
 fscanf(optab,"%s %d",instruct,&opcode);
 while(!feof(optab))
 {
  if(strcmp(mnem,instruct)==0)
  {
    locctr=locctr+3;
    break;
  }
  fscanf(optab,"%s %d",instruct,&opcode);
  }
  fclose(optab);
  if(strcmp(mnem,"WORD")==0)
 
    {
   locctr=locctr+3;
   }
   else if(strcmp(mnem,"RESW")==0)
   {
    fstopn=atoi(operand);
    locctr=locctr+(3*fstopn);
    }
    else if(strcmp(mnem,"BYTE")==0)
    {
    if(operand[0]=='X')
      locctr=locctr+1;
      else
      {
      len=strlen(operand)-2;
      locctr=locctr+len;}
    }
    else if(strcmp(mnem,"RESB")==0)
    {
     fstopn=atoi(operand);
     locctr=locctr+fstopn;
     }
    fscanf(input,"%s%s",label,mnem);
    }
    if(strcmp(mnem,"END")==0)
    {
    //printf("Program length =\n%d",locctr-sttadd);
    fprintf(leng,"%d",locctr-sttadd);
    }
    fclose(input);
    fclose(symtab);
    fclose(output);
    fclose(leng);
	printf("done");
    getch();
    }
