	

%{

	/*****************************************************
	* This is a lex file made into a simple program called
	* ZoomJoyStrong
	*
	* @author Atone Joryman
	* @version Fall 2018 
	*****************************************************/
	#include <stdio.h>
%}


%%

(end)          { printf("END %s\n", yytext); /** exit interpreter**/ } 
(;)            { printf("END_STATEMENT %s\n", yytext); /** All commands should end with a semicolon**/ }
(point)        { printf("POINT %s\n", yytext); /** When we match the command to plot a point.**/ 
		printf("*\n"); }
(line)         { printf("LINE %s\n", yytext); /** When we match the command to draw a line**/ 
		printf("_________________\n"); }
(circle)       { printf("CIRCLE %s\n", yytext); /** When we match the command to draw a circle**/
   	printf(" ---\n");
	printf("|   |\n|   |\n|   |\n|   |\n|   |\n");
	printf(" ---\n");
	 }
(rectangle)    { printf("RECTANGLE %s\n", yytext); /** When we match the command to draw a rectangle.**/ 
   	printf(" ------------\n");
	printf("|           |\n|           |\n");
	printf(" ------------\n");}
(setTheColor)     { printf("SET_COLOR %s\n", yytext); /** Matches the command to change colors.**/ }
[0-9]+         { printf("INT %s\n", yytext);/** Matches an integer value.**/  }
[0-9]+\.[0-9]+ { printf("FLOAT %s\n", yytext); /** Matches a floating-point value**/ }
[ \t\n]     { ; /** A way to match tabs, spaces, or newlines, and to ignore them**/ }
.*             { printf("YOU MESSED UP %s ON LINE %d\n", yytext, yylineno); /** A way to match anything not listed above, and to tell the user they messed up, and on which line.**/ }



%%

int main(int argc, char** argv){
  yylex();
  return 0;

}
