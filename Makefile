# Makefile P-machine
# 	Author:	Andy Zaidman
#	Date:	28/01/2001
CXX     = g++ -Wno-deprecated
LEX   	= flex
YACC	= bison
YFLAGS  = -b pmachine -d -v


all: pmachine

clean:	
	rm -f *.o
	rm -f core
	rm -f pmachine.tab.c
	rm -f pmachine.yy.c
	rm -f pmachine.tab.output
	rm -f pmachine.tab.h

instructions=instruction.o add.o and.o chk.o cup.o cupi.o dec.o div.o dpl.o ent.o equ.o fjp.o geq.o grt.o hlt.o inc.o ind.o ixa.o ixj.o lda.o ldc.o ldo.o leq.o les.o lod.o movd.o movs.o mst.o mstf.o mul.o neg.o neq.o new.o not.o or.o retf.o retp.o sep.o sli.o smp.o sro.o ssp.o sto.o str.o sub.o ujp.o in.o out.o ldd.o conv.o
stackelements=stackaddress.o stackelement.o stackinteger.o stackreal.o stackboolean.o stackcharacter.o
exceptions=executionerror.o compiletimeerror.o

INCinstruction=instruction.h stackmachine.h executionerror.h stackelement.h

pmachine.tab.c pmachine.tab.h: pmachine.y
	$(YACC) -b pmachine -d -v pmachine.y

pmachine.tab.o: pmachine.tab.c stackelement.h stackmachine.h pmachine.h
	$(CXX) -c pmachine.tab.c

pmachine.yy.c: pmachine.l
	$(LEX) -opmachine.yy.c pmachine.l

pmachine.yy.o: pmachine.yy.c pmachine.tab.h
	$(CXX) -c pmachine.yy.c
	
executionerror.o: executionerror.cpp executionerror.h
	$(CXX) -c executionerror.cpp
	
compiletimeerror.o: compiletimeerror.cpp compiletimeerror.h
	$(CXX) -c compiletimeerror.cpp
	
instruction.o: instruction.cpp instruction.h timecounter.h
	$(CXX) -c instruction.cpp
	
labelcenter.o: labelcenter.cpp labelcenter.h executionerror.h compiletimeerror.h
	$(CXX) -c labelcenter.cpp

timecounter.o: timecounter.cpp timecounter.h
	$(CXX) -c timecounter.cpp
	
stackaddress.o: stackaddress.cpp stackaddress.h stackelement.h
	$(CXX) -c stackaddress.cpp

stackboolean.o: stackboolean.cpp stackboolean.h stackelement.h
	$(CXX) -c stackboolean.cpp
	
stackelement.o: stackelement.cpp stackelement.h stackelement.h
	$(CXX) -c stackelement.cpp
	
stackinteger.o: stackinteger.cpp stackinteger.h stackelement.h
	$(CXX) -c stackinteger.cpp

stackcharacter.o: stackcharacter.cpp stackcharacter.h stackelement.h
	$(CXX) -c stackcharacter.cpp
	
stackmachine.o: stackmachine.cpp stackmachine.h labelcenter.h stackinteger.h stackelement.h instruction.h labelcenter.h timecounter.h
	$(CXX) -c stackmachine.cpp
	
stackreal.o: stackreal.cpp stackreal.h stackelement.h
	$(CXX) -c stackreal.cpp
	
add.o: add.cpp add.h $(INCinstruction)
	$(CXX) -c add.cpp

and.o: and.cpp and.h $(INCinstruction)
	$(CXX) -c and.cpp

chk.o: chk.cpp chk.h $(INCinstruction)
	$(CXX) -c chk.cpp

cup.o: cup.cpp cup.h labelcenter.h $(INCinstruction)
	$(CXX) -c cup.cpp

cupi.o: cupi.cpp cupi.h $(INCinstruction)
	$(CXX) -c cupi.cpp
	
dec.o: dec.cpp dec.h $(INCinstruction)
	$(CXX) -c dec.cpp

div.o: div.cpp div.h $(INCinstruction)
	$(CXX) -c div.cpp

dpl.o: dpl.cpp dpl.h $(INCinstruction)
	$(CXX) -c dpl.cpp

ent.o: ent.cpp ent.h $(INCinstruction)
	$(CXX) -c ent.cpp

equ.o: equ.cpp equ.h $(INCinstruction)
	$(CXX) -c equ.cpp
	
ldd.o: ldd.cpp ldd.h $(INCinstruction)
	$(CXX) -c ldd.cpp

