#include "listQueue.h"

#include <iostream>
#include <fstream>
//#include <sstream>
using namespace std;


class registrar{
public:
  //declaring variables
  registrar();
  registrar(string d);
  string* getinfo(string d);
  void getnums(string *r);
  void runReg(int a, int b, int c, string *e);
  int linecount = 0;
  string allinfo = "";
  int windows = 0;
  string winToI = "";
  int time = 0;
  string timeToI = "";
  int numStud = 0;
  string numStudToI = "";
  int timestud = 0;
  string timestudToI = "";
  ifstream ifs;
  string inFile = "";
  listQueue<int> *p;
  listQueue<int> *z;
  string *studtimenums;
  string *nextstudnums;
  int *openwindows;
  int timer = 0;
  int studcount = 0;
  string allstring;
  int used = 0;
  int inuse = 0;
  string *input;
  string *secinput;
  int *idletimes;
  int *waittimes;
  int waiting = 0;


  int tencount = 0;
  double meanidle = 0;
  double meanwait = 0;
  int longwait = 0;
  int longidle = 0;
  int fivecount = 0;
  void runcalc(int *o, int *g);
  int totalwait = 0;
  int totalidle = 0;
  int medianwaitidx = 0;
  int medianidleidx = 0;
  double medianwait = 0;
  double medianidle = 0;




  bool checkEnd(int *q);

};
