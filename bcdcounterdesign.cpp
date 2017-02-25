#include<iostream>
#include<graphics.h>
#include"jkbcd.h"
#define converttochar(Q) ( (Q)== 1? "1" : "0")
using namespace std;

int counts = 0;

void drawclockpulseup(){
/** high pulse*/
int uplevel = 510;
int downlevel = 535;
    setcolor(4);
    line(30+counts*50,downlevel,30+counts*50,uplevel);/**left*/
    line(30+counts*50,uplevel,30+counts*50+20,uplevel);/**up*/
    line(30+counts*50+20,downlevel,30+counts*50+20,uplevel);/**right*/
    line(30+counts*50,downlevel,30+counts*50+20,downlevel);/**down*/
    setfillstyle(1,4);
    floodfill(30+counts*50+10,(uplevel+downlevel)/2,4);
    line(30+counts*50,565,30+counts*50+20,565);/**for f f s down pulse*/
    line(30+counts*50,595,30+counts*50+20,595);
    line(30+counts*50,625,30+counts*50+20,625);
    line(30+counts*50,655,30+counts*50+20,655);


}


void cline(int x1,int y1,int x2,int y2,int mode){
    if(mode)
        setcolor(10);
    else
        setcolor(8);
    line(x1,y1,x2,y2);

}

void drawHeading(){
settextstyle(10,0,4);
setbkcolor(15);
setcolor(0);
outtextxy(400,10,"SYNCHRONOUS BCD COUNTER");
}

void drawPulse(int i){

    int uplevel,downlevel;
    int ff;
    switch(i){
case 0:
    uplevel = 540;
    ff = 0;
    break;
case 230:
    uplevel = 570;
    ff = 1;
    break;
case 460:
    uplevel = 600;
    ff = 2;
    break;
case 790:
    uplevel = 630;
    ff = 3;
    break;

}
downlevel = uplevel + 25;
setcolor(4);
 line(50+counts*50,535,50+counts*50+30,535);/** down clock pulse*/
if(!ffs[ff].Q){/**low pulse*/
    line(50+counts*50,downlevel,50+counts*50+30,downlevel);
}else{/** high pulse*/
    line(50+counts*50,downlevel,50+counts*50,uplevel);/**left*/
    line(50+counts*50,uplevel,50+counts*50+30,uplevel);/**up*/
    line(50+counts*50+30,downlevel,50+counts*50+30,uplevel);/**right*/
    line(50+counts*50,downlevel,50+counts*50+30,downlevel);/**down*/
    setfillstyle(1,4);
    floodfill(50+counts*50+15,(uplevel+downlevel)/2,4);
}
    if(i==790)
        counts++;
}




void displayvalues(){
    char ch[2];
if(ffs[0].Q)
    setcolor(10);
else
    setcolor(8);
itoa(ffs[0].Q,ch,10);
outtextxy(300,45,ch);

if(ffs[1].Q)
    setcolor(10);
else
    setcolor(8);
itoa(ffs[1].Q,ch,10);
outtextxy(300+230,45,ch);

if(ffs[2].Q)
    setcolor(10);
else
    setcolor(8);
itoa(ffs[2].Q,ch,10);
outtextxy(300+460,45,ch);

if(ffs[3].Q)
    setcolor(10);
else
    setcolor(8);
itoa(ffs[3].Q,ch,10);
outtextxy(300+790,45,ch);

}


