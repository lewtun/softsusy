
/** 
   Project:     SOFTSUSY 
   File:        higher.cpp
   Author:      B.C. Allanach, S. Martin, D. Robertson and R. Ruiz de Austri
   Manual:      B.C. Allanach, S. Martin, D. Robertson and R. Ruiz de Austri, 
                arXiv:16??.?????
   Webpage:     http://allanach.home.cern.ch/allanach/softsusy.html
   Description: main calling program to be put in src/ in the softsusy
                directory. Running make will produce an executable called
                "higher.x", which takes no arguments. Running "higher.x"
                produces the data given in "twoLoop.dat", which were used to 
                make the figures in the manual, and which illustrate the size 
                of two-loop contributions to gluino and squark masses and the
                resulting corrections to gluino and squark production 
                cross-sections at the 13 TeV LHC. You will need to install 
                NLL-fast (google it) in some directory, and compile it to get 
                an executable which you should call nllfast13. Then change 
                the (two) references to /home/bca20/code/nllfast-3.0-13TeV 
                below to point to the directory you've placed nllfast13 in. 
*/

#include <iostream>
#include "mycomplex.h"
#include "def.h"
#include "linalg.h"
#include "lowe.h"
#include "rge.h"
#include "softsusy.h"
#include "softpars.h"
#include "susy.h"
#include "utils.h"
#include "numerics.h"

#ifdef COMPILE_TWO_LOOP_SPARTICLE_MASS

bool treeLevelGluino = false;

/// NLLFAST version
void getCrossSection(MssmSoftsusy & r, double m0, double m12, double a0, 
		     double tanb, double & xsGG, double & xsSG, double & xsSS,
		     double & xsSB, double & xsTB) {
  double mg = r.displayPhys().mGluino;
  double mt1 = minimum(r.displayPhys().mu(1, 3), r.displayPhys().mu(2, 3));
  double mq  = (r.displayPhys().mu(1, 1) + r.displayPhys().md(1, 1) +
		r.displayPhys().mu(1, 2) + r.displayPhys().md(1, 2)) * 0.25;

  char buff[500];
  sprintf(buff, "cd /home/bca20/code/nllfast-3.1-13TeV; ./nllfast13 gg mstw %f %f > output 2> err; ./nllfast13 sg mstw %f %f >> output 2>> err; ./nllfast13 ss mstw %f %f >> output 2>> err; ./nllfast13 sb mstw %f %f >> output 2>> err; ./nllfast13 st mstw %f >> output 2>> err",mq,mg,mq,mg,mq,mg,mq,mg,mt1);
  //  cout << buff << endl;
  int err = system(buff);
  xsGG = 0.; xsSG = 0.; xsSS = 0.; xsSB = 0.; xsTB = 0.;

  char c[500];
  char fn[500];
  sprintf(fn, "/home/bca20/code/nllfast-3.1-13TeV/output");
  if (!err) {
    fstream fin(fn, ios::in); 
    fin >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> xsGG >> c >> c >> c >> c >> c >> c >> c >> c >> c;
    fin >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> xsSG >> c >> c >> c >> c >> c >> c >> c >> c >> c;
    fin >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> xsSS >> c >> c >> c >> c >> c >> c >> c >> c >> c;
    fin >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> xsSB >> c >> c >> c >> c >> c >> c >> c >> c >> c;
    fin >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c >> c 
	>> c >> c >> c >> c >> xsTB >> c >> c >> c >> c >> c >> c >> c >> c >> c;
    fin.close();
  } else  cout << "CROSS SECTION ERROR\n" << xsGG;
   
  return;
}

void scaleVariation() {
    /// Sets format of output: 6 decimal places
    outputCharacteristics(9);

    double m12 = 1000., m0 = 1000., a0 = 0., tanb = 10.;

    int sgnMu = 1;      ///< sign of mu parameter 
    
    QedQcd oneset;      ///< See "lowe.h" for default definitions parameters

    /// most important Standard Model inputs: you may change these and recompile
    double alphasMZ = 0.1187, mtop = 173.5, mbmb = 4.18;
     // double lowRatio = 0.7817552, highRatio = 0.7817581;
    oneset.setAlpha(ALPHAS, alphasMZ);
    oneset.setPoleMt(mtop);
    oneset.setMbMb(mbmb);    
    oneset.toMz();      ///< Runs SM fermion masses to MZ
    
    double qewsbStart = 0.5, qewsbEnd = 2.; int numPoints = 20;
    for (int i=0; i<=numPoints; i++) {
      double qewsb = (qewsbEnd - qewsbStart) / double(numPoints) * double(i) + 
	qewsbStart; 
      QEWSB = qewsb;
      DoubleVector pars(3); 
      bool uni = true, ewsbBCscale = false; double mGutGuess = 1.e16;
      
      pars(1) = m0; pars(2) = m12; pars(3) = a0; 
      /// Calculate the spectrum
      MssmSoftsusy r;
      r.lowOrg(sugraBcs, mGutGuess, pars, sgnMu, tanb, oneset, uni, 
	       ewsbBCscale);
      if (treeLevelGluino) {
	r.runto(r.displayMsusy());
	sPhysical aa = r.displayPhys();
	aa.mGluino = r.displayGaugino(3);
	r.setPhys(aa);
      }
      cout << qewsb << " " << r.displayMsusy() << " "  
	   << r.displayPhys().mGluino << " # " 
	   << r.displayProblem() << endl;
    }    
    cout << endl << endl;
}

