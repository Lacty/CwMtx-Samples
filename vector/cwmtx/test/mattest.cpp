// $Id: mattest.cpp 165 2008-01-19 19:53:19Z hkuiper $

// CwMtx matrix and vector math library
// Copyright (C) 1999-2000  Harry Kuiper, Will deVore(template conversion)

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include <iostream>
#include <stdlib.h>
#include <cwmtx.h>

// included for a simple test of namespaces
#include <list>

using namespace std;
using namespace CwMtx;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

// Test matrices with structured elements.
void test_struct_matrix()
{
  cout << endl << "Start test of matrices with structured elements" << endl;

  typedef CWTSMat<CWSquareMatrix, 2> CWSMat2;
  typedef CWTMat<CWTMatrix<CWSMat2>, 2, 3> CWMat23SMat2;
  typedef CWTMat<CWTMatrix<CWSMat2>, 3, 2> CWMat32SMat2;
  typedef CWTMat<CWTMatrix<CWSMat2>, 2, 2> CWMat22SMat2;

  cout << endl << "CWTMatrix<T>" << endl << endl;

  CWSMat2 smtx;
  cout << "smtx = CWTUnity<CWSMat2>() "
       << (smtx = CWTUnity<CWSMat2>()) << endl;
  cout << "smtx *= 3.0 "
       << (smtx *= 3.0) << endl;

  CWMat23SMat2 mtx23Smtx;
  mtx23Smtx.fill(smtx);
  cout << "mtx23Smtx.fill(smtx) "
       << mtx23Smtx << endl;

  CWMat32SMat2 mtx32Smtx;
  mtx32Smtx.fill(smtx);
  cout << "mtx32Smtx.fill(smtx) "
       << mtx32Smtx << endl;

  CWMat22SMat2 mtx22Smtx;
  cout << "mtx22Smtx = mtx23Smtx*mtx32Smtx "
       << (mtx22Smtx = mtx23Smtx*mtx32Smtx) << endl;
  cout << "mtx22Smtx = mtx22Smtx + mtx22Smtx "
       << (mtx22Smtx = mtx22Smtx + mtx22Smtx) << endl;
  cout << "mtx22Smtx += mtx22Smtx "
       << (mtx22Smtx += mtx22Smtx) << endl;
  cout << "mtx22Smtx = mtx22Smtx - mtx22Smtx*smtx "
       << (mtx22Smtx = mtx22Smtx - mtx22Smtx*smtx) << endl;
  cout << "mtx22Smtx -= mtx22Smtx*smtx "
       << (mtx22Smtx -= mtx22Smtx*smtx) << endl;
  cout << "mtx22Smtx = -mtx22Smtx "
       << (mtx22Smtx = -mtx22Smtx) << endl;
  cout << "mtx22Smtx = mtx22Smtx*smtx "
       << (mtx22Smtx = mtx22Smtx*smtx) << endl;
  cout << "mtx22Smtx = smtx*mtx22Smtx "
       << (mtx22Smtx = smtx*mtx22Smtx) << endl;
  cout << "mtx22Smtx *= smtx "
       << (mtx22Smtx *= smtx) << endl;
  cout << "mtx22Smtx = mtx22Smtx/smtx "
       << (mtx22Smtx = mtx22Smtx/smtx) << endl;
  cout << "mtx22Smtx /= smtx "
       << (mtx22Smtx /= smtx) << endl;

  typedef CWTSMat<CWTSquareMatrix<CWSMat2>, 2> CWSMat2SMat2;

  cout << endl << "CWTSquareMatrix<T>" << endl << endl;

  CWSMat2SMat2 smtxSmtx1, smtxSmtx2, smtxSmtx3;
  cout << "smtxSmtx1 = CWTUnity<CWSMat2SMat2>() "
       << (smtxSmtx1 = CWTUnity<CWSMat2SMat2>()) << endl;
  cout << "smtxSmtx2 = CWTUnity<CWSMat2SMat2>() "
       << (smtxSmtx2 = CWTUnity<CWSMat2SMat2>()) << endl;
  cout << "smtxSmtx1 = smtxSmtx1*smtx "
       << (smtxSmtx1 = smtxSmtx1*smtx) << endl;
  cout << "smtxSmtx1 = smtx*smtxSmtx1 "
       << (smtxSmtx1 = smtx*smtxSmtx1) << endl;
  cout << "smtxSmtx1 *= smtx "
       << (smtxSmtx1 *= smtx) << endl;
  cout << "smtxSmtx1 = smtxSmtx1/smtx "
       << (smtxSmtx1 = smtxSmtx1/smtx) << endl;
  cout << "smtxSmtx1 /= smtx "
       << (smtxSmtx1 /= smtx) << endl;

  cout << "smtxSmtx1 *= smtx "
       << (smtxSmtx1 *= smtx) << endl;

  cout << "smtxSmtx3 = smtxSmtx1 + smtxSmtx2 "
       << (smtxSmtx3 = smtxSmtx1 + smtxSmtx2) << endl;
  cout << "smtxSmtx3 += smtxSmtx1 "
       << (smtxSmtx3 += smtxSmtx1) << endl;
  cout << "smtxSmtx3 = smtxSmtx1 - smtxSmtx2 "
       << (smtxSmtx3 = smtxSmtx1 - smtxSmtx2) << endl;
  cout << "smtxSmtx3 -= smtxSmtx1 "
       << (smtxSmtx3 -= smtxSmtx1) << endl;
  cout << "smtxSmtx3 = -smtxSmtx1 "
       << (smtxSmtx3 = -smtxSmtx1) << endl;
  cout << "smtxSmtx3 = smtxSmtx1*smtxSmtx2 "
       << (smtxSmtx3 = smtxSmtx1*smtxSmtx2) << endl;
  cout << "smtxSmtx3 *= smtxSmtx1 "
       << (smtxSmtx3 *= smtxSmtx1) << endl;
  cout << "smtxSmtx3 = smtxSmtx2/smtxSmtx1 "
       << (smtxSmtx3 = smtxSmtx2/smtxSmtx1) << endl;
  cout << "smtxSmtx3 /= smtxSmtx1 "
       << (smtxSmtx3 /= smtxSmtx1) << endl;

  typedef CWTVec<CWTVector<CWSMat2>, 3> CWVec3SMat2;

  cout << endl << "CWTVector<T>" << endl << endl;

  CWSMat2 smtx2 = smtx;
  CWVec3SMat2 vecSmtx1, vecSmtx2, vecSmtx3;
  vecSmtx1.fill(smtx2);
  cout << "vecSmtx1.fill(smtx2) "
       << vecSmtx1 << endl;
  cout << "vecSmtx2 = vecSmtx1 "
       << (vecSmtx2 = vecSmtx1) << endl;
  cout << "vecSmtx3 = CWTZero<CWVec3SMat2>() "
       << (vecSmtx3 = CWTZero<CWVec3SMat2>()) << endl;

  cout << "vecSmtx3 = vecSmtx1 + vecSmtx2 "
       << (vecSmtx3 = vecSmtx1 + vecSmtx2) << endl;
  cout << "vecSmtx3 += vecSmtx1 "
       << (vecSmtx3 += vecSmtx1) << endl;
  cout << "vecSmtx3 = vecSmtx1 - vecSmtx2 "
       << (vecSmtx3 = vecSmtx1 - vecSmtx2) << endl;
  cout << "vecSmtx3 -= vecSmtx1 "
       << (vecSmtx3 -= vecSmtx1) << endl;
  cout << "vecSmtx3 = -vecSmtx1 "
       << (vecSmtx3 = -vecSmtx1) << endl;
  cout << "vecSmtx3 = vecSmtx3*smtx2 "
       << (vecSmtx3 = vecSmtx3*smtx2) << endl;
  cout << "vecSmtx3 = smtx2*vecSmtx3 "
       << (vecSmtx3 = smtx2*vecSmtx3) << endl;
  cout << "vecSmtx3 *= smtx2 "
       << (vecSmtx3 *= smtx2) << endl;
  cout << "smtx2 = vecSmtx1*vecSmtx2 "
       << (smtx2 = vecSmtx1*vecSmtx2) << endl;
  cout << "vecSmtx3 = vecSmtx3/smtx2 "
       << (vecSmtx3 = vecSmtx3/smtx2) << endl;
  cout << "vecSmtx3 /= smtx2 "
       << (vecSmtx3 /= smtx2) << endl;

  int f;
  cout << "f = vecSmtx1 != vecSmtx2 "
       << (f = vecSmtx1 != vecSmtx2) << endl;

  typedef CWTSpaceVector<CWSMat2> CWSvecSMat2;

  cout << endl << "CWTSpaceVector<T>" << endl << endl;

  CWSvecSMat2 svecSmtx1, svecSmtx2, svecSmtx3;
  cout << "svecSmtx1 = CWTZero<CWSvecSMat2>() "
       << (svecSmtx1 = CWTZero<CWSvecSMat2>()) << endl;
  svecSmtx2.fill(smtx);
  cout << "svecSmtx2.fill(smtx) "
       << svecSmtx2 << endl;

  cout << "svecSmtx3 = svecSmtx1 + svecSmtx2 "
       << (svecSmtx3 = svecSmtx1 + svecSmtx2) << endl;
  cout << "svecSmtx3 += svecSmtx2 "
       << (svecSmtx3 += svecSmtx2) << endl;
  cout << "svecSmtx3 = svecSmtx1 - svecSmtx2 "
       << (svecSmtx3 = svecSmtx1 - svecSmtx2) << endl;
  cout << "svecSmtx3 -= svecSmtx2 "
       << (svecSmtx3 -= svecSmtx2) << endl;
  cout << "svecSmtx3 = -svecSmtx2 "
       << (svecSmtx3 = -svecSmtx2) << endl;
  cout << "svecSmtx3 = svecSmtx2*smtx "
       << (svecSmtx3 = svecSmtx2*smtx) << endl;
  cout << "svecSmtx3 = smtx*svecSmtx2 "
       << (svecSmtx3 = smtx*svecSmtx2) << endl;
  cout << "svecSmtx3 *= smtx "
       << (svecSmtx3 *= smtx) << endl;
  cout << "smtx2 = svecSmtx2*svecSmtx2 "
       << (smtx2 = svecSmtx2*svecSmtx2) << endl;

  cout << "svecSmtx1[0] = smtx "
       << (svecSmtx1[0] = smtx) << endl;
  cout << "svecSmtx3 = svecSmtx1%svecSmtx2 "
       << (svecSmtx3 = svecSmtx1%svecSmtx2) << endl;
  cout << "svecSmtx3 %= svecSmtx2 "
       << (svecSmtx3 %= svecSmtx2) << endl;

  cout << "svecSmtx3 = svecSmtx2/smtx "
       << (svecSmtx3 = svecSmtx2/smtx) << endl;
  cout << "svecSmtx3 /= smtx "
       << (svecSmtx3 /= smtx) << endl;

  typedef CWTQuaternion<CWSMat2> CWQuatSMat2;

  cout << endl << "CWTQuaternion<T>" << endl << endl;

  CWQuatSMat2 qtnSmtx1, qtnSmtx2, qtnSmtx3;
  cout << "qtnSmtx1 = CWTZero<CWQuatSMat2>() "
       << (qtnSmtx1 = CWTZero<CWQuatSMat2>()) << endl;
  qtnSmtx1.fill(CWTUnity<CWSMat2>());
  cout << "qtnSmtx1.fill(CWTUnity<CWSMat2>()) "
       << qtnSmtx1  << endl;
  cout << "qtnSmtx2 = qtnSmtx1*smtx2 "
       << (qtnSmtx2 = qtnSmtx1*smtx2) << endl;
  cout << "qtnSmtx3 = qtnSmtx1 "
       << (qtnSmtx3 = qtnSmtx1) << endl;

  cout << "qtnSmtx2 = qtnSmtx1 + qtnSmtx1 "
       << (qtnSmtx2 = qtnSmtx1 + qtnSmtx1) << endl;
  cout << "qtnSmtx3 += qtnSmtx1 "
       << (qtnSmtx3 += qtnSmtx1) << endl;
  cout << "qtnSmtx2 = qtnSmtx1 - qtnSmtx1 "
       << (qtnSmtx2 = qtnSmtx1 - qtnSmtx1) << endl;
  cout << "qtnSmtx3 -= qtnSmtx1 "
       << (qtnSmtx3 -= qtnSmtx1) << endl;
  cout << "qtnSmtx3 = -qtnSmtx1 "
       << (qtnSmtx3 = -qtnSmtx1) << endl;
  cout << "qtnSmtx2 = smtx2*qtnSmtx1 "
       << (qtnSmtx2 = smtx2*qtnSmtx1) << endl;
  cout << "qtnSmtx3 *= qtnSmtx1 "
       << (qtnSmtx3 *= qtnSmtx1) << endl;
  cout << "qtnSmtx3 = qtnSmtx1*conj(qtnSmtx1) "
       << (qtnSmtx3 = qtnSmtx1*conj(qtnSmtx1)) << endl;
  cout << "qtnSmtx3 = inv(qtnSmtx1) "
       << (qtnSmtx3 = inv(qtnSmtx1)) << endl;
  cout << "qtnSmtx3 = qtnSmtx1/smtx2 "
       << (qtnSmtx3 = qtnSmtx1/smtx2) << endl;
  cout << "qtnSmtx3 /= smtx2 "
       << (qtnSmtx3 /= smtx2) << endl;
  cout << "qtnSmtx3 = qtnSmtx1/qtnSmtx2 "
       << (qtnSmtx3 = qtnSmtx1/qtnSmtx2) << endl;
  cout << "qtnSmtx3 /= qtnSmtx1 "
       << (qtnSmtx3 /= qtnSmtx1) << endl;

  cout << endl << "End test of matrices with structured elements" << endl;
}

