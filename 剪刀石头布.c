#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
#include<time.h>
#include<conio.h>
#include<string.h>

//定义玩家结构体
int count=0;
char enter;
struct player{
	char Name[10];
	int win;
	int lose;
	int tide;
	int score;
};
struct player p,player[100];

//主函数
int main()
{
	char Exit,choice,Choice;
	int x;
	int practice();
	int newbie();
	int rank();
	int veteran();
	int rule();

	while(1)
	{
		system("cls");
		printf("		剪刀石头布程序\n");
		printf("============================================\n");
		printf("1-练习模式	2-比赛模式	3-查看排行榜\n");
		printf("4-规则		0-退出\n");
		printf("============================================\n");
		printf("	请选择输入（1-3，0 退出）：\n");
		choice=getch();
		switch(choice){
		case '1':
			for(x=0;;x++){
			practice();
			system("PAUSE");   
			break;
			}
			break;

		case '2':
			while(1){
			system("cls");
			printf("请选择：\n");
			printf("1-我是新玩家	2-我是老玩家	0-返回菜单\n");
			Choice=getch();
			switch(Choice){
			case '1':
				newbie();
				system("PAUSE");
				break;
			case '2':
				veteran();
				system("PAUSE");
				break;
			case '0':main();
			default:;
			}
			}

			system("PAUSE");
			break;
			
		case '3':
			rank();
system("PAUSE");
			break;
		case '4':
			rule();
system("PAUSE");
			break;
		case '0':
			exit(0);
		default:break;
		}
	}
}

//练习模式
int practice()
{
	char a;
	int b,x,c,n=1;
	int win=0,lose=0,tide=0;
	for(c=1;c<=7;c++)
	{
		printf("             第%d局             \n",n);
		printf("==========================\n");
		printf("请选择：");
		printf("1-剪刀     2-石头     3-布\n");
		scanf("%s",&a);
		printf("==========================\n");
		switch(a)
		{
		case '1':printf("   （你）剪刀VS");break;
	    case '2':printf("   （你）石头VS");break;
	    case '3':printf("   （你）布VS");break;
	    default:printf("\n");break;
		}
		srand((int)time(0)); 
		if(a=='3'||a=='1'||a=='2')
		{
			for(x=0;x<999;x++)    { b=random(3);}
			if(b==0)  printf("剪刀（电脑）\n");
			else if(b==1)  printf("石头（电脑）\n");
			else if(b==2)  printf("布（电脑）\n");
			n++;
		}
		else printf("   输入错误，请重新输入\n");
		if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2))
		{printf("\n          平局\n\n\n"),tide++;}
		else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
			printf("\n          你输了\n\n"),lose++;
		else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
			printf("\n          你赢了\n\n"),win++;
		else{printf("\n");c--;
		}
		printf("     目前赢%d局，输%d局,平局%d局\n\n\n",win,lose,tide);    //输赢次数
		if(win>=4)break;
		if(lose>=4)break;
	}
	if(win>lose){
		printf("		=========\n		[ 该局胜利 ]\n		=========\n");}
	else if(lose>win){
		printf("		=========\n		[ 该局失败 ]\n		=========\n");}
	else
		printf("		=========\n		[ 该局平局 ]\n		=========\n");  
	return 0;
}

//对战模式-新玩家
int newbie()
{
	char a;
	int b,x,c,n=1,i,index=-1;
	int win=0,lose=0,tide=0;
	printf("请输入你的用户名：");
	scanf("%s",player[count].Name);
	for (i=0;i<count;i++){
		if (strcmp(player[i].Name,player[count].Name)==0){
			index=i;break;
		}
		else index=-1;
	}
	if (index!=-1) printf("用户已存在!\n");
	else {
		for(c=1;c<=7;c++){
			printf("             第%d局             \n",n);
			printf("==========================\n");
			printf("请选择：");
			printf("1-剪刀     2-石头     3-布\n");
			scanf("%s",&a);
			printf("==========================\n");
			switch(a)
			{
			case '1':printf("   （你）剪刀VS");break;
			case '2':printf("   （你）石头VS");break;
			case '3':printf("   （你）  布VS");break;
			default:printf("\n");break;
			}
			srand((int)time(0)); 
			if(a=='3'||a=='1'||a=='2'){
				for(x=0;x<999;x++)    { b=random(3);}
				if(b==0)  printf("剪刀（电脑）\n");
				else if(b==1)  printf("石头（电脑）\n");
				else if(b==2)  printf("布（电脑）\n");
				n++;
			}
			else printf("   输入错误，请重新输入\n");
			if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2)){
				printf("\n          平局\n\n\n"),tide++;}
			else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
				printf("\n          你输了\n\n"),lose++;
			else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
				printf("\n          你赢了\n\n"),win++;
			else {printf("\n");c--;}
			printf("     目前赢%d局，输%d局,平局%d局\n\n\n",win,lose,tide);
			if(win>=4)break;
			if(lose>=4)break;
		}
		if(win>lose){
			printf("		=========\n		[ 该局胜利 ]\n		=========\n");
			player[count].win++;}
		else if(lose>win){
			printf("		=========\n		[ 该局失败 ]\n		=========\n");
			player[count].lose++;}
		else {
			printf("		=========\n		[ 该局平局 ]\n		=========\n"); 
			player[count].tide++;}
		player[count].score=3*(player[count].win)+player[count].tide-2*player[count].lose;
		printf("你赢了 %d 局，输了 %d 局，平了 %d 局，共获积分 %d 分\n",
			player[count].win,player[count].lose,player[count].tide,player[count].score);
		count++;}
	return 0;
}

