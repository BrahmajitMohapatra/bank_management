#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct msgarr
      {
	char arr[9][30];
      };
char mm[2][30],inp_amt[10]="",descr[20]="";
struct user_det
{
	long ac_no;
	char name[30];
	char fname[30];
	long age;
	char dob[11];
	char address[50];
	char mb_no[11];
	char ac_type[8];
	char ac_op_date[11];
}ud;
struct ac_det
{
      //	int ac_no;
	char tr_date[11];
	char descr[50];
	double debit;
	double credit;
	double total_bal;
}ad;
void trans_win1(int);
void trans_win2(int,char[],char[]);
void make_trans(char[][20]);
long gen_an();
struct msgarr det_copy();
void check_det(char[9][30]);
void login_ac(int,char [2][30]);
int login_check(char [2][30]);
int update_details(char [][30]);
void update(int,char [][30]);
void new_ac_win(int,char [][30]);
char *char_inp(int [],char[][30],char[]);
char *int_inp(int[],char[][30],char[]);
char *date_inp(int[],char[][30],char[]);
char *mix_char_inp(int[],char[][30],char[]);
int cr_ac(char [8][30]);
int login();
void win_main(int);
int delete_ac();
void main()
{
	int gdriver = DETECT, gmode, errorcode;
	int cur_on=1,move_dir,i,cor[5],ac_number;
	char data[2][20];
	char msg[8][30],pr[20],win_name[30];
	struct msgarr mst;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}
MAIN_WINDOW :
{
    // main window label start
	cleardevice();
	win_main(cur_on);
	while(1)
	{
		move_dir=getch();
		if(move_dir==72)
		{
			if(cur_on==1)
			{
				cur_on=6;
				cleardevice();
				win_main(cur_on);
			}
			else
			{
				cur_on--;
				cleardevice();
				win_main(cur_on);
			}
		}
		if(move_dir==80)
		{
			if(cur_on==6)
			{
				cur_on=1;
				cleardevice();
				win_main(cur_on);
			}
			else
			{
				cur_on++;
				cleardevice();
				win_main(cur_on);
			}
		}
		if(move_dir==13)
		{
			if(cur_on==6)
			{
				exit(0);
			}
			if(cur_on==1)
			{
				goto CRE_NEW_AC;
			}
			if(cur_on==2)
			{
				goto CHECK_DET;
			}
			if(cur_on==3)
			{
				goto UPDATE_AC;
			}
			if(cur_on==4)
			{
				goto TRANSACTION;
			}
			if(cur_on==5)
			{
				goto DEL_AC;
			}
		}

	}
};          // main window label end