void doScan(double lowRatio, double highRatio, int numPoints) {
  cout << "# Data file for plots\n";
  cout << "# Figure 3(a) is columns 4, 7, and 10 vs. column 1.\n";
  cout << "# Figure 3(b) is columns 39, 42, 45, 48, and 51 vs. column 1.\n";
  cout << "# m0/M12        m_gl(1-loop)    m_gl(2-loop)    muL(1-loop)     muL(2-loop)     mt1(1-loop)     mt1(2-loop)     mt2(1-loop)     mt2(2-loop)     mdL(1-loop)     mdL(2-loop)     mb1(1-loop)     mb1(2-loop)     muR(1-loop)     muR(2-loop)     muR(1-loop)     muR(2-loop)     mb2(1-loop)     mb2(2-loop)     M3(MSUSY)       muL(MSUSY)      mtL(MSUSY)      mtR(MSUSY)      mdL(MSUSY)      mbL(MSUSY)      muR(MSUSY)      mdR(MSUSY)      mbR(MSUSY)      mt(MSUSY)       mneut1(MSUSY)   mneut2(MSUSY)   mneut3(MSUSY)    mneut4(MSUSY)   gg(1-loop)      gg(2-loop)      sg(1-loop)      sg(2-loop)      ss(1-loop)      ss(2-loop)      sb(1-loop)      sb(2-loop)      tb(1-loop)      tb(2-loop)\n";

    /// Sets format of output: 6 decimal places
    outputCharacteristics(9);

    double m12 = 1000., m0 = 0., m0Overm12 = 0., a0 = 0., tanb = 10.;

    int sgnMu = 1;      ///< sign of mu parameter 
    
    QedQcd oneset;      ///< See "lowe.h" for default definitions parameters

    /// most important Standard Model inputs: you may change these and recompile
    double alphasMZ = 0.1187, mtop = 173.5, mbmb = 4.18;
    oneset.setAlpha(ALPHAS, alphasMZ);
    oneset.setPoleMt(mtop);
    oneset.setMbMb(mbmb);    
    oneset.toMz();      ///< Runs SM fermion masses to MZ

    DoubleVector pars(3); 
    bool uni = true, ewsbBCscale = false; double mGutGuess = 1.e16;
    int i; for (i=0; i<=numPoints; i++) {
      USE_TWO_LOOP_SPARTICLE_MASS = false;

      MssmSoftsusy r; 
      
      m0Overm12 = lowRatio + 
	(highRatio - lowRatio) / double(numPoints) * double(i);
      m0 = m0Overm12 * m12;
      pars(1) = m0; pars(2) = m12; pars(3) = a0; 
      /// Calculate the spectrum
      r.lowOrg(sugraBcs, mGutGuess, pars, sgnMu, tanb, oneset, uni, 
	       ewsbBCscale);
      
      MssmSoftsusy ho;
      USE_TWO_LOOP_SPARTICLE_MASS = true;
      ho.lowOrg(sugraBcs, mGutGuess, pars, sgnMu, tanb, oneset, uni, 
		ewsbBCscale);

      if (r.displayProblem().test()) cout << "# ";
      cout << m0Overm12 << " "                 // 1
	   << r.displayPhys().mGluino << " "   // 2
	   << ho.displayPhys().mGluino << " "  // 3
	   << r.displayPhys().mu(1, 1) << " "  // 4
	   << ho.displayPhys().mu(1, 1) << " " // 5
	   << r.displayPhys().mu(1, 3) << " "  // 6
	   << ho.displayPhys().mu(1, 3) << " " // 7
	   << r.displayPhys().mu(2, 3) << " "  // 8
	   << ho.displayPhys().mu(2, 3) << " " // 9
	   << r.displayPhys().md(1, 1) << " "  // 10
	   << ho.displayPhys().md(1, 1) << " " // 11
	   << r.displayPhys().md(1, 3) << " "  // 12
	   << ho.displayPhys().md(1, 3) << " " // 13
	   << r.displayPhys().mu(2, 1) << " "  // 14
	   << ho.displayPhys().mu(2, 1) << " " // 15
	   << r.displayPhys().md(2, 1) << " "  // 16
	   << ho.displayPhys().md(2, 1) << " " // 17
	   << r.displayPhys().md(2, 3) << " "  // 18
	   << ho.displayPhys().md(2, 3) << " ";// 19

      r.runto(r.displayMsusy());
      r.calcDrBarPars();
      cout << r.displayDrBarPars().mGluino  << " " // 20
	   << r.displayDrBarPars().mu(1, 1) << " " // 21
	   << r.displayDrBarPars().mu(1, 3) << " " // 22
	   << r.displayDrBarPars().mu(2, 3) << " " // 23
	   << r.displayDrBarPars().md(1, 1) << " " // 24
	   << r.displayDrBarPars().md(1, 3) << " " // 25
	   << r.displayDrBarPars().mu(2, 1) << " " // 26
	   << r.displayDrBarPars().md(2, 1) << " " // 27
	   << r.displayDrBarPars().md(2, 3) << " " // 28
	   << r.displayDrBarPars().mt       << " " // 29
	   << r.displayDrBarPars().mneut(1) << " " // 30
	   << r.displayDrBarPars().mneut(2) << " " // 31
	   << r.displayDrBarPars().mneut(3) << " " // 32
	   << r.displayDrBarPars().mneut(4) << " ";// 33

      /// calculate 13 TeV cross-sections
      double xsGG, xsSG, xsSS, xsSB, xsTB;
      double xsGGho, xsSGho, xsSSho, xsSBho, xsTBho;
      getCrossSection(r, m0, m12, a0, tanb, xsGG, xsSG, xsSS, xsSB, xsTB);
      getCrossSection(ho, m0, m12, a0, tanb, xsGGho, xsSGho, xsSSho, xsSBho, 
		      xsTBho);

      cout << xsGG << " "   // 34
	<< xsGGho << " " // 35
	<< xsSG << " "   // 36
	<< xsSGho << " " // 37
	<< xsSS << " "   // 38
	<< xsSSho << " " // 39
	<< xsSB << " "   // 40
	<< xsSBho << " " // 41
	<< xsTB << " "   // 42
	<< xsTBho;       // 43

      if (r.displayProblem().test()) cout << " " << r.displayProblem();      
      cout << endl;
    }
}
#endif

