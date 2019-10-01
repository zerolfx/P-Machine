%{
#include <string>
#include <iostream>
#include <strstream>
#include <stdlib.h>

using namespace std;

#include "pmachine.tab.h"
extern int linecount;

// for debugging
	//#define LEXOUTPUT
// end debugging

%}

%%
add		{
			#ifdef LEXOUTPUT
				cout << "add found" << endl;
			#endif
			
			return add_instr;
		}
sub		{
			#ifdef LEXOUTPUT
				cout << "sub found" << endl;
			#endif
			
			return sub_instr;
		}
mul		{
			#ifdef LEXOUTPUT
				cout << "mul found" << endl;
			#endif
			
			return mul_instr;
		}
div		{
			#ifdef LEXOUTPUT
				cout << "div found" << endl;
			#endif
			
			return div_instr;
		}
neg		{
			#ifdef LEXOUTPUT
				cout << "neg found" << endl;
			#endif
			
			return neg_instr;
		}
and		{
			#ifdef LEXOUTPUT
				cout << "and found" << endl;
			#endif
			
			return and_instr;
		}
or		{
			#ifdef LEXOUTPUT
				cout << "or found" << endl;
			#endif
			
			return or_instr;
		}
not		{
			#ifdef LEXOUTPUT
				cout << "not found" << endl;
			#endif
			
			return not_instr;
		}
equ		{
			#ifdef LEXOUTPUT
				cout << "equ found" << endl;
			#endif
			
			return equ_instr;
		}
geq		{
			#ifdef LEXOUTPUT
				cout << "geq found" << endl;
			#endif
			
			return geq_instr;
		}
leq		{
			#ifdef LEXOUTPUT
				cout << "leq found" << endl;
			#endif
			
			return leq_instr;
		}
les		{
			#ifdef LEXOUTPUT
				cout << "les found" << endl;
			#endif
			
			return les_instr;
		}
grt		{
			#ifdef LEXOUTPUT
				cout << "grt found" << endl;
			#endif
			
			return grt_instr;
		}
neq		{
			#ifdef LEXOUTPUT
				cout << "neq found" << endl;
			#endif
			
			return neq_instr;
		}
ldo		{
			#ifdef LEXOUTPUT
				cout << "ldo found" << endl;
			#endif
			
			return ldo_instr;
		}
ldc		{
			#ifdef LEXOUTPUT
				cout << "ldc found" << endl;
			#endif
			
			return ldc_instr;
		}
ind		{
			#ifdef LEXOUTPUT
				cout << "ind found" << endl;
			#endif
			
			return ind_instr;
		}
sro		{
			#ifdef LEXOUTPUT
				cout << "sro found" << endl;
			#endif
			
			return sro_instr;
		}
sto		{
			#ifdef LEXOUTPUT
				cout << "sto found" << endl;
			#endif
			
			return sto_instr;
		}
ujp		{
			#ifdef LEXOUTPUT
				cout << "ujp found" << endl;
			#endif
			
			return ujp_instr;			
		}
fjp		{
			#ifdef LEXOUTPUT
				cout << "fjp found" << endl;
			#endif
			
			return fjp_instr;			
		}
ixj		{
			#ifdef LEXOUTPUT
				cout << "ixj found" << endl;
			#endif
			
			return ixj_instr;			
		}
ixa		{
			#ifdef LEXOUTPUT
				cout << "ixa found" << endl;
			#endif
			
			return ixa_instr;
		}
inc		{
			#ifdef LEXOUTPUT
				cout << "inc found" << endl;
			#endif
			
			return inc_instr;
		}
dec		{
			#ifdef LEXOUTPUT
				cout << "dec found" << endl;
			#endif
			
			return dec_instr;
		}
chk		{
			#ifdef LEXOUTPUT
				cout << "chk found" << endl;
			#endif
			
			return chk_instr;
		}
dpl		{
			#ifdef LEXOUTPUT
				cout << "dpl found" << endl;
			#endif
			
			return dpl_instr;
}
ldd		{
			#ifdef LEXOUTPUT
				cout << "ldd found" << endl;
			#endif
			
			return ldd_instr;
		}
sli		{
			#ifdef LEXOUTPUT
				cout << "sli found" << endl;
			#endif
			
			return sli_instr;
		}
new		{
			#ifdef LEXOUTPUT
				cout << "new found" << endl;
			#endif
			
			return new_instr;
		}
lod		{
			#ifdef LEXOUTPUT
				cout << "lod found" << endl;
			#endif
			
			return lod_instr;
		}
lda		{
			#ifdef LEXOUTPUT
				cout << "lda found" << endl;
			#endif
			
			return lda_instr;
		}
str		{
			#ifdef LEXOUTPUT
				cout << "str found" << endl;
			#endif
			
			return str_instr;
		}
mst		{
			#ifdef LEXOUTPUT
				cout << "mst found" << endl;
			#endif
			
			return mst_instr;
		}
cup		{
			#ifdef LEXOUTPUT
				cout << "cup found" << endl;
			#endif
			
			return cup_instr;
		}
ssp		{	
			#ifdef LEXOUTPUT
				cout << "ssp found" << endl;
			#endif
			
			return ssp_instr;
		}
