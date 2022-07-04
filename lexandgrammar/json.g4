grammar json ;

json : object
      | array
      ;

object : '{' pair (',' pair)* '}' ;
pair : string ':' value ;
array : '[' value (',' value)*']' ;
value : object
       |
       ;
string : '"' () '"';