//
// Test base matrix
//
void test_matrix ( void )
{

  cout << endl << "Start Matrix test" << endl;
  //_CWMatrix<> mx; must use namespace as below
  CwMtx::CWTMatrix<> mx;

  //
  // Test Phase 1. Check the mechcanics of template.
  //

  // The only way to test the template is through
  // instantiation. Otherwise the compiler does not include the code
  // and hence doesn't compile anything.  So the first set of tests in
  // Test Phase 1 is merely just compilation, the numbers are
  // ficticous.
  cout << endl << "CWMatrix constructors" << endl;
  CWMatrix M0;
  CWMatrix M1( 2 , 2 );
  CWMatrix M2( 3 , 3 );
  CWMatrix M3( M1 );
  CWMatrix M6 = M2;

  cout << endl << "Dimension CWMatrix" << endl;
  M0.dimension( 4 , 5 );
  cout << "M0 = " << M0 << endl;
  CWMatrix M4( M0 , 1 , 2 , 3 , 4 );
  M4.fill(1);
  cout << "M4 = " << M4 << endl;

  cout << endl << "MapInto" << endl;
  M1.mapInto( M0 , 0 , 0 , 1 , 1 );
  M1.fill(1);
  cout << "M1 = " << M1 << endl;
  cout << "M0 = " << M0 << endl;
  cout << endl << "GetStatus" << endl;
  int s = M0.getStatus();
  cout << "Status = " << s << endl;
	
  cout << endl << "GetCols and rows" << endl;
  M0.getCols();
  M0.getRows();
  double d = *M4[0];
  cout << "d = " << d << endl;
	
  cout << endl << "Matrix + Matrix" << endl;
  M3.fill(1);
  cout << "M1 = " << M1 << endl;
  cout << "M3 = " << M3 << endl;
  CWMatrix M5 = M1 + M3;
  cout << "M5 = " << M5 << endl;
  cout << endl << "Matrix - Matrix" << endl;
  // this found an underscore "_" missing in the template
  M5 = M1 - M3;
  cout << "M5 = " << M5 << endl;
  cout << endl << "-Matrix" << endl;
  M5 = -M3;
  cout << "M5 = " << M5 << endl;

  cout << endl << "Matrix * scalar" << endl;
  M2.fill(2);
  M5 = M2 * 2.0;
  cout << "M5 = " << M5 << endl;
  cout << endl << "scalar * Matrix" << endl;
  M5 = 2.0 * M2;
  cout << "M5 = " << M5 << endl;
  cout << endl << "Matrix * Matrix" << endl;
  M6.fill(3);
  M5 = M2 * M6;
  cout << "M5 = " << M5 << endl;
  cout << endl << "Matrix / scalar" << endl;
  // this found the infinite recursion occuring in the "operator /()"
  M5 = M2 / 3.0;
  cout << "M5 = " << M5 << endl;

  M6 -= M2;
  M6 += M2;
  M6 *= 3.0;
  M6 /= 4.0;

  if ( M6 == M2 )
    cout << "M6 equal M2" << endl;
  else
    cout << "M6 not equal M2" << endl;

  if ( M6 != M2 )
    cout << "M6 not equal M2" << endl;
  else
    cout << "M6 equal M2" << endl;

  // Can't do any of the Store* methods until we allocate.
  CWMatrix M7( 3 , 3 );
  M7.storeProduct( M6 , M2 );
  M7.storeTranspose( M6 );
  // this core dumps if M7 was not defined is size.
  M7.storeAtPosition( 0 , 0 , M2 );
  M7.fill( 2 );
  M6.interchangeRows( 1 , 2 );
  M2.addRowToRow( 1 , 2 , 2.0 );
  M3.multiplyRow( 0 , 3.0 );

  //
  // Test Phase 2. Check the mathimatical validty of the matrix template
  //

  // Some checks are going to be done with 2x2 matrices and other 3x3 matrices.
  CWMatrix M10( 2 , 2 );
  CWMatrix M11( 2 , 2 );
  M10[0][0] = 2.5;
  M10[0][1] = 0.0;
  M10[1][0] = 0.0;
  M10[1][1] = 2.5;

  M11[0][0] = 2.5;
  M11[0][1] = 0.0;
  M11[1][0] = 0.0;
  M11[1][1] = 2.5;
  cout << "M10 = " << M10 << endl;
  cout << "M11 = " << M11 << endl;
  cout << "M10*M11 = " << M10*M11 << endl;

  //
  // Test Phase 3
  //

  // Can't be tested until the other sibling classes are converted to templates

  cout << endl << "Deallocate" << endl;
  M0.deallocate();
  cout << "M0 = " << M0 << endl;
  cout << endl << "GetStatus" << endl;
  s = M0.getStatus();
  cout << "Status = " << s << endl;

  cout << endl << "End Matrix test" << endl;

}

