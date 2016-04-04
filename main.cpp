// ===========================================================================
//                                  Includes
// ===========================================================================

#include "System.h"
#include "Envir.h"
#include "Indiv.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================
int main() {
  srand(time(NULL));

  cout<<"START"<<endl;

  ifstream f;
  f.open("params.txt",ios::in);

  float p_mut,p_death,RAA,RBB,RAB,RBC,w_min,d;
  int w,h;
  string in1,in2,in3,in4,in5,in6,in7,in8,in9,in10;
  f>>in1>>p_mut;
  f>>in2>>p_death;
  f>>in3>>w_min;
  f>>in4>>RAA;
  f>>in5>>RAB;
  f>>in6>>RBB;
  f>>in7>>RBC;
  f>>in8>>d;
  f>>in9>>w;
  f>>in10>>h;
  f.close();

  Indiv::set_params(p_mut,p_death,w_min,RAA,RAB,RBB,RBC);
  Envir::set_params(d,w,h);
  System::set_params(w,h,w_min);


//Sans faire varier D  
  //~ ofstream fout1;
  //~ 
  //~ fout1.open("data1sM.txt", ios::out | ios::trunc);
  //~ fout1 << "T"<<"  "<<"Ainit"<<" "<<"Etat"<<"\n";
 //~ 
  //~ for(int t=1;t<=700;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fout1<<t<<" "<<a<<" "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<E<<endl;
    //~ }
  //~ }
  //~ fout1.close();
  
  ofstream fout2;
  fout2.open("data2sM.txt", ios::out | ios::trunc);
  
  for(int t=700;t<1150;t=t+5){ // Pour mut, passer à 780 - 1220
    for(int a=0;a<=50;a++){
      int E=0;
      for(int i=0;i<5;i++){
        System S(t,a);
        S.begin(10000);
        E+=S.get_Etat();
      }
      E=E/5;
      if(E<=1){
        fout2<<t<<" "<<a<<" "<<0<<"\n";
        cout<<t<<" "<<a<<" "<<0<<endl;
      }else {
        fout2<<t<<" "<<a<<" "<<2<<"\n";
        cout<<t<<" "<<a<<" "<<2<<endl;        
      }
    }
  }
  fout2.close();
  
  //~ ofstream fout3;
  //~ fout3.open("data3sM.txt", ios::out | ios::trunc);
  //~ 
  //~ for(int t=1150;t<=1500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fout3<<t<<" "<<a<<" "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<E<<endl;
    //~ }
  //~ }
  //~ fout3.close();
  

//En faisant varier D  
  //~ ofstream fD;
  //~ 
  //~ fD.open("datater.txt", ios::out | ios::trunc);
  //~ fD << "T"<<"  "<<"Ainit"<<" "<<"D"<<" "<<"Etat"<<"\n";
 //~ 
//~ 
  //~ for(int t=11;t<=500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ for(float D=0;D<=0.1;D+=0.01){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ 
  //~ for(int t=500;t<=1000;t=t+25){
    //~ for(int a=0;a<=50;a++){
      //~ for(float D=0;D<=0.1;D+=0.01){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD.close();



  return EXIT_SUCCESS;
}

