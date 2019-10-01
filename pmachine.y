%{
#include <string>
using namespace std;

#include "stackelement.h"
#include "stackmachine.h"
#include "pmachine.h"

#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "neg.h"
#include "and.h"
#include "or.h"
#include "not.h"
#include "equ.h"
#include "geq.h"
#include "leq.h"
#include "les.h"
#include "grt.h"
#include "neq.h"
#include "ldo.h"
#include "ldc.h"
#include "ind.h"
#include "sro.h"
#include "sto.h"
#include "ujp.h"
#include "fjp.h"
#include "ixj.h"
#include "ixa.h"
#include "inc.h"
#include "dec.h"
#include "chk.h"
#include "dpl.h"
#include "ldd.h"
#include "sli.h"
#include "new.h"
#include "lod.h"
#include "lda.h"
#include "str.h"
#include "mst.h"
#include "cup.h"
#include "ssp.h"
#include "sep.h"
#include "ent.h"
#include "retf.h"
#include "retp.h"
#include "movs.h"
#include "movd.h"
#include "smp.h"
#include "cupi.h"
#include "mstf.h"
#include "hlt.h"
#include "in.h"
#include "out.h"
#include "conv.h"

//#define YACCOUTPUT


extern StackMachine Pmachine;
extern int linecount;
extern int yylex();

// prototypes
void yyerror(string msg);


%}
%union {
	int integernumbervalue;
	double realnumbervalue;
	bool booleanvalue;
	string *textvalue;
	char charvalue;
	enum Stacktypes {r, i, b, c, a} type;
}

%token	add_instr
%token	sub_instr
%token	mul_instr
%token	div_instr
%token	neg_instr
%token	and_instr
%token	or_instr
%token	not_instr
%token	equ_instr
%token	geq_instr
%token	leq_instr
%token	les_instr
%token	grt_instr
%token	neq_instr
%token	ldo_instr
%token	ldc_instr
%token	ind_instr
%token	sro_instr
%token 	sto_instr
%token	ujp_instr
%token	fjp_instr
%token	ixj_instr
%token	ixa_instr
%token	inc_instr
%token	dec_instr
%token	chk_instr
%token	dpl_instr
%token	ldd_instr
%token	sli_instr
%token	new_instr
%token	lod_instr
%token	lda_instr
%token	str_instr
%token	mst_instr
%token	cup_instr
%token	ssp_instr
%token	sep_instr
%token	ent_instr
%token	retf_instr
%token	retp_instr
%token	movs_instr
%token	movd_instr
%token	smp_instr
%token	cupi_instr
%token	mstf_instr
%token	hlt_instr
%token	inp_instr
%token	out_instr
%token 	conv_instr

%token 	blank
%token	endline
%token	<integernumbervalue>	boolean_specifier
%token	<integernumbervalue>	real_specifier
%token	<integernumbervalue>	integer_specifier
%token	<integernumbervalue>	character_specifier
%token  <integernumbervalue>	address_specifier

%token	<booleanvalue>		boolvalue
%token	<integernumbervalue>	integervalue
%token	<charvalue>		charactervalue
%token  <realnumbervalue>	realvalue
%token	<integernumbervalue> 	addressvalue

%token	<textvalue>	appliedlabel
%token	<textvalue>	defininglabel

%type	<type>	numeric
%type	<type>	arbitrary
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

Grammar				: /* empty */
				| InstructionSequence
				;
EndlineRepeater			: EndlineRepeater endline
				| endline
				;
InstructionSequence		: InstructionSequence Instruction EndlineRepeater
				| Instruction EndlineRepeater
				| EndlineRepeater
				;
