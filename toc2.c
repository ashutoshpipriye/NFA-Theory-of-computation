
#include<stdio.h>
#include<string.h>

#define fl(i,a,b) for(i=a; i<b; i++)
#define scan(a) scanf("%d", &a)
#define nline printf("\n")

#define MAX 1000

int states, symbols, symdir[20], final_states, mark[20], mat[20][20][20];
char str1[MAX];

int curr[20], t[20];
		
int ind, ind1;
int l1;
		

int main()
{
	
	int i, j, k;

	fl(i,0,20)
		fl(j,0,20)
			fl(k,0,20)
				mat[i][j][k]=-1;

	printf("Enter the number of states : ");
	scan(states);
	printf("Enter the number of symbols : ");
	scan(symbols);
	
	printf("Enter the symbols : ");
	nline;
	fl(i,0,symbols)
	{
		printf("Enter the symbol number %d : ", i);
		scan(symdir[i]);
	}
	
	printf("Enter the number of final states : ");
	scan(final_states);
	
	printf("Enter the number of the states which are final : ");
	fl(i,0,final_states)
	{
		int temp;
		scan(temp);
		mark[temp]=1;
	}
	
	printf("Define the relations for the states and symbols : ");
	nline;
	fl(i,0,states)
	{
		fl(j,0,symbols)
		{
			int ntemp;
			printf("Enter the number of relations for Q(%d) -> %d : ", i, symdir[j]);
			scan(ntemp);
			fl(k,0,ntemp)
			{
				printf("Enter the relation number %d for Q(%d) -> %d : ", k, i, symdir[j]); 
				scan(mat[i][symdir[j]][k]);
			}
			
		}
	}
	
	//--------------------------------------------------------//
	int cases;
	printf("Enter the number of strings to be tested : ");
	scan(cases);
	fl(k,0,cases)
	{
		printf("Enter the string to be tested : ");
		
		scanf("%s", str1);

		curr[0]=0;
		ind=1;
		int limit=strlen(str1);

		fl(i,0,limit)
		{
			int ele=(int)(str1[i]-'0');

			ind1=0;
			
			fl(l1,0,ind)
			{
				j=0;
				while(mat[curr[l1]][ele][j]!=-1)
				{
					t[ind1++]=mat[curr[l1]][ele][j];
					j++;
				}
			}

			fl(l1,0,ind1)
			{
				curr[l1]=t[l1];
			}

			ind=ind1;
		}
		
		int flag=0;

		fl(i,0,ind)
		{
			if(mark[curr[i]]==1)
			{
				flag=1;
				break;
			}
		}
		printf("The entered string is ");

		if(flag==1)
			printf("Accepted");
		else
			printf("Rejected");
		nline;
	}

	return 0;
	
}
