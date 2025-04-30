# Write your MySQL query statement below
select e.name
from Employee e 
join (select managerId,count(managerId)
from Employee 
group by managerId
having count(managerId) >= 5)
e1 on e.id = e1.managerId

