select 
q.query_name,
ROUND(AVG(q.rating/q.position),2) as quality,
ROUND(COUNT(CASE when q.rating < 3 Then 1 ELSE NULL END) / count(*) * 100,2) as  poor_query_percentage 
from Queries q
group by q.query_name