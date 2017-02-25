#define toggle(Q)  ((Q) = ((Q) == (1) ) ? 0 : 1)
#define complementof(Q) (((Q) == (1) ) ? 0 : 1)
struct JKFlipflop{
int Q=0;
int E=0;
int J=0;
int K=0;
};
JKFlipflop ffs[4];
void operateFlipflop(JKFlipflop curr){
   if(curr.E)
    toggle(curr.Q);
}

void updateconnections(){
ffs[0].J=1;
ffs[0].K=1;
ffs[1].J = ffs[0].Q & complementof(ffs[3].Q);
ffs[1].K = ffs[0].Q & complementof(ffs[3].Q);
ffs[2].J = ffs[1].Q & ffs[0].Q ;
ffs[2].K = ffs[1].Q & ffs[0].Q ;
ffs[3].J = (ffs[3].Q & ffs[0].Q ) | (ffs[2].Q & ffs[2].J ) ;
ffs[3].K = (ffs[3].Q & ffs[0].Q ) | (ffs[2].Q & ffs[2].J );

}


void applyclock(){

 for(int i=0;i<4;i++){
        if(ffs[i].J==1 && ffs[i].K==1)
            toggle(ffs[i].Q);
 }
 updateconnections();
}





