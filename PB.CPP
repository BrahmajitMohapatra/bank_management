#include <graphics.h>
#include <stdlib.h>
#include<string.h>
#include <stdio.h>
#include <conio.h>
struct ac_det
{
	char tr_date[11];
	char descr[50];
	double debit;
	double credit;
	double total_bal;
};
void passbook(int,char[]);
void pass_show(int);
void main()
{
	int ac_no;
	int gdriver = DETECT, gmode, errorcode;
	printf("Enter the account no. ");
	scanf("%d",&ac_no);
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
	pass_show(ac_no);
 //	getch();
	closegraph();
}
void pass_show(int ac)
{
	FILE *l2;
	char tr_dat[11],des[50],db[15],cr[15],tt[15];
	double deb,cre,to_bal;
	int i,ef=0;
	struct ac_det c;
	char cho='o',mm[5];
	sprintf(mm,"%d",ac);
	char path[30]="bank\\pass\\";
	strcat(path,mm);
	strcat(path,".txt");
	if((l2=fopen(path,"r+"))==NULL)
	{
		outtextxy(100,100,"WRONG ACCOUNT NUMBER ");
		getch();
		return;
	}
	else
	{
		while(l2)
		{
			cleardevice();
			passbook(ef,mm);
			for(i=0;i<12;i++)
			{
				fread(&c,sizeof(c),1,l2);
				if(feof(l2))
				{
					ef=1;
					break;
				}
				strcpy(tr_dat,c.tr_date);
				strcpy(des,c.descr);
				deb=c.debit;
				cre=c.credit;
				to_bal=c.total_bal;
				sprintf(db,"%.2f",deb);
				sprintf(cr,"%.2f",cre);
				sprintf(tt,"%.2f",to_bal);
				setcolor(RED);
				outtextxy(5,80+i*30,tr_dat);
				outtextxy(130,80+i*30,db);
				outtextxy(255,80+i*30,cr);
				outtextxy(380,80+i*30,tt);
				outtextxy(505,80+i*30,des);
			}
			cho=getch();
			if(cho=='x' || cho=='X')
			{
				return;
			}
			if(ef==1)
			{
				break;

			}

		}
	}
	fclose(l2);

}
void passbook(int ef,char ac[5])
{
	settextstyle(1,0,2);
	setcolor(YELLOW);
	setfillstyle(1,6);
	bar(0,0,640,50);
	outtextxy(230,5,"Yogesh patel Bank");
	outtextxy(10,25,"AC NO. : ");
	outtextxy(100,25,ac);

	setcolor(RED);
	setfillstyle(1,3);
	bar(0,50,640,430);
	settextstyle(1,0,1);
	outtextxy(5,50,"Tra. Date");
	outtextxy(130,50,"Debit");
	outtextxy(255,50,"Credit");
	outtextxy(380,50,"Total");
	outtextxy(505,50,"Description");

	line(0,75,680,75);
	line(125,50,125,430);
	line(250,50,250,430);
	line(375,50,375,430);
	line(500,50,500,430);

	setcolor(GREEN);
	setfillstyle(1,4);
	bar(0,430,640,480);

	settextstyle(1,0,1);
	if(ef==0)
	{
		outtextxy(5,430,"Press any key to next page");
		outtextxy(5,450,"Press X : to Exit");
	}
	else
	{
		setcolor(GREEN);
		setfillstyle(1,4);
		bar(0,430,640,480);
		settextstyle(1,0,1);
		outtextxy(5,430,"End Of File");
		outtextxy(5,450,"Press any key to Exit ");
	}

}
