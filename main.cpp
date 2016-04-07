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

  ifstream f;
  f.open("params.txt",ios::in);

  float p_mut,p_death,RAA,RBB,RAB,RBC,w_min,d;
  int w,h,T,ainit;
  string in1,in2,in3,in4,in5,in6,in7,in8,in9,in10,in11,in12;
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
  f>>in11>>T;
  f>>in12>>ainit;
  f.close();

  Indiv::set_params(p_mut,p_death,w_min,RAA,RAB,RBB,RBC);
  Envir::set_params(d,w,h);
  System::set_params(w,h,w_min);

// 1 Simulation
  //~cout<<"Une Simulation"<<endl;
  //~ System S(T,ainit);
  //~ S.begin(10000);
  //~ cout<<T<<" "<<ainit<<" "<<S.get_Etat()<<endl;


//Sans faire varier D    
  cout<<"2D, sans mutation"<<endl;
  
  //1ère zone
  ofstream fout1;
  fout1.open("data1sM.txt", ios::out | ios::trunc);
  fout1 << "T"<<"  "<<"Ainit"<<" "<<"Etat"<<"\n";
  for(int t=1;t<=26;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout1<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }
  fout1.close();
  
  //Affinement première transition
  ofstream fout2;
  ofstream f2P;
  fout2.open("data2sM.txt", ios::out | ios::trunc);
  f2P.open("data2sMP.txt", ios::out | ios::trunc);
  for(int t=30;t<50;t=t+5){
    for(int a=0;a<=50;a++){
      int E=0;
      for(int i=0;i<10;i++){
        System S(t,a);
        S.begin(10000);
        E+=S.get_Etat();
      }
      E=E/10;
      f2P<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
      if(E!=0){
        if(E<=1.5){
          fout2<<t<<" "<<a<<" "<<1<<"\n";
        }else {
          fout2<<t<<" "<<a<<" "<<2<<"\n";
        } 
      }
    }
  }
  fout2.close();
  f2P.close();
  
  //2ème zone
  ofstream fout3;
  fout3.open("data3sM.txt", ios::out | ios::trunc);
  for(int t=50;t<700;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout3<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }
  fout3.close();


  //Affinement deuxième transition
  ofstream fout4;
  ofstream f4P;
  fout4.open("data4sM.txt", ios::out | ios::trunc);
  f4P.open("data4sMP.txt", ios::out | ios::trunc);
  for(int t=700;t<1065;t=t+5){
    for(int a=0;a<=50;a++){
      int E=0;
      for(int i=0;i<10;i++){
        System S(t,a);
        S.begin(10000);
        E+=S.get_Etat();
      }
      E=E/10;
      f4P<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
      if(E<=1){
        fout4<<t<<" "<<a<<" "<<0<<"\n";
      }else {
        fout4<<t<<" "<<a<<" "<<2<<"\n";
      } 
    }
  }
  fout4.close();
  f4P.close();
  
  //3ème zone
  ofstream fout5;
  fout5.open("data5sM.txt", ios::out | ios::trunc);
  for(int t=1065;t<1500;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout5<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }
  fout5.close();


//En faisant varier D  
  //~ cout<<"3D, sans mutation"<<endl;
  //~ ofstream fD0;
  //~ fD0.open("dataD0.txt", ios::out | ios::trunc);
  //~ fD0 << "T"<<"  "<<"Ainit"<<" "<<"D"<<" "<<"Etat"<<"\n";
  //~ for(int t=1;t<1500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD0<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
    //~ }
  //~ }
  //~ fD0.close();
  
  //~ ofstream fD1;
  
  //~ fD1.open("dataD1.txt", ios::out | ios::trunc);
  //~ fD1 << "T"<<"  "<<"Ainit"<<" "<<"D"<<" "<<"Etat"<<"\n";
  //~ for(int t=1;t<250;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD1<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD1<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD1.close();
  //~ 
  //~ ofstream fD2;
  //~ fD2.open("dataD2.txt", ios::out | ios::trunc);
  //~ fD2 << "T"<<"  "<<"Ainit"<<" "<<"D"<<" "<<"Etat"<<"\n";
  //~ for(int t=250;t<500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD2<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD2<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD2.close();
  //~ 
  //~ ofstream fD3;
  //~ fD3.open("dataD3.txt", ios::out | ios::trunc);
  //~ for(int t=500;t<750;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD3<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD3<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD3.close();
  //~ 
  //~ ofstream fD4;
  //~ fD4.open("dataD4.txt", ios::out | ios::trunc); 
  //~ for(int t=750;t<=1000;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD4<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD4<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD4.close();
  //~ 
  //~ ofstream fD5;
  //~ fD5.open("dataD5.txt", ios::out | ios::trunc);
  //~ for(int t=1000;t<1250;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD5<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD5<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD5.close();
  //~ 
  //~ ofstream fD6;
  //~ fD6.open("dataD6.txt", ios::out | ios::trunc);
  //~ for(int t=1250;t<1500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD6<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
        //~ Envir::set_params(D,w,h);
        //~ System S(t,a);
        //~ S.begin(10000);
        //~ int E=S.get_Etat();
        //~ fD6<<t<<" "<<a<<" "<<D<<"  "<<E<<"\n";
        //~ cout<<t<<" "<<a<<" "<<D<<"  "<<E<<endl;
      //~ }
    //~ }
  //~ }
  //~ fD6.close();


  return EXIT_SUCCESS;
}

