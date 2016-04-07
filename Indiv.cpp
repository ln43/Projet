// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Indiv.h"

using namespace std;

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
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
    B_=0;
    C_=0;
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
    float a_out=aout;
    for (float t=0;t<1;t+=0.1){
      float nAout=a_out-a_out*RAA_*0.1;
      float na=A_+(a_out*RAA_-A_*RAB_)*0.1;
      float nb=B_+A_*RAB_*0.1;
      a_out=nAout;
      A_=na;
      B_=nb;
    }
    return a_out;
  }

  float Indiv::metabolB(float bout){
    float b_out=bout;
    for (float t=0;t<1;t+=0.1){
      float nBout=b_out-b_out*RBB_*0.1;
      float nb=B_+(b_out*RBB_-B_*RBC_)*0.1;
      float nc=C_+B_*RBC_*0.1;
      b_out=nBout;
      B_=nb;
      C_=nc;
    }
    return b_out;
  }