Instruction			: add_instruction
					{
						#ifdef YACCOUTPUT
							cout << "add_instruction completed" << endl;	
						#endif
					}
				| sub_instruction
					{
						#ifdef YACCOUTPUT
							cout << "sub_instruction completed" << endl;	
						#endif
					}
				| mul_instruction
					{
						#ifdef YACCOUTPUT
							cout << "mul_instruction completed" << endl;	
						#endif
					}
				| div_instruction
					{
						#ifdef YACCOUTPUT
							cout << "div_instruction completed" << endl;	
						#endif
					}
				| neg_instruction
					{
						#ifdef YACCOUTPUT
							cout << "neg_instruction completed" << endl;	
						#endif
					}
				| and_instruction
					{
						#ifdef YACCOUTPUT
							cout << "and_instruction completed" << endl;	
						#endif
					}
				| or_instruction
					{
						#ifdef YACCOUTPUT
							cout << "or_instruction completed" << endl;	
						#endif
					}
				| not_instruction
					{
						#ifdef YACCOUTPUT
							cout << "not_instruction completed" << endl;	
						#endif
					}
				| equ_instruction
					{
						#ifdef YACCOUTPUT
							cout << "equ_instruction completed" << endl;	
						#endif
					}
				| geq_instruction
					{
						#ifdef YACCOUTPUT
							cout << "geq_instruction completed" << endl;	
						#endif
					}
				| leq_instruction
					{
						#ifdef YACCOUTPUT
							cout << "leq_instruction completed" << endl;	
						#endif
					}
				| les_instruction
					{
						#ifdef YACCOUTPUT
							cout << "les_instruction completed" << endl;	
						#endif
					}
				| grt_instruction
					{
						#ifdef YACCOUTPUT
							cout << "grt_instruction completed" << endl;	
						#endif
					}
				| neq_instruction
					{
						#ifdef YACCOUTPUT
							cout << "neq_instruction completed" << endl;	
						#endif
					}
				| ldo_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ldo_instruction completed" << endl;	
						#endif
					}
				| ldc_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ldc_instruction completed" << endl;	
						#endif
					}
				| ind_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ind_instruction completed" << endl;	
						#endif
					}
				| sro_instruction
					{
						#ifdef YACCOUTPUT
							cout << "sro_instruction completed" << endl;	
						#endif
					}
				| sto_instruction
					{
						#ifdef YACCOUTPUT
							cout << "sto_instruction completed" << endl;	
						#endif
					}
				| ujp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ujp_instruction completed" << endl;	
						#endif
					}
				| fjp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "fjp_instruction completed" << endl;	
						#endif
					}
				| ixj_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ixj_instruction completed" << endl;	
						#endif
					}
				| ixa_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ixa_instruction completed" << endl;	
						#endif
					}
				| inc_instruction
					{
						#ifdef YACCOUTPUT
							cout << "inc_instruction completed" << endl;	
						#endif
					}
				| dec_instruction
					{
						#ifdef YACCOUTPUT
							cout << "dec_instruction completed" << endl;	
						#endif
					}
				| chk_instruction
					{
						#ifdef YACCOUTPUT
							cout << "chk_instruction completed" << endl;	
						#endif
					}
				| dpl_instruction
					{
						#ifdef YACCOUTPUT
							cout << "dpl_instruction completed" << endl;	
						#endif
					}
				| ldd_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ldd_instruction completed" << endl;	
						#endif
					}
				| sli_instruction
					{
						#ifdef YACCOUTPUT
							cout << "sli_instruction completed" << endl;	
						#endif
					}
				| new_instruction
					{
						#ifdef YACCOUTPUT
							cout << "new_instruction completed" << endl;	
						#endif
					}
				| lod_instruction
					{
						#ifdef YACCOUTPUT
							cout << "lod_instruction completed" << endl;	
						#endif
					}
				| lda_instruction
					{
						#ifdef YACCOUTPUT
							cout << "lda_instruction completed" << endl;	
						#endif
					}
				| str_instruction
					{
						#ifdef YACCOUTPUT
							cout << "str_instruction completed" << endl;	
						#endif
					}
				| mst_instruction
					{
						#ifdef YACCOUTPUT
							cout << "mst_instruction completed" << endl;	
						#endif
					}
				| cup_instruction
					{
						#ifdef YACCOUTPUT
							cout << "cup_instruction completed" << endl;	
						#endif
					}
				| ssp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ssp_instruction completed" << endl;	
						#endif
					}
				| sep_instruction
					{
						#ifdef YACCOUTPUT
							cout << "sep_instruction completed" << endl;	
						#endif
					}
				| ent_instruction
					{
						#ifdef YACCOUTPUT
							cout << "ent_instruction completed" << endl;	
						#endif
					}
				| retf_instruction
					{
						#ifdef YACCOUTPUT
							cout << "retf_instruction completed" << endl;	
						#endif
					}
				| retp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "retp_instruction completed" << endl;	
						#endif
					}
				| movs_instruction
					{
						#ifdef YACCOUTPUT
							cout << "movs_instruction completed" << endl;	
						#endif
					}
				| movd_instruction
					{
						#ifdef YACCOUTPUT
							cout << "movd_instruction completed" << endl;	
						#endif
					}
				| smp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "smp_instruction completed" << endl;	
						#endif
					}
				| cupi_instruction
					{
						#ifdef YACCOUTPUT
							cout << "cupi_instruction completed" << endl;	
						#endif
					}
				| mstf_instruction
					{
						#ifdef YACCOUTPUT
							cout << "mstf_instruction completed" << endl;	
						#endif
					}
				| hlt_instruction
					{
						#ifdef YACCOUTPUT
							cout << "hlt_instruction completed" << endl;	
						#endif
					}
				| inp_instruction
					{
						#ifdef YACCOUTPUT
							cout << "inp_instruction completed" << endl;	
						#endif
					}
				| out_instruction
					{
						#ifdef YACCOUTPUT
							cout << "out_instruction completed" << endl;	
						#endif
					}
				| conv_instruction
					{
						#ifdef YACCOUPUT
							cout << "conv_instruction completed" << endl;
						#endif
					}
				| label_introduction
										{
						#ifdef YACCOUTPUT
							cout << "label_introduction completed" << endl;	
						#endif
					}	
				;