CRE_NEW_AC:
{
  // create new account  window label start
	for(i=0;i<9;i++)
	{
		strcpy(msg[i],"");
	}
	cleardevice();
	new_ac_win(cur_on,msg);
	while(1)
	{
		move_dir=getch();
		if(move_dir==72)
		{
			if(cur_on==1)
			{
				cur_on=10;
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			else
			{
				cur_on--;
				cleardevice();
				new_ac_win(cur_on,msg);
			}
		}
		if(move_dir==80)
		{
			if(cur_on==10)
			{
				cur_on=1;
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			else
			{
				cur_on++;
				cleardevice();
				new_ac_win(cur_on,msg);
			}
		}
		if(move_dir==13)
		{
			if(cur_on==9)
			{
				cur_on=1;
				goto MAIN_WINDOW;
			}
			if(cur_on==1)
			{
				cor[0]=281;
				cor[1]=70;
				cor[2]=629;
				cor[3]=110;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");
				strcpy(msg[0],char_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==2)
			{
				cor[0]=281;
				cor[1]=110;
				cor[2]=629;
				cor[3]=150;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");
				strcpy(msg[1],char_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==3)
			{
				cor[0]=281;
				cor[1]=150;
				cor[2]=629;
				cor[3]=190;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");
				strcpy(msg[2],int_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==4)
			{
				cor[0]=281;
				cor[1]=190;
				cor[2]=629;
				cor[3]=230;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");
				strcpy(msg[3],date_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==5)
			{
				cor[0]=281;
				cor[1]=230;
				cor[2]=629;
				cor[3]=270;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");
				strcpy(msg[4],mix_char_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==6)
			{
				cor[0]=281;
				cor[1]=270;
				cor[2]=629;
				cor[3]=310;
				cor[4]=cur_on;
					strcpy(win_name,"new_ac_win");
				strcpy(msg[5],int_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==7)
			{
				cor[0]=281;
				cor[1]=310;
				cor[2]=629;
				cor[3]=350;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");

				strcpy(msg[6],int_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==8)
			{
				cor[0]=281;
				cor[1]=350;
				cor[2]=629;
				cor[3]=390;
				cor[4]=cur_on;
				strcpy(win_name,"new_ac_win");

				strcpy(msg[7],char_inp(cor,msg,win_name));
				cleardevice();
				new_ac_win(cur_on,msg);
			}
			if(cur_on==10)
			{
				ac_number=cr_ac(msg);
				cleardevice();
				setcolor(RED);
				setbkcolor(YELLOW);
				settextstyle(1,HORIZ_DIR,4);
				if(ac_number==0)
				{
					outtextxy(50,50,"ACCOUNT NOT OPEN");
				}
				else
				{
					outtextxy(50,50,"ACCOUNT CREATE SUCCESSFULL");
					sprintf(pr,"ACCOUNT NO. %d",ac_number);
					outtextxy(50,150,pr);
				}
				getch();
				cur_on=1;

				goto MAIN_WINDOW;
			}

		}

	}       // while(1)
};				// create new account  window label start

CHECK_DET:
{
	for(i=0;i<9;i++)
	{
		strcpy(msg[i],"");
	}
	int ct;
	ct=login();
	if(ct==0)
	{
		goto MAIN_WINDOW;
	}
	else
	{
		mst=det_copy();
		for(i=0;i<9;i++)
		{
			strcpy(msg[i],mst.arr[i]);
		}
		check_det(msg);
		getch();
		cur_on=1;
		goto MAIN_WINDOW;
	}
};

UPDATE_AC:
{
	int ctt;
	for(i=0;i<9;i++)
	{
		strcpy(msg[i],"");
	}
      //	char win_name[20];
	ctt=login();
	if(ctt==0)
	{
		goto MAIN_WINDOW;
	}
	else
	{
		mst=det_copy();
		for(i=0;i<9;i++)
		{
			strcpy(msg[i],mst.arr[i]);
		}

		int up_cur=1,up;
		cleardevice();
		strcpy(win_name,"update_win");
		update(up_cur,msg);
		while(1)
		{
			move_dir=getch();
			if(move_dir==72)
			{
				if(up_cur==1)
				{
					up_cur=9;
					cleardevice();

					update(up_cur,msg);
				}
				else
				{
					up_cur--;
					cleardevice();
					update(up_cur,msg);
				}
			}
			if(move_dir==80)
			{
				if(up_cur==9)
				{
					up_cur=1;
					cleardevice();
					update(up_cur,msg);
				}
				else
				{
					up_cur++;
					cleardevice();
					update(up_cur,msg);
				}
			}
		if(move_dir==13)
		{
			if(up_cur==9)
			{
				goto MAIN_WINDOW;
			}
			if(up_cur==1)
			{
				cor[0]=281;
				cor[1]=70;
				cor[2]=629;
				cor[3]=110;
				cor[4]=up_cur;
				strcpy(msg[0],char_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==2)
			{
				cor[0]=281;
				cor[1]=110;
				cor[2]=629;
				cor[3]=150;
				cor[4]=up_cur;
				strcpy(msg[1],char_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==3)
			{
				cor[0]=281;
				cor[1]=150;
				cor[2]=629;
				cor[3]=190;
				cor[4]=up_cur;
				strcpy(msg[2],int_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==4)
			{
				cor[0]=281;
				cor[1]=190;
				cor[2]=629;
				cor[3]=230;
				cor[4]=up_cur;
				strcpy(msg[3],date_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==5)
			{
				cor[0]=281;
				cor[1]=230;
				cor[2]=629;
				cor[3]=270;
				cor[4]=up_cur;
				strcpy(msg[4],mix_char_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==6)
			{
				cor[0]=281;
				cor[1]=270;
				cor[2]=629;
				cor[3]=310;
				cor[4]=up_cur;
				strcpy(msg[5],int_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==7)
			{
				cor[0]=281;
				cor[1]=310;
				cor[2]=629;
				cor[3]=350;
				cor[4]=up_cur;
				strcpy(msg[7],char_inp(cor,msg,win_name));
				cleardevice();
				update(up_cur,msg);
			}
			if(up_cur==8)
			{
				cleardevice();
				up=update_details(msg);
				setcolor(RED);
				setbkcolor(YELLOW);
				settextstyle(1,HORIZ_DIR,4);
				if(up==0)
				{
					outtextxy(10,10,"UPDATE NOT COMPLETE");
				}
				else
				{
					outtextxy(10,10,"UPDATE COMPLETE");
				}
				getch();
				goto MAIN_WINDOW;
			}
			if(up_cur==9)
			{
				goto MAIN_WINDOW;
			}

		}

	}       // while(1)

	}
};

TRANSACTION:
{
	int ct;
	ct=login();
	setcolor(RED);
	setbkcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,4);

	if(ct==0)
	{
		cleardevice();
		outtextxy(50,50,"CAN NOT LOGIN ");
		getch();
		goto MAIN_WINDOW;
	}
	else
	{
		cleardevice();
		trans_win1(1);

		 cur_on=1;
		 int mv_dir;
		while(1)
		{
			mv_dir=getch();
			if(mv_dir==72)
			{
				if(cur_on==1)
				{
					cur_on=3;
					cleardevice();
					trans_win1(cur_on);
				}
				else
				{
					cur_on--;
					cleardevice();
					trans_win1(cur_on);
				}
			}
			if(mv_dir==80)
			{
				if(cur_on==3)
				{
					cur_on=1;
					cleardevice();
					trans_win1(cur_on);
				}
				else
				{
					cur_on++;
					cleardevice();
					trans_win1(cur_on);
				}
			}
			if(mv_dir==13)
			{
				if(cur_on==3)
				{
					cur_on=1;
					goto MAIN_WINDOW;
				}
				if(cur_on==1)
				{
					cleardevice();
					int cur_on=1,mo_dir;
					//long ac_no;

					trans_win2(cur_on,inp_amt,descr);
					while(1)
					{
						mo_dir=getch();
						if(mo_dir==72)
						{
							if(cur_on==1)
							{
								cur_on=4;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							else
							{
								cur_on--;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
						}
						if(mo_dir==80)
						{
							if(cur_on==4)
							{
								cur_on=1;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							else
							{
								cur_on++;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
						}
						if(mo_dir==13)
						{
							if(cur_on==4)
							{
								cur_on=1;
								goto MAIN_WINDOW;
							}
							if(cur_on==1)
							{
								// input amount
								cor[0]=50;
								cor[1]=150;
								cor[2]=400;
								cor[3]=200;
								cor[4]=cur_on;
								strcpy(win_name,"trans_win2");
								strcpy(inp_amt,int_inp(cor,msg,win_name));
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							if(cur_on==2)
							{
								// input description
								cor[0]=50;
								cor[1]=250;
								cor[2]=400;
								cor[3]=300;
								cor[4]=cur_on;
								strcpy(win_name,"trans_win2");
								strcpy(descr,mix_char_inp(cor,msg,win_name));
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							if(cur_on==3)
							{
								// transaction made for withdraw
								strcpy(data[0],inp_amt);
								strcpy(data[1],"debit");
								strcpy(data[2],descr);
								make_trans(data);
								cur_on=1;
								goto MAIN_WINDOW;
							}
						}
					}
				}
				if(cur_on==2)
				{
					cleardevice();
					int cur_on=1,mo_dir;
					trans_win2(cur_on,inp_amt,descr);
					while(1)
					{
						mo_dir=getch();
						if(mo_dir==72)
						{
							if(cur_on==1)
							{
								cur_on=4;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							else
							{
								cur_on--;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
						}
						if(mo_dir==80)
						{
							if(cur_on==4)
							{
								cur_on=1;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							else
							{
								cur_on++;
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
						}
						if(mo_dir==13)
						{
							if(cur_on==4)
							{
								cur_on=1;
								goto MAIN_WINDOW;
							}
							if(cur_on==1)
							{
								// input amount
								cor[0]=50;
								cor[1]=150;
								cor[2]=400;
								cor[3]=200;
								cor[4]=cur_on;
								strcpy(win_name,"trans_win2");
								strcpy(inp_amt,int_inp(cor,msg,win_name));
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							if(cur_on==2)
							{
								// input description
								cor[0]=50;
								cor[1]=250;
								cor[2]=400;
								cor[3]=300;
								cor[4]=cur_on;
								strcpy(win_name,"trans_win2");
								strcpy(descr,mix_char_inp(cor,msg,win_name));
								cleardevice();
								trans_win2(cur_on,inp_amt,descr);
							}
							if(cur_on==3)
							{
								// transaction made for creadet
								strcpy(data[0],inp_amt);
								strcpy(data[1],"creadit");
								strcpy(data[2],descr);
								make_trans(data);
								cur_on=1;
								goto MAIN_WINDOW;
							}
						}
					}

				}
			}
		}
	}
};

DEL_AC:
{
	int ct;
	ct=login();
	setcolor(RED);
	setbkcolor(YELLOW);
	settextstyle(1,HORIZ_DIR,4);

	if(ct==0)
	{
		cleardevice();
		outtextxy(50,50,"CAN NOT LOGIN ");
		getch();
		goto MAIN_WINDOW;
	}
	else
	{
		int delt=0;
		delt=delete_ac();
		if(delt==0)
		{
			cleardevice();
			outtextxy(50,50,"ACCOUNT NOT DELETE SUCCESSFULLY ");
			getch();
			goto MAIN_WINDOW;
		}
		else
		{
			cleardevice();
			outtextxy(50,50,"ACCOUNT DELETE SUCCESSFULLY ");
			getch();
			goto MAIN_WINDOW;
		}
	}
};

}

int delete_ac()
{

	FILE *l1,*l2;
	struct  user_det s;
	char pass[50],ap[30],ac_numm[5]="";
	strcpy(pass,"bank\\pass\\");
	strcat(pass,mm[1]);
	strcat(pass,".txt");
	if((l1=fopen("bank\\CUS_DETA.txt","r+"))==NULL)
	{
		return 0;
	}
	if((l2=fopen("bank\\demo.txt","a+"))==NULL)
	{
		return 0;
	}

	while(l1)
	{
		fread(&s,sizeof(s),1,l1);

		sprintf(ac_numm,"%d",s.ac_no);
		if((strcmp(s.name,mm[0])!=0) && (strcmp(ac_numm,mm[1])!=0))
		{
			fwrite(&s,sizeof(s),1,l2);
		}
		if(feof(l1))
		{
			break;
		}
	}
	fclose(l1);
	fclose(l2);
	remove("bank\\CUS_DETA.txt");
	remove(pass);
	rename("bank\\demo.txt","bank\\CUS_DETA.txt");
	return 1;
}

void trans_win1(int cur)
{

	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(50,50,400,400);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(50,50,400,150);
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(80,80,"TRANSACTION TYPE");
	setcolor(BLUE);
	line(50,230,400,230);
	outtextxy(150,170,"WITHDRAW");
	line(50,310,400,310);
	outtextxy(150,250,"CREADIT");
	outtextxy(150,330,"CANCEL");
	if(cur==1)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,150,400,230);
		outtextxy(150,170,"WITHDRAW");
	}
	if(cur==2)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,230,400,310);
		outtextxy(150,250,"CREADIT");
	}
	if(cur==3)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,310,400,400);
		outtextxy(150,330,"CANCEL");
	}
}

void make_trans(char data[3][20])
{
	FILE *fl;
	struct  date t;
	getdate(&t);
	char date[30]="",day[5],mon[5],year[5],*endptr;
	struct ac_det ad;
	char path[30]="bank\\pass\\";
	char tot_bal[40],dscr[20];
	double amt;
	int ttt;
	sprintf(day,"%d/",t.da_day);
	sprintf(mon,"%d/",t.da_mon);
	sprintf(year,"%d",t.da_year);

	strcat(path,mm[1]);
	strcat(path,".txt");

	strcat(date,day);
	strcat(date,mon);
	strcat(date,year);

	amt= strtod(data[0], &endptr);
	stpcpy(dscr,data[2]);
	//amt=data[0];

	if((fl=fopen(path,"r+"))==NULL)
	{
		cleardevice();
		settextstyle(1, HORIZ_DIR, 4);
		setbkcolor(YELLOW);
		setcolor(RED);
		outtextxy(50,50,"file not open ");
		getch();
	}
	else
	{
		while(fl)
		{
			fread(&ad,sizeof(ad),1,fl);
			if(feof(fl))
			{
				break;
			}
		}
		if((strcmp(data[1],"creadit"))==0)
		{
			ad.total_bal=amt+ad.total_bal;
			sprintf(tot_bal,"TOTAL BALENCE : %.2f",ad.total_bal);
			strcpy(ad.tr_date,date);
			strcpy(ad.descr,dscr);
			ad.debit=0;
			ad.credit=amt;
			cleardevice();
			settextstyle(1, HORIZ_DIR, 4);
			setbkcolor(YELLOW);
			setcolor(RED);
			if((fwrite(&ad,sizeof(ad),1,fl))!=0)
			{
				outtextxy(50,50," transaction done  ");
				outtextxy(50,100,tot_bal);
				getch();

			}
			else
			{
				outtextxy(50,50," transaction not done  ");
				outtextxy(50,100,tot_bal);
				getch();

			}
		}
		if((strcmp(data[1],"debit"))==0)
		{
			settextstyle(1, HORIZ_DIR, 4);
			setbkcolor(YELLOW);
			setcolor(RED);
			if(ad.total_bal-amt>=0)
			{
				ad.total_bal=ad.total_bal-amt;
				sprintf(tot_bal,"TOTAL BLANCE : %.2f",ad.total_bal);
				strcpy(ad.tr_date,date);
				strcpy(ad.descr,dscr);
				ad.debit=amt;
				ad.credit=0;
				cleardevice();

				if((fwrite(&ad,sizeof(ad),1,fl))!=0)
				{
					outtextxy(50,50," transaction done  ");
					outtextxy(50,100,tot_bal);
					getch();

				}
				else
				{
					cleardevice();
					outtextxy(50,50," transaction not done  ");
					outtextxy(50,100,tot_bal);
					getch();

				}
			}
			else
			{
				cleardevice();
				outtextxy(50,50," insufficient amount");
				getch();

			}
		}

		fclose(fl);
	}
}

int login()
{
	int cur=1,mv,i,lo=0,cor[5];
	char ms[2][30],win_name[30];
	int ct=1;
	for(i=0;i<2;i++)
	{
		strcpy(ms[i],"");
	}


	login_ac(cur,ms);


	while(1)
	{
		mv=getch();
		if(mv==72)
		{
			if(cur==1)
			{
				cur=4;
				cleardevice();
				login_ac(cur,ms);
			}
			else
			{
				cur--;
				cleardevice();
				login_ac(cur,ms);
			}
		}
		if(mv==80)
		{
			if(cur==4)
			{
				cur=1;
				cleardevice();
				login_ac(cur,ms);
			}
			else
			{
				cur++;
				cleardevice();
				login_ac(cur,ms);
			}
		}
		if(mv==13)
		{
			if(cur==4)
			{
				ct=0;
				break;
			}
			if(cur==1)
			{
				cor[0]=50;
				cor[1]=150;
				cor[2]=400;
				cor[3]=200;
				cor[4]=cur;
				strcpy(win_name,"login_win");

				strcpy(ms[0],char_inp(cor,ms,win_name));
				cleardevice();
				login_ac(cur,ms);
			}
			if(cur==2)
			{
				cor[0]=50;
				cor[1]=250;
				cor[2]=400;
				cor[3]=300;
				cor[4]=cur;
				strcpy(win_name,"login_win");

				strcpy(ms[1],int_inp(cor,ms,win_name));
				cleardevice();
				login_ac(cur,ms);
			}
			if(cur==3)
			{
				lo=login_check(ms);
				if(lo==1)
				{
					cleardevice();
					strcpy(mm[0],ms[0]);
					strcpy(mm[1],ms[1]);
				       break;
				}
				else
				{	cleardevice();
					setcolor(RED);
					settextstyle(1,HORIZ_DIR,4);
					outtextxy(50,50,"can not login");
					getch();
					cleardevice();
					login_ac(1,ms);
					cur=1;
				}

			}

		}

	}
	return ct;
}

int cr_ac(char msg[8][30])
{
	struct date d;
	getdate(&d);
	long an,ag,mn;
	char nam[30],fnam[30],ac_t[8],addr[50],des[50];
	char d_b[12],path[100],d_ac_o[12],d_tr[12],a[5],ac_nn[15],*endptr;
	double bal,dbt,crd;
	FILE *f1,*f2;
	if((f1=fopen("bank\\CUS_DETA.txt","a+"))==NULL)
	{
		return 0;
	}
	fclose(f1);
	an=gen_an();
	if(an==-1)
	{
		return 0;
	}
	ud.ac_no=an;
	if((f1=fopen("bank\\CUS_DETA.txt","a+"))==NULL)
	{
		return 0;
	}

		sprintf(ac_nn,"%d.txt",an);
		strcpy(path,"bank\\pass\\");
		strcat(path,ac_nn);

		if((f2=fopen(path,"a+"))==NULL)
		{
			return 0;
		}



	strcpy(nam,msg[0]);
	strcpy(ud.name,nam);

	strcpy(fnam,msg[1]);
	strcpy(ud.fname,fnam);

	ag = strtol(msg[2], &endptr, 10);
	ud.age=ag;

	strcpy(d_b,msg[3]);
	strcpy(ud.dob,d_b);

	strcpy(addr,msg[4]);
	strcpy(ud.address,addr);

     //	mn = strtol(msg[5], &endptr, 10);
	strcpy(ud.mb_no,msg[5]);

	strcpy(ac_t,msg[7]);
	strcpy(ud.ac_type,ac_t);

	crd = strtod(msg[6], &endptr);
	bal=crd;

	sprintf(d_ac_o,"%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	strcpy(ud.ac_op_date,d_ac_o);


	fwrite(&ud, sizeof(ud), 1, f1); /* write struct s to file */
	fclose(f1); /* close file */


		strcpy(ad.tr_date,d_ac_o);
		ad.debit=0;
		ad.credit=crd;
		ad.total_bal=bal;
		strcpy(ad.descr,"account open with ");

		fwrite(&ad, sizeof(ad), 1, f2); /* write struct s to file */
		fclose(f2); /* close file */


	return an;

}

long gen_an()
{
	FILE *l1;
	struct  user_det s;
	int t=0;
	if((l1=fopen("bank\\CUS_DETA.txt","r+"))==NULL)
	{
		return -1;
	}
	while(l1)
	{
		fread(&s,sizeof(s),1,l1);
		t++;
		if(s.ac_no>t)
		{
			break;
		}
		if(feof(l1))
		{
			break;
		}
	}
	fclose(l1);
	return t;
}

void login_ac(int cur,char ms[2][30])
{
	cleardevice();
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(50,50,400,400);
	setcolor(RED);
	settextstyle(1,HORIZ_DIR,4);
	setfillstyle(1,CYAN);
	bar(50,50,400,100);
	outtextxy(100,55,"LOGIN ACCOUNT");
	setcolor(BLUE);
	settextstyle(1,HORIZ_DIR,3);
	setfillstyle(1,YELLOW);
	bar(50,150,400,200);
	bar(50,250,400,300);
	line(50,350,400,350);
	outtextxy(60,120,"ENTER THE COSTUMER NAME : ");
	outtextxy(60,160,ms[0]);

	outtextxy(60,220,"ENTER THE AC. NO. : ");
	outtextxy(60,260,ms[1]);

	outtextxy(60,310,"SUBMIT             Ctrl+S ");
	outtextxy(60,360,"CANCEL             Ctrl+C");

	if(cur==1)
	{
		setfillstyle(1,GREEN);
		bar(50,150,400,200);
		outtextxy(60,160,ms[0]);

	}
	else if(cur==2)
	{
		setfillstyle(1,GREEN);
		bar(50,250,400,300);
		outtextxy(60,260,ms[1]);

	}
	else if(cur==3)
	{
		setfillstyle(1,GREEN);
		bar(50,300,400,350);
		outtextxy(60,310,"SUBMIT             Ctrl+S ");

	}
	else
	{
		setfillstyle(1,GREEN);
		bar(50,350,400,400);
		outtextxy(60,360,"CANCEL             Ctrl+C ");

	}
	settextstyle(0,HORIZ_DIR,1);

}

int login_check(char ms[2][30])
{
	FILE *l1;
	struct  user_det s;
	int t=0;
	char tt[30];
	if((l1=fopen("bank\\CUS_DETA.txt","r+"))==NULL)
	{
		return -1;
	}
	while(l1)
	{
		fread(&s,sizeof(s),1,l1);
		ltoa(s.ac_no,tt,10);
		if(strcmp(ms[0],s.name)==0 && strcmp(ms[1],tt)==0)
		{
			t=1;
		}

		if(feof(l1))
		{
			break;
		}
	}
	fclose(l1);
	return t;

}

void check_det(char msg[9][30])
{
	int x,y,i,j;
	char submsg[25];
	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(10,30,629,469);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(10,30,629,70);
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(170,30,"ACCOUNT DETAILS");

	settextstyle(1,HORIZ_DIR,2);
	setcolor(BLACK);
	outtextxy(20,80,"1. NAME ");
	outtextxy(290,80,msg[0]);

	line(10,110,629,110);
	outtextxy(20,120,"2. FATHER'S NAME ");
	outtextxy(290,120,msg[1]);

	line(10,150,629,150);
	outtextxy(20,160,"3. AGE ");
	outtextxy(290,160,msg[2]);

	line(10,190,629,190);
	outtextxy(20,200,"4. DATE OF BIRTH ");
	outtextxy(290,200,msg[3]);

	line(10,230,629,230);
	outtextxy(20,240,"5. ADDRESS ");
	outtextxy(290,240,msg[4]);

	line(10,270,629,270);
	outtextxy(20,280,"6. MOBILE NO. ");
	outtextxy(290,280,msg[5]);

	line(10,310,629,310);
	outtextxy(20,320,"7. ACCOUNT NUMBER");
	outtextxy(290,320,msg[6]);

	line(10,350,629,350);
	outtextxy(20,360,"8. ACCOUNT TYPE ");
	outtextxy(290,360,msg[7]);

	line(10,390,629,390);
	outtextxy(20,400,"9. TOTAL BALANCE ");
	outtextxy(290,400,msg[8]);
	line(10,430,629,430);
	line(250,70,250,430);
	setfillstyle(1,GREEN);
	settextstyle(1, HORIZ_DIR, 4);

	bar(10,430,629,469);
	outtextxy(310,433,"OK");
	settextstyle(0, HORIZ_DIR, 1);
}

struct msgarr det_copy()
{
	FILE *l1,*l2;
	struct  user_det s;
	struct  ac_det c;
	struct msgarr msg;
	int t;
	char tt[30];
 //	char static msg[9][30];
	char path[50],ap[30];
	strcpy(path,"bank\\pass\\");
	strcat(path,mm[1]);
	strcat(path,".txt");
	if((l1=fopen("bank\\CUS_DETA.txt","r+"))==NULL)
	{
		return msg;
	}
	if((l2=fopen(path,"r+"))==NULL)
	{
		return msg;
	}

	while(l1)
	{
		fread(&s,sizeof(s),1,l1);
		ltoa(s.ac_no,tt,10);
		if(strcmp(mm[0],s.name)==0 && strcmp(mm[1],tt)==0)
		{
			strcpy(msg.arr[0],s.name);
			strcpy(msg.arr[1],s.fname);
			ltoa(s.age,ap,10);
			strcpy(msg.arr[2],ap);
			strcpy(msg.arr[3],s.dob);
			//ltoa(s.mb_no,ap,10);
			strcpy(msg.arr[4],s.address);
			strcpy(msg.arr[5],s.mb_no);
			strcpy(msg.arr[6],tt);
			strcpy(msg.arr[7],s.ac_type);
		     //	strcpy(msg.arr[8],tt);
			break;

		}

		if(feof(l1))
		{
			break;
		}
	}
	while(l2)
	{
	   fread(&c,sizeof(c),1,l2);
	   sprintf(tt,"%.3f",c.total_bal);
	   strcpy(msg.arr[8],tt);
	   if(feof(l2))
	   {
		break;
	   }

	}
	fclose(l1);
	fclose(l2);
	return msg;
}

void trans_win2(int cur,char input[10],char descr[20])
{

	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(50,50,400,400);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(50,50,400,100);
	settextstyle(1, HORIZ_DIR, 3);
	outtextxy(80,60,"TRANSACTION WIN");
	
	setcolor(BLUE);
	settextstyle(1, HORIZ_DIR, 2);
	line(50,150,400,150);
	line(50,200,400,200);
	line(50,250,400,250);
	line(50,300,400,300);
	line(50,350,400,350);
	outtextxy(60,110,"ENTER THE AMOUNT : ");
	outtextxy(60,210,"DESCRIPTION : ");
	outtextxy(150,310,"SUBMIT ");
	outtextxy(150,360,"CANCEL");
	outtextxy(60,160,input);
	outtextxy(60,260,descr);
	if(cur==1)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,150,400,200);
		outtextxy(60,160,input);
	}
	if(cur==2)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,250,400,300);
		outtextxy(60,260,descr);
	}
	if(cur==3)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,300,400,350);
		outtextxy(150,310,"SUBMIT");
	}
	if(cur==4)
	{
		setcolor(RED);
		setfillstyle(1,GREEN);
		bar(50,350,400,400);
		outtextxy(150,360,"CANCEL");
	}
}

int update_details(char msg[][30])
{
	FILE *fp;
	struct user_det st;
	char ch, name[30],clas[5],*endptr;
	char aat[10];
	int rec, id, c;
	fp = fopen("bank\\CUS_DETA.txt", "r+");


	fseek(fp, 0, 0);

	int gp,sp,ngp;
	long ac_no;
	fpos_t flp;
	fgetpos(fp,&flp);

	while (fp)
	{
		fgetpos(fp,&flp);
		fread(&st, sizeof(st), 1, fp);

		sprintf(aat,"%d",st.ac_no);

		if ((strcmp(mm[1],aat)==0) && (strcmp(msg[0],st.name)==0))
		{
			fsetpos(fp,&flp);

			ac_no = strtol(mm[1], &endptr, 10);
			st.ac_no=ac_no;
			strcpy(st.name,msg[0]);
			strcpy(st.fname,msg[1]);
			st.age = strtol(msg[2], &endptr, 10);
			strcpy(st.dob,msg[3]);
			strcpy(st.address,msg[4]);
			strcpy(st.mb_no,msg[5]);
			strcpy(st.ac_type,msg[7]);
			strcpy(st.ac_op_date,st.ac_op_date);



			c = fwrite(&st, sizeof(st), 1, fp);
			break;
		}
		if(feof(fp))
		{
			break;
		}

	}
	fclose(fp);
	return c;
}

void update(int cur,char msg[9][30])
{
	int x,y,i,j;
	char submsg[25];
	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(10,30,629,469);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(10,30,629,70);
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(170,30,"UPDATE DETAILS");

	settextstyle(1,HORIZ_DIR,2);
	setcolor(BLACK);
	outtextxy(20,80,"1. NAME ");
	outtextxy(290,80,msg[0]);

	line(10,110,629,110);
	outtextxy(20,120,"2. FATHER'S NAME ");
	outtextxy(290,120,msg[1]);

	line(10,150,629,150);
	outtextxy(20,160,"3. AGE ");
	outtextxy(290,160,msg[2]);

	line(10,190,629,190);
	outtextxy(20,200,"4. DATE OF BIRTH ");
	outtextxy(290,200,msg[3]);

	line(10,230,629,230);
	outtextxy(20,240,"5. ADDRESS ");
	outtextxy(290,240,msg[4]);

	line(10,270,629,270);
	outtextxy(20,280,"6. MOBILE NUMBER ");
	outtextxy(290,280,msg[5]);

	line(10,310,629,310);
	outtextxy(20,320,"7. ACCOUNT TYPE");
	outtextxy(290,320,msg[7]);

	line(10,350,629,350);

	line(250,70,250,350);
	setfillstyle(1,BROWN);
	settextstyle(1, HORIZ_DIR, 4);
	bar(10,350,629,469);
	line(10,410,629,410);

	outtextxy(50,360,"SUBMIT Ctrl+S");
	outtextxy(50,420,"CANCEL Ctrl+C");
	settextstyle(1, HORIZ_DIR, 2);

	if(cur==1)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,70,629,110);
		outtextxy(290,80,msg[0]);
	}
	else if(cur==2)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,110,629,150);
		outtextxy(290,120,msg[1]);
	}
	else if(cur==3)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,150,629,190);
		outtextxy(290,160,msg[2]);
	}
	else if(cur==4)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,190,629,230);
		outtextxy(290,200,msg[3]);
	}
	else if(cur==5)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,230,629,270);
		outtextxy(290,240,msg[4]);
	}
	else if(cur==6)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,270,629,310);
		outtextxy(290,280,msg[5]);
	}
	else if(cur==7)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 2);
		bar(250,310,629,350);
		outtextxy(290,320,msg[7]);
	}
	else if(cur==8)
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 4);
		bar(10,350,629,410);
		outtextxy(50,360,"SUBMIT                     Ctrl+S");

	}
	else
	{
		setfillstyle(1,GREEN);
		settextstyle(1, HORIZ_DIR, 4);
		bar(10,410,629,469);
		outtextxy(50,420,"CANCEL                     Ctrl+C");

	}
	settextstyle(0, HORIZ_DIR, 1);
}

