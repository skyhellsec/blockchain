#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct component
{
	int num;	//编号
	int amount;//数量
	char name[20];//名称
}com[3000];
int S=0;//货物数量

//入库函数

void input()
{
	int i=0;
	char c;
	while(1)
	{
		system("cls");
		printf("物品%d\n",++S);
		printf("请输入物品编号：");
		scanf("%d",&com[i].num);
		printf("请输入物品名称：");
		scanf("%s",&com[i].name);
		printf("是否继续入库(Y/N):");
		scanf(" %c",&c);
		i++;
		if(c=='N'||c=='n') break;
	}
}

//出库函数

void output()
{
	int a,b,c,i,j;
	char d;
	char _name[20];
	while(1)
	{
		system("cls");
		printf("\t\t1.按编号出库\n");
		printf("\t\t2.按名称出库\n");
		printf("\t\t0.返回\n");
		printf("请选择：");
		scanf("%d",&a);
		if(a==1)
		{
			printf("请输入出货货物的编号：");
			scanf("%d",&b);
			printf("\n");
			for(i=0;i<=S;i++)
			{
				if(com[i].num) j=i;
			}
			if(com[j].amount>0)
			{
				printf("请输入出货量：");
				scanf("%d",&c);
				printf("\n");
				if(c>com[j].amount)
					printf("货物不足\n");
				else
				{
					com[j].amount-=c;
					printf("编号%d货物成功出货！\n货物剩余%d\n",com[j].num,com[j].amount);
				}
			}
			else
				printf("此货物为0\n");
		}
		if(a==2)
		{
			printf("请输入出货货物的名称：");
			scanf("%s",_name);
			printf("\n");
			for(i=0;i<=S;i++)
			{
				if(strcmp(com[i].name,_name)==0) 
					j=i;
			}
			if(com[j].amount>0)
			{
				printf("请输入出货量：");
				scanf("%d",&c);
				if(c>com[j].amount)
					printf("货物不足");
				else
				{
					com[i].amount-=c;
					printf("编号%d货物成功出货！\n货物剩余%d\n",com[j].num,com[j].amount);
				}
			}
			else
			{
				printf("此货物为0\n");
			}
		}
		else if(a==0) break;
		printf("是否继续出库(Y/N)：");
		scanf("%c",&d);
		if(d=='N'||d=='n') break;
	}
}

//货物出库和入库

void current()
{
	int a;
	system("cls");
	printf("\t\t1.货物入库\n");
	printf("\t\t2.货物出库\n");
	printf("\t\t0.返回\n");
	printf("\t\t请选择：");
	scanf("%d",&a);
	if(a==1)
		input();
	else if(a==2)
		output();
}

//查找函数

void search()
{
	int i,a,b; 
	char c; 
	char _name[20]; 
	while(1) 
	{ 
	system("cls"); 
	printf("\t\t1.按编号查找\n"); 
	printf("\t\t2.按名称查找\n"); 
	printf("\t\t0.返回\n"); 
	printf("\t\t请选择："); 
	scanf("%d",&a); 
	if(a==1) 
	{
		printf("请输入需要查询货物的编号:"); 
		scanf("%d",&b); 
		printf("\n"); 
		for(i=0;i<S;i++) 
		{ 
			if(b==com[i].num) break; 
		} 
		if(i<S) 
			printf("编号：%d\n名称：%s\n数量：%d\n",com[i].num,com[i].name,com[i].amount); 
		else 
			printf("未找到此编号\n"); 
		printf("是否继续查找(Y/N): "); 
		scanf(" %c",&c); 
		if(c=='N'||c=='n') break; 
	} 
	else if(a==2) 
	{ 
		printf("请输入需要查询货物的名称:"); 
		scanf("%s",&_name); 
		printf("\n"); 
		for(i=0;i<S;i++) 
		{ 
		if(strcmp(_name,com[i].name)==0) break; 
		} 
		if(i<S) 
			printf("编号：%d\n名称：%s\n数量：%d\n",com[i].num,com[i].name,com[i].amount); 
		else 
			printf("未找到此名称\n"); 
		printf("是否继续查找(Y/N): "); 
		scanf(" %c",&c); 
		if(c=='N'||c=='n') break; 
	} 
	else if(a==0) break;
	}
}

//显示函数

void show() 
{ 
	int i; 
	char c; 
	system("cls"); 
	printf("\t编号\t名称\t数量\n"); 
	for(i=0; i<S; i++) 
	{ 
	printf("\t%d\t%s\t%d",com[i].num,com[i].name,com[i].amount); 
	} 
	printf("\n\n"); 
	printf("按回车键返回！"); 
	c=getchar(); 
	c=getchar(); 
}

//主菜单

int main()
{
	int a;
	while(1)
	{
	system("cls");
	printf("\t\t\t\t************************\n");
	printf("\t\t\t\t 1.元器件出库和入库*\n");
	printf("\t\t\t\t 2.查找元器件表*\n");
	printf("\t\t\t\t 3.显示元器件仓库货物表*\n");
	printf("\t\t\t\t 0.退出*\n");
	printf("\t\t\t\t************************\n");
	printf("\t\t\t\t请选择： ");
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