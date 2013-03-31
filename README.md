## A C lexical analyzer written in C ##

## Example ##

### Input ###

```
 char to_octa(char c) {
     if (c - '0' >= 0 && c - '0' <= 7) {
         return '$';
     }
     return c;
 }
 
 // comment
 
 /*
  multiline comment
  end *
  here again
 */
 
 return '~';
```


### Output ###

```
KEYWORD: char
IDENTIFIER: to_octa
OPERATOR: (
KEYWORD: char
IDENTIFIER: c
OPERATOR: )
OPERATOR: {
KEYWORD: if
OPERATOR: (
IDENTIFIER: c
OPERATOR: -
CHAR: '0'
OPERATOR: >=
VALUE: 0
OPERATOR: &&
IDENTIFIER: c
OPERATOR: -
CHAR: '0'
OPERATOR: <=
VALUE: 7
OPERATOR: )
OPERATOR: {
KEYWORD: return
CHAR: '$'
OPERATOR: ;
OPERATOR: }
KEYWORD: return
IDENTIFIER: c
OPERATOR: ;
OPERATOR: }
COMMENT: // comment
COMMENT: /*
 multiline comment
 end *
 here again
*/
KEYWORD: return
CHAR: '~'
OPERATOR: ;
```

