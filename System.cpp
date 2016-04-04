
// ===========================================================================
//                                  Includes
// ===========================================================================
#include "System.h"

using namespace std;

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
int System::W_=0;
int System::H_=0;
float System::wMin_=0;

// ===========================================================================
//                                Constructors
// ===========================================================================
  System::System(){
    T_=0;
    Ainit_=0;
    indiv_=nullptr;
  }

  System::System(int T,float Ainit): env_(Ainit){
    T_=T;
    Ainit_=Ainit;
    indiv_=new Indiv[W_*H_];
    for(int i=0;i<W_*H_/2;i++){
      int x=rand()%(W_*H_);
      while(indiv_[x].isVivant()==true){
        x=rand()%(W_*H_);
      }
      Indiv ind(0);
      indiv_[x]=ind;
    }
    for(int i=0;i<W_*H_;i++){
      if(indiv_[i].isVivant()==false){
        Indiv ind(1);
        indiv_[i]=ind;
      }
    }
  }

// ===========================================================================
//                                 Destructor
// ===========================================================================
  System::~System(){
    delete[] indiv_;
  }
// ===========================================================================
//                               Public Methods
// ===========================================================================
  void System::begin(int tempsSimul){ 
    for(int x=0;x<W_;x++){ //1er métabolisme
      for(int y=0;y<H_;y++){
        metabol(x,y);
      }
    }

    for(int i=0; i<W_*H_;i++){ // mise à jour de la fitness initiale
      indiv_[i].set_fitness();
    }
    

    for(int i=0;i<tempsSimul;i++){ 
      if(i>0 && i%T_==0){ // réinitialisation du milieu tous les T pas de temps
        env_.reinit(Ainit_);
      }
      if(isDeath()){ //interrompt la simulation si la population est morte
        i=tempsSimul;
      }
      run1time();
    }
  }
  
  void System::run1time(){


    //Phase1 : diffusion des métabolites externes
    env_.diffusion();
    
    //Memoire des trous 
    int* gaps=new int[W_*H_]; //retient si la case est un trou, vaut 0 si trou
    int nbGaps=0;
    for(int x=0;x<W_;x++){
      for(int y=0;y<H_;y++){
        if(indiv_[x+y*W_].isVivant()==false){
          gaps[x+y*W_]=0;
          nbGaps++;
        }else {gaps[x+y*W_]=1;}
      }
    }

    //Phase 2 : mort
    for(int x=0;x<W_;x++){
      for(int y=0;y<H_;y++){
        if(indiv_[x+y*W_].isVivant()){
          indiv_[x+y*W_].death();
          if(indiv_[x+y*W_].isVivant()==false){
            float A= env_.get_concentration(x,y,0);
            float B= env_.get_concentration(x,y,1);
            env_.set_concentration(x,y,0,A+indiv_[x+y*W_].get_A());
            env_.set_concentration(x,y,1,B+indiv_[x+y*W_].get_B());
          }
        }
      }
    }

    //Phase 3 : competition
    int* isDivised=new int[W_*H_]; //garde en memoire les cellules déjà divisées
    for(int i=0;i<W_*H_;i++){
      isDivised[i]=0; // vaut 0 si non divisé
    }

    while(nbGaps>0){
      int indic=rand()%(W_*H_);
      if(gaps[indic]==0){
        int x=indic%W_;
        int y=indic/W_;
        int xFit=-1;
        int yFit=-1;
        float fitMax=wMin_;
        for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
            if(i!=0 || j!=0){
              int X=x+i;
              int Y=y+j;
              if(X==W_){X=0;}
              else if(X==-1){X=W_-1;}
              if(Y==H_){Y=0;}
              else if(Y==-1){Y=H_-1;}
              if(isDivised[X+Y*W_]==0){
                if(fitMax<=indiv_[X+Y*W_].get_fitness() && indiv_[X+Y*W_].isVivant()){
                  fitMax=indiv_[X+Y*W_].get_fitness();
                  xFit=X;
                  yFit=Y;
                }
              }
            }
          }
        }
        if(xFit!=-1){
          indiv_[x+y*W_].set_genotype(indiv_[xFit+yFit*W_].get_genotype());
          indiv_[x+y*W_].set_A(indiv_[xFit+yFit*W_].get_A()/2);
          indiv_[x+y*W_].set_B(indiv_[xFit+yFit*W_].get_B()/2);
          indiv_[x+y*W_].set_C(indiv_[xFit+yFit*W_].get_C()/2);
          indiv_[x+y*W_].set_fitness();
          indiv_[x+y*W_].set_vivant();
          indiv_[x+y*W_].mute();
          indiv_[xFit+yFit*W_].set_A(indiv_[xFit+yFit*W_].get_A()/2);
          indiv_[xFit+yFit*W_].set_B(indiv_[xFit+yFit*W_].get_B()/2);
          indiv_[xFit+yFit*W_].set_C(indiv_[xFit+yFit*W_].get_C()/2);
          indiv_[xFit+yFit*W_].set_fitness();
          indiv_[xFit+yFit*W_].mute();
          isDivised[xFit+yFit*W_]=1;
          isDivised[x+y*W_]=1;
          gaps[indic]=1;
          nbGaps--;
        }else{
          isDivised[x+y*W_]=1;
          gaps[indic]=1;  
          nbGaps--;
        }
      }
    }
    delete[] gaps;
    delete[] isDivised;

    // Phase 4 : Vie grace au réseau métabolique
    for(int x=0;x<W_;x++){
      for(int y=0;y<H_;y++){
        if(indiv_[x+y*W_].isVivant()){
          metabol(x,y);
          indiv_[x+y*W_].set_fitness();
        }
      }
    }
    
  }

  void System::metabol(int x,int y){
    if(indiv_[x+y*W_].get_genotype()==0){
      float aout=env_.get_concentration(x,y,0);
      env_.set_concentration(x,y,0,indiv_[x+y*W_].metabolA(aout));
    }else{
      float bout=env_.get_concentration(x,y,1);
      env_.set_concentration(x,y,1,indiv_[x+y*W_].metabolB(bout));
    }
  }
  
  int System::get_Etat(){
    if (isDeath()){
      return 0;
    }else{
      int compt=0;
      for(int j=0;j<W_*H_;j++){
        if(indiv_[j].get_genotype()==0){
          compt++;
        }
      }
      if (compt==W_*H_){
        return 1;
      }else{
        return 2;
      }
    }
  }

