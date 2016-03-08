#ifndef INDIV_H__
#define INDIV_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include <iostream>
#include <cstdlib>

class Indiv{
  public:
  // =========================================================================
  //                               Constructors
  // =========================================================================
    Indiv();
    Indiv(int genot);
  // =========================================================================
  //                                Destructor
  // =========================================================================
    ~Indiv();
  // =========================================================================
  //                                  Getters
  // =========================================================================
    inline int get_genotype() const;
    inline float get_A() const;
    inline float get_B() const;
    inline float get_C() const;
    inline float get_fitness() const;
    inline bool isVivant() const;

  // =========================================================================
  //                                  Setters
  // =========================================================================
    inline void set_genotype(int g);
    inline void set_A(float a);
    inline void set_B(float b);
    inline void set_C(float c);
    inline static void set_params(float pMut,float pDeath,float wMin,float raa,
    float rab,float rbb,float rbc);


  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
    void death();
    void mute();
    void set_fitness();
    float metabolA(float Aout);//return Aout
    float metabolB(float Bout);//return Bout

 protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
    int genot_; //genotype, prend la valeur 0 pour A et 1 pour B
    float A_; // concentration interne en A
    float B_;
    float C_;
    float fit_; //fitness, valeur de B ou de C
    bool vivant;
    static float pMut_;
    static float pDeath_;
    static float wMin_;
    static float RAA_;
    static float RAB_;
    static float RBB_;
    static float RBC_;

};
  // =========================================================================
  //                                INLINE
  // =========================================================================
  inline int Indiv::get_genotype() const{return genot_;}
  inline float Indiv::get_A() const{return A_;}
  inline float Indiv::get_B() const{return B_;}
  inline float Indiv::get_C() const{return C_;}
  inline float Indiv::get_fitness() const{return fit_;}
  inline bool Indiv::isVivant() const{return vivant;}

  inline void Indiv::set_genotype(int g){genot_=g;}
  inline void Indiv::set_A(float a){A_=a;}
  inline void Indiv::set_B(float b){B_=b;}
  inline void Indiv::set_C(float c){C_=c;}

  inline void Indiv::set_params(float pMut,float pDeath,float wMin,float raa,
  float rab,float rbb,float rbc){
    pMut_=pMut;
    pDeath_=pDeath;
    wMin_=wMin;
    RAA_=raa;
    RAB_=rab;
    RBB_=rbb;
    RBC_=rbc;
  };


#endif

