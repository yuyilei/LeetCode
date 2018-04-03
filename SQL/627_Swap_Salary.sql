# Write your MySQL query statement below

update salary 
set sex = if ( sex='m','f','m') ;  

/*
学了 if 的用法 
IF( expr1 , expr2 , expr3 )
expr1 的值为 TRUE，则返回值为 expr2 
expr2 的值为FALSE，则返回值为 expr3
*/


# 有个很厉害的方法...
update salary 
set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex)) ;  

/*
 a^b^a = b .... 
*/