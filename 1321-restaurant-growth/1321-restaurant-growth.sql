# Write your MySQL query statement below
Select visited_on, amount, round(average_amount, 2) as average_amount 
from(
    Select
    visited_on,
    sum(daily_amount)over(
         order by visited_on 
         rows between 6 preceding and current row) as amount,
    avg(daily_amount)over(
        order by visited_on
        rows between 6 preceding and current row) as average_amount
    from
     (
        Select visited_on, 
        sum(amount) as daily_amount
        from Customer
        group by visited_on
    )daily_totals
) final_window

where visited_on >=(
    Select date_add(min(visited_on), interval 6 day) 
    from Customer) 