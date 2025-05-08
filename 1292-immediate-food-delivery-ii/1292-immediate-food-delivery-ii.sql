select ROUND(COUNT(case when d.customer_pref_delivery_date = sub.first_order then 1 end)*100/count(*),2) as immediate_percentage 
from Delivery d join(
    select customer_id,MIN(order_date) as first_order
    from Delivery
    group by customer_id) sub
on sub.customer_id = d.customer_id and sub.first_order = d.order_date