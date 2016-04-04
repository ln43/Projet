#ifndef SYSTEM_H__
#define SYSTEM_H__

// ===========================================================================
//                                  Includes
// ===========================================================================

#include "Envir.h"
#include "Indiv.h"

#include <iostream>
#include <time.h> 

class System{
  public:
  // =========================================================================
  //                               Constructors
  // =========================================================================
    System();
    System(int T,float Ainit);
  // =========================================================================
  //                                Destructor
  // =========================================================================
    ~System();
  // =========================================================================
  //                                  Getters
  // =========================================================================

  // =========================================================================
  //                                  Setters
  // =========================================================================
  inline static void set_params(int W,int H,float wMin);

  // =========================================================================
  //                                 Operators
  // =========================================================================

  // =========================================================================
  //                              Public Methods
  // =========================================================================
    void begin(int tempsSimul);
    void run1time();
    void metabol(int x,int y);
    int get_Etat(); // Retourne 0 si exctinction, 2 si cohabitation, 1 si S meurt
    bool isDeath();

 protected :
  // =========================================================================
  //                             Protected Methods
  // =========================================================================

  // =========================================================================
  //                                Attributes
  // =========================================================================
  Envir env_;
  Indiv* indiv_;
  int T_;
  float Ainit_;
  static int W_;
  static int H_;
  static float wMin_;
};
  // =========================================================================
  //                                INLINE
  // =========================================================================
  inline void System::set_params(int W,int H,float wMin){
    W_=W;
    H_=H;
    wMin_=wMin;
  };
  
  
#endif

