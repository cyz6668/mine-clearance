#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void show();
void clear();
void number();
void circle(int a,int b);
int win();
void check(int a,int b);
char in[50][50];
char out[50][50];
int m,n;
int main()
{
	int a,b,c,d,e,f,g,h,i,j,r,s;
	int p[2500];
	clock_t begin,end;
	printf("游戏说明：请输入坐标，中间以空格隔开\n若要显示该格，请在后面输入任意一个非0个位数；若要标记该格（有雷），请在后面输入0。\n"); 
	printf("请选择游戏难度：\n1.初级\t2.中级\t3.高级\t4.自定义\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:m=n=10;break;
		case 2:m=40;n=16;break;
		case 3:m=99;n=22;break;
		case 4:printf("请输入雷的数目与棋盘边长(<50)\n");
		       scanf("%d%d",&m,&n);break; 
		default:printf("输入错误"); 
	}
	clear();
	srand(time(NULL));
	for (b=0;b<m;b++)
	{
		p[b]=rand()%(n*n);
		for (e=b;e>=0;e--)
		{
			if (p[b]==p[e])
			{
				p[b]=rand()%(n*n);
				e=b;
			}
		}
	}
	for (j=0;j<m;j++){
	    in[(p[j]/n+1)][(p[j]%n+1)]=42;
    }
	number();
	begin=clock();
	while(1)
	{
	scanf("%d%d%d",&f,&g,&h);
	if(h)
	{
		out[f][g]=in[f][g];
	    if(in[f][g]=='0')
    	check(f,g);
	    show();
	    printf("\n");
	}
	else
	{
	    if(out[f][g]=='X')
		{
		    out[f][g]=23;
		    show();
	    }
		else
		{
		    out[f][g]='X';
	        show();
        }
    }
	i=win();
	if(out[f][g]==42)
	{
	    printf("游戏结束，你失败了\n\n");
	    for(r=0;r<n+1;r++)
	    for(s=0;s<n+1;s++)
	    if(in[r][s]==42)
		out[r][s]=42;
	    show();
	    break;
	}
	else if(i)
	{
		end=clock();
	    printf("恭喜通关！用时%f秒\n",(double)(end-begin)/CLK_TCK);
	    break;
    }
    else printf("请输入坐标及操作\n\n");
    }
}
void clear()
{
	int a,b,c,d,e,f;
    for(a=1;a<50;a++)
    for(b=1;b<50;b++)
    out[a][b]=23;
    for(e=0;e<50;e++)
    out[0][e]=e;
    for(f=0;f<50;f++)
    out[f][0]=f;
    for(c=0;c<50;c++)
    for(d=0;d<50;d++)
    if(c>n-1||d>n-1)
    in[c][d]=48;
}
void number()
{
	int a,b,c,d;
	for(a=1;a<n+1;a++)
	for(b=1;b<n+1;b++)
	if(in[a][b]!=42)
	{
	    in[a][b]=48;
		if(a==1&&b==1)
	{
		if(in[a+1][b]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
		if(in[a+1][b+1]==42)in[a][b]++;
	}
	else if(a==n&&b==n)
	{
		if(in[a-1][b]==42)in[a][b]++;
		if(in[a-1][b-1]==42)in[a][b]++;
		if(in[a][b-1]==42)in[a][b]++;
	}
	else if(a==1&&b==n)
	{
		if(in[a][b-1]==42)in[a][b]++;
		if(in[a+1][b-1]==42)in[a][b]++;
		if(in[a+1][b]==42)in[a][b]++;
	}
	else if(a==n&&b==1)
	{
		if(in[a-1][b]==42)in[a][b]++;
		if(in[a-1][b+1]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
	}
	else if(a==1)
	{
		if(in[a][b-1]==42)in[a][b]++;
		if(in[a+1][b-1]==42)in[a][b]++;
		if(in[a+1][b]==42)in[a][b]++;
		if(in[a+1][b+1]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
	}
	else if(b==1)
	{
		if(in[a+1][b]==42)in[a][b]++;
		if(in[a+1][b+1]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
		if(in[a-1][b+1]==42)in[a][b]++;
		if(in[a-1][b]==42)in[a][b]++;
	}
	else if(a==n)
	{
		if(in[a][b-1]==42)in[a][b]++;
		if(in[a-1][b-1]==42)in[a][b]++;
		if(in[a-1][b]==42)in[a][b]++;
		if(in[a-1][b+1]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
	}
	else if(b==n)
	{
		if(in[a-1][b]==42)in[a][b]++;
		if(in[a-1][b-1]==42)in[a][b]++;
		if(in[a][b-1]==42)in[a][b]++;
		if(in[a+1][b-1]==42)in[a][b]++;
		if(in[a+1][b]==42)in[a][b]++;
	}
	else
	{
		if(in[a+1][b]==42)in[a][b]++;
		if(in[a+1][b+1]==42)in[a][b]++;
		if(in[a][b+1]==42)in[a][b]++;
		if(in[a-1][b+1]==42)in[a][b]++;
		if(in[a-1][b]==42)in[a][b]++;
		if(in[a-1][b-1]==42)in[a][b]++;
		if(in[a][b-1]==42)in[a][b]++;
		if(in[a+1][b-1]==42)in[a][b]++;
	}
    }
    show();
}
int win()
{
	int a,b,c,d;
	c=d=0;
	for(a=0;a<50;a++)
	for(b=0;b<50;b++)
	if(in[a][b]==42&&out[a][b]=='X')c++;
	if(c==m)d=1;
	return(d);
}
void check(int a,int b)
{
	int c,d,e,f;
	if(a==1&&b==1)
	{
		if(out[a+1][b]==23)circle(a+1,b);
		if(out[a][b+1]==23)circle(a,b+1);
		if(out[a+1][b+1]==23)circle(a+1,b+1);
	}
	else if(a==n&&b==n)
	{
		if(out[a-1][b]==23)circle(a-1,b);
		if(out[a-1][b-1]==23)circle(a-1,b-1);
		if(out[a][b-1]==23)circle(a,b-1);
	}
	else if(a==1&&b==n)
	{
		if(out[a][b-1]==23)circle(a,b-1);
		if(out[a+1][b-1]==23)circle(a+1,b-1);
		if(out[a+1][b]==23)circle(a+1,b);
	}
	else if(a==n&&b==1)
	{
		if(out[a-1][b]==23)circle(a-1,b);
		if(out[a-1][b+1]==23)circle(a-1,b+1);
		if(out[a][b+1]==23)circle(a,b+1);
	}
	else if(a==1)
	{
		if(out[a][b-1]==23)circle(a,b-1);
		if(out[a+1][b-1]==23)circle(a+1,b-1);
		if(out[a+1][b]==23)circle(a+1,b);
		if(out[a+1][b+1]==23)circle(a+1,b+1);
		if(out[a][b+1]==23)circle(a,b+1);
	}
	else if(b==1)
	{
		if(out[a+1][b]==23)circle(a+1,b);
		if(out[a+1][b+1]==23)circle(a+1,b+1);
		if(out[a][b+1]==23)circle(a,b+1);
		if(out[a-1][b+1]==23)circle(a-1,b+1);
		if(out[a-1][b]==23)circle(a-1,b);
	}
	else if(a==n)
	{
		if(out[a][b-1]==23)circle(a,b-1);
		if(out[a-1][b-1]==23)circle(a-1,b-1);
		if(out[a-1][b]==23)circle(a-1,b);
		if(out[a-1][b+1]==23)circle(a-1,b+1);
		if(out[a][b+1]==23)circle(a,b+1);
	}
	else if(b==n)
	{
		if(out[a-1][b]==23)circle(a-1,b);
		if(out[a-1][b-1]==23)circle(a-1,b-1);
		if(out[a][b-1]==23)circle(a,b-1);
		if(out[a+1][b-1]==23)circle(a+1,b-1);
		if(out[a+1][b]==23)circle(a+1,b);
	}
	else
	{
		if(out[a+1][b]==23)circle(a+1,b);
		if(out[a+1][b+1]==23)circle(a+1,b+1);
		if(out[a][b+1]==23)circle(a,b+1);
		if(out[a-1][b+1]==23)circle(a-1,b+1);
		if(out[a-1][b]==23)circle(a-1,b);
		if(out[a-1][b-1]==23)circle(a-1,b-1);
		if(out[a][b-1]==23)circle(a,b-1);
		if(out[a+1][b-1]==23)circle(a+1,b-1);
	}
}
void show()
{
	int x,y;
	for(x=0;x<n+1;x++)
	    {     
		    for(y=0;y<n+1;y++)
		    if(x==0)
		    {
		    if(y==9){printf("%2d ",out[x][y]);}
		    else
		    printf("%2d",out[x][y]);
		    }
		    else if(y==0)
		    printf("%2d ",out[x][y]);
		    else printf("%c ",out[x][y]);
    	    printf("\n");
        }
}
void circle(int a,int b)
{
	out[a][b]=in[a][b];
	if(in[a][b]=='0')check(a,b);
}
