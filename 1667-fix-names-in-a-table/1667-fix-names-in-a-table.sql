# Write your MySQL query statement below
Select 
      user_id , 
      concat(
        upper(substring(name,1,1)), 
        lower(substring(name,2)) 
       ) as name
From Users
order by user_id


-- (1,1) → position 1 se start karo, 1 character uthao
-- start, length   1 se start kro length 1 ithao 
-- (2,)  2 se start kro aur purwe tk ...