fjp.o: fjp.cpp fjp.h labelcenter.h $(INCinstruction)
	$(CXX) -c fjp.cpp

geq.o: geq.cpp geq.h $(INCinstruction)
	$(CXX) -c geq.cpp

grt.o: grt.cpp grt.h $(INCinstruction)
	$(CXX) -c grt.cpp

hlt.o: hlt.cpp hlt.h $(INCinstruction)
	$(CXX) -c hlt.cpp

inc.o: inc.cpp inc.h $(INCinstruction)
	$(CXX) -c inc.cpp

ind.o: ind.cpp ind.h $(INCinstruction)
	$(CXX) -c ind.cpp

ixa.o: ixa.cpp ixa.h $(INCinstruction)
	$(CXX) -c ixa.cpp

ixj.o: ixj.cpp ixj.h labelcenter.h $(INCinstruction)
	$(CXX) -c ixj.cpp

lda.o: lda.cpp lda.h $(INCinstruction)
	$(CXX) -c lda.cpp

ldc.o: ldc.cpp ldc.h $(INCinstruction)
	$(CXX) -c ldc.cpp

ldo.o: ldo.cpp ldo.h $(INCinstruction)
	$(CXX) -c ldo.cpp

leq.o: leq.cpp leq.h $(INCinstruction)
	$(CXX) -c leq.cpp

les.o: les.cpp les.h $(INCinstruction)
	$(CXX) -c les.cpp

lod.o: lod.cpp lod.h $(INCinstruction)
	$(CXX) -c lod.cpp

movd.o: movd.cpp movd.h $(INCinstruction)
	$(CXX) -c movd.cpp

movs.o: movs.cpp movs.h $(INCinstruction)
	$(CXX) -c movs.cpp

mst.o: mst.cpp mst.h $(INCinstruction)
	$(CXX) -c mst.cpp

mstf.o: mstf.cpp mstf.h $(INCinstruction)
	$(CXX) -c mstf.cpp

mul.o: mul.cpp mul.h $(INCinstruction)
	$(CXX) -c mul.cpp 

neg.o: neg.cpp neg.h $(INCinstruction)
	$(CXX) -c neg.cpp

neq.o: neq.cpp neq.h $(INCinstruction)
	$(CXX) -c neq.cpp

new.o: new.cpp new.h placeholder.h $(INCinstruction)
	$(CXX) -c new.cpp

not.o: not.cpp not.h $(INCinstruction)
	$(CXX) -c not.cpp

or.o: or.cpp or.h $(INCinstruction)
	$(CXX) -c or.cpp

retf.o: retf.cpp retf.h $(INCinstruction)
	$(CXX) -c retf.cpp

retp.o: retp.cpp retp.h $(INCinstruction)
	$(CXX) -c retp.cpp

sep.o: sep.cpp sep.h $(INCinstruction)
	$(CXX) -c sep.cpp

sli.o: sli.cpp sli.h $(INCinstruction)
	$(CXX) -c sli.cpp

smp.o: smp.cpp smp.h $(INCinstruction)
	$(CXX) -c smp.cpp

sro.o: sro.cpp sro.h $(INCinstruction)
	$(CXX) -c sro.cpp

ssp.o: ssp.cpp ssp.h $(INCinstruction)
	$(CXX) -c ssp.cpp

sto.o: sto.cpp sto.h $(INCinstruction)
	$(CXX) -c sto.cpp

str.o: str.cpp str.h $(INCinstruction)
	$(CXX) -c str.cpp

sub.o: sub.cpp sub.h $(INCinstruction)
	$(CXX) -c sub.cpp

ujp.o: ujp.cpp ujp.h labelcenter.h $(INCinstruction)
	$(CXX) -c ujp.cpp
	
in.o: in.cpp in.h $(INCinstruction)
	$(CXX) -c in.cpp
	
out.o: out.cpp out.h $(INCinstruction)
	$(CXX) -c out.cpp

conv.o: conv.cpp conv.h $(INCinstruction)
	$(CXX) -c conv.cpp

main.o: main.cpp $(INCinstruction) pmachine.h
	$(CXX) -c main.cpp

pmachine: pmachine.yy.o pmachine.tab.o $(instructions) $(stackelements) $(exceptions) labelcenter.o timecounter.o stackmachine.o main.o pmachine.tab.o pmachine.yy.c
	$(CXX) -o Pmachine $(instructions) $(stackelements) $(exceptions) labelcenter.o timecounter.o stackmachine.o main.o pmachine.yy.o pmachine.tab.o -lfl