numeric				: real_specifier
					{
						$$ = YYSTYPE::r;
					}
				| integer_specifier
					{
						$$ = YYSTYPE::i;
					}
				;
arbitrary				: numeric 
						| boolean_specifier
							{
								$$ = YYSTYPE::b;
							}
						| character_specifier
							{
								$$ = YYSTYPE::c;
							}
						| address_specifier
							{
								$$ = YYSTYPE::a;
							}
						;
space 	: blank space
	| blank
	;
add_instruction			: add_instr space numeric
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Add(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Add(real));
								break;
						}
					}
				| add_instr error
					{
						yyerror("instruction add: add [i|r]");
					}
				;
sub_instruction			: sub_instr space numeric
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Sub(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Sub(real));
								break;
						}
					}
				| sub_instr error
					{
						yyerror("instruction sub: sub [i|r]");
					}
				;
mul_instruction			: mul_instr space numeric
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Mul(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Mul(real));
								break;
						}
					}
				| mul_instr error
					{
						yyerror("instruction mul: mul [i|r]");
					}
				
				;
div_instruction			: div_instr space numeric
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Div(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Div(real));
								break;
						}
					}
				| div_instr error
					{
						yyerror("instruction div: div [i|r]");
					}
				;
neg_instruction			: neg_instr space numeric
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Neg(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Neg(real));
								break;
						}
					}
				| neg_instr error
					{
						yyerror("instruction neg: neg [i|r]");
					}
				;
and_instruction			: and_instr
					{
						Pmachine.addInstruction(new And());
					}					
				;
or_instruction			: or_instr
					{
						Pmachine.addInstruction(new Or());
					}	
				;
not_instruction			: not_instr
					{
						Pmachine.addInstruction(new Not());
					}	
				;