int main(int argc, char *argv[]) {
#ifdef COMPILE_TWO_LOOP_SPARTICLE_MASS
  /// Sets up exception handling
  signal(SIGFPE, FPE_ExceptionHandler); 

  TOLERANCE = 1.0e-4;
  try {
/* This is what is currently in Figure 3 of the present paper.
*/
//    doScan(0.1, 4.5, 20); cout << endl << endl;

/* A higher resolution scan. Use this for the paper instead? 
   Much slower of course...
    doScan(0.1, 3.3, 320); cout << endl << endl;
*/

/* These should agree at the point m0/mhalf = 1.76, but they all give different
   results for delta(mstop1)/mstop1 there! Bug??!? */
    doScan(0.16, 1.76, 16); cout << endl << endl;
    doScan(1.60, 1.76, 16); cout << endl << endl;
    doScan(1.66, 1.76, 10); cout << endl << endl;
    doScan(1.72, 1.76, 2); cout << endl << endl;


    cout << "# Figure 4, tree-level gluino mass\n";
    cout << "# Q/MSUSY       Q/GeV           M3(Q)\n";
    treeLevelGluino = true;
    USE_TWO_LOOP_SPARTICLE_MASS = false; 
    scaleVariation(); 
    treeLevelGluino = false;
    USE_TWO_LOOP_SPARTICLE_MASS = false;
    cout << "# Figure 4, 1-loop gluino pole mass\n";
    cout << "# 1-loop result\n# Q/MSUSY       Q/GeV           mgluinopole\n";

    scaleVariation(); 
    USE_TWO_LOOP_SPARTICLE_MASS = true;

    expandAroundGluinoPole = 1;
    cout << "# Figure 4, 2-loop gluino pole mass, re-expand around gluino, squark poles\n";
    cout << "# Q/MSUSY       Q/GeV           mgluinopole\n";
    scaleVariation(); 

    expandAroundGluinoPole = 0;
    cout << "# Figure 4, 2-loop gluino pole mass, no re-expansion\n";
    cout << "# Q/MSUSY       Q/GeV           mgluinopole\n";
    scaleVariation(); 

    expandAroundGluinoPole = 2;
    cout << "# Figure 4, 2-loop gluino pole mass, re-expand around gluino pole\n";
    cout << "# Q/MSUSY       Q/GeV           mgluinopole\n";
    scaleVariation(); 
  }
  catch(const string & a) { cout << a; return -1; }
  catch(const char * a) { cout << a; return -1; }
  catch(...) { cout << "Unknown type of exception caught.\n"; return -1; }
#else
  cout << "Error: you must do ./configure --enable-two-loop-sparticle-mass-compilation before making this program\n";
#endif
  return 0;
}


