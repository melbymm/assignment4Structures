#include "registrar.h"
#include <algorithm>

registrar :: registrar(string d){
  listQueue<int> *p = new listQueue<int>();
  getinfo(d);
}
string* registrar :: getinfo(string d){
  ifs.open(d);
//open file
    if(!ifs.is_open()){
      cout << "Couldn't Open! " << endl;
}
//count lines before intaking lines, to create array
    while(ifs){
      //iterate through lines and count
      linecount++;

      getline(ifs,inFile);

    }
    ifs.close();

    ifs.open(d);

      if(!ifs.is_open()){
        cout << "Couldn't Open! " << endl;
  }
  input = new string[linecount];
  linecount = 0;
  while(ifs){
//read lines to array
    getline(ifs,input[linecount]);
    linecount++;

  }
//call next method
  getnums(input);

  //close file
  ifs.close();
}
void registrar :: getnums(string *r){
//iterate line by line
  for(int i = 0; i < linecount; ++i){
      if(i == 0){

        //input window number
        winToI = input[i];
        try{
        windows = stoi(winToI);
      } catch(const invalid_argument& a){
          cerr << "Invalid input" << endl;
          exit(1);
      }
       //initialize array keeping track of idle windows
        idletimes = new int[windows];

      }
      else if(i == 1){
        //input for time students arrive
        timeToI = input[i];
        try{
        time = stoi(timeToI);
      }catch(const invalid_argument& a){
          cerr << "Invalid input" << endl;
          exit(1);
      }
    }
      else if(i == 2){
        //get input for number of students arrriving
        numStudToI = input[i];
        try{
          numStud = stoi(numStudToI);
      }catch(const invalid_argument& a){
          cerr << "Invalid input" << endl;
          exit(1);
      }
        waittimes = new int[numStud];

      }
      else if(i <= 2 + numStud){
//get number for time each student will take
        timestudToI =input[i];

      if(i == 3){
        //create array when inputting first student time
        studtimenums = new string[numStud];

      }
//insert times into array
        studtimenums[studcount] = timestudToI;
        studcount++;
//call next method upon accounting for all students
        if(studcount==numStud){
            registrar::runReg(windows,time,numStud, studtimenums);

        }
      }

}

}


void registrar :: runReg(int a, int b, int c, string *e){

  inuse = a;
  int bnum = b;
  int cnum = c;
  string *r = new string[c];
  //make queue
  listQueue<int> *z = new listQueue<int>();
  openwindows = new int[a];
  //enter numbers into array
  for(int i = 0; i < numStud; ++i){

    waittimes [i] = 0;
  }
  //inserting numbers to queue
  for(int i = 0; i < cnum; ++i){
    try{
      timestud = stoi(studtimenums[i]);
  } catch(const invalid_argument& a){
      cerr << "Invalid input" << endl;
      exit(1);
  }
    z->insert(timestud);

  }
  //removing from queue, entering into array
  for (int i = 0; i < a; ++i){
    if(z->asize > 1){
      openwindows[i] = z->remove();
    }
    else if(z->asize > 0){
      openwindows[i] = z->getfront();
      z->asize--;
    }
    }


  while(inuse > 0){
//iterate timer
    time ++;
//array for how long students have been waiting
    for(int i = 0; i < (numStud - windows); ++i){
      waittimes[i + numStud - z->asize]++;
    }

    for (int i = 0; i < a; ++i){
      openwindows[i]--;
//iterate how much time each student at the windows needs
      if(openwindows[i] == 0){
//remove if possible, otherwise retrieve front
        if(z->asize> 1){

          openwindows[i] = z->remove();


        }
        else if(z->asize == 1){
          openwindows[i] = z->getfront();
          z->asize--;

        }
        else{
          openwindows[i] == -1;
          inuse --;

        }
      }
      //iterate idle window time counter
      else if(openwindows[i] <= -1){
        idletimes[i] ++;
      }

    }


}
//call calculation method
    runcalc(idletimes, waittimes);

}


void registrar :: runcalc(int *o, int *g){
  //declaring arrays
  int *allidle = o;
  int *allwait = g;
  longidle = 0;

  for(int i = 0; i < windows; ++i){
    //count time all windows have been idle
    totalidle+=allidle[i];

//sort to find median
    sort(allidle, allidle + windows);
    //look for max
    if(allidle[i] > allidle[longidle]){

      longidle = i;
    }
    //check if been idle 5 minutes
    if(allidle[i] >= 5){
      fivecount++;
    }
  }


  //calculate median
  if(windows %2 == 1){
    medianidleidx = (windows)/2;
    medianidle = allidle[medianidleidx];
  }
  else{
    medianidleidx = windows/2;
    medianidle = double((allidle[medianidleidx] + allidle[medianidleidx - 1])/2);
  }
  //calculate mean
  meanidle = (double)totalidle/windows;
  for(int i = 0; i < numStud; ++i){
    //calc time all students have collectively waited
    totalwait += allwait[i];
    //calulate max
    if(allwait[i] > allwait[longwait]){
      longwait = i;
    }
    //check if waited for 10 seconds
    if(allwait[i] >= 10){
      tencount ++;
    }
  }
//calculate mean
  meanwait= (double)totalwait/numStud;
  //calculate median
  if(numStud %2 == 1){
    medianwaitidx = (numStud)/2;
    medianwait = allwait[medianwaitidx];
  }
  else{
    medianwaitidx = numStud/2;
    medianwait = double((allwait[medianwaitidx] + allwait[medianwaitidx - 1])/2);
  }
//output results
  cout << "Mean student wait time: " << meanwait << endl;
  cout << "Median student wait time: " << medianwait << endl;
  cout << "Longest student wait time: " << allwait[longwait] << endl;
  cout << "Number of students waiting 10+ minutes: " <<tencount << endl;
  cout << "Mean window idle time: " << meanidle << endl;
  cout << "Median idle window time: " << medianidle << endl;
  cout << "Longest time a window is idle: " << allidle[longidle] << endl;
  cout << "Windows idle for 5+ minutes: " << fivecount << endl;

}
