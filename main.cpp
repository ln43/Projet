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
  //~ cout<<"Une Simulation"<<endl;
  //~ System S(T,ainit);
  //~ S.begin(10000);
  //~ cout<<T<<" "<<ainit<<" "<<S.get_Etat()<<endl;


//Sans faire varier D    
  cout<<"2D, sans mutation"<<endl;
    
  //1ère zone
  ofstream fout;
  fout.open("datasM.txt", ios::out | ios::trunc);
  fout << "T"<<"  "<<"Ainit"<<" "<<"Etat"<<"\n";
  for(int t=1;t<=26;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }

  //Affinement première transition
  for(int t=30;t<50;t=t+5){
    for(int a=0;a<=50;a++){
      float E=0;
      for(int i=0;i<10;i++){
        System S(t,a);
        S.begin(10000);
        E+=S.get_Etat();
      }
      E=E/10;
      fout<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }
  
  //2ème zone
  for(int t=50;t<700;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }

  //Affinement deuxième transition
  for(int t=700;t<1200;t=t+5){
    for(int a=0;a<=50;a++){
      float E=0;
      for(int i=0;i<10;i++){
        System S(t,a);
        S.begin(10000);
        E+=S.get_Etat();
      }
      E=E/10;
      fout<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }

  //3ème zone
  for(int t=1200;t<1500;t=t+5){
    for(int a=0;a<=50;a++){
      System S(t,a);
      S.begin(10000);
      int E=S.get_Etat();
      fout<<t<<" "<<a<<" "<<E<<"\n";
      cout<<t<<" "<<a<<" "<<E<<endl;
    }
  }
  fout.close();


//En faisant varier D, sans ajustement
  //~ cout<<"3D, sans mutation"<<endl;
  //~ ofstream fD;
  //~ fD.open("dataD.txt", ios::out | ios::trunc);
  //~ fD << "T"<<"  "<<"Ainit"<<" "<<"D"<<" "<<"Etat"<<"\n";
//~ 
  //~ for(int t=1;t<1500;t=t+5){
    //~ for(int a=0;a<=50;a++){
      //~ Envir::set_params(0,w,h);
      //~ System S(t,a);
      //~ S.begin(10000);
      //~ int E=S.get_Etat();
      //~ fD<<t<<" "<<a<<" "<<0<<"  "<<E<<"\n";
      //~ cout<<t<<" "<<a<<" "<<0<<"  "<<E<<endl;
      //~ for(float D=0.00000001;D<=0.1;D=D*10){
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