void new_ac_win(int cur,char msg[8][30])
{
	int x,y,i,j;
	char submsg[25];
	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(10,30,629,469);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(10,30,629,70);
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(170,30,"CREATE NEW ACCOUNT");

	settextstyle(1,HORIZ_DIR,2);
	setcolor(BLACK);
	outtextxy(20,80,"1. NAME ");
	outtextxy(290,80,msg[0]);

	line(10,110,629,110);
	outtextxy(20,120,"2. FATHER'S NAME ");
	outtextxy(290,120,msg[1]);

	line(10,150,629,150);
	outtextxy(20,160,"3. AGE ");
	outtextxy(290,160,msg[2]);

	line(10,190,629,190);
	outtextxy(20,200,"4. DATE OF BIRTH ");
	outtextxy(290,200,msg[3]);

	line(10,230,629,230);
	outtextxy(20,240,"5. ADDRESS ");
	outtextxy(290,240,msg[4]);

	line(10,270,629,270);
	outtextxy(20,280,"6. MOBILE NO. ");
	outtextxy(290,280,msg[5]);

	line(10,310,629,310);
	outtextxy(20,320,"7. AC. OPENNING AMOUNT ");
	outtextxy(290,320,msg[6]);

	line(10,350,629,350);
	outtextxy(20,360,"8. ACCOUNT TYPE ");
	outtextxy(290,360,msg[7]);

	line(10,390,629,390);
	settextstyle(0, HORIZ_DIR, 1);

	outtextxy(20,400,"HELP : ");
    //	outtextxy(20,420,msg);
	line(280,430,629,430);
	line(280,70,280,470);

	settextstyle(1, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(290,390,"C");
	settextstyle(1, HORIZ_DIR, 2);
	setcolor(BLACK);
	outtextxy(305,400,"ANCEL                    Ctrl+C");

	settextstyle(1, HORIZ_DIR, 4);
	setcolor(RED);
	outtextxy(290,430,"S");
	settextstyle(1, HORIZ_DIR, 2);
	setcolor(BLACK);
	outtextxy(305,440,"UBMIT                    Ctrl+S");
	settextstyle(1,HORIZ_DIR,2);

	if(cur==1)
	{
		setfillstyle(1,GREEN);
		bar(281,70,629,110);
		outtextxy(290,80,msg[0]);

	}
	else if(cur==2)
	{
		setfillstyle(1,GREEN);
		bar(281,110,629,150);
		outtextxy(290,120,msg[1]);

	}
	else if(cur==3)
	{
		setfillstyle(1,GREEN);
		bar(281,150,629,190);
		outtextxy(290,160,msg[2]);

	}
	else if(cur==4)
	{
		setfillstyle(1,GREEN);
		bar(281,190,629,230);
		outtextxy(290,200,msg[3]);

	}
	else if(cur==5)
	{
		setfillstyle(1,GREEN);
		bar(281,230,629,270);
		outtextxy(290,240,msg[4]);

	}
	else if(cur==6)
	{
		setfillstyle(1,GREEN);
		bar(281,270,629,310);
		outtextxy(290,280,msg[5]);

	}
	else if(cur==7)
	{
		setfillstyle(1,GREEN);
		bar(281,310,629,350);
		outtextxy(290,320,msg[6]);

	}
	else if(cur==8)
	{
		setfillstyle(1,GREEN);
		bar(281,350,629,390);
		outtextxy(290,360,msg[7]);

	}
	else if(cur==9)
	{
		setfillstyle(1,GREEN);
		bar(281,390,629,430);
		settextstyle(1, HORIZ_DIR, 4);
		setcolor(RED);
		outtextxy(290,390,"C");
		settextstyle(1, HORIZ_DIR, 2);
		setcolor(BLACK);
		outtextxy(305,400,"ANCEL                    Ctrl+C");

	}
	else
	{
		setfillstyle(1,GREEN);
		bar(281,430,629,470);
		settextstyle(1, HORIZ_DIR, 4);
		setcolor(RED);
		outtextxy(290,430,"S");
		settextstyle(1, HORIZ_DIR, 2);
		setcolor(BLACK);
		outtextxy(305,440,"UBMIT                    Ctrl+S");

	}

	settextstyle(0, HORIZ_DIR, 1);
}

char *char_inp(int cor[5],char msg[8][30],char win_name[15])
{
	int h,q,l,i,t,cr=cor[4];
	char inp[50];
	char chp[50],*endptr;
	char ch='0';
	char ap[50]="",bp[50],cp[50],dp[50];
	h=cor[0]+10;
	i=cor[1]+10;
	settextstyle(1,HORIZ_DIR,2);

	while(ch!='\r')
	{
	  //	delay(200);
		cleardevice();
		if(strcmp(win_name,"new_ac_win")==0)
		{
			new_ac_win(cr,msg);
		}
		if(strcmp(win_name,"update_win")==0)
		{
			update(cr,msg);
		}
		if(strcmp(win_name,"login_win")==0)
		{
			login_ac(cr,msg);
		}
		if(strcmp(win_name,"trans_win2")==0)
		{
			trans_win2(cr,inp_amt,descr);
		}

		setbkcolor(BLUE);
		setcolor(YELLOW);
		setfillstyle(1,RED);
		h=cor[0]+10;
		i=cor[1]+10;
		settextstyle(1,HORIZ_DIR,2);
		bar(cor[0],cor[1],cor[2],cor[3]);
		outtextxy(h,i,ap);
		ch=getch();

			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
			}

			if(ch=='a' || ch=='b'|| ch=='c'|| ch=='d' || ch=='e' || ch=='f'|| ch=='g' || ch=='h'|| ch=='i'|| ch=='j' || ch=='k' || ch=='l' || ch=='m' || ch=='n'|| ch=='o'|| ch=='p' || ch=='q' || ch=='r'|| ch=='s' || ch=='t'|| ch=='u'|| ch=='v' || ch=='w' || ch=='x' || ch=='y' || ch=='z')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}
			if(ch==' ' || ch=='A' || ch=='B'|| ch=='C'|| ch=='D' || ch=='E' || ch=='F'|| ch=='G' || ch=='H'|| ch=='I'|| ch=='J' || ch=='K' || ch=='L' || ch=='M' || ch=='N'|| ch=='O'|| ch=='P' || ch=='Q' || ch=='R'|| ch=='S' || ch=='T'|| ch=='U'|| ch=='V' || ch=='W' || ch=='X' || ch=='Y' || ch=='Z')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}


	 }
	 strcpy(dp,ap);
	 return(dp);
}

