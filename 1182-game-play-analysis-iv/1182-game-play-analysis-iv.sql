select ROUND(count(distinct a.player_id)/(select count(distinct player_id) from Activity),2) as fraction from Activity a join
(select distinct player_id,MIN(event_date) as event_date
from Activity 
group by player_id) sub
on sub.player_id = a.player_id
where DATEDIFF(a.event_date,sub.event_date) = 1
