# Write your MySQL query statement below
Select  round(avg(if(d.order_date = d.customer_pref_delivery_date,1 ,0) * 100),2)as immediate_percentage
From Delivery d
where (d.customer_id, order_date) in(
    Select customer_id, min(order_date)
    from Delivery
    group by customer_id
)