char *int_inp(int cor[5],char msg[8][30],char win_name[30])
{
	int h,q,l=0,i,t,cr=cor[4];
	char inp[50];
	char chp[50],*endptr;
	char ch='0';
	char ap[50]="",bp[50],cp[50],dp[50];
	h=cor[0]+10;
	i=cor[1]+10;
	settextstyle(1,HORIZ_DIR,2);

	while(ch!='\r')
	{
	    //	delay(200);
		cleardevice();
		if(strcmp(win_name,"new_ac_win")==0)
		{
			new_ac_win(cr,msg);
		}
		if(strcmp(win_name,"login_win")==0)
		{
			login_ac(cr,msg);
		}
		if(strcmp(win_name,"trans_win2")==0)
		{
			trans_win2(cr,inp_amt,descr);
		}
		if(strcmp(win_name,"update_win")==0)
		{
			update(cr,msg);
		}
		setbkcolor(BLUE);
		setcolor(YELLOW);
		setfillstyle(1,RED);
		h=cor[0]+10;
		i=cor[1]+10;
		settextstyle(1,HORIZ_DIR,2);
		bar(cor[0],cor[1],cor[2],cor[3]);
		outtextxy(h,i,ap);
		ch=getch();

			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
			}

			if(ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6'|| ch=='7'|| ch=='8' || ch=='9' || ch=='0')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}
			if(ch=='.')
			{
				if(l==0)
				{
					l=1;
					sprintf(chp,"%c",ch);
					strcat(ap,chp);
				}
			}


	 }
	 strcpy(dp,ap);
	 return(dp);
}

