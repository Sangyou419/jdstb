#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
#include<time.h>
#include<conio.h>
#include<string.h>

//������ҽṹ��
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

//������
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
		printf("		����ʯͷ������\n");
		printf("============================================\n");
		printf("1-��ϰģʽ	2-����ģʽ	3-�鿴���а�\n");
		printf("4-����		0-�˳�\n");
		printf("============================================\n");
		printf("	��ѡ�����루1-3��0 �˳�����\n");
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
			printf("��ѡ��\n");
			printf("1-���������	2-���������	0-���ز˵�\n");
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

//��ϰģʽ
int practice()
{
	char a;
	int b,x,c,n=1;
	int win=0,lose=0,tide=0;
	for(c=1;c<=7;c++)
	{
		printf("             ��%d��             \n",n);
		printf("==========================\n");
		printf("��ѡ��");
		printf("1-����     2-ʯͷ     3-��\n");
		scanf("%s",&a);
		printf("==========================\n");
		switch(a)
		{
		case '1':printf("   ���㣩����VS");break;
	    case '2':printf("   ���㣩ʯͷVS");break;
	    case '3':printf("   ���㣩��VS");break;
	    default:printf("\n");break;
		}
		srand((int)time(0)); 
		if(a=='3'||a=='1'||a=='2')
		{
			for(x=0;x<999;x++)    { b=random(3);}
			if(b==0)  printf("���������ԣ�\n");
			else if(b==1)  printf("ʯͷ�����ԣ�\n");
			else if(b==2)  printf("�������ԣ�\n");
			n++;
		}
		else printf("   �����������������\n");
		if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2))
		{printf("\n          ƽ��\n\n\n"),tide++;}
		else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
			printf("\n          ������\n\n"),lose++;
		else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
			printf("\n          ��Ӯ��\n\n"),win++;
		else{printf("\n");c--;
		}
		printf("     ĿǰӮ%d�֣���%d��,ƽ��%d��\n\n\n",win,lose,tide);    //��Ӯ����
		if(win>=4)break;
		if(lose>=4)break;
	}
	if(win>lose){
		printf("		=========\n		[ �þ�ʤ�� ]\n		=========\n");}
	else if(lose>win){
		printf("		=========\n		[ �þ�ʧ�� ]\n		=========\n");}
	else
		printf("		=========\n		[ �þ�ƽ�� ]\n		=========\n");  
	return 0;
}

//��սģʽ-�����
int newbie()
{
	char a;
	int b,x,c,n=1,i,index=-1;
	int win=0,lose=0,tide=0;
	printf("����������û�����");
	scanf("%s",player[count].Name);
	for (i=0;i<count;i++){
		if (strcmp(player[i].Name,player[count].Name)==0){
			index=i;break;
		}
		else index=-1;
	}
	if (index!=-1) printf("�û��Ѵ���!\n");
	else {
		for(c=1;c<=7;c++){
			printf("             ��%d��             \n",n);
			printf("==========================\n");
			printf("��ѡ��");
			printf("1-����     2-ʯͷ     3-��\n");
			scanf("%s",&a);
			printf("==========================\n");
			switch(a)
			{
			case '1':printf("   ���㣩����VS");break;
			case '2':printf("   ���㣩ʯͷVS");break;
			case '3':printf("   ���㣩  ��VS");break;
			default:printf("\n");break;
			}
			srand((int)time(0)); 
			if(a=='3'||a=='1'||a=='2'){
				for(x=0;x<999;x++)    { b=random(3);}
				if(b==0)  printf("���������ԣ�\n");
				else if(b==1)  printf("ʯͷ�����ԣ�\n");
				else if(b==2)  printf("�������ԣ�\n");
				n++;
			}
			else printf("   �����������������\n");
			if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2)){
				printf("\n          ƽ��\n\n\n"),tide++;}
			else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
				printf("\n          ������\n\n"),lose++;
			else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
				printf("\n          ��Ӯ��\n\n"),win++;
			else {printf("\n");c--;}
			printf("     ĿǰӮ%d�֣���%d��,ƽ��%d��\n\n\n",win,lose,tide);
			if(win>=4)break;
			if(lose>=4)break;
		}
		if(win>lose){
			printf("		=========\n		[ �þ�ʤ�� ]\n		=========\n");
			player[count].win++;}
		else if(lose>win){
			printf("		=========\n		[ �þ�ʧ�� ]\n		=========\n");
			player[count].lose++;}
		else {
			printf("		=========\n		[ �þ�ƽ�� ]\n		=========\n"); 
			player[count].tide++;}
		player[count].score=3*(player[count].win)+player[count].tide-2*player[count].lose;
		printf("��Ӯ�� %d �֣����� %d �֣�ƽ�� %d �֣�������� %d ��\n",
			player[count].win,player[count].lose,player[count].tide,player[count].score);
		count++;}
	return 0;
}

