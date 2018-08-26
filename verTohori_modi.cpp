#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main(int argc, char *argv[])
{
	int way;
	char line[1000];
	FILE *fptr_in,*fptr_out;

	int max=0;	
	int total=0;

	if((fptr_in = fopen(argv[1],"r"))== NULL){
	printf("Error opening file");
	exit(1);
	}
	fptr_out = fopen(argv[2],"w");
	int i,j;
	for(i=0;i<4096;i++)
	{
		for(j=0;j<4;j++)
		{

			fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line);
			fprintf(fptr_out,"%d ",way);
			if(max < way)
			    max = way;
			//std::string str(line);
			//int count=0;
			/*for(std::string::iterator it=str.begin();it!=str.end();++it)
			{			
				count++;				
				if(*it!=32&&count>30)
				{
					//stringstream geek(it);
					//int num = 0;
					//geek >> num;
					fprintf(fptr_out,"%c",*it);
				}
				else if(*it!=32&&count>70) break;
				
				
			}*/
			//fprintf(fptr_out," ");
		}
		fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line);
		total = total + way;
		fprintf(fptr_out,"\n");
	}
	fprintf(fptr_out,"%d ",max);
	fprintf(fptr_out,"%d ",total/16384);

fclose(fptr_in);
fclose(fptr_out);

}