char *date_inp(int cor[5],char msg[8][30],char win_name[30])
{
	int h,q,l,i,t=0,cr=cor[4];
	char inp[50];
	char chp[50],*endptr;
	char ch='0';
	char ap[50]="",bp[50],cp[50],dp[50];
	h=cor[0]+10;
	i=cor[1]+10;
	settextstyle(1,HORIZ_DIR,2);

	while(ch!='\r')
	{
	//	delay(200);
		cleardevice();
		if(strcmp(win_name,"new_ac_win")==0)
		{
			new_ac_win(cr,msg);
		}
		if(strcmp(win_name,"login_win")==0)
		{
			login_ac(cr,msg);
		}
		if(strcmp(win_name,"trans_win2")==0)
		{
			trans_win2(cr,inp_amt,descr);
		}
		if(strcmp(win_name,"update_win")==0)
		{
			update(cr,msg);
		}
		setbkcolor(BLUE);
		setcolor(YELLOW);
		setfillstyle(1,RED);
		h=cor[0]+10;
		i=cor[1]+10;
		settextstyle(1,HORIZ_DIR,2);
		bar(cor[0],cor[1],cor[2],cor[3]);
		outtextxy(h,i,ap);
		ch=getch();

			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
				t--;
			}
			if(ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6'|| ch=='7'|| ch=='8' || ch=='9' || ch=='0')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
				t++;
			}
			q=strlen(ap)-1;
			if(q==1 || q==4)
			{
				strcat(ap,"/");
				t++;
			}
			if(t==10)
			{
				strcpy(dp,ap);
				return dp;
			}


	 }
	 strcpy(dp,ap);
	 return(dp);
}

