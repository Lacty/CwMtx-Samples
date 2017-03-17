
#include <iostream>
#include "cwmtx/cwmtx.h"


auto showStatus(int status)-> void {
  if (status == CwMtx::N_NOTALLOCATED) std::cout << "NOT ALLOCATED" << std::endl;
  if (status == CwMtx::N_ALLOCATED)    std::cout << "ALLOCATED"     << std::endl;
  if (status == CwMtx::N_MAPPED)       std::cout << "MAPPED"        << std::endl;
};

int main() {
  CwMtx::CWTVector<double> vec;
  showStatus(vec.getStatus()); // NOT ALLOCATED
  
  // 2次元でallocate
  vec.dimension(2);
  
  // 出力
  std::cout << vec << std::endl; // [0; 0]
  
  // 同じ値で埋める
  vec.fill( 4.32 );
  std::cout << vec << std::endl; // [4.32; 4.32]

  // アクセス
  vec[0] = 3.14;
  vec[1] = 1.33;
  std::cout << vec << std::endl; // [3.14; 1.33]
  
  // 単位行列化
  vec.makeUnit();
  std::cout << vec << std::endl; // [0.920805; 0.390023]
  
  // ベクトルの長さを返す
  auto norm = vec.norm();
  std::cout << norm << std::endl; // 1
  
  // 状態を取得
  auto status = vec.getStatus();
  showStatus(status); // ALLOCATED
  
  // 別のベクトルで上書き
  {
    CwMtx::CWTVector<double> tmp( 2 );
    tmp.mapInto(vec, 0, 1);
    std::cout << tmp << std::endl; // [0.920805; 0.390023]
  }
  {
    CwMtx::CWTVector<double> tmp( 2 );
    tmp.mapInto(vec, 0, 0);
    std::cout << tmp << std::endl; // [0.920805]
  }
  {
    CwMtx::CWTVector<double> tmp( 2 );
    tmp.mapInto(vec, 1, 1);
    std::cout << tmp << std::endl; // [0.390023]
    showStatus(tmp.getStatus());   // MAPPED
  }
}
