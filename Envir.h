#ifndef ENVIR_H__
#define ENVIR_H__
// ===========================================================================
//                                  Includes
// ===========================================================================
#include <iostream>

class Envir{
  public:
  // =========================================================================
  //                               Constructors
  // =========================================================================
    Envir();
    Envir(float Ainit);
  // =========================================================================
  //                                Destructor
  // =========================================================================
    ~Envir();
  // =========================================================================
  //                                  Getters
  // =========================================================================
    float get_concentration(int x,int y,int c) const;
  // =========================================================================
  //                                  Setters
  // =========================================================================
    void set_concentration(int x,int y,int c,float newC);
    inline static void set_params(float D,int W,int H);
    
  // =========================================================================
  //                              Public Methods
  // =========================================================================
    void diffusion();
    void reinit(float Ainit);

 protected :
  // =========================================================================
  //                                Attributes
  // =========================================================================
  static int W_;
  static int H_;
  float* concent_;
  static float D_;
};
  // =========================================================================
  //                                INLINE
  // =========================================================================
  inline void Envir::set_params(float D,int W,int H){
    D_=D;
    W_=W;
    H_=H;
  };
  
#endif