char *mix_char_inp(int cor[5],char msg[8][30],char win_name[30])
{
	int h,q,l,i,t,cr=cor[4];
	char inp[50];
	char chp[50],*endptr;
	char ch='0';
	char ap[50]="",bp[50],cp[50],dp[50];
	h=cor[0]+10;
	i=cor[1]+10;
	settextstyle(1,HORIZ_DIR,2);

	while(ch!='\r')
	{
	  //	delay(200);
		cleardevice();

		if(strcmp(win_name,"new_ac_win")==0)
		{
			new_ac_win(cr,msg);
		}
		if(strcmp(win_name,"login_win")==0)
		{
			login_ac(cr,msg);
		}
		if(strcmp(win_name,"trans_win2")==0)
		{
			trans_win2(cr,inp_amt,descr);
		}
		if(strcmp(win_name,"update_win")==0)
		{
			update(cr,msg);
		}
		setbkcolor(BLUE);
		setcolor(YELLOW);
		setfillstyle(1,RED);
		h=cor[0]+10;
		i=cor[1]+10;
		settextstyle(1,HORIZ_DIR,2);
		bar(cor[0],cor[1],cor[2],cor[3]);
		outtextxy(h,i,ap);
		ch=getch();

			if(ch=='\b')
			{
				strcpy(bp,ap);
				strrev(bp);
				q=strlen(bp)-1;
				i=0;
				while(q>0)
				{
					cp[i]=bp[q];
					i++;
					q--;
				}
				cp[i]='\0';
				strcpy(ap,cp);
			}

			if(ch=='a' || ch=='b'|| ch=='c'|| ch=='d' || ch=='e' || ch=='f'|| ch=='g' || ch=='h'|| ch=='i'|| ch=='j' || ch=='k' || ch=='l' || ch=='m' || ch=='n'|| ch=='o'|| ch=='p' || ch=='q' || ch=='r'|| ch=='s' || ch=='t'|| ch=='u'|| ch=='v' || ch=='w' || ch=='x' || ch=='y' || ch=='z')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}
			if(ch==' ' || ch=='A' || ch=='B'|| ch=='C'|| ch=='D' || ch=='E' || ch=='F'|| ch=='G' || ch=='H'|| ch=='I'|| ch=='J' || ch=='K' || ch=='L' || ch=='M' || ch=='N'|| ch=='O'|| ch=='P' || ch=='Q' || ch=='R'|| ch=='S' || ch=='T'|| ch=='U'|| ch=='V' || ch=='W' || ch=='X' || ch=='Y' || ch=='Z')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}
			if(ch==',' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6'|| ch=='7'|| ch=='8' || ch=='9' || ch=='0')
			{
				sprintf(chp,"%c",ch);
				strcat(ap,chp);
			}




	 }
	 strcpy(dp,ap);
	 return(dp);
}

