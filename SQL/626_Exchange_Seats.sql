# Write your MySQL query statement below

select ( case 
          when id % 2 = 1 and id != (select max(id) from seat) then id + 1
          when id % 2 = 1 and id = (select max(id) from seat) then id 
         else 
            id - 1 
         end ) as id, student
from seat 
order by id ;  

/*
分为两种情况，id如果为奇数，如果最大的id是奇数，就不改，如果最大的id不是奇数，就改为id+1
            id如果是偶数，就改为id-1 
然后按照id 排序。 
*/