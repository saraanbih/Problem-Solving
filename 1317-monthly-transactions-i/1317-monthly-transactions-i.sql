# Write your MySQL query statement below
select DATE_FORMAT(trans_date,'%Y-%m') as month,
        country,
        count(*) as trans_count,
        IFNULL(count(CASE when state = 'approved' then 1 end),0) as approved_count,
        SUM(amount) as trans_total_amount,
        IFNULL(SUM(case when state = 'approved' then amount end),0) as approved_total_amount
from Transactions
group by month,country