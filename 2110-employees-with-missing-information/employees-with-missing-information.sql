# Write your MySQL query statement below
-- we have to left join


select Salaries.employee_id from Salaries left join
Employees on  Salaries.employee_id=Employees.employee_id where
name is null
union
select Employees.employee_id from Employees left join
Salaries on Employees.employee_id=Salaries.employee_id where
salary is null
order by employee_id;