// Test vector

void test_vector( )
{

  cout << endl << "Start Vector test" << endl;

  //
  // Test Phase 1. Check the mechcanics of template.
  //
  CWVector v0( 3 );
  v0[0] = 1.0;
  v0[1] = 1.0;
  v0[2] = 1.0;
  cout << "v0 = " << v0 << endl;
	
  CWMatrix m0( 3 , 1 );
  CWVector v1( m0 );
  CWVector v2( v1 );
  CWVector v3( m0 , 1 , 2 , 3 );
  CWVector v4( v3 , 1 , 2 );

  v3.mapInto( m0 , 1 , 2 , 3 );
  v3.mapInto( v1 , 1 , 2 );

  CWVector v5;
  v5.dimension( 3 );

  double d = v0[0];
  cout << "d = " << d << endl;

  CWVector v6( 3 );
  v6[0] = 2.0;
  v6[1] = 2.0;
  v6[2] = 2.0;
  cout << "v6 = " << v6 << endl;

  cout << "v0 + v6 = " << (v0 + v6) << endl;
  cout << "v0 - v6 = " << (v0 - v6) << endl;
  cout << "v0 * v6 = " << (v0 * v6) << endl;
  cout << "v0 / 3.0 = " << (v0 / 3.0) << endl;

  CWVector v7( 3 );

  v7 = v6;
  v7 += v6;
  v7 -= v6;
  v7 *= 3.0;
  v7 /= 3.0;

  v7.storeAtRow( 0 , v6 );

  CWMatrix m2( 3 , 3 );
  CWVector v8 = m2*v0;

  //
  // Test Phase 2. Check the mathimatical validty of the vector template
  //

  // Some checks are going to be done with 2x2 matrices and other 3x3 matrices.
  v6[0] = 3.0;
  v6[1] = 4.0;
  v6[2] = 5.0;
  cout << "v6 = " << v6 << endl;

  cout << "v0 + v6 = " << (v0 + v6) << endl;
  cout << "v0 - v6 = " << (v0 - v6) << endl;
  cout << "v0 * v6 = " << (v0 * v6) << endl;
  cout << "v0 / 3.0 = " << (v0 / 3.0) << endl;
  cout << "norm as !v6 " << !v6 << endl;
  cout << "norm as norm(v6) " << norm(v6) << endl;
  cout << "unit vector v6.unit() " << v6.unit() << endl;

  v6.makeUnit();
  cout << "v6.makeUnit() " << v6 << endl;

  // Test matrix*vector.
  CWMatrix m3( 2 , 3 );
  m3.fill(1.0);
  cout << "m3 * v6 = " << (m3 * v6) << endl;
	
  cout << endl << "End Vector test" << endl;

}

