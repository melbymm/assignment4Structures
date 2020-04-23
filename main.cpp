#include "registrar.h"
//#include "linkedList.h"
int main(int argc, char **argv){
  string filename;
  if(argc == 1){
    cerr << " Enter an argument into the command line plz" << endl;
    exit(1);
  }
  else {
    filename = argv[1];
  }
  registrar *t = new registrar(filename);


}
