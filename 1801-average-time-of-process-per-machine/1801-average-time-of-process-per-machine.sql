
select machine_id,round(avg(process_time),3) as processing_time
from(
select s.machine_id,s.process_id,
e.timestamp - s.timestamp as process_time from
Activity s join Activity e
on s.machine_id = e.machine_id and
s.process_id = e.process_id where
s.activity_type = 'start' and e.activity_type = 'end'
) as sub 
group by machine_id