equ_instruction			: equ_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Equ(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Equ(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Equ(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Equ(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Equ(boolean));
								break;
						}
					}
				| equ_instr error
					{
						yyerror("instruction equ: equ [i|r|a|b|c]");
					}
				; 
geq_instruction			: geq_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Geq(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Geq(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Geq(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Geq(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Geq(boolean));
								break;
						}
					}
				| geq_instr error
					{
						yyerror("instruction geq: geq [i|r|a|b|c]");
					}
				;
leq_instruction			: leq_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Leq(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Leq(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Leq(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Leq(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Leq(boolean));
								break;
						}
					}
				| leq_instr error
					{
						yyerror("instruction leq: leq [i|r|a|b|c]");
					}
				;
les_instruction			: les_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Les(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Les(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Les(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Les(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Les(boolean));
								break;
						}
					}
				| les_instr error
					{
						yyerror("instruction les: les [i|r|a|b|c]");
					}
				;
grt_instruction			: grt_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Grt(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Grt(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Grt(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Grt(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Grt(boolean));
								break;
						}
					}
				| grt_instr error
					{
						yyerror("instruction grt: grt [i|r|a|b|c]");
					}
				;
neq_instruction			: neq_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Neq(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Neq(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Neq(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Neq(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Neq(boolean));
								break;
						}
					}
				| neq_instr error
					{
						yyerror("instruction neq: neq [i|r|a|b|c]");
					}
				;
ldo_instruction			: ldo_instr space arbitrary space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Ldo(integer, $5));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Ldo(real, $5));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Ldo(character, $5));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Ldo(address, $5));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Ldo(boolean, $5));
								break;
						}
					}
				| ldo_instr error
					{
						yyerror("instruction ldo: ldo [i|r|a|b|c]");
					}
				;
ldc_instruction			: ldc_instr space real_specifier space realvalue
					{
						Pmachine.addInstruction(new Ldc(real, new StackReal($5)));
					}
				| ldc_instr space integer_specifier space integervalue
					{
						Pmachine.addInstruction(new Ldc(integer, new StackInteger($5)));
					}
				| ldc_instr space boolean_specifier space boolvalue
					{
						Pmachine.addInstruction(new Ldc(boolean, new StackBoolean($5)));
					}
				| ldc_instr space character_specifier space integervalue
					{
						Pmachine.addInstruction(new Ldc(character, new StackCharacter(static_cast<char>($5))));
					}
				| ldc_instr space character_specifier space charactervalue
					{
						Pmachine.addInstruction(new Ldc(character, new StackCharacter(static_cast<char>($5))));
					}
				| ldc_instr space address_specifier space integervalue
					{
						Pmachine.addInstruction(new Ldc(address, new StackAddress($5)));
					}
				| ldc_instr error
					{
						yyerror("instruction ldc: ldc [i|r|a|b|c] [value]");
					}
				;
ind_instruction			: ind_instr space arbitrary
					{
						
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Ind(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Ind(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Ind(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Ind(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Ind(boolean));
								break;
						}
					}
				| ind_instr error
					{
						yyerror("instruction ind: ind [i|r|a|b|c]");
					}
				;
sro_instruction			: sro_instr space arbitrary space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Sro(integer, $5));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Sro(real, $5));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Sro(character, $5));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Sro(address, $5));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Sro(boolean, $5));
								break;
						}
					}
				| sro_instr error
					{
						yyerror("instruction sro: sro [i|r|a|b|c] [integer]");
					}
				;
sto_instruction			: sto_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Sto(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Sto(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Sto(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Sto(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Sto(boolean));
								break;
						}
					}
				| sto_instr error
					{
						yyerror("instruction sto: sto [i|r|a|b|c]");
					}
				;
ujp_instruction			: ujp_instr space appliedlabel
					{
						Pmachine.addInstruction(new Ujp(*$3));
					}
				| ujp_instr error
					{	
						yyerror("instruction ujp: ujp [label]");
					}
				;
fjp_instruction			: fjp_instr space appliedlabel
					{
						Pmachine.addInstruction(new Fjp(*$3));
					}
				| fjp_instr error
					{
						yyerror("instruction fjp: fjp [label]");
					}
				;
ixj_instruction			: ixj_instr space appliedlabel
					{
						Pmachine.addInstruction(new Ixj(*$3));
					}
				| ixj_instr error
					{
						yyerror("instruction ixj: ixj [label]");
					}
				;
ixa_instruction			: ixa_instr space integervalue
					{
						Pmachine.addInstruction(new Ixa($3));
					}
				| ixa_instr error
					{
						yyerror("instruction ixa: ixa [integer]");
					}
				;
inc_instruction			: inc_instr space arbitrary space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Inc(integer, $5));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Inc(real, $5));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Inc(character, $5));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Inc(address, $5));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Inc(boolean, $5));
								break;
						}
					}
				| inc_instr error
					{
						yyerror("instruction inc: inc [i|r|a|b|c] [integervalue]");
					}
				;
