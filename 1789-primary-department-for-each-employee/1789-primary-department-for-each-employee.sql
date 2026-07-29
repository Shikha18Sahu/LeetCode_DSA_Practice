# Write your MySQL query statement below
Select employee_id, department_id
from Employee
where primary_flag = 'Y'
or employee_id in (
    Select employee_id from Employee
    group by employee_id
    having count(department_id) = 1
)


# dono condition sath me check kr rhi 
# where primaryflay = Y or 
# in employee_id(1,3)

-- taki where se N vale condition gayab na ho jayen 