// Test Square Matrix

void test_smatrix( )
{

  cout << endl << "Start Square Matrix test" << endl;
  //
  // Test Phase 1. Check the mechcanics of template.
  //
  typedef CWTSquareMatrix< CWTSquareMatrix<> > CWMatrixMatrix;

  // allocate a 2x2 matrix
  // This only allocates the elements. not what is in the elements.
  CWMatrixMatrix mm0( 2 );
  CWMatrixMatrix mm1( 2 );
  // allocate each element
  CWSquareMatrix smatTmp( 2 );
  mm0[0][0] = smatTmp;
  mm0[0][1] = smatTmp;
  mm0[1][0] = smatTmp;
  mm0[1][1] = smatTmp;
  mm1[0][0] = smatTmp;
  mm1[0][1] = smatTmp;
  mm1[1][0] = smatTmp;
  mm1[1][1] = smatTmp;

  CWSquareMatrix mIdentity( 2 );
  mIdentity.makeUnity();
  // fill it with a bunch of Identity matrices.
  mm1.fill( mIdentity );
  mm0.fill( mIdentity );
  cout << endl << "mm0 = " << mm0 << endl;
  cout << endl << "mm1 = " << mm1 << endl;

  CWMatrixMatrix mm3 = mm0 + mm1;
  cout << endl << "mm3 0,0 = " << mm3[0][0] << endl;
  cout << endl << "mm3 0,1 = " << mm3[1][0] << endl;
  cout << endl << "mm3 1,0 = " << mm3[0][1] << endl;
  cout << endl << "mm3 1,1 = " << mm3[1][1] << endl;
  // or perhaps
  cout << endl << "mm3 = " << mm3 << endl;
	
  // Test trace
  cout << endl << "Calculate the trace of a unity matrix." << endl;

  for (unsigned c = 1; c <= 5; c++)
    {
      CWSquareMatrix smtx(c);
      smtx.makeUnity();
      cout << "smtx(" << smtx.getCols() << ") = " << smtx
	   << " tr(smtx) = " << tr(smtx) << endl << endl;
    }

  //CWMatrixOfSquareMatrices mosm( 3 , 3 );

  // Test determinant
  cout << endl << "Calculate the determinant of a matrix." << endl;

  CWSquareMatrix smtx(3);

  smtx[0][0] = 2; smtx[0][1] =  3; smtx[0][2] = -1;
  smtx[1][0] = 3; smtx[1][1] =  5; smtx[1][2] =  2;
  smtx[2][0] = 1; smtx[2][1] = -2; smtx[2][2] = -3;

  cout << "mtx = " << smtx << " det(mtx) = " << det(smtx) << endl;

  //
  // Test Phase 2. Check the mathimatical validty of the vector template
  //
	
  cout << endl << "End Square Matrix test" << endl;

}

