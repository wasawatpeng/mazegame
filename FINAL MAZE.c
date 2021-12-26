#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<windows.h>

char victory(int count,int hp,char life[4],int score,int mode,char s[3]);
char lost(int count,int hp,char life[4],int score,int mode,char s[3]);
void how();
char welcome();
char select_mode();
void set_map(char s[3],char stage[20][20]);


main()
{
    char stage[20][20];
    int i,j,count=200,hp;
    char move,t;
    int posx=1,posy=1;
    char life[11]={'X','X','X','X','X','X','X','X','X','X'};
    char n;
    int r;
    int eny1=7,enx1=11;
    int eny2=6,enx2=18;
    int eny[4],enx[4];
    int enm1;
    int enm2;
    int retry=0;
    char a;
    char s[3]={NULL};
    char mode;
    int score=0;
    int num;

    printf("\n\n");
    printf("                XXXXXXXX   XX    XX   XXXXXX           XXXX      XXXXX      XXXXXX      XXXX      XX    XX    XXXXXX        XX       XX     XXXX     XXXXXXX   XXXXXX   \n");
    printf("                   XX      XX    XX   XX             XX    XX    XX   XX      XX      XX    XX    XX    XX   XX             XXXX   XXXX   XX    XX        XX   XX       \n");
    printf("                   XX      XXXXXXXX   XXXXXX        XX      XX   XX    XX     XX     XX      XX   XX    XX    XXXXX         XX XX XX XX   XXXXXXXX      XX     XXXXXX   \n");
    printf("                   XX      XX    XX   XX             XX    XX    XX   XX      XX      XX    XX    XX    XX        XX        XX  XXX  XX   XX    XX    XX       XX       \n");
    printf("                   XX      XX    XX   XXXXXX           XXXX      XXXXX      XXXXXX      XXXX        XXXX     XXXXXX         XX   X   XX   XX    XX   XXXXXXX   XXXXXX   \n");
    printf("\n\n                ");
    printf("Press any key to continue...");

    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(494,400);
    Beep(587,400);
    Beep(523,400);
    Beep(440,750);

    Beep(330,400);
    Beep(440,400);
    Beep(523,400);
    Beep(659,400);
    Beep(880,400);
    Beep(988,400);

    Beep(330,400);
    Beep(415,400);
    Beep(659,400);
    Beep(831,400);
    Beep(988,400);
    Beep(1047,400);

    Beep(330,400);
    Beep(440,400);
    Beep(659,400);
    Beep(659,400);

    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(622,400);
    Beep(659,400);
    Beep(494,400);
    Beep(587,400);
    Beep(523,400);
    Beep(440,1000);

    _getch();

	while(1)
    {
	mode = welcome(); // รับค่าความยากจาก function welcome()
	if(mode=='1')
        hp=5;
    else if(mode=='2')
        hp=10;
    s[0]='1';  // กำหนดค่าเริ่มต้นสำหรับด่านแรก
    set_map(s,stage);
    num=2;
    eny[0]=15;
    enx[0]=5;
    eny[1]=1;
    enx[1]=17;
    posx=1; posy=1;
    stage[posy][posx]='*';
    for(i=0;i<num;i++)
    {
    stage[eny[i]][enx[i]]='X';
    }
    while(1)
    {

    if(count==0||hp==0) // เเมื่อเลือดหรือจำนวนการเดินหมดให้แช่หน้าจอใว้
    {
        if(mode=='1')
        score+=count*hp;
        else if(mode=='2')
        score+=count*hp*2;

        system("COLOR C"); //เปลี่ยนข้อความเป็นสีแดง
        printf("\n\n");
    	if(s[0]=='8')
        printf("                                                                                               Final Stage\n",s); // แสดงข้อมูลของด่าน
        else
        printf("                                                                                                  Stage %s\n",s); // แสดงข้อมูลของด่าน
    	if(mode=='1')
    	printf("                                                                                  Normal mode                ");
    	else if(mode=='2')
    	printf("                                                                                  Hard mode                  ");
    	printf("Score : %d\n",score);
        printf("                                                                                  Moving remaining : %d",count);
        printf("     Life : ");

        for(i=0;i<hp;i++)
        {
            printf("%c",life[i]);
        }

        printf("\n\n");

        for(i=0;i<20;i++)
        {
            printf("                                                                                 ");
            for(j=0;j<20;j++)
            {
                if(stage[i][j]=='|'||stage[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",stage[i][j]);
            }
            printf("\n");
        }
        _getch();
        system("cls");
    }

    if(retry==1) //เมื่อผู้เล่นเลือก retry จะกลับไปจุดเริ่มต้นของด่าน
    {
        set_map(s,stage);
                if(s[0]=='1')
                {
                    num=2;
                    eny[0]=15;
                    enx[0]=5;
                    eny[1]=1;
                    enx[1]=17;
                    posx=1; posy=1;
                    stage[posy][posx]='*';
                    for(i=0;i<num;i++)
                    {
                        stage[eny[i]][enx[i]]='X';
                    }
                }
                else if(s[0]=='2')
					{
						num=2;
   					 	eny[0]=8;
   						enx[0]=8;
    					eny[1]=13;
    					enx[1]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='3')
					{
					    num=2;
                        eny[0]=9;
   						enx[0]=5;
    					eny[1]=13;
    					enx[1]=17;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='4')
					{
                        num=2;
   					 	eny[0]=5;
   						enx[0]=17;
    					eny[1]=15;
    					enx[1]=7;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='5')
					{
                        num=3;
   					 	eny[0]=10;
   						enx[0]=8;
    					eny[1]=17;
    					enx[1]=7;
    					eny[2]=13;
    					enx[2]=13;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='6')
					{
                        num=3;
   					 	eny[0]=1;
   						enx[0]=7;
    					eny[1]=13;
    					enx[1]=7;
    					eny[2]=17;
    					enx[2]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='7')
					{
                        num=3;
   					 	eny[0]=6;
   						enx[0]=10;
    					eny[1]=12;
    					enx[1]=4;
    					eny[2]=13;
    					enx[2]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='8')
					{
                        num=4;
   					 	eny[0]=4;
   						enx[0]=8;
    					eny[1]=9;
    					enx[1]=9;
    					eny[2]=10;
    					enx[2]=12;
    					eny[3]=14;
    					enx[3]=10;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
        for(i=0;i<20;i++)
        {
            for(j=0;j<20;j++)
            {
                if(stage[i][j]=='|'||stage[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",stage[i][j]);
            }
            printf("\n");
        }
        system("cls"); count=200; hp=5; retry=0;
    }

    if(count==0||hp==0) //เมื่อเลือดเหลือ 0 หรือจำนวยการเดินหมด จะเข้า function lose
    {
        if(mode=='1')
        score+=count*hp;
        else if(mode=='2')
        score+=count*hp*2;

        n = lost(count,hp,life,score,mode,s);

        switch(n)
        {
        case '1': count=200; hp=5; retry=1; printf("\n%d\n",retry); _getch; break;
        case '2': count=200; hp=5; score=0; system("cls");  break;
        }
        if(n=='2')break;
    }

    else //เมื่อเลือดและจำนวนการเดินยังไม่หมด
    {
        printf("\n\n");
    	if(s[0]=='8')
        printf("                                                                                               Final Stage\n",s); // แสดงข้อมูลของด่าน
        else
        printf("                                                                                                  Stage %s\n",s); // แสดงข้อมูลของด่าน
    	if(mode=='1')
    	printf("                                                                                  Normal mode                ");
    	else if(mode=='2')
    	printf("                                                                                  Hard mode                  ");
    	printf("Score : %d\n",score);
        printf("                                                                                  Moving remaining : %d",count);
        printf("     Life : ");

        for(i=0;i<hp;i++)
        {
            printf("%c",life[i]);
        }
            printf("\n\n");

        for(i=0;i<20;i++) // แสดงภาพด่าน
        {
            printf("                                                                                 ");
            for(j=0;j<20;j++)
            {
                if(stage[i][j]=='|'||stage[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",stage[i][j]);
            }
            printf("\n");
        }

        system("COLOR 7"); //ตั้งค่าสีข้อความ

    while(1) //รับค่าเพื่อเคลื่อนที่ตัวละคร
    {
        move = _getch();
        if(move=='w'&&(stage[posy-1][posx]==' '||stage[posy-1][posx]=='E'))
            break;
        else if(move=='a'&&(stage[posy][posx-1]==' '||stage[posy][posx-1]=='E'))
            break;
        else if(move=='s'&&(stage[posy+1][posx]==' '||stage[posy+1][posx]=='E'))
            break;
        else if(move=='d'&&(stage[posy][posx+1]==' '||stage[posy][posx+1]=='E'))
            break;
    }
    count--; //ลบจำนวนการเดินแต่ละครั้ง

    for(i=0;i<num;i++) // random การเดินของศัตรู โดยใช้เงื่อนไขเพื่อเพิ่มความเร็วในการคำนวณ
    {
    srand(time(NULL));
    if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%4;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 2: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 3: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%3;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 2: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%3;
        printf("3 ");
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 2: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%3;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 2: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        r = rand()%3;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 2: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        r = rand()%2;
        switch(r)
        {
            case 0: stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X'; break;
            case 1: stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X'; break;
        }
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]==' ')
    {
        stage[eny[i]][enx[i]]=' '; enx[i]--; stage[eny[i]][enx[i]]='X';
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]==' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        stage[eny[i]][enx[i]]=' '; enx[i]++; stage[eny[i]][enx[i]]='X';
    }

    else if(stage[eny[i]+1][enx[i]]==' ' && stage[eny[i]-1][enx[i]]!=' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        stage[eny[i]][enx[i]]=' '; eny[i]++; stage[eny[i]][enx[i]]='X';
    }

    else if(stage[eny[i]+1][enx[i]]!=' ' && stage[eny[i]-1][enx[i]]==' ' && stage[eny[i]][enx[i]+1]!=' ' && stage[eny[i]][enx[i]-1]!=' ')
    {
        stage[eny[i]][enx[i]]=' '; eny[i]--; stage[eny[i]][enx[i]]='X';
    }
	}

    switch(move) // เคลื่อนที่ตัวละครตามค่าที่รับมา
    {
        case 'w': t=stage[posy-1][posx]; stage[posy][posx]=' '; posy--; stage[posy][posx]='*'; break;
        case 'a': t=stage[posy][posx-1]; stage[posy][posx]=' '; posx--; stage[posy][posx]='*'; break;
        case 's': t=stage[posy+1][posx]; stage[posy][posx]=' '; posy++; stage[posy][posx]='*'; break;
        case 'd': t=stage[posy][posx+1]; stage[posy][posx]=' '; posx++; stage[posy][posx]='*'; break;
    }

    if(t=='X') //เมื่อตัวละครชนกับศัตรู
    {
        system("COLOR C"); //เปลี่ยนข้อความเป็นสีแดง
        hp--; //ลดเลือด 1 แต้ม
        Beep(1000,100);
        //_getch();
    }

    if(t=='E') //เมื่อตัวละครเถึงทางออกจะเข้า function victory
    {
        if(mode=='1')
        score+=count*hp;
        else if(mode=='2')
        score+=count*hp*2;

        n = victory(count,hp,life,score,mode,s);
        switch(n)
        {
        case '1': count=200; if(mode=='1')hp=5; s[0]+=1; set_map(s,stage);
				if(s[0]=='2')
					{
						num=2;
   					 	eny[0]=8;
   						enx[0]=8;
    					eny[1]=13;
    					enx[1]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='3')
					{
					    num=2;
                        eny[0]=9;
   						enx[0]=5;
    					eny[1]=13;
    					enx[1]=17;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='4')
					{
                        num=2;
   					 	eny[0]=5;
   						enx[0]=17;
    					eny[1]=15;
    					enx[1]=7;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='5')
					{
                        num=3;
   					 	eny[0]=10;
   						enx[0]=8;
    					eny[1]=17;
    					enx[1]=7;
    					eny[2]=13;
    					enx[2]=13;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='6')
					{
                        num=3;
   					 	eny[0]=1;
   						enx[0]=7;
    					eny[1]=13;
    					enx[1]=7;
    					eny[2]=17;
    					enx[2]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='7')
					{
                        num=3;
   					 	eny[0]=6;
   						enx[0]=10;
    					eny[1]=12;
    					enx[1]=4;
    					eny[2]=13;
    					enx[2]=15;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
				else if(s[0]=='8')
					{
                        num=4;
   					 	eny[0]=4;
   						enx[0]=8;
    					eny[1]=9;
    					enx[1]=9;
    					eny[2]=10;
    					enx[2]=12;
    					eny[3]=14;
    					enx[3]=10;
    					posx=1; posy=1;
    					stage[posy][posx]='*';
    					for(i=0;i<num;i++)
    					{
    						stage[eny[i]][enx[i]]='X';
    					}
					}
                break;
        case '2': count=200; hp=5; score=0; system("cls"); break;
        }
        if(n=='2')break;
    }
    system("cls"); //ล้างหน้าจอ
    }
    }
}
}

char welcome() //เป็น function เริ่มต้น เปรียบเสมือนหน้าเมนูหลัก
{
    system("COLOR 7");
    system("cls");
    char n;
    int mode;
    printf("\n\n");
    printf("                XXXXXXXX   XX    XX   XXXXXX           XXXX      XXXXX      XXXXXX      XXXX      XX    XX    XXXXXX        XX       XX     XXXX     XXXXXXX   XXXXXX   \n");
    printf("                   XX      XX    XX   XX             XX    XX    XX   XX      XX      XX    XX    XX    XX   XX             XXXX   XXXX   XX    XX        XX   XX       \n");
    printf("                   XX      XXXXXXXX   XXXXXX        XX      XX   XX    XX     XX     XX      XX   XX    XX    XXXXX         XX XX XX XX   XXXXXXXX      XX     XXXXXX   \n");
    printf("                   XX      XX    XX   XX             XX    XX    XX   XX      XX      XX    XX    XX    XX        XX        XX  XXX  XX   XX    XX    XX       XX       \n");
    printf("                   XX      XX    XX   XXXXXX           XXXX      XXXXX      XXXXXX      XXXX        XXXX     XXXXXX         XX   X   XX   XX    XX   XXXXXXX   XXXXXX   \n");
    printf("\n\n");
    printf("                                                                                Start game (Press 1)\n");
    printf("                                                                                How to play (Press 2)\n");
    printf("                                                                                Exit (Press 3)\n");
    while(1)
    {
        n = _getch();
        if(n=='1'||n=='2'||n=='3') break;
    }
    switch(n)
    {
        case '1': mode=select_mode(); return mode; break;
        case '2': how(); break;
        case '3': exit(0); break;
    }
}

char select_mode() //เลือกระดับความยาก
{
    char mode;
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("                                                                                Select Mode ( 1 = Normal, 2 = Hard ) : ");\
	while(1)
	{
		mode = _getch();
		if(mode=='1'||mode=='2')
		{
		system("cls");
    	return mode;
		break;
		}
	}
}

void how() //แสดงวิธีเล่น
{
    char n;
    system("cls");
    printf("\n\n");
    printf("                                                                             -------------------\n");
    printf("                                                                                 How to play\n");
    printf("                                                                             -------------------\n");
    printf("                                                   Move your character to escape the maze\n");
    printf("                                                   You need to avoid your enemy.If you hit it, you will lose your health point.\n\n");
    printf("                                                   * --> Your character\n");
    printf("                                                   E --> Exit\n");
    printf("                                                   X --> Your enemy\n");
    printf("                                                                             --------------------\n");
    printf("                                                                                     Mode\n");
    printf("                                                                             --------------------\n");
    printf("                                                   Normal mode :\n");
    printf("                                                   1. You can retry, if you lose\n");
    printf("                                                   2. When you pass each stages, your health point will heal to max\n");
    printf("                                                   Hard mode : \n");
    printf("                                                   1. If you lose, you can not retry and you will back to the main menu\n");
    printf("                                                   2. You have 10 health point and can not heal\n");
    printf("                                                   3. Score x2\n");
    printf("                                                                             --------------------\n");
    printf("                                                                                   Controls\n");
    printf("                                                                             --------------------\n");
	printf("                                                                       W --> Move up   S --> Move down\n");
	printf("                                                                       A --> Move left D --> Move right\n");
	printf("                                                                             -------------------\n");
    printf("                                                                                Back (Press 1)");
    while(1)
    {
        n = _getch();
        if(n=='1') break;
    }
    welcome();
}

char victory(int count,int hp,char life[4],int score,int mode,char s[3]) //แสดงผลเมื่อผู้เล่นชนะแต่ละด่าน
{
    system("COLOR 2");
    char  n;
    char win[20][20]=
    {
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ','Y','O','U',' ','W','I','N','!',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        };
    char win_game[20][20]=
    {
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ','C','O','N','G','R','A','T','U','L','A','T','I','O','N','S','!',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|','Y','O','U',' ','H','A','V','E',' ','C','O','M','P','L','E','T','E','D','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ','A',' ','G','R','E','A','T',' ','G','A','M','E',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|','T','H','A','N','K','S',' ','F','O','R',' ','P','L','A','Y','I','N','G','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        };
    int i,j;
    system("cls");
    printf("\n\n");
    if(s[0]=='8')
        printf("                                                                                               Final Stage\n",s); // แสดงข้อมูลของด่าน
    else
        printf("                                                                                                  Stage %s\n",s); // แสดงข้อมูลของด่าน
    	if(mode=='1')
    	printf("                                                                                  Normal mode                ");
    	else if(mode=='2')
    	printf("                                                                                  Hard mode                  ");
    	printf("Score : %d\n",score);
        printf("                                                                                  Moving remaining : %d",count);
        printf("     Life : ");
    for(i=0;i<hp;i++)
    {
        printf("%c",life[i]);
    }
    printf("\n\n");
    if(s[0]=='8')
    {
        for(i=0;i<20;i++)
        {
                            printf("                                                                                 ");
        for(j=0;j<20;j++)
            {
                if(win_game[i][j]=='|'||win_game[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",win_game[i][j]);
            }
            printf("\n");
        }
        printf("\n                                                                                 Back to the main menu (Press 1) ");
    }
    else
    {
        for(i=0;i<20;i++)
        {
                            printf("                                                                                 ");
        for(j=0;j<20;j++)
            {
                if(win[i][j]=='|'||win[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",win[i][j]);
            }
            printf("\n");
        }
            printf("\n                                                                                 Next stage (Press 1) \n");
            printf("                                                                                 Back to the main menu (Press 2) ");
    }
    Beep(1319,200);
    Beep(1319,300);
    Beep(1319,400);
    Beep(1319,750);
    Beep(1047,750);
    Beep(1175,750);
    Beep(1319,500);
    Beep(1319,200);
    Beep(1319,1000);
        while(1)
        {
            n = _getch();
            if((n=='1'||n=='2')&&s[0]!='8') {return n; break;}
            else if(n=='1'&&s[0]=='8') {return '2'; break;}
        }
}
char lost(int count,int hp,char life[4],int score,int mode,char s[3]) //แสดงผลเมื่อตัวละครแพ้
{
    char n;
    char over[20][20]={
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ','G','A','M','E',' ','O','V','E','R','!',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
        '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',
        };
    int i,j;
    printf("\n\n");
    if(s[0]=='8')
        printf("                                                                                               Final Stage\n",s); // แสดงข้อมูลของด่าน
    else
        printf("                                                                                                  Stage %s\n",s); // แสดงข้อมูลของด่าน
    	if(mode=='1')
    	printf("                                                                                  Normal mode                ");
    	else if(mode=='2')
    	printf("                                                                                  Hard mode                  ");
    	printf("Score : %d\n",score);
        printf("                                                                                  Moving remaining : %d     ",count);
        printf("Life : ");
    for(i=0;i<hp;i++)
    {
        printf("%c",life[i]);
    }
    printf("\n\n");
    for(i=0;i<20;i++)
    {
        printf("                                                                                 ");
        for(j=0;j<20;j++)
            {
                if(over[i][j]=='|'||over[i][j]=='-')
                    printf("%c%c",178,178);
                else
                    printf("%c ",over[i][j]);
            }
            printf("\n");
    }

    if(mode=='1')
    {
    printf("\n                                                                                 Retry (Press 1) \n");
    printf("                                                                                 Back to the main menu (Press 2) ");
    Beep(262,300);
    Beep(262,400);
    Beep(262,500);
    Beep(250,1200);
        while(1)
        {
            n = _getch();
            if(n=='1'||n=='2') {return n; break;}
        }
	}

	else if(mode=='2')
	{
    printf("\n                                                                                 Back to the main menu (Press 1) ");
    Beep(262,300);
    Beep(262,400);
    Beep(262,500);
    Beep(250,1200);
        while(1)
        {
            n = _getch();
            if(n=='1') {return n='2'; break;}
        }
	}
}

void set_map(char s[3],char stage[20][20]) //รับค่าแผนที่ในแต่ละด่านจาก file
{
    int i,j;
    char a;
    FILE *map;

    map=fopen(s,"r");
    i=0;
    j=0;
    while((a=fgetc(map))!=EOF)
    {
            stage[i][j]=a;
            j++;
        if(a=='\n')
        {
            i++;
            j=0;
        }
    }
    fclose(map);

}
