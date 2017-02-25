#include "bcdcounterdesign.cpp"
#include<iostream>
#include<graphics.h>
int main(){
int gm;
int gd = 6;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
setfillstyle(1,15);
floodfill(getmaxx()/2,getmaxy()/2,15);
delay(3000);
drawHeading();
delay(3000);
drawFlipFlop(0);
//delay(3000);
drawFlipFlop(230);
drawFlipFlop(460);
drawFlipFlop(790);
redrawsplitters();
displayvalues();
ffs[0].J = 1;
ffs[0].K = 1;
int X = -1,Y = -1;
while(1){
    delay(50);
    X = mousex();
    Y = mousey();
    if(ismouseclick(WM_LBUTTONUP) && (X < 110 && X > 65 && Y < 470 && Y > 450)){
        paintclocks(0,1);
        paintclocks(230,1);
        paintclocks(460,1);
        paintclocks(790,1);
        redrawsplitters();
        drawclockpulseup();
        delay(2000);
        paintclocks(0,0);
        paintclocks(230,0);
        paintclocks(460,0);
        paintclocks(790,0);
        redrawsplitters();
        applyclock();
        cout<<ffs[3].Q<<" "<<ffs[2].Q<<" "<<ffs[1].Q<<" "<<ffs[0].Q<<" "<<endl;
        updateFlipFlop(0,0);
        updateFlipFlop(230,1);
        updateFlipFlop(460,2);
        updateFlipFlop(790,3);
        redrawsplitters();
        delay(400);
        displayvalues();
    }
    clearmouseclick(WM_LBUTTONUP);

}
getch();
return 0;
}
