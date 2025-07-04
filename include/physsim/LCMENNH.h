#ifndef LCMENNH_H
#define LCMENNH_H
//*****************************************************************************
//* =====================
//*  LCMENNH
//* =====================
//*  
//* (Description)
//*    e+e- -> NNH Matrix Element
//*
//* (Update Record)
//*    2007/03/29  K.Fujii	Original version.
//*    2014/02/18  J.Tian       modified for MEM in Marlin
//*****************************************************************************

#include "TNamed.h"
#include "TLorentzVector.h"

#include "physsim/HELLib.h"
#include "physsim/GENLib.h"

#include "physsim/LCMEBase.h"
//_______________________________________________________________________
// =====================
//  class LCMENNH
// =====================
//-----------------------------------------------------------------------
namespace lcme{
  class LCMENNH : public LCMEBase {
  public:
    // --------------------------------------------------------------------
    //  Member Functions
    // --------------------------------------------------------------------
    // ----------------------
    //  C-tor and D-tor
    // ----------------------
    LCMENNH(const char *name, const char *title,
	    Double_t massHiggs = 125.,
	    Double_t polE = 0.,
	    Double_t polP = 0.);
    virtual ~LCMENNH();
    
    // ----------------------
    //  Getters and Setters
    // ----------------------
    Double_t GetMass     ()           const { return fMass;      }
    Double_t GetQ2NNH    ()           const { return fQ2NNH;      }
    Double_t GetCosTheta ()           const { return fCosTheta;  }
    Double_t GetPhi      ()           const { return fPhi;       }
    Double_t GetQ2NN     ()           const { return fQ2NN;       }
    Double_t GetCosThetaF()           const { return fCosThetaF; }
    Double_t GetPhiF     ()           const { return fPhiF;      }
    Bool_t   GetPropagator ()         const { return fPropagator;  }
    
    // ----------------------
    //   Base class methods
    // ----------------------
    Double_t GetMatrixElement2();                 // matrix element squared with weighted helicities
    Double_t GetMatrixElement2ByHelicity(Int_t vHel[]);     // matrix element squared with specified helicities
    void     SetMass     (Double_t m      ) { fMass      = m;    }
    void     SetMomentumFinal(TLorentzVector vLortz[]); // set four-momenta of final states
    void     SetPropagator(Bool_t i) {fPropagator = i;};
    
    // ----------------------
    //   Utility methods
    // ----------------------
  private:
    void Initialize();        // Bases initialization
    Double_t  DSigmaDX     ();
    Complex_t FullAmplitude();
    Complex_t AmpEEtoNNH (const HELFermion &em,
                          const HELFermion &ep,
                          const HELFermion &ne,
                          const HELFermion &neb,
                          const HELScalar  &hs);
    void     SetHelicities(Int_t vHel[]);
    
  private:
    // --------------------------------------------------------------------
    //  Data Members
    // --------------------------------------------------------------------
    // ----------------
    //  Lorentz Vector of final state particle
    TLorentzVector fLortzN1,fLortzN2; // two neutrinos
    TLorentzVector fLortzH; // Higgs
    
    // ----------------
    //  Particle Data
    // ----------------
    GENPDTWBoson *fWBosonPtr;       //! PD table entry of "W"
    
    // ----------------
    //  Event info
    // ----------------
    Int_t          fHelInitial[2];  // initial state helicities
    Int_t          fHelFinal  [2];  // final   state helicities
    ANL4DVector    fK[2];           // [0,1] = [e-, e+]
    ANL4DVector    fP[3];           // [0,1,2] = [h, ne, neb]
    Double_t       fM[3];           // [0,1,2] = [mh,mn ,mn ]
    
    Double_t       fMass;           // m_h    : mass  of H
    Double_t       fQ2NNH;          // q^2 of NNH system
    Double_t       fQ2NN;           // q^2 of final state NN
    Double_t       fCosTheta;       // cos(theta_x) in cm  frame
    Double_t       fPhi;            // phi_x        in cm  frame
    Double_t       fCosThetaF;      // cos(theta_N) in NN  frame
    Double_t       fPhiF;           // phi_N        in NN  frame
    
    Bool_t         fPropagator;     // including B-W of Higgs
    
    ClassDef(LCMENNH, 1) // Matrix Element for e+e- -> NNH process
  };
}
#endif
