#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct component
{
	int num;	//���
	int amount;//����
	char name[20];//����
}com[3000];
int S=0;//��������

//��⺯��

void input()
{
	int i=0;
	char c;
	while(1)
	{
		system("cls");
		printf("��Ʒ%d\n",++S);
		printf("��������Ʒ��ţ�");
		scanf("%d",&com[i].num);
		printf("��������Ʒ���ƣ�");
		scanf("%s",&com[i].name);
		printf("�Ƿ�������(Y/N):");
		scanf(" %c",&c);
		i++;
		if(c=='N'||c=='n') break;
	}
}

//���⺯��

void output()
{
	int a,b,c,i,j;
	char d;
	char _name[20];
	while(1)
	{
		system("cls");
		printf("\t\t1.����ų���\n");
		printf("\t\t2.�����Ƴ���\n");
		printf("\t\t0.����\n");
		printf("��ѡ��");
		scanf("%d",&a);
		if(a==1)
		{
			printf("�������������ı�ţ�");
			scanf("%d",&b);
			printf("\n");
			for(i=0;i<=S;i++)
			{
				if(com[i].num) j=i;
			}
			if(com[j].amount>0)
			{
				printf("�������������");
				scanf("%d",&c);
				printf("\n");
				if(c>com[j].amount)
					printf("���ﲻ��\n");
				else
				{
					com[j].amount-=c;
					printf("���%d����ɹ�������\n����ʣ��%d\n",com[j].num,com[j].amount);
				}
			}
			else
				printf("�˻���Ϊ0\n");
		}
		if(a==2)
		{
			printf("�����������������ƣ�");
			scanf("%s",_name);
			printf("\n");
			for(i=0;i<=S;i++)
			{
				if(strcmp(com[i].name,_name)==0) 
					j=i;
			}
			if(com[j].amount>0)
			{
				printf("�������������");
				scanf("%d",&c);
				if(c>com[j].amount)
					printf("���ﲻ��");
				else
				{
					com[i].amount-=c;
					printf("���%d����ɹ�������\n����ʣ��%d\n",com[j].num,com[j].amount);
				}
			}
			else
			{
				printf("�˻���Ϊ0\n");
			}
		}
		else if(a==0) break;
		printf("�Ƿ��������(Y/N)��");
		scanf("%c",&d);
		if(d=='N'||d=='n') break;
	}
}

//�����������

void current()
{
	int a;
	system("cls");
	printf("\t\t1.�������\n");
	printf("\t\t2.�������\n");
	printf("\t\t0.����\n");
	printf("\t\t��ѡ��");
	scanf("%d",&a);
	if(a==1)
		input();
	else if(a==2)
		output();
}

//���Һ���

void search()
{
	int i,a,b; 
	char c; 
	char _name[20]; 
	while(1) 
	{ 
	system("cls"); 
	printf("\t\t1.����Ų���\n"); 
	printf("\t\t2.�����Ʋ���\n"); 
	printf("\t\t0.����\n"); 
	printf("\t\t��ѡ��"); 
	scanf("%d",&a); 
	if(a==1) 
	{
		printf("��������Ҫ��ѯ����ı��:"); 
		scanf("%d",&b); 
		printf("\n"); 
		for(i=0;i<S;i++) 
		{ 
			if(b==com[i].num) break; 
		} 
		if(i<S) 
			printf("��ţ�%d\n���ƣ�%s\n������%d\n",com[i].num,com[i].name,com[i].amount); 
		else 
			printf("δ�ҵ��˱��\n"); 
		printf("�Ƿ��������(Y/N): "); 
		scanf(" %c",&c); 
		if(c=='N'||c=='n') break; 
	} 
	else if(a==2) 
	{ 
		printf("��������Ҫ��ѯ���������:"); 
		scanf("%s",&_name); 
		printf("\n"); 
		for(i=0;i<S;i++) 
		{ 
		if(strcmp(_name,com[i].name)==0) break; 
		} 
		if(i<S) 
			printf("��ţ�%d\n���ƣ�%s\n������%d\n",com[i].num,com[i].name,com[i].amount); 
		else 
			printf("δ�ҵ�������\n"); 
		printf("�Ƿ��������(Y/N): "); 
		scanf(" %c",&c); 
		if(c=='N'||c=='n') break; 
	} 
	else if(a==0) break;
	}
}

//��ʾ����

void show() 
{ 
	int i; 
	char c; 
	system("cls"); 
	printf("\t���\t����\t����\n"); 
	for(i=0; i<S; i++) 
	{ 
	printf("\t%d\t%s\t%d",com[i].num,com[i].name,com[i].amount); 
	} 
	printf("\n\n"); 
	printf("���س������أ�"); 
	c=getchar(); 
	c=getchar(); 
}

//���˵�

int main()
{
	int a;
	while(1)
	{
	system("cls");
	printf("\t\t\t\t************************\n");
	printf("\t\t\t\t 1.Ԫ������������*\n");
	printf("\t\t\t\t 2.����Ԫ������*\n");
	printf("\t\t\t\t 3.��ʾԪ�����ֿ�����*\n");
	printf("\t\t\t\t 0.�˳�*\n");
	printf("\t\t\t\t************************\n");
	printf("\t\t\t\t��ѡ�� ");
	scanf(" %d",&a);
	switch(a)
	{
	case 1:current();break;
	case 2:search();break;
	case 3:show();break;
	case 0:exit(0);break;
	}
	}
	return 0;
}