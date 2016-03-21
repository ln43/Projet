
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "Envir.h"

using namespace std;

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
  float Envir::D_=0;
  int Envir::W_=0;
  int Envir::H_=0;

// ===========================================================================
//                                Constructors
// ===========================================================================
  Envir::Envir(){
    concent_=nullptr;
  }
    
  Envir::Envir(float Ainit){
    concent_=new float[W_*H_*2];
    for(int i=0;i<W_*H_*2;i=i+2){
      concent_[i]=Ainit;
      concent_[i+2]=0;
    }
  }
// ===========================================================================
//                                 Destructor
// ===========================================================================
  Envir::~Envir(){
    delete[] concent_;
  }

// ===========================================================================
//                               Public Methods
// ===========================================================================
  float Envir::get_concentration(int x,int y,int c) const{
    return concent_[(x+y*W_)*2+c];
  }
  
  void Envir::set_concentration(int x,int y,int c,float newC){
    concent_[(x+y*W_)*2+c]=newC;
  }
  
  void Envir::diffusion(){
    float* newConcent=new float[W_*H_*2];
    int X=0;
    int Y=0;
    for(int x=0;x<W_;x++){
      for(int y=0;y<H_;y++){
        for(int c=0;c<2;c++){
          newConcent[(x+y*W_)*2+c]=concent_[(x+y*W_)*2+c];
        }
        for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
            X=x+i;
            Y=y+j;
            if(X==W_){X=0;}
            else if(X==-1){X=W_-1;}
            if(Y==H_){Y=0;}
            else if(Y==-1){Y=H_-1;}
            for(int c=0;c<2;c++){
              newConcent[(x+y*W_)*2+c]+=D_*concent_[(X+Y*W_)*2+c];
            }
          }
        }
        for(int c=0;c<2;c++){
          newConcent[(x+y*W_)*2+c]-=9*D_*concent_[(x+y*W_)*2+c];
        }
      }
    }
    delete concent_;
    concent_=newConcent;
  }
  
  void Envir::reinit(float Ainit){
    for(int i=0;i<W_*H_*2;i=i+2){
      concent_[i]=Ainit;
      concent_[i+1]=0;
    }
  }
  
  //Methode à supprimer ensuite
  void Envir::affichageA(){
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
          cout<<concent_[(x+y*W_)*2]<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }
