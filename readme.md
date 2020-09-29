This PMachine is for course project of Compilation Principles.

Based on [http://fots.ua.ac.be/~pvgorp/professional/teaching/compiler1LIC/pMachine/](http://fots.ua.ac.be/~pvgorp/professional/teaching/compiler1LIC/pMachine/), ~~and you can find all instruction specifications here~~. We have a backup [here](Pmachine_specs.pdf).

Modifications:

+ fix compatibility problems
+ add instruction: pop (SP:=SP-1)
+ add instruction: mod (STORE[SP-1]:=STORE[SP-1]%STORE[SP], SP:=SP-1)
