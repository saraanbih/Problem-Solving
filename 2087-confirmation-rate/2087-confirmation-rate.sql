# Write your MySQL query statement below
select s.user_id,
COALESCE(ROUND(SUM(c.action = 'confirmed') / COUNT(c.action), 2), 0) as confirmation_rate
from Confirmations c
right join Signups s
on c.user_id = s.user_id
group by user_id 
