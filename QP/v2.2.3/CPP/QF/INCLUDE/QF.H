/////////////////////////////////////////////////////////////////////
// Quantum Framework OS-independent declarations (C++ version)
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#ifndef qf_h
#define qf_h

         // densly packet 32-bit "list" of subscriber active objects,
         // allocating 4-bits per active object-id allows to store 
         // up to 8 subscribers in this "list" 
typedef unsigned long QSubscrList;

class QF {
public:
   static void init(QSubscrList subscr[], unsigned maxSignal);
   static void cleanup();
   static void poolInit(QEvent *poolSto, 
                        unsigned nEvts, unsigned evtSize);
   static void tick();
   static const char *getVersion(); 
   static QEvent *create(unsigned evtSize, QSignal sig);
   #define Q_NEW(evtT_, sig_) \
          ((evtT_ *)QF::create(sizeof(evtT_), (sig_)))
   static void subscribe(QActive *a, QSignal sig);
   static void unsubscribe(QActive *a, QSignal sig);
   static void publish(QEvent *e);                   // publish event

   static void background(); //for foreground/background systems only

private:                       // internal interface for QActive only
   static void osInit();
   static void osCleanup();
   static void add(QActive *a);
   static void remove(QActive *a);
   static void propagate(QEvent *e);  // propagate to next subsrciber
   static void annihilate(QEvent *e);
   friend class QActive;
};

#endif                                                        // qf_h
