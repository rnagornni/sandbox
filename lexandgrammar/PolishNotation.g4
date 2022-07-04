grammar PolishNotation;

stat: expr NEWLINE
    ;

expr: ('*'|'/') expr
    | ('+'|'-') expr
    | '(' expr ')'
    | expr
    | INT
    ;

INT : [0-9]+ ;
NEWLINE : '\r'? '\n' ;
WS : [ \t]+ -> skip ;
