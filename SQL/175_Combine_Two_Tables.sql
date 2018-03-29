select Person.FirstName, Person.LastName, Address.City, Address.State 
from Person left join Address on Person.PersonId = Address.PersonId ; 
/*
    使用左连接，因为它要求对每个人找到他的地址和洲 。。
*/