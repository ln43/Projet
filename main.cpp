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
  System::set_params(w,h);
  
  ofstream fout;
  fout.open("data.txt", ios::out | ios::trunc);
  fout << "T"<<"  "<<"Ainit"<<" "<<"Etat"<<"\n";
 

  //~ for(int t=1;t<=50;t++){
      //~ for(int a=0;a<=50;a++){
        int t=450;
        int a=45;
           System S(t,a);
           S.begin(10000);
           int E=S.get_Etat();
           fout<<t<<" "<<a<<" "<<E<<"\n";
           cout<<t<<" "<<a<<" "<<E<<endl;
      //~ }
  //~ }
  fout.close();
 
//  cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
//  S1.begin(10);
//  cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
//  S1.affichageViv();
//  cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
//  S1.affichageFit();
  return EXIT_SUCCESS;
}