dec_instruction			: dec_instr space arbitrary space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Dec(integer, $5));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Dec(real, $5));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Dec(character, $5));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Dec(address, $5));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Dec(boolean, $5));
								break;
						}
					}
				| dec_instr error
					{
						yyerror("instruction dec: dec [i|r|a|b|c] [integervalue]");
					}
				;
chk_instruction			: chk_instr space integervalue space integervalue
					{
						Pmachine.addInstruction(new Chk($3, $5));
					}
				| chk_instr error
					{
						yyerror("instruction chk: chk [integervalue] [integervalue]");
					}
				;
dpl_instruction			: dpl_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Dpl(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Dpl(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Dpl(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Dpl(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Dpl(boolean));
								break;
						}
					}
				| dpl_instr error
					{
						yyerror("instruction dpl: dpl [i|r|a|b|c]");
					}
				;
ldd_instruction			: ldd_instr space integervalue
					{
						Pmachine.addInstruction(new Ldd($3));
					}
				| ldd_instr error
					{
						yyerror("instruction ldd: ldd [integervalue]");
					}
				;
sli_instruction			: sli_instr space arbitrary
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Sli(integer));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Sli(real));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Sli(character));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Sli(address));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Sli(boolean));
								break;
						}
					}
				| sli_instr error
					{
						yyerror("instruction sli: sli [i|r|a|b|c]");
					}
				;
new_instruction			: new_instr
					{
						Pmachine.addInstruction(new New());
					}
				;
lod_instruction			: lod_instr space arbitrary space integervalue space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Lod(integer, $5, $7));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Lod(real, $5, $7));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Lod(character, $5, $7));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Lod(address, $5, $7));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Lod(boolean, $5, $7));
								break;
						}
					}
				| lod_instr error
					{
						yyerror("instruction lod: lod [i|r|a|b|c] [integervalue] [integervalue]");
					}
				
				;
lda_instruction			: lda_instr space integervalue space integervalue
					{
						Pmachine.addInstruction(new Lda($3, $5));
					}
				| lda_instr error
					{
						yyerror("instruction lda: lda [integervalue] [integervalue]");
					}
				;
str_instruction			: str_instr space arbitrary space integervalue space integervalue
					{
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Str(integer, $5, $7));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Str(real, $5, $7));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Str(character, $5, $7));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Str(address, $5, $7));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Str(boolean, $5, $7));
								break;
						}
					}
				| str_instr error
					{
						yyerror("instruction str: str [i|r|a|b|c] [intergervalue] [integervalue]");
					}
				;
mst_instruction			: mst_instr space integervalue
					{
						Pmachine.addInstruction(new Mst($3));
					}
				| mst_instr error
					{
						yyerror("instruction mst: mst [integer]");
					}
				;
cup_instruction			: cup_instr space integervalue space appliedlabel
					{
						Pmachine.addInstruction(new Cup($3, *$5));
					}
				| cup_instr error
					{
						yyerror("instruction cup: cup [integervalue] [integervalue]");
					}
				;
ssp_instruction			: ssp_instr space integervalue
					{
						Pmachine.addInstruction(new Ssp($3));
					}
				| ssp_instr error
					{
						yyerror("instruction ssp: ssp [integervalue]");
					}
				;
sep_instruction			: sep_instr space integervalue
					{
						Pmachine.addInstruction(new Sep($3));
					}
				| sep_instr error
					{
						yyerror("instruction sep: sep [integervalue]");
					}
				;
ent_instruction			: ent_instr space integervalue space integervalue
					{
						Pmachine.addInstruction(new Ent($3, $5));
					}
				| ent_instr error
					{
						yyerror("instruction ent: ent [integervalue] [integervalue]");
					}
				;
retf_instruction		: retf_instr
					{
						Pmachine.addInstruction(new Retf());
					}
				;
