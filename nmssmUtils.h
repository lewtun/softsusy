
#ifndef NMSSM_UTILS_H
#define NMSSM_UTILS_H

#include <iosfwd>
#include <string>

#include "linalg.h"

class NmssmSoftsusy;

/// class for NMSSM input parameters
class NMSSM_input {
public:
   enum NMSSM_parameters {
      tanBeta,               // MINPAR entry 3
      mHd2,                  // EXTPAR entry 21
      mHu2,                  // EXTPAR entry 22
      mu,                    // EXTPAR entry 23
      BmuOverCosBetaSinBeta, // m3^2/(cos(Beta)sin(Beta)) EXTPAR entry 24
      lambda,                // EXTPAR entry 61
      kappa,                 // EXTPAR entry 62
      Alambda,               // EXTPAR entry 63
      Akappa,                // EXTPAR entry 64
      lambdaS,               // lambda * <S> EXTPAR entry 65
      xiF,                   // EXTPAR entry 66
      xiS,                   // EXTPAR entry 67
      muPrime,               // EXTPAR entry 68
      mPrimeS2,              // EXTPAR entry 69
      mS2,                   // EXTPAR entry 70
      NUMBER_OF_NMSSM_INPUT_PARAMETERS
   };

   NMSSM_input();
   ~NMSSM_input() {}

   /// set parameter to given value
   void set(NMSSM_parameters, double);
   /// get value of parameter
   double get(NMSSM_parameters) const;
   /// returns vector with supersymmetric NMSSM parameters
   DoubleVector get_nmpars() const;
   /// returns true if parameter was set, false otherwise
   bool is_set(NMSSM_parameters par) const;
   /// returns true if input parameter set defines a Z3 symmetric NMSSM
   bool is_Z3_symmetric() const;
   /// checks the NMSSM parameter setup, throws if not SLHA2 conform
   void check_setup();

   friend std::ostream& operator<<(std::ostream&, const NMSSM_input&);

private:
   double parameter[NUMBER_OF_NMSSM_INPUT_PARAMETERS];  ///< NMSSM parameters
   bool has_been_set[NUMBER_OF_NMSSM_INPUT_PARAMETERS];
   static char const * const parameter_names[NUMBER_OF_NMSSM_INPUT_PARAMETERS];

   /// checks if the unset parameters can be used as EWSB output
   void check_ewsb_output_parameters() const;
};

class NMSSM_command_line_parser {
public:
   NMSSM_command_line_parser();
   ~NMSSM_command_line_parser() {}

   void parse(int argc, char* argv[], NMSSM_input*);
   const std::string& get_modelIdent() const;
   DoubleVector get_pars() const;

private:
   NMSSM_input* nmssm_input;
   std::string model_ident;
   double m0, m12, a0;

   static double get_value(const std::string& str, const std::string& prefix);
   static bool starts_with(const std::string& str, const std::string& prefix);
};

void NmssmMsugraBcs(NmssmSoftsusy & m, const DoubleVector & inputParameters);

void MssmMsugraBcs(NmssmSoftsusy & m, const DoubleVector & inputParameters);

void SemiMsugraBcs(NmssmSoftsusy & m, const DoubleVector & inputParameters);

void extendedNMSugraBcs(NmssmSoftsusy & m, const DoubleVector & inputParameters);

#endif
