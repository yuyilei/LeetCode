# Write your MySQL query statement below
select S1.Score as Score, (
    select count(*) 
    from ( 
          select distinct S2.Score 
          from Scores S2 
         ) TEMP
    where S1.Score <= TEMP.Score
    ) as Rank
from Scores S1
order by Score desc