bool System::isDeath(){
  int d=0;
  for(int i=0;i<W_*H_;i++){
    if(indiv_[i].isVivant()==false){
      d++;
    }
  }
  if (d==W_*H_){
    return true;
  }else{
    return false;
  }
}
  //Methode a supprimer ensuite
  void System::affichageViv(){
    cout<<"VIVANT"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        if(indiv_[x+y*W_].isVivant()){cout<<"1 ";}
        else{cout<<"0 ";}
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }

  //Methode a supprimer ensuite
  void System::affichageFit(){
    cout<<"FITNESS"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        cout<<indiv_[x+y*W_].get_fitness()<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }

  //Methode a supprimer ensuite
  void System::affichageGen(){
    cout<<"GENOTYPE"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        cout<<indiv_[x+y*W_].get_genotype()<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }
  //Methode a supprimer ensuite
  void System::affichageA(){
    cout<<"CONCENTRATION A INDIV"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        cout<<indiv_[x+y*W_].get_A()<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }
  
  //Methode a supprimer ensuite
  void System::affichageB(){
    cout<<"CONCENTRATION B INDIV"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        cout<<indiv_[x+y*W_].get_B()<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }
  
  //Methode a supprimer ensuite
  void System::affichageC(){
    cout<<"CONCENTRATION C INDIV"<<endl;
    for(int y=0;y<H_;y++){
      for(int x=0;x<W_;x++){
        cout<<indiv_[x+y*W_].get_C()<<" ";
      }
      cout<<endl;
    }
     cout<<"_ _ _ _ _ _ _ _ _ _ _ "<<endl;
  }