void drawFlipFlop(int marginx){
    /**FlipFlop**/
settextstyle(10,0,3);
setlinestyle(1,1,2);
setcolor(0);
setbkcolor(15);
rectangle(200+marginx,220,300+marginx,370);/**frame*/
outtextxy(210+marginx,230,"J");
outtextxy(210+marginx,335,"K");
outtextxy(280+marginx,230,"Q");
outtextxy(280+marginx,308,"_");
outtextxy(280+marginx,335,"Q");
line(200+marginx,285,220+marginx,295);/**arrow*/
line(200+marginx,305,220+marginx,295);/**arrow*/
setlinestyle(1,1,3);
setcolor(8);
if(!marginx)
    setcolor(10);
line(198+marginx,240,170+marginx,240);/**from j*/
line(198+marginx,345,170+marginx,345);/**from k*/
line(170+marginx,240,170+marginx,345);/**from j to k*/
setcolor(8);
if(marginx == 790)
   line(302+marginx,250,305+marginx,250);/**from q*/
    else
line(302+marginx,250,325+marginx,250);/**from q*/
if(marginx != 790){
    /**And gate*/
    setcolor(0);
    setlinestyle(0,1,2);
    line(325+marginx,220,325+marginx,260);/**left bound*/
    line(325+marginx,220,350+marginx,220);/**upper bound*/
    line(325+marginx,260,350+marginx,260);/**lower bound*/
    arc(350+marginx,240,270,90,20);/**curve*/
    setlinestyle(1,1,3);
    setcolor(8);
    if(!marginx)
        setcolor(10);

    line(323+marginx,230,315+marginx,230);/**AND input*/
    setcolor(8);
    line(371+marginx,240,400+marginx,240);/**AND output*/
}
if(marginx == 460){/**second AND gate*/
    setcolor(0);
    setlinestyle(0,1,2);
    line(325+marginx,130,325+marginx,170);/**left bound*/
    line(325+marginx,130,350+marginx,130);/**upper bound*/
    line(325+marginx,170,350+marginx,170);/**lower bound*/
    arc(350+marginx,150,270,90,20);/**curve*/
    setlinestyle(1,1,3);
    setcolor(8);
    line(323+marginx,140,315+marginx,140);/**AND input*/
    line(371+marginx,150,400+marginx,150);/**AND output*/
}
if(marginx == 460){/**OR gate*/
    setcolor(0);
    setlinestyle(0,1,2);
    arc(350+430+85,195,290,70,20);/**left curve*/
    arc(350+430+85,255,50,88,80);/**upper curve*/
    arc(350+430+85,135,272,310,80);/**lower curve*/
    setlinestyle(1,1,3);
    setcolor(8);
    line(400+marginx,185,400+marginx+18,185);/**OR input 1*/
    line(400+marginx,205,400+marginx+18,205);/** OR input 2*/
}
if(marginx == 460){/** twin AND connectors for OR*/
    line(400+marginx,185,400+marginx,150);
    line(400+marginx,205,400+marginx,240);
}

if(marginx == 790 ){/** one time connections*/
    setcolor(10);
    line(302+marginx,345,325+marginx,345);/**from q dash*/
    line(325+marginx,345,325+marginx,500);
    line(315,500,325+marginx,500);
    setcolor(10);
    line(170,240,130,240);/**First FF input */
    setcolor(10);
    line(315,230,315,500);
    setcolor(8);
    line(305,250,305,160);
    line(305,160,323+460,160);
    line(315+230,160,315+230,230);
    line(170+460,238,170+460,210);/**from flip flop 3 to AND gate*/
    line(170+460,210,315+460,210);
    line(315+460,210,315+460,230);
    line(315+460,140,315+460,120);/**from out of flip flop 4 to in of AND */
    line(315+460,120,305+marginx,120);
    line(400+460+57,195,170+marginx,195);/**from out of OR to ff 4*/
    line(170+marginx,195,170+marginx,240);
}
setcolor(8);
line(305+marginx,250,305+marginx,70);/**from q to out*/

line(150+marginx,295,150+marginx,460);/**from enable to clock*/

line(150+marginx,295,190+marginx,295);/**to enable*/

if(marginx!=790)
    line(155+marginx,460,150+marginx+230-5,460);/** main clock line*/

else
     line(145+marginx+5,460,145+marginx-100,460);/**last piece of clock line*/
line(110,460,145,460);/**first piece of clock line*/


setlinestyle(1,1,3);
circle(195+marginx,295,4);/**enable*/
setcolor(0);
/**clock bar*/
settextstyle(10,0,1);
setfillstyle(1,0);
rectangle(65,450,110,470);
floodfill(95,460,0);
setcolor(11);
setbkcolor(0);
outtextxy(70,450,"CLK");
setbkcolor(15);
setcolor(1);
outtextxy(90,230,"+5V");
/**set clock headings*/
    setcolor(3);
    setbkcolor(15);
    outtextxy(5,520,"CP");
    outtextxy(5,550,"Q0");
    outtextxy(5,580,"Q1");
    outtextxy(5,610,"Q2");
    outtextxy(5,640,"Q3");
}