void win_main(int cur)
{
	int x,y;
	settextstyle(4, HORIZ_DIR, 2);
	setbkcolor(BLUE);
	setcolor(RED);
	setfillstyle(1,YELLOW);
	bar(0,0,639,25);
	outtextxy(220,0,"YOGESH PATEL BANK ");
	setcolor(RED);
	setfillstyle(1,WHITE);
	bar(10,30,629,469);
	setcolor(RED);
	setfillstyle(1,LIGHTGRAY);
	bar(10,30,629,70);
	settextstyle(1, HORIZ_DIR, 4);
	outtextxy(220,32,"MAIN MENU");
	line(10,135,629,135);
	line(10,200,629,200);
	line(10,265,629,265);
	line(10,330,629,330);
	line(10,395,629,395);
	settextstyle(1, HORIZ_DIR, 3);
	setcolor(BLACK);
	outtextxy(50,90,"1. CREATE NEW ACCOUNT");
	outtextxy(50,150,"2. CHECK ACCOUNT DETAILS");
	outtextxy(50,215,"3. UPDATE EXISTING ACCOUNT DETAILS");
	outtextxy(50,280,"4. MAKE TRANSACTION");
	outtextxy(50,345,"5. DELETE THE EXISTING ACCOUNT");
	outtextxy(50,410,"6. EXIT");
	if(cur==1)
	{
		setfillstyle(1,GREEN);
		bar(10,70,629,135);
		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(50,90,"1. CREATE NEW ACCOUNT");
	}
	else if(cur==2)
	{
		setfillstyle(1,GREEN);
		bar(10,135,629,200);
		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(50,150,"2. CHECK ACCOUNT DETAILS");

	}
	else if(cur==3)
	{
		setfillstyle(1,GREEN);
		bar(10,200,629,265);
		settextstyle(1, HORIZ_DIR, 3);
		outtextxy(50,215,"3. UPDATE EXISTING ACCOUNT DETAILS");
	}
	else if(cur==4)
	{
		setfillstyle(1,GREEN);
		bar(10,265,629,330);
		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(50,280,"4. MAKE TRANSACTION");
	}
	else if(cur==5)
	{
		setfillstyle(1,GREEN);
		bar(10,330,629,395);
		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(50,345,"5. DELETE THE EXISTING ACCOUNT");
	}
	else
	{
		setfillstyle(1,GREEN);
		bar(10,395,629,469);
		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(50,410,"6. EXIT");
	}
	settextstyle(0, HORIZ_DIR, 1);
}