sep		{
			#ifdef LEXOUTPUT
				cout << "sep found" << endl;
			#endif
			
			return sep_instr;
		}
ent		{
			#ifdef LEXOUTPUT
				cout << "ent found" << endl;
			#endif
			
			return ent_instr;
		}
retf		{
			#ifdef LEXOUTPUT
				cout << "retf found" << endl;
			#endif
			
			return retf_instr;
		}
retp		{
			#ifdef LEXOUTPUT
				cout << "retp found" << endl;
			#endif
			
			return retp_instr;
		}
movs		{
			#ifdef LEXOUTPUT
				cout << "movs found" << endl;
			#endif
			
			return movs_instr;			
		}
movd		{
			#ifdef LEXOUTPUT
				cout << "movd found" << endl;
			#endif
			
			return movd_instr;
		}
smp		{
			#ifdef LEXOUTPUT
				cout << "smp found" << endl;
			#endif
			
			return smp_instr;
		}
cupi		{
			#ifdef LEXOUTPUT
				cout << "cupi found" << endl;
			#endif
			
			return cupi_instr;
		}
mstf		{
			#ifdef LEXOUTPUT
				cout << "mstf found" << endl;
			#endif
			
			return mstf_instr;
		}
hlt		{
			#ifdef LEXOUTPUT
				cout << "hlt found" << endl;
			#endif
			
			return hlt_instr;
		}
in		{
			#ifdef LEXOUTPUT
				cout << "inp found" << endl;
			#endif
			
			return inp_instr;
		}
out		{
			#ifdef LEXOUTPUT
				cout << "out found" << endl;
			#endif
			
			return out_instr;
		}
conv	{
			#ifdef LEXOUTPUT
				cout << "conv found" << endl;
			#endif
			
			return conv_instr;
		}
a		{
			#ifdef LEXOUTPUT
				cout << "address_specifier found" << endl;
			#endif
			
			return address_specifier;
		}
c		{
			#ifdef LEXOUTPUT
				cout << "character_specifier found" << endl;
			#endif
			
			return character_specifier;
		}
i		{
			#ifdef LEXOUTPUT
				cout << "integer_specifier found" << endl;
			#endif
			
			return integer_specifier;
		}
r		{
			#ifdef LEXOUTPUT
				cout << "real_specifier found" << endl;
			#endif
			
			return real_specifier;
		}
b		{
			#ifdef LEXOUTPUT
				cout << "boolean_specifier found" << endl;
			#endif
			
			return boolean_specifier;
		}
t		{
			#ifdef LEXOUTPUT
				cout << "true found" << endl;	
			#endif

			yylval.booleanvalue = true;
			return boolvalue;
		}
f		{
			#ifdef LEXOUTPUT
				cout << "false found" << endl;	
			#endif

			yylval.booleanvalue = false;
			return boolvalue;
		}

'.' 		{
			#ifdef LEXOUTPUT
				cout << "single character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = static_cast<char>(string(yytext)[1]);
			return charactervalue;
		}
"'\\n'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\n';
			return charactervalue;
		}
"'\\t'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\t';
			return charactervalue;
		}
"'\\v'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\v';
			return charactervalue;
		}
"'\\b'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\b';
			return charactervalue;
		}
"'\\r'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\r';
			return charactervalue;
		}
"'\\a'"		{
			#ifdef LEXOUTPUT
				cout << "double character found: " << yytext << endl;
			#endif
			
			yylval.charvalue = '\a';
			return charactervalue;
		}
[0-9]+		|
"+"[0-9]+	|
"-"[0-9]+	{
			#ifdef LEXOUTPUT
				cout << "number " << yytext << " found" << endl;
			#endif

			strstream convertor;
			int getal;
			convertor << yytext;
			convertor >> getal;

			yylval.integernumbervalue = getal;
			return integervalue;
		}
[0-9]+\.[0-9]+		|
"+"[0-9]+\.[0-9]+	|
"-"[0-9]+\.[0-9]+		{
				#ifdef LEXOUTPUT
					cout << "number " << yytext << " found" << endl;
				#endif

				
				double getal = atof(string(yytext).c_str());
				yylval.realnumbervalue = getal;
				return realvalue;
			}
[a-zA-Z][0-9a-zA-Z_]*	{
				#ifdef LEXOUTPUT
					cout << "applied label found" << endl;	
				#endif

				yylval.textvalue = new string(yytext);
				return appliedlabel;
			}
[a-zA-Z][0-9a-zA-Z_]*:	{
				#ifdef LEXOUTPUT
					cout << "defining label found" << endl;	
				#endif

				string temp(yytext);
				temp = temp.substr(0, temp.length() - 1);

				yylval.textvalue = new string(temp);
				return defininglabel;
			}
\n			{
				#ifdef LEXOUTPUT
					cout << "newline found" << endl;	
				#endif
				
				++linecount;
				
				return endline;
			}
([ \t])*;(.)*\n		{
				#ifdef LEXOUTPUT
					cout << "comment found + applied newline" << endl;	
				#endif

				++linecount;
				
				return endline;
			}
[ \t]			{
				#ifdef LEXOUTPUT
					cout << "space found" << endl;
				#endif
				
				return blank;
			}
							
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

