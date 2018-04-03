
#  使用联结表的方法，效率应该不高 
delete P1
from Person as P1, Person as P2 
where P1.Email = P2.Email 
      and P1.Id > P2.Id ;  

# 找出每个email的最小ID，然后删除，这个效率应该比之前那个高 
delete from Person 
where Id not in ( 
    select P.Id from ( 
        select min(Id) as Id from Person group by Email 
    ) P 
) ; 

# 注意那个 select min(Id) 要加 Id ，否则，P找不到Id 
 