retp_instruction		: retp_instr
					{
						Pmachine.addInstruction(new Retp());
					}
				;
movs_instruction		: movs_instr space integervalue
					{
						Pmachine.addInstruction(new Movs($3));
					}
				| movs_instr error
					{
						yyerror("instruction movs: movs [integervalue]");
					}
				;
movd_instruction		: movd_instr space integervalue
					{
						Pmachine.addInstruction(new Movd($3));
					}
				| movd_instr error
					{
						yyerror("instruction movd: movd [integervalue]");
					}
				;
smp_instruction			: smp_instr space integervalue
					{
						Pmachine.addInstruction(new Smp($3));
					}
				| smp_instr error
					{
						yyerror("instruction smp: smp [integervalue]");
					}
				;
cupi_instruction		: cupi_instr space integervalue space integervalue
					{
						Pmachine.addInstruction(new Cupi($3, $5));
					}
				| cupi_instr error
					{
						yyerror("instruction cupi: cupi [integervalue] [integervalue]");
					}
				;
mstf_instruction		: mstf_instr space integervalue space integervalue
					{
						Pmachine.addInstruction(new Mstf($3, $5));
					}
				| mstf_instr error
					{
						yyerror("instruction mstf: mstf [integervalue] [integervalue]");
					}
				;
hlt_instruction			: hlt_instr
					{
						Pmachine.addInstruction(new Hlt());
					}
				;
inp_instruction			: inp_instr space integer_specifier
					{
						Pmachine.addInstruction(new In(integer));
					}
				| inp_instr space real_specifier
					{
						Pmachine.addInstruction(new In(real));
					}
				| inp_instr space boolean_specifier
					{
						Pmachine.addInstruction(new In(boolean));
					}				
				| inp_instr space character_specifier					
					{
						Pmachine.addInstruction(new In(character));
					}
				| inp_instr space address_specifier
					{
						yyerror("instruction in: input of address at runtime is forbidden");
					}
				| inp_instr error
					{
						yyerror("instruction in: in [i|r|b|c]");
					}
				;
out_instruction			: out_instr space real_specifier space integer_specifier
					{
						Pmachine.addInstruction(new Out(real, true));
					}
				| out_instr space real_specifier
					{
						Pmachine.addInstruction(new Out(real, false));
					}
				| out_instr space integer_specifier
					{
						Pmachine.addInstruction(new Out(integer));
					}
				| out_instr space character_specifier
					{
						Pmachine.addInstruction(new Out(character));				
					}
				| out_instr space address_specifier
					{
						Pmachine.addInstruction(new Out(address));
					}
				| out_instr space boolean_specifier
					{
						Pmachine.addInstruction(new Out(boolean));
					}
				| out_instr error
					{
						yyerror("instruction out: out r i\ninstruction out: out [r|i|a|b|c]");
					}
				;
conv_instruction:	conv_instr space arbitrary space arbitrary
					{
						StackElementType type;
						switch($5)
						{
							case YYSTYPE::i:
								type = integer;
								break;
							case YYSTYPE::r:
								type = real;
								break;
							case YYSTYPE::c:
								type = character;
								break;
							case YYSTYPE::a:
								type = address;
								break;
							case YYSTYPE::b:
								type = boolean;
								break;
						}
												
						switch($3)
						{
							case YYSTYPE::i:
								Pmachine.addInstruction(new Conv(integer, type));
								break;
							case YYSTYPE::r:
								Pmachine.addInstruction(new Conv(real, type));
								break;
							case YYSTYPE::c:
								Pmachine.addInstruction(new Conv(character, type));
								break;
							case YYSTYPE::a:
								Pmachine.addInstruction(new Conv(address, type));
								break;
							case YYSTYPE::b:
								Pmachine.addInstruction(new Conv(boolean, type));
								break;
						}
					}
					| conv_instr error
						{
							yyerror("instruction conv: conv [r|i|a|b|c] [r|i|a|b|c]");
						};
label_introduction		: defininglabel
					{
						Pmachine.addLabel(*$1);
					}
					;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void yyerror(string msg)
{
	cerr << "--> line " << linecount << ": " << msg << endl;
	exit(0);
}

