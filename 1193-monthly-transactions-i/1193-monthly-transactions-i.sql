# Write your MySQL query statement below
Select date_format(trans_date, '%Y-%m')as month, 
country, 
count(id)as trans_count, 
sum(if (state = 'approved' ,1, 0))as approved_count, 
sum(amount)as trans_total_amount, 
sum(if (state = 'approved' ,amount, 0))as approved_total_amount
From Transactions
group by month, country