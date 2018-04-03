# Write your MySQL query statement below

select name, population, area 
from World 
having population > 25000000 or area > 3000000 ;  


/*
之前看错题目了，用name把表分组了，然后分组使用聚合函数sum，居然有个样例是错的。。
如果每个name是不一样的，那应该分组也行啊。。。
*/