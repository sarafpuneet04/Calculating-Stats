#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main(int argc, char *argv[])
{
	int way,wayR,wayWB,wayM,cacheSW[4096][4];
	char line[1000];
	FILE *fptr_in,*fptr_out;

	int maxR=0,maxWB=0,maxM=0,maxAll=0;	
	int totalR=0,totalWB=0,totalM=0,totalAll=0;

	if((fptr_in = fopen(argv[1],"r"))== NULL){
	printf("Error opening file");
	exit(1);
	}
	fptr_out = fopen(argv[2],"w");
	
	for(int k=0;k<4096;k++)
	{
	    for(int l=0;l<4;l++)
	    {
		cacheSW[k][l]=0;
	    }
	}

	for(int p=0;p<3;p++)
	{
		for(int i=0;i<4096;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(p==0)
				{
					fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line,line,line,line);
					fprintf(fptr_out,"%d ",way);
					cacheSW[i][j] += way;
					if(maxR < way)
					    maxR = way;
				}
				else if(p==1)
				{
					fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line);
					fprintf(fptr_out,"%d ",way);
					cacheSW[i][j] += way;
					if(maxWB < way)
					    maxWB = way;
				}
				else if(p==2)
				{
					fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line,line,line,line);
					fprintf(fptr_out,"%d ",way);
					cacheSW[i][j] += way;
					if(maxM < way)
					    maxM = way;
				}

			}
			if(p==0)
			{
				fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line,line,line,line);
				totalR = totalR + way;
				fprintf(fptr_out,"\n");
			}
			else if(p==1)
			{
				fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line);
				totalWB = totalWB + way;
				fprintf(fptr_out,"\n");
			}
			else if(p==2)
			{
				fscanf(fptr_in,"%s %d %s %s %s %s %s %s %s %s %s %s\n",line,&way,line,line,line,line,line,line,line,line,line,line);
				totalM = totalM + way;
				fprintf(fptr_out,"\n");
			}

		}
	}
	
	for(int z=0;z<4096;z++)
	{
		for(int y=0;y<4;y++)
		{
			fprintf(fptr_out,"%d ",cacheSW[z][y]);
			totalAll += cacheSW[z][y];
			if(maxAll < cacheSW[z][y])
			    maxAll = cacheSW[z][y];
		}
		fprintf(fptr_out,"\n");
	}
	
	fprintf(fptr_out,"Total, Max and Mean Retention Writes\n");
	fprintf(fptr_out,"%d %d ",totalR,maxR);
	fprintf(fptr_out,"%d \nTotal, Max and Mean WriteBacks Writes\n",totalR/16384);

	fprintf(fptr_out,"%d %d ",totalWB,maxWB);
	fprintf(fptr_out,"%d \nTotal, Max and Mean Misses Writes\n",totalWB/16384);

	fprintf(fptr_out,"%d %d ",totalM,maxM);
	fprintf(fptr_out,"%d \nTotal, Max and Mean Total Writes\n",totalM/16384);

	fprintf(fptr_out,"%d %d ",totalAll ,maxAll);
	fprintf(fptr_out,"%d ",totalAll/16384);

fclose(fptr_in);
fclose(fptr_out);

}