//对战模式-老玩家
int veteran()
{
	char name[10],a;
	int index;
	int b,x,c,n=1,i;
	int win=0,lose=0,tide=0;
	printf("请输入用户名:");
	scanf("%s",&name);
	     for (i=0;i<count;i++){
			 if (strcmp(player[i].Name,name)==0){
				 index=i;break;
			 }
			 else index=-1;
		 }
		 if (index==-1) printf("学生不存在!\n");
		 else {
			 for(c=1;c<=7;c++)
			 {
				 printf("             第%d局             \n",n);
				printf("==========================\n");
				printf("请选择：");
				printf("1-剪刀     2-石头     3-布\n");
				scanf("%s",&a);
				printf("==========================\n");
				switch(a)
				{
				case '1':printf("   （你）剪刀VS");break;
				case '2':printf("   （你）石头VS");break;
				case '3':printf("   （你）  布VS");break;
				default:printf("\n");break;
				}
				srand((int)time(0)); 
				if(a=='3'||a=='1'||a=='2')
				{
					for(x=0;x<999;x++)    { b=random(3);}
					if(b==0)  printf("剪刀（电脑）\n");
					else if(b==1)  printf("石头（电脑）\n");
					else if(b==2)  printf("布（电脑）\n");
					n++;
				}
				else printf("   输入错误，请重新输入\n");
				if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2)){
				printf("\n          平局\n\n\n"),tide++;
				}
				else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
					printf("\n          你输了\n\n"),lose++;
				else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
					printf("\n          你赢了\n\n"),win++;
				else {
					printf("\n");c--;
				}
				printf("     目前赢%d局，输%d局,平局%d局\n\n\n",win,lose,tide);
				if(win>=4)break;
				if(lose>=4)break;
			 }
			 if(win>lose){
				 printf("		=========\n		[ 该局胜利 ]\n		=========\n");
				 player[index].win++;
			 }
			 else if(lose>win){
				 printf("		=========\n		[ 该局失败 ]\n		=========\n");
				 player[index].lose++;
			 }
			 else {
				 printf("		=========\n		[ 该局平局 ]\n		=========\n"); 
				 player[index].tide++;
			 }
			 player[index].score=3*(player[index].win)+player[index].tide-2*player[index].lose;
		 
		 printf("你赢了 %d 局，输了 %d 局，平了 %d 局，共获积分 %d 分\n",
			 player[index].win,player[index].lose,player[index].tide,player[index].score);
		 }
		 return 0;
}

//排行榜
int rank()
{
	int i,j,k;
	for(i=0;i<count;i++){
		for(j=i+1;j<=count;j++){
			if(player[i].score<player[j].score){
				p=player[i];
				player[i]=player[j];
				player[j]=p;
			}
		}
	}
	printf("*****************************************************************\n");
	printf("			  排行榜\n\n");
	printf("名次	姓名		胜局	           平局	          负局		    总分\n");
	for(k=0;k<count;k++){
		printf("%d%12s%15d%16d%17d%18d\n",k+1,player[k].Name,
			player[k].win,player[k].tide,player[k].lose,player[k].score);
	}
	printf("*****************************************************************\n");
	return 0;
}

//游戏规则
int rule()
{
	system("cls");
	printf("				游戏基本规则\n\n");
	printf("石头赢剪刀，剪刀赢布，布赢石头的简单规则。五局三胜制，先取得三局胜利则游戏结束\n\n");
	printf("在练习模式中，可以与电脑一直比试。\n\n");
	printf("在对战模式中，每轮胜利得3分，平手得-2分，失败得0分\n\n");
	printf("排行榜将会记录对战模式胜负次数、积分、用户积分排名。\n\n");
	return 0;
}

