
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Indiv.h"

using namespace std;

float Indiv::pMut_=0;
float Indiv::pDeath_=0;
float Indiv::wMin_=0;
float Indiv::RAA_=0;
float Indiv::RAB_=0;
float Indiv::RBB_=0;
float Indiv::RBC_=0;


// ===========================================================================
//                                Constructors
// ===========================================================================
  Indiv::Indiv(){
    genot_=0;
    A_=0;
    B_=0;
    C_=0;
    fit_=0;
    vivant=false;
  }

  Indiv::Indiv(int genot){
    genot_=genot;
    A_=0;
    B_=1;
    C_=2;
    if (genot_==0){
      fit_=B_;
    }else{
      fit_=C_;
    }
    vivant=true;
  }
// ===========================================================================
//                                 Destructor
// ===========================================================================
  Indiv::~Indiv(){}

// ===========================================================================
//                               Public Methods
// ===========================================================================
  void Indiv::death(){
    int p=rand()%101;
    if(p<pDeath_*100){vivant=false;}
  }

  void Indiv::mute(){
    int p=rand()%101;
    if(p<pMut_*100){
      if(genot_==0){genot_=1;}
      else{genot_=0;}
    }
  }

  void Indiv::set_fitness(){
    if (genot_==0){
      fit_=B_;
    }else{
      fit_=C_;
    }
    if(fit_<wMin_){
      fit_=0;
    }
  }

  float Indiv::metabolA(float aout){
    float Aout=aout;
    float a=A_;
    for (float t=0;t<1;t+=0.1){
      Aout=Aout-Aout*RAA_*0.1;
      A_=A_+(aout*RAA_-A_*RAB_)*0.1;
      B_=B_+a*RAB_*0.1;
      aout=Aout;
      a=A_;
    }
    return Aout;
  }

  float Indiv::metabolB(float bout){
    float Bout=bout;
    float b=B_;
    for (float t=0;t<1;t+=0.1){
      Bout=Bout-Bout*RBB_*0.1;
      B_=B_+(bout*RBB_-B_*RBC_)*0.1;
      C_=C_+b*RBC_*0.1;
      b=B_;
      bout=Bout;
    }
    return Bout;
  }