void updateFlipFlop(int marginx,int i){
setlinestyle(1,1,3);
int in1;
cline(198+marginx,240,170+marginx,240,ffs[i].J);/**from j*/
cline(198+marginx,345,170+marginx,345,ffs[i].K);/**from k*/
cline(170+marginx,240,170+marginx,345,ffs[i].J);/**from j to k*/
if(marginx == 790)
   cline(302+marginx,250,305+marginx,250,ffs[i].Q);/**from q*/
    else
cline(302+marginx,250,325+marginx,250,ffs[i].Q);/**from q*/
if(marginx != 790){
    setlinestyle(1,1,3);
    if(marginx==0){
        cline(323+marginx,230,315+marginx,230,complementof(ffs[3].Q));/**AND input*/
        in1 = complementof(ffs[3].Q);
    }
    else if(marginx == 230){
        cline(323+marginx,230,315+marginx,230,ffs[0].Q);/**AND input*/
        in1 = ffs[0].Q;
    }
    else{
        cline(323+marginx,230,315+marginx,230,ffs[0].Q & ffs[1].Q);/**AND input*/
        in1 = ffs[0].Q & ffs[1].Q;
    }

    cline(371+marginx,240,400+marginx,240,in1 & ffs[i].Q);/**AND output*/
}
if(marginx == 460){/**second AND gate*/
    setlinestyle(1,1,3);
    cline(323+marginx,140,315+marginx,140,ffs[3].Q);/**AND input*/
    cline(371+marginx,150,400+marginx,150,ffs[3].Q & ffs[0].Q);/**AND output*/
}
if(marginx == 460){/**OR gate*/

    setlinestyle(1,1,3);
    cline(400+marginx,185,400+marginx+18,185,ffs[3].Q & ffs[0].Q);/**OR input 1*/
    cline(400+marginx,205,400+marginx+18,205,in1 & ffs[2].Q);/** OR input 2*/
}
if(marginx == 460){/** twin AND connectors for OR*/
    cline(400+marginx,185,400+marginx,150,ffs[3].Q & ffs[0].Q);
    cline(400+marginx,205,400+marginx,240,in1 & ffs[2].Q);
}
int orout = (ffs[3].Q & ffs[0].Q) | (in1 & ffs[2].Q);
if(marginx == 790 ){/** one time connections*/
    cline(302+marginx,345,325+marginx,345,complementof(ffs[3].Q));/**from q dash*/
    cline(325+marginx,345,325+marginx,500,complementof(ffs[3].Q));
    cline(315,500,325+marginx,500,complementof(ffs[3].Q));
    cline(315,230,315,500,complementof(ffs[3].Q));
    cline(170,240,130,240,1);/**First FF input */
    cline(305,250,305,160,ffs[0].Q);/**out of FF1 to second AND gate*/
    cline(305,160,323+460,160,ffs[0].Q);
    cline(315+230,160,315+230,230,ffs[0].Q);
    cline(170+460,238,170+460,210,ffs[2].J);/**from flip flop 3 to AND gate*/
    cline(170+460,210,315+460,210,ffs[2].J);
    cline(315+460,210,315+460,230,ffs[2].J);
    cline(315+460,140,315+460,120,ffs[3].Q);/**from out of flip flop 4 to in of AND */
    cline(315+460,120,305+marginx,120,ffs[3].Q);
    cline(400+460+57,195,170+marginx,195,orout);/**from out of OR to ff 4*/
    cline(170+marginx,195,170+marginx,240,orout);
}
cline(305+marginx,250,305+marginx,70,ffs[i].Q);/**from q to out*/
drawPulse(marginx);

}

void paintclocks(int marginx,int i){
    cline(150+marginx,295,150+marginx,460,i);/**from enable to clock*/

    cline(150+marginx,295,190+marginx,295,i);/**to enable*/
    if(marginx!=790)
        cline(155+marginx,460,150+marginx+230-5,460,i);/** main clock line*/

else
    cline(145+marginx+5,460,145+marginx-100,460,i);/**last piece of clock line*/
    cline(110,460,145,460,i);/**first piece of clock line*/

}

void redrawsplitters(){
    for(int marginx=0;marginx<=790;marginx+=230){
        if(marginx==690)
            marginx+=100;
        setfillstyle(1,0);
setcolor(0);
/** Splitters*/
circle(170+marginx,240,4);
floodfill(170+marginx,240,0);/**on j*/
circle(85+460,160,4);
floodfill(85+460,160,0);/**above AND 2*/
circle(305,160,4);
floodfill(305,160,0);/**above AND 1*/
circle(305+790,120,4);
floodfill(305+790,120,0);/**on out of FF4*/
circle(170+marginx,240,4);
floodfill(170+marginx,240,0);/**on j*/
if(marginx!=790){
    circle(150+marginx,460,4);
    floodfill(150+marginx,460,0);/** clock splitters*/
    circle(305+marginx,250,4);
    floodfill(305+marginx,250,0);/** on q */
}
    }

}
