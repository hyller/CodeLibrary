/////////////////////////////////////////////////////////////////////
// Pointer-to-Member funciton test
// Copyright (c) 2002 Miro Samek, Palo Alto, CA. 
// All Rights Reserved.
/////////////////////////////////////////////////////////////////////
#include <stdio.h>

class Foo {
public:
   typedef void (Foo::*Handler)();
   virtual ~Foo() {};
   Handler f();
   virtual void g();
};

class Bar : public Foo {
public:
   virtual void g();
};

Foo::Handler Foo::f() { return &Foo::g; }
void Foo::g() { printf("Foo::g()\n"); }
void Bar::g() { printf("Bar::g()\n"); }

Foo foo;
Bar bar;
Foo::Handler h = foo.f();

void main() {
   (foo.*h)();
   (bar.*h)();
}