// Test space vector

void test_svector( )
{

  cout << endl << "Start Space Vector test" << endl;
  //
  // Test Phase 1. Check the mechcanics of template.
  //
  CWSpaceVector v0, v1;
  v0[0] = 1.0;
  v0[1] = 0.0;
  v0[2] = 0.0;
  cout << "v0 = " << v0 << endl;

  v1[0] = 0.0;
  v1[1] = 1.0;
  v1[2] = 0.0;
  cout << "v1 = " << v1 << endl;

  cout << "v0*v1 = " << v0*v1 << endl;
  cout << "v0%v1 = " << v0%v1 << endl;

  // without the namespace gcc complains.
  CwMtx::CWTSpaceVector<> v2;

  //
  // Test Phase 2. Check the mathimatical validty of the space vector template
  //

  cout << endl << "End Space Vector test" << endl;

}

// Test Quaternions

void test_quaternions( )
{
  // VC++ is more compliant with namespaces.  I can't seem to find the
  // exact pattern at which gcc begins to complain.  It seems that gcc
  // ignores template functions being in namespaces. That is ok as
  // templates functions are always specific to templates classes so
  // there is rarely namespace clashes. Gcc will complain about
  // namespace directives missing for template though.
  using namespace CwMtx;
  using namespace std;

  // just making sure the matrix namespace doesn't clash with something else.
  // it meant as a test against gcc's namespace handling.
  list<int> x;

  cout << endl << "Start Quaternion test" << endl;
  //
  // Test Phase 1. Check the mechcanics of template.
  //
  // 1-axis
  CWSpaceVector vAxis( 0.0 , 1.0 , 0.0 );
  // rotate 45.0 degrees about Y-axis.
  CWQuaternion q0( qtnFromAxisAngle( vAxis , 45.0/57.3 ) );
  cout << "q0 = " << q0 << endl;
  CWVector vAxisAngle = axisAngleFromQtn( q0 );
  cout << "vAxisAngle = " << vAxisAngle << endl;
	
  // Test conjugate
  cout << endl << "Calculate the conjugate of a quaternion." << endl;

  CWQuaternion qtn(1, 2, 3, 4);

  cout << "qtn = " << qtn << endl
       << "conj(qtn) = " << conj(qtn) << endl
       << "qtn*conj(qtn) = " << qtn*conj(qtn) << endl;

  CWQuaternion qtnReal(1);

  cout << "qtnReal = " << qtnReal << endl;

  CWQuaternion q0Conj;
  q0Conj.storeConjugate( q0 );
  cout << "q0Conj = " << q0Conj << endl;
  // or
  cout << "conjugate q0 = " << conj(q0) << endl;

  CWSpaceVector vUnit( 1.0 , 1.0 , 0.0 );
  // should give (0.707 , 0.707 , 0.0)
  cout << "Unit axis = " << vUnit.unit() << endl;

  //
  // Test Phase 2. Check the mathimatical validty of the Quaternions template
  //
  // point to be rotated in the X,Z plane.
  CWQuaternion qPoint( 2.0 , 0.0 , 0.0 , 0.0 );
  // For a right-handed system this should rotate the point CCW to
  // (1.414 , 0 , -1.414)
  // q1 is now a rotated point.
  CWQuaternion q1 = q0 * qPoint * conj(q0);
  cout << "q1 = " << q1 << endl;

  vAxisAngle = axisAngleFromQtn( q1 );
  cout << "vAxisAngle = " << vAxisAngle << endl;

  CWSpaceVector vNewAxis;
  vNewAxis.mapInto( vAxisAngle );
  cout << "vNewAxis = " << vNewAxis << endl;
  // or
  CWSpaceVector vNewAxis2;
  // map quaternion into a space vector
  vNewAxis2.mapInto(  q1 , 0 );
  cout << "vNewAxis2 = " << vNewAxis2 << endl;
  // or
  CWVector vNewAxis3;
  vNewAxis3.mapInto( vAxisAngle , 0 , 2 );
  cout << "vNewAxis3 = " << vNewAxis3 << endl;

  cout << "Norm of vNewAxis = " << vNewAxis.norm() << endl;
  cout << "Unit norm of vNewAxis = " << vNewAxis.unit() << endl;

  // Test quaternion division
  CWQuaternion qtn1(0.5*sqrt(2.0), 0.5*sqrt(2.0), 0, 0);
  CWQuaternion qtn2(0, 0, sqrt(2.0), sqrt(2.0));
  cout << endl << "Quaternion division" << endl << endl
       << "qtn1 = " << qtn1 << endl
       << "qtn2 = " << qtn2 << endl
       << "(qtn1*qtn2)/qtn2 = " << (qtn1*qtn2)/qtn2 << endl
       << "(qtn1*qtn2)/qtn1 = " << (qtn1*qtn2)/qtn1 << endl;

  // Test QtnFromSmat
  cout << endl << "Calculate quaternion from a transformation matrix." << endl;

  const double DEG2RAD = M_PI/180.0;
  for (double psi = 0; psi < 360; psi += 45)
    {
      for (double theta = 0; theta < 360; theta += 45)
	{
	  for (double phi = 0; phi < 360; phi += 45)
	    {
	      CWTSquareMatrix<double> smat =
		smatFromEuler321Angles(psi*DEG2RAD,
				       theta*DEG2RAD,
				       phi*DEG2RAD);
	      CWTQuaternion<double> qtn = qtnFromSmat(smat);

	      int i = 0;
	      if (smat[1][1] > smat[0][0]) i = 1;
	      if (smat[2][2] > smat[i][i]) i = 2;

	      cout << "psi = " << psi
		   << ", theta = " << theta
		   << ", phi = " << phi << endl
		   << "trace = " << tr(smat) << ", case label: " << i << endl
		   << "psi = " << euler321Angle3FromQtn(qtn)/DEG2RAD
		   << ", theta = " << euler321Angle2FromQtn(qtn)/DEG2RAD
		   << ", phi = " << euler321Angle1FromQtn(qtn)/DEG2RAD << endl
		   << "qtn = " << qtn << endl
		   << "qtnEuler = " << qtnFromEuler321Angles(psi*DEG2RAD,
							     theta*DEG2RAD,
							     phi*DEG2RAD)
		   << endl << endl;
	    }
	}
    }

  // Test quaternions constructed from exponential form.
  cout << endl
       << "Test quaternions constructed from exponential form." << endl;

  CWMatrix qeMat(3, 1);
  qeMat[0][0] = 1.0;
  qeMat[1][0] = 0.0;
  qeMat[2][0] = 0.0;

  CWSpaceVector qeSVec(-1.4, 3.2, 1.7);

  CWQuaternion qe0(1.0, qeMat, (45.0 / 180.0) * M_PI);
  CWQuaternion qEuler = qtnFromEuler321Angles(0.0, 0.0, 2.0*(45.0 / 180.0) * M_PI);
  CWQuaternion qe1(1.7, qeSVec, (-45.0 / 180.0) * M_PI);
  CWQuaternion qe2(-0.7, CWSpaceVector(0.4, 0.2, -0.7), (25.0 / 180.0) * M_PI);

  // should give
  cout << "qe0    = " << qe0 << endl;
  cout << "qEuler = " << qEuler << endl;
  cout << "qe1    = " << qe1 << endl;
  cout << "qe2    = " << qe2 << endl << endl;

  qtn1 = CWTQuaternion<>(1, 2, 3, 4);
  qtn2 = qtn1;

  cout << "sgn(qtn1) "
       << (sgn(qtn1)) << endl;
  cout << "sgn(CWTQuaternion<>(0, 0, 0, 1)) "
       << (sgn(CWTQuaternion<>(0, 0, 0, 1))) << endl;
  cout << "sgn(CWTQuaternion<>(0, 0, 0, 2)) "
       << (sgn(CWTQuaternion<>(0, 0, 0, 2))) << endl;
  cout << "sgn(CWTQuaternion<>(1, 0, 0, 0)) "
       << (sgn(CWTQuaternion<>(1, 0, 0, 0))) << endl;
  cout << "sgn(CWTQuaternion<>(2, 0, 0, 0)) "
       << (sgn(CWTQuaternion<>(2, 0, 0, 0))) << endl;
  cout << "sgn(CWTQuaternion<>(1, 1, 1, 1)) "
       << (sgn(CWTQuaternion<>(1, 1, 1, 1))) << endl;
  cout << "sgn(CWTQuaternion<>(2, 2, 2, 2)) "
       << (sgn(CWTQuaternion<>(2, 2, 2, 2))) << endl;
  cout << "sgn(CWTQuaternion<>(3, 3, 3, 3)) "
       << (sgn(CWTQuaternion<>(3, 3, 3, 3))) << endl;
  cout << "sgn(CWTQuaternion<>(-4, -4, -4, -4)) "
       << (sgn(CWTQuaternion<>(-4, -4, -4, -4))) << endl << endl;

  cout << "arg(qtn1) "
       << (arg(qtn1)) << endl;
  cout << "arg(CWTQuaternion<>(0, 0, 0, 1)) "
       << (arg(CWTQuaternion<>(0, 0, 0, 1))) << endl;
  cout << "arg(CWTQuaternion<>(0, 0, 0, 2)) "
       << (arg(CWTQuaternion<>(0, 0, 0, 2))) << endl;
  cout << "arg(CWTQuaternion<>(1, 0, 0, 0)) "
       << (arg(CWTQuaternion<>(1, 0, 0, 0))) << endl;
  cout << "arg(CWTQuaternion<>(2, 0, 0, 0)) "
       << (arg(CWTQuaternion<>(2, 0, 0, 0))) << endl;
  cout << "arg(CWTQuaternion<>(1, 1, 1, 1)) "
       << (arg(CWTQuaternion<>(1, 1, 1, 1))) << endl;
  cout << "arg(CWTQuaternion<>(2, 2, 2, 2)) "
       << (arg(CWTQuaternion<>(2, 2, 2, 2))) << endl;
  cout << "arg(CWTQuaternion<>(3, 3, 3, 3)) "
       << (arg(CWTQuaternion<>(3, 3, 3, 3))) << endl;
  cout << "arg(CWTQuaternion<>(-4, -4, -4, -4)) "
       << (arg(CWTQuaternion<>(-4, -4, -4, -4))) << endl << endl;

  cout << "exp(qtn1) "
       << (exp(qtn1)) << endl;
  cout << "norm(qtn1)*exp(CWTQuaternion<>(sgn(im(qtn1))*arg(qtn1))) "
       << (norm(qtn1)*exp(CWTQuaternion<>(sgn(im(qtn1))*arg(qtn1)))) << endl;
  cout << "exp(CWTQuaternion<>(0, 0, 0, 1)) "
       << (exp(CWTQuaternion<>(0, 0, 0, 1))) << endl;
  cout << "exp(CWTQuaternion<>(0, 0, 0, 2)) "
       << (exp(CWTQuaternion<>(0, 0, 0, 2))) << endl;
  cout << "exp(CWTQuaternion<>(1, 0, 0, 0)) "
       << (exp(CWTQuaternion<>(1, 0, 0, 0))) << endl;
  cout << "exp(CWTQuaternion<>(2, 0, 0, 0)) "
       << (exp(CWTQuaternion<>(2, 0, 0, 0))) << endl;
  cout << "exp(CWTQuaternion<>(1, 1, 1, 1)) "
       << (exp(CWTQuaternion<>(1, 1, 1, 1))) << endl;
  double d = M_PI/sqrt(3.0);
  cout << "exp(CWTQuaternion<>(" << d << ", " << d << ", " << d << ", "  << d  << ")) "
       << (exp(CWTQuaternion<>(d, d, d, d))) << endl;
  cout << "exp(CWTQuaternion<>(2, 2, 2, 2)) "
       << (exp(CWTQuaternion<>(2, 2, 2, 2))) << endl;
  cout << "exp(CWTQuaternion<>(3, 3, 3, 3)) "
       << (exp(CWTQuaternion<>(3, 3, 3, 3))) << endl;
  cout << "exp(CWTQuaternion<>(-4, -4, -4, -4)) "
       << (exp(CWTQuaternion<>(-4, -4, -4, -4))) << endl << endl;

  cout << "log(qtn1) "
       << (log(qtn1)) << endl;
  cout << "log(CWTQuaternion<>(0, 0, 0, 1)) "
       << (log(CWTQuaternion<>(0, 0, 0, 1))) << endl;
  cout << "log(CWTQuaternion<>(0, 0, 0, 2)) "
       << (log(CWTQuaternion<>(0, 0, 0, 2))) << endl;
  cout << "log(CWTQuaternion<>(1, 0, 0, 0)) "
       << (log(CWTQuaternion<>(1, 0, 0, 0))) << endl;
  cout << "log(CWTQuaternion<>(2, 0, 0, 0)) "
       << (log(CWTQuaternion<>(2, 0, 0, 0))) << endl;
  cout << "log(CWTQuaternion<>(1, 1, 1, 1)) "
       << (log(CWTQuaternion<>(1, 1, 1, 1))) << endl;
  cout << "log(CWTQuaternion<>(" << d << ", " << d << ", " << d << ", "  << d  << ")) "
       << (log(CWTQuaternion<>(d, d, d, d))) << endl;
  cout << "log(CWTQuaternion<>(2, 2, 2, 2)) "
       << (log(CWTQuaternion<>(2, 2, 2, 2))) << endl;
  cout << "log(CWTQuaternion<>(3, 3, 3, 3)) "
       << (log(CWTQuaternion<>(3, 3, 3, 3))) << endl;
  cout << "log(CWTQuaternion<>(-4, -4, -4, -4)) "
       << (log(CWTQuaternion<>(-4, -4, -4, -4))) << endl << endl;

  cout << "exp(log(qtn1)) "
       << (exp(log(qtn1))) << endl;
  cout << "log(exp(qtn1)) "
       << (log(exp(qtn1))) << endl;
  cout << "exp(log(CWTQuaternion<>(0, 0, 0, 1))) "
       << (exp(log(CWTQuaternion<>(0, 0, 0, 1)))) << endl;
  cout << "log(exp(CWTQuaternion<>(0, 0, 0, 1))) "
       << (log(exp(CWTQuaternion<>(0, 0, 0, 1)))) << endl;
  cout << "exp(log(CWTQuaternion<>(0, 0, 0, 2))) "
       << (exp(log(CWTQuaternion<>(0, 0, 0, 2)))) << endl;
  cout << "log(exp(CWTQuaternion<>(0, 0, 0, 2))) "
       << (log(exp(CWTQuaternion<>(0, 0, 0, 2)))) << endl;
  cout << "exp(log(CWTQuaternion<>(1, 0, 0, 0))) "
       << (exp(log(CWTQuaternion<>(1, 0, 0, 0)))) << endl;
  cout << "log(exp(CWTQuaternion<>(1, 0, 0, 0))) "
       << (log(exp(CWTQuaternion<>(1, 0, 0, 0)))) << endl;
  cout << "exp(log(CWTQuaternion<>(2, 0, 0, 0))) "
       << (exp(log(CWTQuaternion<>(2, 0, 0, 0)))) << endl;
  cout << "log(exp(CWTQuaternion<>(2, 0, 0, 0))) "
       << (log(exp(CWTQuaternion<>(2, 0, 0, 0)))) << endl;
  cout << "exp(log(CWTQuaternion<>(0.5, 0.5, 0.5, 0.5))) "
       << (exp(log(CWTQuaternion<>(0.5, 0.5, 0.5, 0.5)))) << endl;
  cout << "log(exp(CWTQuaternion<>(0.5, 0.5, 0.5, 0.5))) "
       << (log(exp(CWTQuaternion<>(0.5, 0.5, 0.5, 0.5)))) << endl;
  cout << "exp(log(CWTQuaternion<>(1, 1, 1, 1))) "
       << (exp(log(CWTQuaternion<>(1, 1, 1, 1)))) << endl;
  cout << "log(exp(CWTQuaternion<>(1, 1, 1, 1))) "
       << (log(exp(CWTQuaternion<>(1, 1, 1, 1)))) << endl;
  cout << "log(exp(CWTQuaternion<>(" << d << ", " << d << ", " << d << ", "  << d  << "))) "
       << (log(exp(CWTQuaternion<>(d, d, d, d)))) << endl;
  cout << "exp(log(CWTQuaternion<>(" << d << ", " << d << ", " << d << ", "  << d  << "))) "
       << (exp(log(CWTQuaternion<>(d, d, d, d)))) << endl;
  cout << "exp(log(CWTQuaternion<>(2, 2, 2, 2))) "
       << (exp(log(CWTQuaternion<>(2, 2, 2, 2)))) << endl;
  cout << "log(exp(CWTQuaternion<>(2, 2, 2, 2))) "
       << (log(exp(CWTQuaternion<>(2, 2, 2, 2)))) << endl;
  cout << "exp(log(CWTQuaternion<>(3, 3, 3, 3))) "
       << (exp(log(CWTQuaternion<>(3, 3, 3, 3)))) << endl;
  cout << "log(exp(CWTQuaternion<>(3, 3, 3, 3))) "
       << (log(exp(CWTQuaternion<>(3, 3, 3, 3)))) << endl;
  cout << "exp(log(CWTQuaternion<>(-4, -4, -4, -4))) "
       << (exp(log(CWTQuaternion<>(-4, -4, -4, -4)))) << endl;
  cout << "log(exp(CWTQuaternion<>(-4, -4, -4, -4))) "
       << (log(exp(CWTQuaternion<>(-4, -4, -4, -4)))) << endl << endl;

  cout << "pow(qtn1, qtn2) "
       << (pow(qtn1, qtn2)) << endl;
  cout << "pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(0, 0, 0, 1) "
       << (pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(0, 0, 0, 1)))
       << endl;
  cout << "pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(0, 0, 0, 2) "
       << (pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(0, 0, 0, 2)))
       << endl;
  cout << "pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(1, 0, 0, 0) "
       << (pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(1, 0, 0, 0)))
       << endl;
  cout << "pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(2, 0, 0, 0) "
       << (pow(CWTQuaternion<>(0, 0, 0, 2), CWTQuaternion<>(2, 0, 0, 0)))
       << endl;
  cout << "pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(0, 0, 0, 1) "
       << (pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(0, 0, 0, 1)))
       << endl;
  cout << "pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(0, 0, 0, 2) "
       << (pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(0, 0, 0, 2)))
       << endl;
  cout << "CWTQuaternion<>(2, 0, 0, 0)*CWTQuaternion<>(2, 0, 0, 0) "
       << (CWTQuaternion<>(2, 0, 0, 0)*CWTQuaternion<>(2, 0, 0, 0))
       << endl;
  cout << "pow(CWTQuaternion<>(1, 0, 0, 0), CWTQuaternion<>(1, 0, 0, 0) "
       << (pow(CWTQuaternion<>(1, 0, 0, 0), CWTQuaternion<>(1, 0, 0, 0)))
       << endl;
  cout << "pow(CWTQuaternion<>(1, 0, 0, 0), CWTQuaternion<>(2, 0, 0, 0) "
       << (pow(CWTQuaternion<>(1, 0, 0, 0), CWTQuaternion<>(2, 0, 0, 0)))
       << endl;
  cout << "pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(1, 0, 0, 0) "
       << (pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(1, 0, 0, 0)))
       << endl;
  cout << "pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(2, 0, 0, 0) "
       << (pow(CWTQuaternion<>(2, 0, 0, 0), CWTQuaternion<>(2, 0, 0, 0)))
       << endl << endl;

  cout << "End Quaternion test" << endl;

}

