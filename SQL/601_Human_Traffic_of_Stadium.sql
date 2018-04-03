# Write your MySQL query statement below

select distinct S1.* 
from stadium S1, stadium S2, stadium S3 
where ( S1.people >= 100 and S2.people >= 100 and S3.people >= 100 ) 
    and (  ( S1.id = S2.id - 1 and S1.id = S3.id - 2 ) 
        or ( S1.id = S2.id + 1 and S1.id = S3.id - 1 ) 
        or ( S1.id = S2.id + 2 and S1.id = S3.id + 1 ) )
order by S1.id ; 