//��սģʽ-�����
int veteran()
{
	char name[10],a;
	int index;
	int b,x,c,n=1,i;
	int win=0,lose=0,tide=0;
	printf("�������û���:");
	scanf("%s",&name);
	     for (i=0;i<count;i++){
			 if (strcmp(player[i].Name,name)==0){
				 index=i;break;
			 }
			 else index=-1;
		 }
		 if (index==-1) printf("ѧ��������!\n");
		 else {
			 for(c=1;c<=7;c++)
			 {
				 printf("             ��%d��             \n",n);
				printf("==========================\n");
				printf("��ѡ��");
				printf("1-����     2-ʯͷ     3-��\n");
				scanf("%s",&a);
				printf("==========================\n");
				switch(a)
				{
				case '1':printf("   ���㣩����VS");break;
				case '2':printf("   ���㣩ʯͷVS");break;
				case '3':printf("   ���㣩  ��VS");break;
				default:printf("\n");break;
				}
				srand((int)time(0)); 
				if(a=='3'||a=='1'||a=='2')
				{
					for(x=0;x<999;x++)    { b=random(3);}
					if(b==0)  printf("���������ԣ�\n");
					else if(b==1)  printf("ʯͷ�����ԣ�\n");
					else if(b==2)  printf("�������ԣ�\n");
					n++;
				}
				else printf("   �����������������\n");
				if((a=='1'&&b==0)||(a=='2'&&b==1)||(a=='3'&&b==2)){
				printf("\n          ƽ��\n\n\n"),tide++;
				}
				else if((a=='1'&&b==1)||(a=='2'&&b==2)||(a=='3'&&b==0))
					printf("\n          ������\n\n"),lose++;
				else if((a=='1'&&b==2)||(a=='2'&&b==0)||(a=='3'&&b==1))
					printf("\n          ��Ӯ��\n\n"),win++;
				else {
					printf("\n");c--;
				}
				printf("     ĿǰӮ%d�֣���%d��,ƽ��%d��\n\n\n",win,lose,tide);
				if(win>=4)break;
				if(lose>=4)break;
			 }
			 if(win>lose){
				 printf("		=========\n		[ �þ�ʤ�� ]\n		=========\n");
				 player[index].win++;
			 }
			 else if(lose>win){
				 printf("		=========\n		[ �þ�ʧ�� ]\n		=========\n");
				 player[index].lose++;
			 }
			 else {
				 printf("		=========\n		[ �þ�ƽ�� ]\n		=========\n"); 
				 player[index].tide++;
			 }
			 player[index].score=3*(player[index].win)+player[index].tide-2*player[index].lose;
		 
		 printf("��Ӯ�� %d �֣����� %d �֣�ƽ�� %d �֣�������� %d ��\n",
			 player[index].win,player[index].lose,player[index].tide,player[index].score);
		 }
		 return 0;
}

//���а�
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
	printf("			  ���а�\n\n");
	printf("����	����		ʤ��	           ƽ��	          ����		    �ܷ�\n");
	for(k=0;k<count;k++){
		printf("%d%12s%15d%16d%17d%18d\n",k+1,player[k].Name,
			player[k].win,player[k].tide,player[k].lose,player[k].score);
	}
	printf("*****************************************************************\n");
	return 0;
}

//��Ϸ����
int rule()
{
	system("cls");
	printf("				��Ϸ��������\n\n");
	printf("ʯͷӮ����������Ӯ������Ӯʯͷ�ļ򵥹��������ʤ�ƣ���ȡ������ʤ������Ϸ����\n\n");
	printf("����ϰģʽ�У����������һֱ���ԡ�\n\n");
	printf("�ڶ�սģʽ�У�ÿ��ʤ����3�֣�ƽ�ֵ�-2�֣�ʧ�ܵ�0��\n\n");
	printf("���а񽫻��¼��սģʽʤ�����������֡��û�����������\n\n");
	return 0;
}