// Test coordinate system template functions.

void test_coordsys( )
{

  // using gcc 2.95.2 the namespace can be left out. VC++ is more
  // strict and it must be present
  using namespace CwMtx;

  cout << endl << "Start Coordinate System test" << endl;
  //
  // Test Phase 1. Check the mechcanics of template.
  //
  CWSquareMatrix sm0( 3 );
  double d = euler321Angle3FromSmat( sm0 );
  cout << "d = " << d << endl;

  //
  // Test Phase 2. Check the mathimatical validty of the coordinate template
  //

  // Test vectors in vectors
  typedef CWTSpaceVector< CWTSpaceVector<> > CWSpaceVectors;

  CWSpaceVectors vStandardBasisFrame;
  // x-axis or right
  vStandardBasisFrame[0] = CWSpaceVector( 1.0 , 0.0 , 0.0 );
  // y-axis or up
  vStandardBasisFrame[1] = CWSpaceVector( 0.0 , 1.0 , 0.0 );
  // z-axis or line of sight
  vStandardBasisFrame[2] = CWSpaceVector( 0.0 , 0.0 , 1.0 );
  // or
  CWSpaceVectors vObjectFrame(CWSpaceVector( 0.707 , 0.0 , 0.707 ),
			      CWSpaceVector( 0.0 , 1.0 , 0.0 ),
			      CWSpaceVector( 0.707 , 0.0 , 0.707 ));
	
  // Get the rotation matrix that represents a rotation from the
  // standard basis to the object's frame where a frame represents an
  // orientation.
  CWSquareMatrix rM( changeOfBasis( vObjectFrame , vStandardBasisFrame ) );
  cout << "rM = " << rM << endl;

  // convert matrix to quaternion and get conjugate. We want the
  // conjugate because we want to feed OpenGL a rotatation that
  // rotates the object from standard frame to the frame of the
  // object.  Typically this quaternion is converted to a AxisAngle
  // combo and passed to the glRotated method which just happens to
  // take an angle(degrees) plus an axis.
  CWQuaternion q = conj( qtnFromSmat( rM ) );

  // For example, if I were to call glRotate then I would do somthing
  // similar from "test_quaternions" method. Note: HERE I AM
  // INTERPRITING {q} TO REPRESENT AN ORIENTATION.
  CWVector vAxisAngle = axisAngleFromQtn( q );
  // The following is real working code that I use in practice.
  // glPushMatrix(); glRotated( vAxisAngle[3]*57.3 , vAxisAngle[0],
  // vAxisAngle[1] , vAxisAngle[2] ); Draw object here glPopMatrix();

  // Or, we can apply that rotation to some other object, given that
  // the object's default local orientation/frame is the standard
  // basis.  Note: HERE I AM INTERPRITING {q} TO REPRESENT A ROTATION.
  CWSpaceVector vSomePointInAnObject( 0.7 , 1.0 , 1.2 );
  // map from [vector space] into [quaternion space].
  CWQuaternion qSomePointInAnObject( vSomePointInAnObject , 0.0 );

  // or perhaps we overite
  qSomePointInAnObject = q * qSomePointInAnObject * conj(q);
  // map quaternion back into vector space
  vSomePointInAnObject.mapInto( qSomePointInAnObject , 0 );

  //
  // Test Phase 3
  //

  // Can't be tested until the other sibling classes are converted to templates

  cout << endl << "End Coordinate System test" << endl;

}

int main(int argc, char *argv[])
{
  test_matrix();
  test_vector();
  test_smatrix();
  test_svector();
  test_quaternions();
  test_coordsys();
  test_struct_matrix();

  return 0;
}
