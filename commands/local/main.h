#include "local.h"
#include "IO.h"
#include "debug.h"
#include "exit.h"


void ____IO_XXCaller__A(){
  __XXMM__File_IO();
  std::atexit(__XX__TIMER__AMAN_YY);
}


class m_main_XX{
  public:
  m_main_XX(){
    ____IO_XXCaller__A();
  }
};

m_main_XX _MXXMXXM_;